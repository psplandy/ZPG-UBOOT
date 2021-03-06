/*
 * (C) Copyright 2011
 * Logic Product Development <www.logicpd.com>
 *
 * Author :
 *	Peter Barada <peter.barada@logicpd.com>
 *
 * Derived from Beagle Board and 3430 SDP code by
 *	Richard Woodruff <r-woodruff2@ti.com>
 *	Syed Mohammed Khasim <khasim@ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <dm.h>
#include <ns16550.h>
#include <netdev.h>
#include <flash.h>
#include <nand.h>
#include <i2c.h>
#include <twl4030.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <linux/mtd/rawnand.h>
#include <asm/omap_musb.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include "omap3logic.h"

DECLARE_GLOBAL_DATA_PTR;

/* This is only needed until SPL gets OF support */
#ifdef CONFIG_SPL_BUILD
static const struct ns16550_platdata omap3logic_serial = {
	.base = OMAP34XX_UART1,
	.reg_shift = 2,
	.clock = V_NS16550_CLK,
	.fcr = UART_FCR_DEFVAL,
};

U_BOOT_DEVICE(omap3logic_uart) = {
	"ns16550_serial",
	&omap3logic_serial
};
#endif

/*
 * two dimensional array of strucures containining board name and Linux
 * machine IDs; row it selected based on CPU column is slected based
 * on hsusb0_data5 pin having a pulldown resistor
 */
static struct board_id {
	char *name;
	int machine_id;
	char *fdtfile;
} boards[2][2] = {
	{
		{
			.name		= "OMAP35xx SOM LV",
			.machine_id	= MACH_TYPE_OMAP3530_LV_SOM,
			.fdtfile	= "logicpd-som-lv-35xx-devkit.dtb",
		},
		{
			.name		= "OMAP35xx Torpedo",
			.machine_id	= MACH_TYPE_OMAP3_TORPEDO,
			.fdtfile	= "logicpd-torpedo-35xx-devkit.dtb",
		},
	},
	{
		{
			.name		= "DM37xx SOM LV",
			.fdtfile	= "logicpd-som-lv-37xx-devkit.dtb",
		},
		{
			.name		= "DM37xx Torpedo",
			.fdtfile	= "logicpd-torpedo-37xx-devkit.dtb",
		},
	},
};

#ifdef CONFIG_SPL_OS_BOOT
int spl_start_uboot(void)
{
	/* break into full u-boot on 'c' */
	return serial_tstc() && serial_getc() == 'c';
}
#endif

#if defined(CONFIG_SPL_BUILD)
/*
 * Routine: get_board_mem_timings
 * Description: If we use SPL then there is no x-loader nor config header
 * so we have to setup the DDR timings ourself on the first bank.  This
 * provides the timing values back to the function that configures
 * the memory.
 */
void get_board_mem_timings(struct board_sdrc_timings *timings)
{
	timings->mr = MICRON_V_MR_165;
	/* 256MB DDR */
	timings->mcfg = MICRON_V_MCFG_200(256 << 20);
	timings->ctrla = MICRON_V_ACTIMA_200;
	timings->ctrlb = MICRON_V_ACTIMB_200;
	timings->rfr_ctrl = SDP_3430_SDRC_RFR_CTRL_200MHz;
}
#endif

#ifdef CONFIG_USB_MUSB_OMAP2PLUS
static struct musb_hdrc_config musb_config = {
	.multipoint     = 1,
	.dyn_fifo       = 1,
	.num_eps        = 16,
	.ram_bits       = 12,
};

static struct omap_musb_board_data musb_board_data = {
	.interface_type	= MUSB_INTERFACE_ULPI,
};

static struct musb_hdrc_platform_data musb_plat = {
#if defined(CONFIG_USB_MUSB_HOST)
	.mode           = MUSB_HOST,
#elif defined(CONFIG_USB_MUSB_GADGET)
	.mode		= MUSB_PERIPHERAL,
#else
#error "Please define either CONFIG_USB_MUSB_HOST or CONFIG_USB_MUSB_GADGET"
#endif
	.config         = &musb_config,
	.power          = 100,
	.platform_ops	= &omap2430_ops,
	.board_data	= &musb_board_data,
};
#endif


/*
 * Routine: misc_init_r
 * Description: Configure board specific parts
 */
int misc_init_r(void)
{
	twl4030_power_init();
	omap_die_id_display();

#ifdef CONFIG_USB_MUSB_OMAP2PLUS
	musb_register(&musb_plat, &musb_board_data, (void *)MUSB_BASE);
#endif

	return 0;
}

/*
 * BOARD_ID_GPIO - GPIO of pin with optional pulldown resistor on SOM LV
 */
#define BOARD_ID_GPIO	189 /* hsusb0_data5 pin */

/*
 * Routine: board_init
 * Description: Early hardware init.
 */
int board_init(void)
{
	gpmc_init(); /* in SRAM or SDRAM, finish GPMC */

	/* boot param addr */
	gd->bd->bi_boot_params = (OMAP34XX_SDRC_CS0 + 0x100);

	return 0;
}

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
	struct board_id *board;
	unsigned int val;

	/*
	 * To identify between a SOM LV and Torpedo module,
	 * a pulldown resistor is on hsusb0_data5 for the SOM LV module.
	 * Drive the pin (and let it soak), then read it back.
	 * If the pin is still high its a Torpedo.  If low its a SOM LV
	 */

	/* Mux hsusb0_data5 as a GPIO */
	MUX_VAL(CP(HSUSB0_DATA5),	(IEN  | PTD | DIS | M4));

	if (gpio_request(BOARD_ID_GPIO, "husb0_data5.gpio_189") == 0) {

		/*
		 * Drive BOARD_ID_GPIO - the pulldown resistor on the SOM LV
		 * will drain the voltage.
		 */
		gpio_direction_output(BOARD_ID_GPIO, 0);
		gpio_set_value(BOARD_ID_GPIO, 1);

		/* Let it soak for a bit */
		sdelay(0x100);

		/*
		 * Read state of BOARD_ID_GPIO as an input and if its set.
		 * If so the board is a Torpedo
		 */
		gpio_direction_input(BOARD_ID_GPIO);
		val = gpio_get_value(BOARD_ID_GPIO);
		gpio_free(BOARD_ID_GPIO);

		board = &boards[!!(get_cpu_family() == CPU_OMAP36XX)][!!val];
		printf("Board: %s\n", board->name);

		/* Set the machine_id passed to Linux */
		if (board->machine_id)
			gd->bd->bi_arch_number = board->machine_id;

		/* If the user has not set fdtimage, set the default */
		if (!env_get("fdtimage"))
			env_set("fdtimage", board->fdtfile);
	}

	/* restore hsusb0_data5 pin as hsusb0_data5 */
	MUX_VAL(CP(HSUSB0_DATA5),	(IEN  | PTD | DIS | M0));
	return 0;
}
#endif

#if defined(CONFIG_MMC)
int board_mmc_init(bd_t *bis)
{
	return omap_mmc_init(0, 0, 0, -1, -1);
}
#endif

#if defined(CONFIG_MMC)
void board_mmc_power_init(void)
{
	twl4030_power_mmc_init(0);
}
#endif

#ifdef CONFIG_SMC911X
/* GPMC CS1 settings for Logic SOM LV/Torpedo LAN92xx Ethernet chip */
static const u32 gpmc_lan92xx_config[] = {
	NET_LAN92XX_GPMC_CONFIG1,
	NET_LAN92XX_GPMC_CONFIG2,
	NET_LAN92XX_GPMC_CONFIG3,
	NET_LAN92XX_GPMC_CONFIG4,
	NET_LAN92XX_GPMC_CONFIG5,
	NET_LAN92XX_GPMC_CONFIG6,
};

int board_eth_init(bd_t *bis)
{
	enable_gpmc_cs_config(gpmc_lan92xx_config, &gpmc_cfg->cs[1],
			CONFIG_SMC911X_BASE, GPMC_SIZE_16M);

	return smc911x_initialize(0, CONFIG_SMC911X_BASE);
}
#endif

/*
 * IEN  - Input Enable
 * IDIS - Input Disable
 * PTD  - Pull type Down
 * PTU  - Pull type Up
 * DIS  - Pull type selection is inactive
 * EN   - Pull type selection is active
 * M0   - Mode 0
 * The commented string gives the final mux configuration for that pin
 */

/*
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers specific to the
 *		hardware. Many pins need to be moved from protect to primary
 *		mode.
 */
void set_muxconf_regs(void)
{
	MUX_VAL(CP(SDRC_D0), (IEN  | PTD | DIS | M0)); /*SDRC_D0*/
	MUX_VAL(CP(SDRC_D1), (IEN  | PTD | DIS | M0)); /*SDRC_D1*/
	MUX_VAL(CP(SDRC_D2), (IEN  | PTD | DIS | M0)); /*SDRC_D2*/
	MUX_VAL(CP(SDRC_D3), (IEN  | PTD | DIS | M0)); /*SDRC_D3*/
	MUX_VAL(CP(SDRC_D4), (IEN  | PTD | DIS | M0)); /*SDRC_D4*/
	MUX_VAL(CP(SDRC_D5), (IEN  | PTD | DIS | M0)); /*SDRC_D5*/
	MUX_VAL(CP(SDRC_D6), (IEN  | PTD | DIS | M0)); /*SDRC_D6*/
	MUX_VAL(CP(SDRC_D7), (IEN  | PTD | DIS | M0)); /*SDRC_D7*/
	MUX_VAL(CP(SDRC_D8), (IEN  | PTD | DIS | M0)); /*SDRC_D8*/
	MUX_VAL(CP(SDRC_D9), (IEN  | PTD | DIS | M0)); /*SDRC_D9*/
	MUX_VAL(CP(SDRC_D10), (IEN  | PTD | DIS | M0)); /*SDRC_D10*/
	MUX_VAL(CP(SDRC_D11), (IEN  | PTD | DIS | M0)); /*SDRC_D11*/
	MUX_VAL(CP(SDRC_D12), (IEN  | PTD | DIS | M0)); /*SDRC_D12*/
	MUX_VAL(CP(SDRC_D13), (IEN  | PTD | DIS | M0)); /*SDRC_D13*/
	MUX_VAL(CP(SDRC_D14), (IEN  | PTD | DIS | M0)); /*SDRC_D14*/
	MUX_VAL(CP(SDRC_D15), (IEN  | PTD | DIS | M0)); /*SDRC_D15*/
	MUX_VAL(CP(SDRC_D16), (IEN  | PTD | DIS | M0)); /*SDRC_D16*/
	MUX_VAL(CP(SDRC_D17), (IEN  | PTD | DIS | M0)); /*SDRC_D17*/
	MUX_VAL(CP(SDRC_D18), (IEN  | PTD | DIS | M0)); /*SDRC_D18*/
	MUX_VAL(CP(SDRC_D19), (IEN  | PTD | DIS | M0)); /*SDRC_D19*/
	MUX_VAL(CP(SDRC_D20), (IEN  | PTD | DIS | M0)); /*SDRC_D20*/
	MUX_VAL(CP(SDRC_D21), (IEN  | PTD | DIS | M0)); /*SDRC_D21*/
	MUX_VAL(CP(SDRC_D22), (IEN  | PTD | DIS | M0)); /*SDRC_D22*/
	MUX_VAL(CP(SDRC_D23), (IEN  | PTD | DIS | M0)); /*SDRC_D23*/
	MUX_VAL(CP(SDRC_D24), (IEN  | PTD | DIS | M0)); /*SDRC_D24*/
	MUX_VAL(CP(SDRC_D25), (IEN  | PTD | DIS | M0)); /*SDRC_D25*/
	MUX_VAL(CP(SDRC_D26), (IEN  | PTD | DIS | M0)); /*SDRC_D26*/
	MUX_VAL(CP(SDRC_D27), (IEN  | PTD | DIS | M0)); /*SDRC_D27*/
	MUX_VAL(CP(SDRC_D28), (IEN  | PTD | DIS | M0)); /*SDRC_D28*/
	MUX_VAL(CP(SDRC_D29), (IEN  | PTD | DIS | M0)); /*SDRC_D29*/
	MUX_VAL(CP(SDRC_D30), (IEN  | PTD | DIS | M0)); /*SDRC_D30*/
	MUX_VAL(CP(SDRC_D31), (IEN  | PTD | DIS | M0)); /*SDRC_D31*/
	MUX_VAL(CP(SDRC_CLK), (IEN  | PTD | DIS | M0)); /*SDRC_CLK*/
	MUX_VAL(CP(SDRC_DQS0), (IEN  | PTD | DIS | M0)); /*SDRC_DQS0*/
	MUX_VAL(CP(SDRC_DQS1), (IEN  | PTD | DIS | M0)); /*SDRC_DQS1*/
	MUX_VAL(CP(SDRC_DQS2), (IEN  | PTD | DIS | M0)); /*SDRC_DQS2*/
	MUX_VAL(CP(SDRC_DQS3), (IEN  | PTD | DIS | M0)); /*SDRC_DQS3*/
	MUX_VAL(CP(SDRC_CKE0), (IDIS | PTU | EN  | M0)); /*SDRC_CKE0*/
	MUX_VAL(CP(SDRC_CKE1), (IDIS | PTU | DIS | M0)); /*SDRC_CKE1*/

	MUX_VAL(CP(GPMC_A1), (IDIS | PTU | EN  | M0)); /*GPMC_A1*/
	MUX_VAL(CP(GPMC_A2), (IDIS | PTU | EN  | M0)); /*GPMC_A2*/
	MUX_VAL(CP(GPMC_A3), (IDIS | PTU | EN  | M0)); /*GPMC_A3*/
	MUX_VAL(CP(GPMC_A4), (IDIS | PTU | EN  | M0)); /*GPMC_A4*/
	MUX_VAL(CP(GPMC_A5), (IDIS | PTU | EN  | M0)); /*GPMC_A5*/
	MUX_VAL(CP(GPMC_A6), (IDIS | PTU | EN  | M0)); /*GPMC_A6*/
	MUX_VAL(CP(GPMC_A7), (IDIS | PTU | EN  | M0)); /*GPMC_A7*/
	MUX_VAL(CP(GPMC_A8), (IDIS | PTU | EN  | M0)); /*GPMC_A8*/
	MUX_VAL(CP(GPMC_A9), (IDIS | PTU | EN  | M0)); /*GPMC_A9*/
	MUX_VAL(CP(GPMC_A10), (IDIS | PTU | EN  | M0)); /*GPMC_A10*/
	MUX_VAL(CP(GPMC_D0), (IEN  | PTU | EN  | M0)); /*GPMC_D0*/
	MUX_VAL(CP(GPMC_D1), (IEN  | PTU | EN  | M0)); /*GPMC_D1*/
	MUX_VAL(CP(GPMC_D2), (IEN  | PTU | EN  | M0)); /*GPMC_D2*/
	MUX_VAL(CP(GPMC_D3), (IEN  | PTU | EN  | M0)); /*GPMC_D3*/
	MUX_VAL(CP(GPMC_D4),  (IEN  | PTU | EN  | M0)); /*GPMC_D4*/
	MUX_VAL(CP(GPMC_D5),  (IEN  | PTU | EN  | M0)); /*GPMC_D5*/
	MUX_VAL(CP(GPMC_D6),  (IEN  | PTU | EN  | M0)); /*GPMC_D6*/
	MUX_VAL(CP(GPMC_D7),   (IEN  | PTU | EN  | M0)); /*GPMC_D7*/
	MUX_VAL(CP(GPMC_D8),  (IEN  | PTU | EN  | M0)); /*GPMC_D8*/
	MUX_VAL(CP(GPMC_D9),  (IEN  | PTU | EN  | M0)); /*GPMC_D9*/
	MUX_VAL(CP(GPMC_D10), (IEN  | PTU | EN  | M0)); /*GPMC_D10*/
	MUX_VAL(CP(GPMC_D11), (IEN  | PTU | EN  | M0)); /*GPMC_D11*/
	MUX_VAL(CP(GPMC_D12), (IEN  | PTU | EN  | M0)); /*GPMC_D12*/
	MUX_VAL(CP(GPMC_D13), (IEN  | PTU | EN  | M0)); /*GPMC_D13*/
	MUX_VAL(CP(GPMC_D14), (IEN  | PTU | EN  | M0)); /*GPMC_D14*/
	MUX_VAL(CP(GPMC_D15), (IEN  | PTU | EN  | M0)); /*GPMC_D15*/
	MUX_VAL(CP(GPMC_NCS0), (IDIS | PTU | EN  | M0)); /*GPMC_nCS0*/
	MUX_VAL(CP(GPMC_NCS1), (IDIS | PTU | EN  | M0)); /*GPMC_nCS1*/
	MUX_VAL(CP(GPMC_NCS2), (IDIS | PTU | EN  | M0)); /*GPMC_nCS2*/
	MUX_VAL(CP(GPMC_NCS3), (IDIS | PTU | EN  | M0)); /*GPMC_nCS3*/
	MUX_VAL(CP(GPMC_NCS4), (IEN  | PTU | EN  | M0)); /*GPMC_nCS4*/
	MUX_VAL(CP(GPMC_NCS5), (IDIS | PTU | EN  | M0)); /*GPMC_nCS5*/
	MUX_VAL(CP(GPMC_NCS6), (IEN  | PTU | EN | M0)); /*GPMC_nCS6*/
	MUX_VAL(CP(GPMC_NCS7), (IEN  | PTU | EN  | M0)); /*GPMC_nCS7*/
	MUX_VAL(CP(GPMC_CLK),  (IDIS | PTU | EN  | M0)); /*GPMC_CLK*/
	MUX_VAL(CP(GPMC_NADV_ALE), (IDIS | PTD | DIS | M0)); /*GPMC_nADV_ALE*/
	MUX_VAL(CP(GPMC_NOE), (IDIS | PTD | DIS | M0)); /*GPMC_nOE*/
	MUX_VAL(CP(GPMC_NWE), (IDIS | PTD | DIS | M0)); /*GPMC_nWE*/
	MUX_VAL(CP(GPMC_NBE0_CLE), (IDIS | PTU | EN  | M0)); /*GPMC_nBE0_CLE*/
	MUX_VAL(CP(GPMC_NBE1), (IEN  | PTU | EN  | M0)); /*GPMC_nBE1*/
	MUX_VAL(CP(GPMC_NWP),  (IEN  | PTD | DIS | M0)); /*GPMC_nWP*/
	MUX_VAL(CP(GPMC_WAIT0), (IEN  | PTU | EN  | M0)); /*GPMC_WAIT0*/
	MUX_VAL(CP(GPMC_WAIT1), (IEN  | PTU | EN  | M0)); /*GPMC_WAIT1*/
	MUX_VAL(CP(GPMC_WAIT2), (IEN  | PTU | EN  | M4)); /*GPIO_64*/
	MUX_VAL(CP(GPMC_WAIT3), (IEN  | PTU | EN  | M0)); /*GPMC_WAIT3*/

	MUX_VAL(CP(CAM_HS), (IEN  | PTU | EN  | M0)); /*CAM_HS */
	MUX_VAL(CP(CAM_VS), (IEN  | PTU | EN  | M0)); /*CAM_VS */
	MUX_VAL(CP(CAM_XCLKA), (IDIS | PTD | DIS | M0)); /*CAM_XCLKA*/
	MUX_VAL(CP(CAM_PCLK), (IEN  | PTU | EN  | M0)); /*CAM_PCLK*/
	MUX_VAL(CP(CAM_FLD), (IDIS | PTD | DIS | M4)); /*GPIO_98*/
	MUX_VAL(CP(CAM_D0), (IEN  | PTD | DIS | M0)); /*CAM_D0*/
	MUX_VAL(CP(CAM_D1), (IEN  | PTD | DIS | M0)); /*CAM_D1*/
	MUX_VAL(CP(CAM_D2), (IEN  | PTD | DIS | M0)); /*CAM_D2*/
	MUX_VAL(CP(CAM_D3), (IEN  | PTD | DIS | M0)); /*CAM_D3*/
	MUX_VAL(CP(CAM_D4), (IEN  | PTD | DIS | M0)); /*CAM_D4*/
	MUX_VAL(CP(CAM_D5), (IEN  | PTD | DIS | M0)); /*CAM_D5*/
	MUX_VAL(CP(CAM_D6), (IEN  | PTD | DIS | M0)); /*CAM_D6*/
	MUX_VAL(CP(CAM_D7), (IEN  | PTD | DIS | M0)); /*CAM_D7*/
	MUX_VAL(CP(CAM_D8), (IEN  | PTD | DIS | M0)); /*CAM_D8*/
	MUX_VAL(CP(CAM_D9), (IEN  | PTD | DIS | M0)); /*CAM_D9*/
	MUX_VAL(CP(CAM_D10), (IEN  | PTD | DIS | M0)); /*CAM_D10*/
	MUX_VAL(CP(CAM_D11), (IEN  | PTD | DIS | M0)); /*CAM_D11*/
	MUX_VAL(CP(CAM_XCLKB), (IDIS | PTD | DIS | M0)); /*CAM_XCLKB*/
	MUX_VAL(CP(CAM_WEN), (IEN  | PTD | DIS | M4)); /*GPIO_167*/
	MUX_VAL(CP(CAM_STROBE), (IDIS | PTD | DIS | M0)); /*CAM_STROBE*/

	MUX_VAL(CP(CSI2_DX0), (IEN  | PTD | DIS | M0)); /*CSI2_DX0*/
	MUX_VAL(CP(CSI2_DY0), (IEN  | PTD | DIS | M0)); /*CSI2_DY0*/
	MUX_VAL(CP(CSI2_DX1), (IEN  | PTD | DIS | M0)); /*CSI2_DX1*/
	MUX_VAL(CP(CSI2_DY1), (IEN  | PTD | DIS | M0)); /*CSI2_DY1*/

	MUX_VAL(CP(MCBSP2_FSX), (IEN  | PTD | DIS | M0)); /*McBSP2_FSX*/
	MUX_VAL(CP(MCBSP2_CLKX), (IEN  | PTD | DIS | M0)); /*McBSP2_CLKX*/
	MUX_VAL(CP(MCBSP2_DR), (IEN  | PTD | DIS | M0)); /*McBSP2_DR*/
	MUX_VAL(CP(MCBSP2_DX), (IDIS | PTD | DIS | M0)); /*McBSP2_DX*/

	MUX_VAL(CP(MMC1_CLK), (IDIS | PTU | EN  | M0)); /*MMC1_CLK*/
	MUX_VAL(CP(MMC1_CMD), (IEN  | PTU | EN  | M0)); /*MMC1_CMD*/
	MUX_VAL(CP(MMC1_DAT0), (IEN  | PTU | EN  | M0)); /*MMC1_DAT0*/
	MUX_VAL(CP(MMC1_DAT1), (IEN  | PTU | EN  | M0)); /*MMC1_DAT1*/
	MUX_VAL(CP(MMC1_DAT2), (IEN  | PTU | EN  | M0)); /*MMC1_DAT2*/
	MUX_VAL(CP(MMC1_DAT3), (IEN  | PTU | EN  | M0)); /*MMC1_DAT3*/
	MUX_VAL(CP(MMC1_DAT4), (IEN  | PTU | EN  | M0)); /*MMC1_DAT4*/
	MUX_VAL(CP(MMC1_DAT5), (IEN  | PTU | EN  | M0)); /*MMC1_DAT5*/
	MUX_VAL(CP(MMC1_DAT6), (IEN  | PTU | EN  | M0)); /*MMC1_DAT6*/
	MUX_VAL(CP(MMC1_DAT7), (IEN  | PTU | EN  | M0)); /*MMC1_DAT7*/

	MUX_VAL(CP(MMC2_CLK),  (IEN  | PTD | DIS | M0)); /*MMC2_CLK*/
	MUX_VAL(CP(MMC2_CMD),  (IEN  | PTU | EN  | M0)); /*MMC2_CMD*/
	MUX_VAL(CP(MMC2_DAT0), (IEN  | PTU | EN  | M0)); /*MMC2_DAT0*/
	MUX_VAL(CP(MMC2_DAT1), (IEN  | PTU | EN  | M0)); /*MMC2_DAT1*/
	MUX_VAL(CP(MMC2_DAT2), (IEN  | PTU | EN  | M0)); /*MMC2_DAT2*/
	MUX_VAL(CP(MMC2_DAT3), (IEN  | PTU | EN  | M0)); /*MMC2_DAT3*/
	MUX_VAL(CP(MMC2_DAT4), (IDIS | PTD | DIS | M0)); /*MMC2_DAT4*/
	MUX_VAL(CP(MMC2_DAT5), (IDIS | PTD | DIS | M0)); /*MMC2_DAT5*/
	MUX_VAL(CP(MMC2_DAT6), (IDIS | PTD | DIS | M0)); /*MMC2_DAT6 */
	MUX_VAL(CP(MMC2_DAT7), (IEN  | PTU | EN  | M0)); /*MMC2_DAT7*/

	MUX_VAL(CP(MCBSP3_DX), (IDIS | PTD | DIS | M0)); /*McBSP3_DX*/
	MUX_VAL(CP(MCBSP3_DR), (IEN  | PTD | DIS | M0)); /*McBSP3_DR*/
	MUX_VAL(CP(MCBSP3_CLKX), (IEN  | PTD | DIS | M0)); /*McBSP3_CLKX*/
	MUX_VAL(CP(MCBSP3_FSX), (IEN  | PTD | DIS | M0)); /*McBSP3_FSX*/

	MUX_VAL(CP(UART2_CTS), (IEN  | PTU | EN  | M0)); /*UART2_CTS*/
	MUX_VAL(CP(UART2_RTS), (IDIS | PTD | DIS | M0)); /*UART2_RTS*/
	MUX_VAL(CP(UART2_TX), (IDIS | PTD | DIS | M0)); /*UART2_TX*/
	MUX_VAL(CP(UART2_RX), (IEN  | PTD | DIS | M0)); /*UART2_RX*/

	MUX_VAL(CP(UART1_TX), (IDIS | PTD | DIS | M0)); /*UART1_TX*/
	MUX_VAL(CP(UART1_RTS), (IDIS | PTD | DIS | M0)); /*UART1_RTS*/
	MUX_VAL(CP(UART1_CTS), (IEN  | PTU | DIS | M0)); /*UART1_CTS*/
	MUX_VAL(CP(UART1_RX), (IEN  | PTD | DIS | M0)); /*UART1_RX*/

	MUX_VAL(CP(MCBSP4_CLKX), (IDIS | PTD | DIS | M4)); /*GPIO_152*/
	MUX_VAL(CP(MCBSP4_DR), (IDIS | PTD | DIS | M4)); /*GPIO_153*/

	MUX_VAL(CP(MCBSP1_CLKR), (IEN  | PTD | DIS | M0)); /*MCBSP1_CLKR*/
	MUX_VAL(CP(MCBSP1_FSR), (IDIS | PTU | EN  | M0)); /*MCBSP1_FSR*/
	MUX_VAL(CP(MCBSP1_DX), (IDIS | PTD | DIS | M0)); /*MCBSP1_DX*/
	MUX_VAL(CP(MCBSP1_DR), (IEN  | PTD | DIS | M0)); /*MCBSP1_DR*/
	MUX_VAL(CP(MCBSP_CLKS), (IEN  | PTU | DIS | M0)); /*MCBSP_CLKS*/
	MUX_VAL(CP(MCBSP1_FSX), (IEN  | PTD | DIS | M0)); /*MCBSP1_FSX*/
	MUX_VAL(CP(MCBSP1_CLKX), (IEN  | PTD | DIS | M0)); /*MCBSP1_CLKX*/

	MUX_VAL(CP(UART3_CTS_RCTX), (IEN  | PTD | EN  | M0)); /*UART3_CTS_*/
	MUX_VAL(CP(UART3_RTS_SD),  (IDIS | PTD | DIS | M0)); /*UART3_RTS_SD */
	MUX_VAL(CP(UART3_RX_IRRX), (IEN  | PTD | DIS | M0)); /*UART3_RX_IRRX*/
	MUX_VAL(CP(UART3_TX_IRTX), (IDIS | PTD | DIS | M0)); /*UART3_TX_IRTX*/

	MUX_VAL(CP(HSUSB0_CLK), (IEN  | PTD | DIS | M0)); /*HSUSB0_CLK*/
	MUX_VAL(CP(HSUSB0_STP), (IDIS | PTU | EN  | M0)); /*HSUSB0_STP*/
	MUX_VAL(CP(HSUSB0_DIR), (IEN  | PTD | DIS | M0)); /*HSUSB0_DIR*/
	MUX_VAL(CP(HSUSB0_NXT), (IEN  | PTD | DIS | M0)); /*HSUSB0_NXT*/
	MUX_VAL(CP(HSUSB0_DATA0), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA0*/
	MUX_VAL(CP(HSUSB0_DATA1), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA1*/
	MUX_VAL(CP(HSUSB0_DATA2), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA2*/
	MUX_VAL(CP(HSUSB0_DATA3), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA3*/
	MUX_VAL(CP(HSUSB0_DATA4), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA4*/
	MUX_VAL(CP(HSUSB0_DATA5), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA5*/
	MUX_VAL(CP(HSUSB0_DATA6), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA6*/
	MUX_VAL(CP(HSUSB0_DATA7), (IEN  | PTD | DIS | M0)); /*HSUSB0_DATA7*/

	MUX_VAL(CP(I2C1_SCL), (IEN  | PTU | EN  | M0)); /*I2C1_SCL*/
	MUX_VAL(CP(I2C1_SDA), (IEN  | PTU | EN  | M0)); /*I2C1_SDA*/

	MUX_VAL(CP(I2C2_SCL), (IEN  | PTU | EN  | M0)); /*I2C2_SCL*/
	MUX_VAL(CP(I2C2_SDA), (IEN  | PTU | EN  | M0)); /*I2C2_SDA*/

	MUX_VAL(CP(I2C3_SCL), (IEN  | PTU | EN  | M0)); /*I2C3_SCL*/
	MUX_VAL(CP(I2C3_SDA), (IEN  | PTU | EN  | M0)); /*I2C3_SDA*/

	MUX_VAL(CP(I2C4_SCL), (IEN  | PTU | EN  | M0)); /*I2C4_SCL*/
	MUX_VAL(CP(I2C4_SDA), (IEN  | PTU | EN  | M0)); /*I2C4_SDA*/

	MUX_VAL(CP(HDQ_SIO), (IEN  | PTU | EN  | M0)); /*HDQ_SIO*/

	MUX_VAL(CP(MCSPI1_CLK), (IEN  | PTD | DIS | M0)); /*McSPI1_CLK*/
	MUX_VAL(CP(MCSPI1_SIMO), (IEN  | PTD | DIS | M0)); /*McSPI1_SIMO  */
	MUX_VAL(CP(MCSPI1_SOMI), (IEN  | PTD | DIS | M0)); /*McSPI1_SOMI  */
	MUX_VAL(CP(MCSPI1_CS0), (IEN  | PTD | EN  | M0)); /*McSPI1_CS0*/
	MUX_VAL(CP(MCSPI1_CS1), (IEN  | PTD | EN  | M4)); /*GPIO_175*/
	MUX_VAL(CP(MCSPI1_CS2), (IEN  | PTU | DIS | M4)); /*GPIO_176*/
	MUX_VAL(CP(MCSPI1_CS3), (IEN  | PTD | EN  | M0)); /*McSPI1_CS3*/

	MUX_VAL(CP(MCSPI2_CLK), (IEN  | PTD | DIS | M0)); /*McSPI2_CLK*/
	MUX_VAL(CP(MCSPI2_SIMO), (IEN  | PTD | DIS | M0)); /*McSPI2_SIMO*/
	MUX_VAL(CP(MCSPI2_SOMI), (IEN  | PTD | DIS | M0)); /*McSPI2_SOMI*/
	MUX_VAL(CP(MCSPI2_CS0),  (IEN  | PTD | EN  | M0)); /*McSPI2_CS0*/
	MUX_VAL(CP(MCSPI2_CS1),  (IEN  | PTD | EN  | M0)); /*McSPI2_CS1*/

	MUX_VAL(CP(SYS_32K), (IEN  | PTD | DIS | M0)); /*SYS_32K*/
	MUX_VAL(CP(SYS_CLKREQ), (IEN  | PTD | DIS | M0)); /*SYS_CLKREQ*/
	MUX_VAL(CP(SYS_NIRQ), (IEN  | PTU | EN  | M0)); /*SYS_nIRQ*/
	MUX_VAL(CP(SYS_BOOT0), (IEN  | PTD | DIS | M4)); /*GPIO_2*/
	MUX_VAL(CP(SYS_BOOT1), (IEN  | PTD | DIS | M4)); /*GPIO_3 */
	MUX_VAL(CP(SYS_BOOT2), (IEN  | PTD | DIS | M4)); /*GPIO_4*/
	MUX_VAL(CP(SYS_BOOT3), (IEN  | PTD | DIS | M4)); /*GPIO_5*/
	MUX_VAL(CP(SYS_BOOT4), (IEN  | PTD | DIS | M4)); /*GPIO_6*/
	MUX_VAL(CP(SYS_BOOT5), (IEN  | PTD | DIS | M4)); /*GPIO_7*/

	MUX_VAL(CP(SYS_OFF_MODE), (IEN  | PTD | DIS | M0)); /*SYS_OFF_MODE*/
	MUX_VAL(CP(SYS_CLKOUT1), (IEN  | PTD | DIS | M0)); /*SYS_CLKOUT1*/
	MUX_VAL(CP(SYS_CLKOUT2), (IEN  | PTU | EN  | M0)); /*SYS_CLKOUT2*/

	MUX_VAL(CP(JTAG_TCK), (IEN  | PTD | DIS | M0)); /*JTAG_TCK*/
	MUX_VAL(CP(JTAG_TMS), (IEN  | PTD | DIS | M0)); /*JTAG_TMS*/
	MUX_VAL(CP(JTAG_TDI), (IEN  | PTD | DIS | M0)); /*JTAG_TDI*/
	MUX_VAL(CP(JTAG_EMU0), (IEN  | PTD | DIS | M0)); /*JTAG_EMU0*/
	MUX_VAL(CP(JTAG_EMU1), (IEN  | PTD | DIS | M0)); /*JTAG_EMU1*/

	MUX_VAL(CP(ETK_CLK_ES2), (IDIS | PTU | EN  | M0)); /*ETK_CLK*/
	MUX_VAL(CP(ETK_CTL_ES2), (IDIS | PTD | DIS | M0)); /*ETK_CTL*/
	MUX_VAL(CP(ETK_D0_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D0*/
	MUX_VAL(CP(ETK_D1_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D1*/
	MUX_VAL(CP(ETK_D2_ES2), (IEN  | PTD | EN  | M0)); /*ETK_D2*/
	MUX_VAL(CP(ETK_D3_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D3*/
	MUX_VAL(CP(ETK_D4_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D4*/
	MUX_VAL(CP(ETK_D5_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D5*/
	MUX_VAL(CP(ETK_D6_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D6*/
	MUX_VAL(CP(ETK_D7_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D7*/
	MUX_VAL(CP(ETK_D8_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D8*/
	MUX_VAL(CP(ETK_D9_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D9*/
	MUX_VAL(CP(ETK_D10_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D10*/
	MUX_VAL(CP(ETK_D11_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D11*/
	MUX_VAL(CP(ETK_D12_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D12*/
	MUX_VAL(CP(ETK_D13_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D13*/
	MUX_VAL(CP(ETK_D14_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D14*/
	MUX_VAL(CP(ETK_D15_ES2), (IEN  | PTD | DIS | M0)); /*ETK_D15*/

	MUX_VAL(CP(D2D_MCAD1), (IEN  | PTD | EN  | M0)); /*d2d_mcad1*/
	MUX_VAL(CP(D2D_MCAD2), (IEN  | PTD | EN  | M0)); /*d2d_mcad2*/
	MUX_VAL(CP(D2D_MCAD3), (IEN  | PTD | EN  | M0)); /*d2d_mcad3*/
	MUX_VAL(CP(D2D_MCAD4), (IEN  | PTD | EN  | M0)); /*d2d_mcad4*/
	MUX_VAL(CP(D2D_MCAD5), (IEN  | PTD | EN  | M0)); /*d2d_mcad5*/
	MUX_VAL(CP(D2D_MCAD6), (IEN  | PTD | EN  | M0)); /*d2d_mcad6*/
	MUX_VAL(CP(D2D_MCAD7), (IEN  | PTD | EN  | M0)); /*d2d_mcad7*/
	MUX_VAL(CP(D2D_MCAD8), (IEN  | PTD | EN  | M0)); /*d2d_mcad8*/
	MUX_VAL(CP(D2D_MCAD9), (IEN  | PTD | EN  | M0)); /*d2d_mcad9*/
	MUX_VAL(CP(D2D_MCAD10), (IEN  | PTD | EN  | M0)); /*d2d_mcad10*/
	MUX_VAL(CP(D2D_MCAD11), (IEN  | PTD | EN  | M0)); /*d2d_mcad11*/
	MUX_VAL(CP(D2D_MCAD12), (IEN  | PTD | EN  | M0)); /*d2d_mcad12*/
	MUX_VAL(CP(D2D_MCAD13), (IEN  | PTD | EN  | M0)); /*d2d_mcad13*/
	MUX_VAL(CP(D2D_MCAD14), (IEN  | PTD | EN  | M0)); /*d2d_mcad14*/
	MUX_VAL(CP(D2D_MCAD15), (IEN  | PTD | EN  | M0)); /*d2d_mcad15*/
	MUX_VAL(CP(D2D_MCAD16), (IEN  | PTD | EN  | M0)); /*d2d_mcad16*/
	MUX_VAL(CP(D2D_MCAD17), (IEN  | PTD | EN  | M0)); /*d2d_mcad17*/
	MUX_VAL(CP(D2D_MCAD18), (IEN  | PTD | EN  | M0)); /*d2d_mcad18*/
	MUX_VAL(CP(D2D_MCAD19), (IEN  | PTD | EN  | M0)); /*d2d_mcad19*/
	MUX_VAL(CP(D2D_MCAD20), (IEN  | PTD | EN  | M0)); /*d2d_mcad20*/
	MUX_VAL(CP(D2D_MCAD21), (IEN  | PTD | EN  | M0)); /*d2d_mcad21*/
	MUX_VAL(CP(D2D_MCAD22), (IEN  | PTD | EN  | M0)); /*d2d_mcad22*/
	MUX_VAL(CP(D2D_MCAD23), (IEN  | PTD | EN  | M0)); /*d2d_mcad23*/
	MUX_VAL(CP(D2D_MCAD24), (IEN  | PTD | EN  | M0)); /*d2d_mcad24*/
	MUX_VAL(CP(D2D_MCAD25), (IEN  | PTD | EN  | M0)); /*d2d_mcad25*/
	MUX_VAL(CP(D2D_MCAD26), (IEN  | PTD | EN  | M0)); /*d2d_mcad26*/
	MUX_VAL(CP(D2D_MCAD27), (IEN  | PTD | EN  | M0)); /*d2d_mcad27*/
	MUX_VAL(CP(D2D_MCAD28), (IEN  | PTD | EN  | M0)); /*d2d_mcad28*/
	MUX_VAL(CP(D2D_MCAD29), (IEN  | PTD | EN  | M0)); /*d2d_mcad29*/
	MUX_VAL(CP(D2D_MCAD30), (IEN  | PTD | EN  | M0)); /*d2d_mcad30*/
	MUX_VAL(CP(D2D_MCAD31), (IEN  | PTD | EN  | M0)); /*d2d_mcad31*/
	MUX_VAL(CP(D2D_MCAD32), (IEN  | PTD | EN  | M0)); /*d2d_mcad32*/
	MUX_VAL(CP(D2D_MCAD33), (IEN  | PTD | EN  | M0)); /*d2d_mcad33*/
	MUX_VAL(CP(D2D_MCAD34), (IEN  | PTD | EN  | M0)); /*d2d_mcad34*/
	MUX_VAL(CP(D2D_MCAD35), (IEN  | PTD | EN  | M0)); /*d2d_mcad35*/
	MUX_VAL(CP(D2D_MCAD36), (IEN  | PTD | EN  | M0)); /*d2d_mcad36*/
	MUX_VAL(CP(D2D_CLK26MI), (IEN  | PTD | DIS | M0)); /*d2d_clk26mi*/
	MUX_VAL(CP(D2D_NRESPWRON), (IEN  | PTD | EN  | M0)); /*d2d_nrespwron*/
	MUX_VAL(CP(D2D_NRESWARM), (IEN  | PTU | EN  | M0)); /*d2d_nreswarm */
	MUX_VAL(CP(D2D_ARM9NIRQ), (IEN  | PTD | DIS | M0)); /*d2d_arm9nirq */
	MUX_VAL(CP(D2D_UMA2P6FIQ), (IEN  | PTD | DIS | M0)); /*d2d_uma2p6fiq*/
	MUX_VAL(CP(D2D_SPINT), (IEN  | PTD | EN  | M0)); /*d2d_spint*/
	MUX_VAL(CP(D2D_FRINT), (IEN  | PTD | EN  | M0)); /*d2d_frint*/
	MUX_VAL(CP(D2D_DMAREQ0), (IEN  | PTD | DIS | M0)); /*d2d_dmareq0*/
	MUX_VAL(CP(D2D_DMAREQ1), (IEN  | PTD | DIS | M0)); /*d2d_dmareq1*/
	MUX_VAL(CP(D2D_DMAREQ2), (IEN  | PTD | DIS | M0)); /*d2d_dmareq2*/
	MUX_VAL(CP(D2D_DMAREQ3), (IEN  | PTD | DIS | M0)); /*d2d_dmareq3*/
	MUX_VAL(CP(D2D_N3GTRST), (IEN  | PTD | DIS | M0)); /*d2d_n3gtrst*/
	MUX_VAL(CP(D2D_N3GTDI),  (IEN  | PTD | DIS | M0)); /*d2d_n3gtdi*/
	MUX_VAL(CP(D2D_N3GTDO),  (IEN  | PTD | DIS | M0)); /*d2d_n3gtdo*/
	MUX_VAL(CP(D2D_N3GTMS),  (IEN  | PTD | DIS | M0)); /*d2d_n3gtms*/
	MUX_VAL(CP(D2D_N3GTCK),  (IEN  | PTD | DIS | M0)); /*d2d_n3gtck*/
	MUX_VAL(CP(D2D_N3GRTCK), (IEN  | PTD | DIS | M0)); /*d2d_n3grtck*/
	MUX_VAL(CP(D2D_MSTDBY),  (IEN  | PTU | EN  | M0)); /*d2d_mstdby*/
	MUX_VAL(CP(D2D_SWAKEUP), (IEN  | PTD | EN  | M0)); /*d2d_swakeup*/
	MUX_VAL(CP(D2D_IDLEREQ), (IEN  | PTD | DIS | M0)); /*d2d_idlereq*/
	MUX_VAL(CP(D2D_IDLEACK), (IEN  | PTU | EN  | M0)); /*d2d_idleack*/
	MUX_VAL(CP(D2D_MWRITE),  (IEN  | PTD | DIS | M0)); /*d2d_mwrite*/
	MUX_VAL(CP(D2D_SWRITE),  (IEN  | PTD | DIS | M0)); /*d2d_swrite*/
	MUX_VAL(CP(D2D_MREAD),   (IEN  | PTD | DIS | M0)); /*d2d_mread*/
	MUX_VAL(CP(D2D_SREAD),   (IEN  | PTD | DIS | M0)); /*d2d_sread*/
	MUX_VAL(CP(D2D_MBUSFLAG), (IEN  | PTD | DIS | M0)); /*d2d_mbusflag*/
	MUX_VAL(CP(D2D_SBUSFLAG), (IEN  | PTD | DIS | M0)); /*d2d_sbusflag*/
}
