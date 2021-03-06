/*
 * Copyright (c) 2018 Fuzhou Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef _SFNOR_H
#define _SFNOR_H

#include "sfc.h"

/* Four line data transmission detection */
#define SNOR_4BIT_DATA_DETECT_EN	0

#define NOR_PAGE_SIZE		256
#define NOR_BLOCK_SIZE		(64 * 1024)
#define NOR_SECS_BLK		(NOR_BLOCK_SIZE / 512)
#define NOR_SECS_PAGE		4

#define FEA_READ_STATUE_MASK	(0x3 << 0)
#define FEA_STATUE_MODE1	0
#define FEA_STATUE_MODE2	1
#define FEA_4BIT_READ		BIT(2)
#define FEA_4BIT_PROG		BIT(3)
#define FEA_4BYTE_ADDR		BIT(4)
#define FEA_4BYTE_ADDR_MODE	BIT(5)

/*Manufactory ID*/
#define MID_WINBOND             0xEF
#define MID_GIGADEV             0xC8
#define MID_MICRON              0x2C
#define MID_MACRONIX            0xC2
#define MID_SPANSION            0x01
#define MID_EON                 0x1C
#define MID_ST                  0x20
#define MID_XTX                 0x0B
#define MID_PUYA                0x85
#define MID_XMC                 0x20

/*Command Set*/
#define CMD_READ_JEDECID        (0x9F)
#define CMD_READ_DATA           (0x03)
#define CMD_READ_STATUS         (0x05)
#define CMD_WRITE_STATUS        (0x01)
#define CMD_PAGE_PROG           (0x02)
#define CMD_SECTOR_ERASE        (0x20)
#define CMD_BLK64K_ERASE        (0xD8)
#define CMD_BLK32K_ERASE        (0x52)
#define CMD_CHIP_ERASE          (0xC7)
#define CMD_WRITE_EN            (0x06)
#define CMD_WRITE_DIS           (0x04)
#define CMD_PAGE_READ           (0x13)
#define CMD_GET_FEATURE         (0x0F)
#define CMD_SET_FEATURE         (0x1F)
#define CMD_PROG_LOAD           (0x02)
#define CMD_PROG_EXEC           (0x10)
#define CMD_BLOCK_ERASE         (0xD8)
#define CMD_READ_DATA_X2        (0x3B)
#define CMD_READ_DATA_X4        (0x6B)
#define CMD_PROG_LOAD_X4        (0x32)
#define CMD_READ_STATUS2        (0x35)
#define CMD_READ_STATUS3        (0x15)
#define CMD_WRITE_STATUS2       (0x31)
#define CMD_WRITE_STATUS3       (0x11)
/* X1 cmd, X1 addr, X1 data */
#define CMD_FAST_READ_X1        (0x0B)
/* X1 cmd, X1 addr, X2 data */
#define CMD_FAST_READ_X2        (0x3B)
/* X1 cmd, X1 addr, X4 data SUPPORT GD MARCONIX WINBOND */
#define CMD_FAST_READ_X4        (0x6B)
/* X1 cmd, X1 addr, X4 data SUPPORT GD MARCONIX WINBOND */
#define CMD_FAST_4READ_X4       (0x6C)
/* X1 cmd, X4 addr, X4 data SUPPORT EON GD MARCONIX WINBOND */
#define CMD_FAST_READ_A4        (0xEB)
/* X1 cmd, X1 addr, X4 data, SUPPORT GD WINBOND */
#define CMD_PAGE_PROG_X4        (0x32)
/* X1 cmd, X4 addr, X4 data, SUPPORT MARCONIX */
#define CMD_PAGE_PROG_A4        (0x38)
#define CMD_RESET_NAND          (0xFF)
#define CMD_ENTER_4BYTE_MODE    (0xB7)
#define CMD_EXIT_4BYTE_MODE     (0xE9)
#define CMD_ENABLE_RESER	(0x66)
#define CMD_RESET_DEVICE	(0x99)
#define CMD_READ_PARAMETER	(0x5A)

enum NOR_ERASE_TYPE {
	ERASE_SECTOR = 0,
	ERASE_BLOCK64K,
	ERASE_CHIP
};

enum SNOR_IO_MODE {
	IO_MODE_SPI = 0,
	IO_MODE_QPI
};

enum SNOR_READ_MODE {
	READ_MODE_NOMAL = 0,
	READ_MODE_FAST
};

enum SNOR_ADDR_MODE {
	ADDR_MODE_3BYTE = 0,
	ADDR_MODE_4BYTE
};

typedef int (*SNOR_WRITE_STATUS)(u32 reg_index, u8 status);

struct SFNOR_DEV {
	u32	capacity;
	u8	manufacturer;
	u8	mem_type;
	u16	page_size;
	u32	blk_size;

	u8	read_cmd;
	u8	prog_cmd;
	u8	sec_erase_cmd;
	u8	blk_erase_cmd;
	u8	QE_bits;

	enum SNOR_READ_MODE  read_mode;
	enum SNOR_ADDR_MODE  addr_mode;
	enum SNOR_IO_MODE    io_mode;

	enum SFC_DATA_LINES read_lines;
	enum SFC_DATA_LINES prog_lines;

	SNOR_WRITE_STATUS write_status;
	struct mutex	lock; /* to lock this object */
};

struct flash_info {
	u32 id;

	u8 block_size;
	u8 sector_size;
	u8 read_cmd;
	u8 prog_cmd;

	u8 read_cmd_4;
	u8 prog_cmd_4;
	u8 sector_erase_cmd;
	u8 block_erase_cmd;

	u8 feature;
	u8 density;  /* (1 << density) sectors*/
	u8 QE_bits;
	u8 reserved2;
};

int snor_init(struct SFNOR_DEV *p_dev);
u32 snor_get_capacity(struct SFNOR_DEV *p_dev);
int snor_read(struct SFNOR_DEV *p_dev, u32 sec, u32 n_sec, void *p_data);
int snor_write(struct SFNOR_DEV *p_dev, u32 sec, u32 n_sec, const void *p_data);

#endif
