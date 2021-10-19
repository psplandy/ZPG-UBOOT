/* SPDX-License-Identifier:     GPL-2.0+ */
/*
 * (C) Copyright 2019 Rockchip Electronics Co., Ltd
 */

#ifndef _ROCKCHIP_CRYPTO_V2_H_
#define _ROCKCHIP_CRYPTO_V2_H_

#include <asm/io.h>

#define	cache_op_inner(area, addr, size) \
		flush_cache((unsigned long)addr, (unsigned long)size)

#define	RK_CRYPTO_KEY_ROOT		   0x00010000
#define	RK_CRYPTO_KEY_PRIVATE		   0x00020000
#define	RK_CRYPTO_MODE_MASK		   0x0000ffff
#define	RK_GET_CRYPTO_MODE(mode)	   (mode & RK_CRYPTO_MODE_MASK)
#define	RK_IS_CRYPTO_USE_ROOT_KEY(mode)    (!!(mode & RK_CRYPTO_KEY_ROOT))
#define	RK_IS_CRYPTO_USE_PRIVATE_KEY(mode) (!!(mode & RK_CRYPTO_KEY_PRIVATE)

#define	RK_AES_HASH_RX	0
#define	RK_AES_HASH_TX	1

enum rk_hash_algo {
	TEE_ALG_SHA1 = 1,
	TEE_ALG_MD5,
	TEE_ALG_SHA256,
	TEE_ALG_SHA224,
	TEE_ALG_SHA512,
	TEE_ALG_SHA384,
	TEE_ALG_SHA512_224,
	TEE_ALG_SHA512_256,
};

#define	_SBF(s,	v)			((v) <<	(s))
#define	_BIT(b)				_SBF(b,	1)

#define	DES_KEYSIZE			8
#define	TDES_EDE_KEYSIZE		24
#define	AES_KEYSIZE_128			16
#define	AES_KEYSIZE_192			24
#define	AES_KEYSIZE_256			32

#define	DES_BLOCK_SIZE			8
#define	AES_BLOCK_SIZE			16

#define	RK_MODE_ENCRYPT			0
#define	RK_MODE_DECRYPT			1

#define	HASH_MAX_SIZE			8192
#define	CIPHER_MAX_SIZE			8192

#define	_SBF(s,	v)			((v) <<	(s))
#define	_BIT(b)				_SBF(b,	1)

#define	DES_KEYSIZE			8
#define	TDES_EDE_KEYSIZE		24
#define	AES_KEYSIZE_128			16
#define	AES_KEYSIZE_192			24
#define	AES_KEYSIZE_256			32

#define	DES_BLOCK_SIZE			8
#define	AES_BLOCK_SIZE			16

#define	RK_MODE_ENCRYPT			0
#define	RK_MODE_DECRYPT			1

#define	CRYPTO_WRITE_MASK_SHIFT		(16)
#define	CRYPTO_WRITE_MASK_ALL		((0xffffu << CRYPTO_WRITE_MASK_SHIFT))

#define	WRITE_MASK			(16)

#define	CRU_CLKGATE_CON8_ALLCLK_EN	_SBF(12, 0x0F)
#define	CRU_CLKGATE_CON9_ALLCLK_EN	_SBF(2,	0x0F)

#define	CRYPTO_MST_NON_SECURE		_SBF(0,	0x03)
#define	CRYPTO_SLV_SECURE		_BIT(8)

/* Crypto control registers*/
#define	CRYPTO_CLK_CTL			0x0000
#define	CRYPTO_AUTO_CLKGATE_EN		_BIT(0)

#define	CRYPTO_RST_CTL			0x0004
#define	CRYPTO_SW_PKA_RESET		_BIT(2)
#define	CRYPTO_SW_RNG_RESET		_BIT(1)
#define	CRYPTO_SW_CC_RESET		_BIT(0)

/* Crypto DMA control registers*/
#define	CRYPTO_DMA_INT_EN		0x0008
#define	CRYPTO_ZERO_ERR_INT_EN		_BIT(6)
#define	CRYPTO_LIST_ERR_INT_EN		_BIT(5)
#define	CRYPTO_SRC_ERR_INT_EN		_BIT(4)
#define	CRYPTO_DST_ERR_INT_EN		_BIT(3)
#define	CRYPTO_SRC_ITEM_INT_EN		_BIT(2)
#define	CRYPTO_DST_ITEM_DONE_INT_EN	_BIT(1)
#define	CRYPTO_LIST_DONE_INT_EN		_BIT(0)

#define	CRYPTO_DMA_INT_ST		0x000C
#define	CRYPTO_ZERO_LEN_INT_ST		_BIT(6)
#define	CRYPTO_LIST_ERR_INT_ST		_BIT(5)
#define	CRYPTO_SRC_ERR_INT_ST		_BIT(4)
#define	CRYPTO_DST_ERR_INT_ST		_BIT(3)
#define	CRYPTO_SRC_ITEM_DONE_INT_ST	_BIT(2)
#define	CRYPTO_DST_ITEM_DONE_INT_ST _BIT(1)
#define	CRYPTO_LIST_DONE_INT_ST		_BIT(0)

#define	CRYPTO_DMA_CTL			0x0010
#define	CRYPTO_DMA_RESTART		_BIT(1)
#define	CRYPTO_DMA_START		_BIT(0)

/* DMA LIST Start Address Register */
#define	CRYPTO_DMA_LLI_ADDR		0x0014

#define	CRYPTO_DMA_ST			0x0018
#define	CRYPTO_DMA_BUSY			_BIT(0)

#define	CRYPTO_DMA_STATE		0x001C
#define	CRYPTO_LLI_IDLE_STATE		_SBF(4,	0x00)
#define	CRYPTO_LLI_FETCH_STATE		_SBF(4,	0x01)
#define	CRYPTO_LLI_WORK_STATE		_SBF(4,	0x02)
#define	CRYPTO_SRC_IDLE_STATE		_SBF(2,	0x00)
#define	CRYPTO_SRC_LOAD_STATE		_SBF(2,	0x01)
#define	CRYPTO_SRC_WORK_STATE		_SBF(2,	0x02)
#define	CRYPTO_DST_IDLE_STATE		_SBF(0,	0x00)
#define	CRYPTO_DST_LOAD_STATE		_SBF(0,	0x01)
#define	CRYPTO_DST_WORK_STATE		_SBF(0,	0x02)

/* DMA LLI Read	Address	Register */
#define	CRYPTO_DMA_LLI_RADDR		0x0020

/* DMA Source Data Read	Address	Register */
#define	CRYPTO_DMA_SRC_RADDR		0x0024

/* DMA Destination Data	Read Address Register */
#define	CRYPTO_DMA_DST_RADDR		0x0028

#define	CRYPTO_DMA_ITEM_ID		0x002C

#define	CRYPTO_FIFO_CTL			0x0040
#define	CRYPTO_DOUT_BYTESWAP		_BIT(1)
#define	CRYPTO_DOIN_BYTESWAP		_BIT(0)

/* Block Cipher	Control	Register */
#define	CRYPTO_BC_CTL			0x0044
#define	CRYPTO_BC_AES			_SBF(8,	0x00)
#define	CRYPTO_BC_DES			_SBF(8,	0x02)
#define	CRYPTO_BC_TDES			_SBF(8,	0x03)
#define	CRYPTO_BC_ECB			_SBF(4,	0x00)
#define	CRYPTO_BC_CBC			_SBF(4,	0x01)
#define	CRYPTO_BC_CTS			_SBF(4,	0x02)
#define	CRYPTO_BC_CTR			_SBF(4,	0x03)
#define	CRYPTO_BC_CFB			_SBF(4,	0x04)
#define	CRYPTO_BC_OFB			_SBF(4,	0x05)
#define	CRYPTO_BC_XTS			_SBF(4,	0x06)
#define	CRYPTO_BC_CCM			_SBF(4,	0x07)
#define	CRYPTO_BC_GCM			_SBF(4,	0x08)
#define	CRYPTO_BC_CMAC			_SBF(4,	0x09)
#define	CRYPTO_BC_CBC_MAC		_SBF(4,	0x0A)
#define	CRYPTO_BC_128_bit_key		_SBF(2,	0x00)
#define	CRYPTO_BC_192_bit_key		_SBF(2,	0x01)
#define	CRYPTO_BC_256_bit_key		_SBF(2,	0x02)
#define	CRYPTO_BC_DECRYPT		_BIT(1)
#define	CRYPTO_BC_ENABLE		_BIT(0)

/* Hash	Control	Register */
#define	CRYPTO_HASH_CTL			0x0048
#define	CRYPTO_MODE_SHA1		_SBF(4,	0x00)
#define	CRYPTO_MODE_MD5			_SBF(4,	0x01)
#define	CRYPTO_MODE_SHA256		_SBF(4,	0x02)
#define	CRYPTO_MODE_SHA224		_SBF(4,	0x03)
#define	CRYPTO_MODE_SHA512		_SBF(4,	0x08)
#define	CRYPTO_MODE_SHA384		_SBF(4,	0x09)
#define	CRYPTO_MODE_SHA512_224		_SBF(4,	0x0A)
#define	CRYPTO_MODE_SHA512_256		_SBF(4,	0x0B)
#define	CRYPTO_HMAC_ENABLE		_BIT(3)
#define	CRYPTO_HW_PAD_ENABLE		_BIT(2)
#define	CRYPTO_HASH_SRC_SEL		_BIT(1)
#define	CRYPTO_HASH_ENABLE		_BIT(0)

/* Cipher Status Register */
#define	CRYPTO_CIPHER_ST		0x004C
#define	CRYPTO_OTP_KEY_VALID		_BIT(2)
#define	CRYPTO_HASH_BUSY		_BIT(1)
#define	CRYPTO_BLOCK_CIPHER_BUSY	_BIT(0)

#define	CRYPTO_CIPHER_STATE		0x0050
#define	CRYPTO_HASH_IDLE_STATE		_SBF(10, 0x01)
#define	CRYPTO_HASH_IPAD_STATE		_SBF(10, 0x02)
#define	CRYPTO_HASH_TEXT_STATE		_SBF(10, 0x04)
#define	CRYPTO_HASH_OPAD_STATE		_SBF(10, 0x08)
#define	CRYPTO_HASH_OPAD_EXT_STATE	_SBF(10, 0x10)
#define	CRYPTO_GCM_IDLE_STATE		_SBF(8,	0x00)
#define	CRYPTO_GCM_PRE_STATE		_SBF(8,	0x01)
#define	CRYPTO_GCM_NA_STATE		_SBF(8,	0x02)
#define	CRYPTO_GCM_PC_STATE		_SBF(8,	0x03)
#define	CRYPTO_CCM_IDLE_STATE		_SBF(6,	0x00)
#define	CRYPTO_CCM_PRE_STATE		_SBF(6,	0x01)
#define	CRYPTO_CCM_NA_STATE		_SBF(6,	0x02)
#define	CRYPTO_CCM_PC_STATE		_SBF(6,	0x03)
#define	CRYPTO_PARALLEL_IDLE_STATE	_SBF(4,	0x00)
#define	CRYPTO_PARALLEL_PRE_STATE	_SBF(4,	0x01)
#define	CRYPTO_PARALLEL_BULK_STATE	_SBF(4,	0x02)
#define	CRYPTO_MAC_IDLE_STATE		_SBF(2,	0x00)
#define	CRYPTO_MAC_PRE_STATE		_SBF(2,	0x01)
#define	CRYPTO_MAC_BULK_STATE		_SBF(2,	0x02)
#define	CRYPTO_SERIAL_IDLE_STATE	_SBF(0,	0x00)
#define	CRYPTO_SERIAL_PRE_STATE		_SBF(0,	0x01)
#define	CRYPTO_SERIAL_BULK_STATE	_SBF(0,	0x02)

#define	CRYPTO_CH0_IV_0			0x0100
#define	CRYPTO_CH0_IV_1			0x0104
#define	CRYPTO_CH0_IV_2			0x0108
#define	CRYPTO_CH0_IV_3			0x010c
#define	CRYPTO_CH1_IV_0			0x0110
#define	CRYPTO_CH1_IV_1			0x0114
#define	CRYPTO_CH1_IV_2			0x0118
#define	CRYPTO_CH1_IV_3			0x011c
#define	CRYPTO_CH2_IV_0			0x0120
#define	CRYPTO_CH2_IV_1			0x0124
#define	CRYPTO_CH2_IV_2			0x0128
#define	CRYPTO_CH2_IV_3			0x012c
#define	CRYPTO_CH3_IV_0			0x0130
#define	CRYPTO_CH3_IV_1			0x0134
#define	CRYPTO_CH3_IV_2			0x0138
#define	CRYPTO_CH3_IV_3			0x013c
#define	CRYPTO_CH4_IV_0			0x0140
#define	CRYPTO_CH4_IV_1			0x0144
#define	CRYPTO_CH4_IV_2			0x0148
#define	CRYPTO_CH4_IV_3			0x014c
#define	CRYPTO_CH5_IV_0			0x0150
#define	CRYPTO_CH5_IV_1			0x0154
#define	CRYPTO_CH5_IV_2			0x0158
#define	CRYPTO_CH5_IV_3			0x015c
#define	CRYPTO_CH6_IV_0			0x0160
#define	CRYPTO_CH6_IV_1			0x0164
#define	CRYPTO_CH6_IV_2			0x0168
#define	CRYPTO_CH6_IV_3			0x016c
#define	CRYPTO_CH7_IV_0			0x0170
#define	CRYPTO_CH7_IV_1			0x0174
#define	CRYPTO_CH7_IV_2			0x0178
#define	CRYPTO_CH7_IV_3			0x017c

#define	CRYPTO_CH0_KEY_0		0x0180
#define	CRYPTO_CH0_KEY_1		0x0184
#define	CRYPTO_CH0_KEY_2		0x0188
#define	CRYPTO_CH0_KEY_3		0x018c
#define	CRYPTO_CH1_KEY_0		0x0190
#define	CRYPTO_CH1_KEY_1		0x0194
#define	CRYPTO_CH1_KEY_2		0x0198
#define	CRYPTO_CH1_KEY_3		0x019c
#define	CRYPTO_CH2_KEY_0		0x01a0
#define	CRYPTO_CH2_KEY_1		0x01a4
#define	CRYPTO_CH2_KEY_2		0x01a8
#define	CRYPTO_CH2_KEY_3		0x01ac
#define	CRYPTO_CH3_KEY_0		0x01b0
#define	CRYPTO_CH3_KEY_1		0x01b4
#define	CRYPTO_CH3_KEY_2		0x01b8
#define	CRYPTO_CH3_KEY_3		0x01bc
#define	CRYPTO_CH4_KEY_0		0x01c0
#define	CRYPTO_CH4_KEY_1		0x01c4
#define	CRYPTO_CH4_KEY_2		0x01c8
#define	CRYPTO_CH4_KEY_3		0x01cc
#define	CRYPTO_CH5_KEY_0		0x01d0
#define	CRYPTO_CH5_KEY_1		0x01d4
#define	CRYPTO_CH5_KEY_2		0x01d8
#define	CRYPTO_CH5_KEY_3		0x01dc
#define	CRYPTO_CH6_KEY_0		0x01e0
#define	CRYPTO_CH6_KEY_1		0x01e4
#define	CRYPTO_CH6_KEY_2		0x01e8
#define	CRYPTO_CH6_KEY_3		0x01ec
#define	CRYPTO_CH7_KEY_0		0x01f0
#define	CRYPTO_CH7_KEY_1		0x01f4
#define	CRYPTO_CH7_KEY_2		0x01f8
#define	CRYPTO_CH7_KEY_3		0x01fc
#define	CRYPTO_KEY_CHANNLE_NUM		8

#define	CRYPTO_CH0_PKEY_0		0x0200
#define	CRYPTO_CH0_PKEY_1		0x0204
#define	CRYPTO_CH0_PKEY_2		0x0208
#define	CRYPTO_CH0_PKEY_3		0x020c
#define	CRYPTO_CH1_PKEY_0		0x0210
#define	CRYPTO_CH1_PKEY_1		0x0214
#define	CRYPTO_CH1_PKEY_2		0x0218
#define	CRYPTO_CH1_PKEY_3		0x021c
#define	CRYPTO_CH2_PKEY_0		0x0220
#define	CRYPTO_CH2_PKEY_1		0x0224
#define	CRYPTO_CH2_PKEY_2		0x0228
#define	CRYPTO_CH2_PKEY_3		0x022c
#define	CRYPTO_CH3_PKEY_0		0x0230
#define	CRYPTO_CH3_PKEY_1		0x0234
#define	CRYPTO_CH3_PKEY_2		0x0238
#define	CRYPTO_CH3_PKEY_3		0x023c
#define	CRYPTO_CH4_PKEY_0		0x0240
#define	CRYPTO_CH4_PKEY_1		0x0244
#define	CRYPTO_CH4_PKEY_2		0x0248
#define	CRYPTO_CH4_PKEY_3		0x024c
#define	CRYPTO_CH5_PKEY_0		0x0250
#define	CRYPTO_CH5_PKEY_1		0x0254
#define	CRYPTO_CH5_PKEY_2		0x0258
#define	CRYPTO_CH5_PKEY_3		0x025c
#define	CRYPTO_CH6_PKEY_0		0x0260
#define	CRYPTO_CH6_PKEY_1		0x0264
#define	CRYPTO_CH6_PKEY_2		0x0268
#define	CRYPTO_CH6_PKEY_3		0x026c
#define	CRYPTO_CH7_PKEY_0		0x0270
#define	CRYPTO_CH7_PKEY_1		0x0274
#define	CRYPTO_CH7_PKEY_2		0x0278
#define	CRYPTO_CH7_PKEY_3		0x027c
#define	CRYPTO_PKEY_CHANNLE_NUM		8

#define	CRYPTO_CH0_PC_LEN_0		0x0280
#define	CRYPTO_CH0_PC_LEN_1		0x0284
#define	CRYPTO_CH1_PC_LEN_0		0x0288
#define	CRYPTO_CH1_PC_LEN_1		0x028c
#define	CRYPTO_CH2_PC_LEN_0		0x0290
#define	CRYPTO_CH2_PC_LEN_1		0x0294
#define	CRYPTO_CH3_PC_LEN_0		0x0298
#define	CRYPTO_CH3_PC_LEN_1		0x029c
#define	CRYPTO_CH4_PC_LEN_0		0x02a0
#define	CRYPTO_CH4_PC_LEN_1		0x02a4
#define	CRYPTO_CH5_PC_LEN_0		0x02a8
#define	CRYPTO_CH5_PC_LEN_1		0x02ac
#define	CRYPTO_CH6_PC_LEN_0		0x02b0
#define	CRYPTO_CH6_PC_LEN_1		0x02b4
#define	CRYPTO_CH7_PC_LEN_0		0x02b8
#define	CRYPTO_CH7_PC_LEN_1		0x02bc

#define	CRYPTO_CH0_AAD_LEN_0		0x02c0
#define	CRYPTO_CH0_AAD_LEN_1		0x02c4
#define	CRYPTO_CH1_AAD_LEN_0		0x02c8
#define	CRYPTO_CH1_AAD_LEN_1		0x02cc
#define	CRYPTO_CH2_AAD_LEN_0		0x02d0
#define	CRYPTO_CH2_AAD_LEN_1		0x02d4
#define	CRYPTO_CH3_AAD_LEN_0		0x02d8
#define	CRYPTO_CH3_AAD_LEN_1		0x02dc
#define	CRYPTO_CH4_AAD_LEN_0		0x02e0
#define	CRYPTO_CH4_AAD_LEN_1		0x02e4
#define	CRYPTO_CH5_AAD_LEN_0		0x02e8
#define	CRYPTO_CH5_AAD_LEN_1		0x02ec
#define	CRYPTO_CH6_AAD_LEN_0		0x02f0
#define	CRYPTO_CH6_AAD_LEN_1		0x02f4
#define	CRYPTO_CH7_AAD_LEN_0		0x02f8
#define	CRYPTO_CH7_AAD_LEN_1		0x02fc

#define	CRYPTO_CH0_IV_LEN_0		0x0300
#define	CRYPTO_CH1_IV_LEN_0		0x0304
#define	CRYPTO_CH2_IV_LEN_0		0x0308
#define	CRYPTO_CH3_IV_LEN_0		0x030c
#define	CRYPTO_CH4_IV_LEN_0		0x0310
#define	CRYPTO_CH5_IV_LEN_0		0x0314
#define	CRYPTO_CH6_IV_LEN_0		0x0318
#define	CRYPTO_CH7_IV_LEN_0		0x031c

#define	CRYPTO_CH0_TAG_0		0x0320
#define	CRYPTO_CH0_TAG_1		0x0324
#define	CRYPTO_CH0_TAG_2		0x0328
#define	CRYPTO_CH0_TAG_3		0x032c
#define	CRYPTO_CH1_TAG_0		0x0330
#define	CRYPTO_CH1_TAG_1		0x0334
#define	CRYPTO_CH1_TAG_2		0x0338
#define	CRYPTO_CH1_TAG_3		0x033c
#define	CRYPTO_CH2_TAG_0		0x0340
#define	CRYPTO_CH2_TAG_1		0x0344
#define	CRYPTO_CH2_TAG_2		0x0348
#define	CRYPTO_CH2_TAG_3		0x034c
#define	CRYPTO_CH3_TAG_0		0x0350
#define	CRYPTO_CH3_TAG_1		0x0354
#define	CRYPTO_CH3_TAG_2		0x0358
#define	CRYPTO_CH3_TAG_3		0x035c
#define	CRYPTO_CH4_TAG_0		0x0360
#define	CRYPTO_CH4_TAG_1		0x0364
#define	CRYPTO_CH4_TAG_2		0x0368
#define	CRYPTO_CH4_TAG_3		0x036c
#define	CRYPTO_CH5_TAG_0		0x0370
#define	CRYPTO_CH5_TAG_1		0x0374
#define	CRYPTO_CH5_TAG_2		0x0378
#define	CRYPTO_CH5_TAG_3		0x037c
#define	CRYPTO_CH6_TAG_0		0x0380
#define	CRYPTO_CH6_TAG_1		0x0384
#define	CRYPTO_CH6_TAG_2		0x0388
#define	CRYPTO_CH6_TAG_3		0x038c
#define	CRYPTO_CH7_TAG_0		0x0390
#define	CRYPTO_CH7_TAG_1		0x0394
#define	CRYPTO_CH7_TAG_2		0x0398
#define	CRYPTO_CH7_TAG_3		0x039c

#define	CRYPTO_HASH_DOUT_0		0x03a0
#define	CRYPTO_HASH_DOUT_1		0x03a4
#define	CRYPTO_HASH_DOUT_2		0x03a8
#define	CRYPTO_HASH_DOUT_3		0x03ac
#define	CRYPTO_HASH_DOUT_4		0x03b0
#define	CRYPTO_HASH_DOUT_5		0x03b4
#define	CRYPTO_HASH_DOUT_6		0x03b8
#define	CRYPTO_HASH_DOUT_7		0x03bc
#define	CRYPTO_HASH_DOUT_8		0x03c0
#define	CRYPTO_HASH_DOUT_9		0x03c4
#define	CRYPTO_HASH_DOUT_10		0x03c8
#define	CRYPTO_HASH_DOUT_11		0x03cc
#define	CRYPTO_HASH_DOUT_12		0x03d0
#define	CRYPTO_HASH_DOUT_13		0x03d4
#define	CRYPTO_HASH_DOUT_14		0x03d8
#define	CRYPTO_HASH_DOUT_15		0x03dc

#define	CRYPTO_TAG_VALID		0x03e0
#define	CRYPTO_CH7_TAG_VALID		_BIT(7)
#define	CRYPTO_CH6_TAG_VALID		_BIT(6)
#define	CRYPTO_CH5_TAG_VALID		_BIT(5)
#define	CRYPTO_CH4_TAG_VALID		_BIT(4)
#define	CRYPTO_CH3_TAG_VALID		_BIT(3)
#define	CRYPTO_CH2_TAG_VALID		_BIT(2)
#define	CRYPTO_CH1_TAG_VALID		_BIT(1)
#define	CRYPTO_CH0_TAG_VALID		_BIT(0)

#define	CRYPTO_HASH_VALID		0x03e4
#define	CRYPTO_HASH_IS_VALID		_BIT(0)

#define	CRYPTO_VERSION			0x03f0

#define	CRYPTO_RNG_CTL			0x0400
#define	CRYPTO_RNG_64_bit_len		_SBF(4,	0x00)
#define	CRYPTO_RNG_128_bit_len		_SBF(4,	0x01)
#define	CRYPTO_RNG_192_bit_len		_SBF(4,	0x02)
#define	CRYPTO_RNG_256_bit_len		_SBF(4,	0x03)
#define	CRYPTO_RNG_FATESY_SOC_RING	_SBF(2,	0x00)
#define	CRYPTO_RNG_SLOWER_SOC_RING_0	_SBF(2,	0x01)
#define	CRYPTO_RNG_SLOWER_SOC_RING_1	_SBF(2,	0x02)
#define	CRYPTO_RNG_SLOWEST_SOC_RING	_SBF(2,	0x03)
#define	CRYPTO_RNG_ENABLE		_BIT(1)
#define	CRYPTO_RNG_START		_BIT(0)

#define	CRYPTO_RNG_SAMPLE_CNT		0x0404
#define	CRYPTO_RNG_DOUT_0		0x0410
#define	CRYPTO_RNG_DOUT_1		0x0414
#define	CRYPTO_RNG_DOUT_2		0x0418
#define	CRYPTO_RNG_DOUT_3		0x041c
#define	CRYPTO_RNG_DOUT_4		0x0420
#define	CRYPTO_RNG_DOUT_5		0x0424
#define	CRYPTO_RNG_DOUT_6		0x0428
#define	CRYPTO_RNG_DOUT_7		0x042c

#define	CRYPTO_RAM_CTL			0x0480
#define	CRYPTO_RAM_PKA_RDY		_BIT(0)

#define	CRYPTO_RAM_ST			0x0484
#define	CRYPTO_CLK_RAM_RDY		_BIT(0)

#define	CRYPTO_DEBUG_CTL		0x04a0
#define	CRYPTO_DEBUG_MODE		_BIT(0)

#define	CRYPTO_DEBUG_ST			0x04a4
#define	CRYPTO_PKA_DEBUG_CLK_EN		_BIT(0)

#define	CRYPTO_DEBUG_MONITOR		0x04a8

#define	CRYPTO_MEMORY_MAP0		0x00800
#define	CRYPTO_MEMORY_MAP1		0x00804
#define	CRYPTO_MEMORY_MAP2		0x00808
#define	CRYPTO_MEMORY_MAP3		0x0080C
#define	CRYPTO_MEMORY_MAP4		0x00810
#define	CRYPTO_MEMORY_MAP5		0x00814
#define	CRYPTO_MEMORY_MAP6		0x00818
#define	CRYPTO_MEMORY_MAP7		0x0081C
#define	CRYPTO_MEMORY_MAP8		0x00820
#define	CRYPTO_MEMORY_MAP9		0x00824
#define	CRYPTO_MEMORY_MAP10		0x00828
#define	CRYPTO_MEMORY_MAP11		0x0082C
#define	CRYPTO_MEMORY_MAP12		0x00830
#define	CRYPTO_MEMORY_MAP13		0x00834
#define	CRYPTO_MEMORY_MAP14		0x00838
#define	CRYPTO_MEMORY_MAP15		0x0083C
#define	CRYPTO_MEMORY_MAP16		0x00840
#define	CRYPTO_MEMORY_MAP17		0x00844
#define	CRYPTO_MEMORY_MAP18		0x00848
#define	CRYPTO_MEMORY_MAP19		0x0084C
#define	CRYPTO_MEMORY_MAP20		0x00850
#define	CRYPTO_MEMORY_MAP21		0x00854
#define	CRYPTO_MEMORY_MAP22		0x00858
#define	CRYPTO_MEMORY_MAP23		0x0085C
#define	CRYPTO_MEMORY_MAP24		0x00860
#define	CRYPTO_MEMORY_MAP25		0x00864
#define	CRYPTO_MEMORY_MAP26		0x00868
#define	CRYPTO_MEMORY_MAP27		0x0086C
#define	CRYPTO_MEMORY_MAP28		0x00870
#define	CRYPTO_MEMORY_MAP29		0x00874
#define	CRYPTO_MEMORY_MAP30		0x00878
#define	CRYPTO_MEMORY_MAP31		0x0087C

#define	CRYPTO_OPCODE			0x00880
#define	CRYPTO_OPCODE_REG_TAG_SHIFT	0
#define	CRYPTO_OPCODE_TAG_MASK		0x0000003f
#define	CRYPTO_OPCODE_REG_R_SHIFT	6
#define	CRYPTO_OPCODE_REG_R_MASK	0x00000fc0
#define	CRYPTO_OPCODE_REG_B_SHIFT	12
#define	CRYPTO_OPCODE_REG_B_MASK	0x0003f000
#define	CRYPTO_OPCODE_REG_A_SHIFT	18
#define	CRYPTO_OPCODE_REG_A_MASK	0x00fc0000
#define	CRYPTO_OPCODE_LEN_SHIFT		24
#define	CRYPTO_OPCODE_LEN_MASK		0x03000000
#define	CRYPTO_OPCODE_CODE_SHIFT	27
#define	CRYPTO_OPCODE_CODE_MASK		0xfc000000

#define	CRYPTO_N_NP_T0_T1_ADDR		0x00884
#define	CRYPTO_N_VIRTUAL_ADDR_SHIFT	0
#define	CRYPTO_N_VIRTUAL_ADDR_MASK	0x0000001f
#define	CRYPTO_NP_VIRTUAL_ADDR_SHIFT	5
#define	CRYPTO_NP_VIRTUAL_ADDR_MASK	0x000003e0
#define	CRYPTO_T0_VIRTUAL_ADDR_SHIFT	10
#define	CRYPTO_T0_VIRTUAL_ADDR_MASK	0x00007c00
#define	CRYPTO_T1_VIRTUAL_ADDR_SHIFT	15
#define	CRYPTO_T1_VIRTUAL_ADDR_MASK	0x000f8000

#define	CRYPTO_PKA_STATUS		0x00888
#define	CRYPTO_PKA_PIPE_IS_RDY		_BIT(0)
#define	CRYPTO_PKA_BUSY				_BIT(1)
#define	CRYPTO_PKA_ALU_OUT_ZERO		_BIT(2)
#define	CRYPTO_PKA_ALU_MODOVRFLW	_BIT(3)
#define	CRYPTO_PKA_DIV_BY_ZERO		_BIT(4)
#define	CRYPTO_PKA_ALU_CARRY		_BIT(5)
#define	CRYPTO_PKA_ALU_SIGN_OUT		_BIT(6)
#define	CRYPTO_PKA_MODINV_OF_ZERO	_BIT(7)
#define	CRYPTO_PKA_CPU_BUSY		_BIT(8)
#define	CRYPTO_PKA_OPCODE_STATUS_SHIFT	9
#define	CRYPTO_PKA_OPCODE_STATUS_MASK	0x00003e00
#define	CRYPTO_PKA_TAG_STATUS_SHIFT	14
#define	CRYPTO_PKA_TAG_STATUS_MASK	0x0003c000

#define	CRYPTO_PKA_SW_RESET		0x0088C
#define	CRYPTO_PKA_L0			0x00890
#define	CRYPTO_PKA_L1			0x00894
#define	CRYPTO_PKA_L2			0x00898
#define	CRYPTO_PKA_L3			0x0089C
#define	CRYPTO_PKA_L4			0x008A0
#define	CRYPTO_PKA_L5			0x008A4
#define	CRYPTO_PKA_L6			0x008A8
#define	CRYPTO_PKA_L7			0x008AC
#define	CRYPTO_PKA_PIPE_RDY		0x008B0
#define	CRYPTO_PKA_DONE			0x008B4
#define	CRYPTO_PKA_MON_SELECT		0x008B8
#define	CRYPTO_PKA_DEBUG_REG_EN		0x008BC
#define	CRYPTO_DEBUG_CNT_ADDR		0x008C0
#define	CRYPTO_DEBUG_EXT_ADDR		0x008C4
#define	CRYPTO_PKA_DEBUG_HALT		0x008C8
#define	CRYPTO_PKA_MON_READ		0x008D0
#define	CRYPTO_PKA_INT_ENA		0x008D4
#define	CRYPTO_PKA_INT_ST		0x008D8
#define	CRYPTO_SRAM_ADDR		0x01000
#define	CRYPTO_SRAM_BASE		0x1000

#define	LLI_DMA_CTRL_LAST		_BIT(0)
#define	LLI_DMA_CTRL_PAUSE		_BIT(1)
#define	LLI_DMA_CTRL_LIST_DONE		_BIT(8)
#define	LLI_DMA_CTRL_DST_DONE		_BIT(9)
#define	LLI_DMA_CTRL_SRC_DONE		_BIT(10)

#define LLI_USER_CPIHER_START		_BIT(0)
#define LLI_USER_STRING_START		_BIT(1)
#define LLI_USER_STRING_LAST		_BIT(2)
#define LLI_USER_STRING_ADA		_BIT(3)
#define LLI_USER_PRIVACY_KEY		_BIT(7)
#define LLI_USER_ROOT_KEY		_BIT(8)

enum endian_mode {
	BIG_ENDIAN = 0,
	LITTLE_ENDIAN
};

enum clk_type {
	CLK = 0,
	HCLK
};

struct crypto_lli_desc {
	u32 src_addr;
	u32 src_len;
	u32 dst_addr;
	u32 dst_len;
	u32 user_define;
	u32 reserve;
	u32 dma_ctrl;
	u32 next_addr;
};

struct rk_hash_ctx {
	const	u8 *null_hash;	/* when hash is null or length is zero */
	void	*cur_data_lli;	/* to recored the lli that not computed	*/
	void	*free_data_lli;	/* free lli that can use for next lli */
	void	*vir_src_addr;	/* virt addr for hash src data*/
	u32	magic;		/* to check whether the ctx is correct */
	u32	algo;		/* hash algo */
	u32	digest_size;	/* hash out length according to hash algo*/
	u32	dma_started;	/* choose use start or restart */
};

#define	RK_HASH_CTX_MAGIC		0x1A1A1A1A

extern fdt_addr_t crypto_base;

static inline u32 crypto_read(u32 offset)
{
	return readl(crypto_base + offset);
}

static inline void crypto_write(u32 val, u32 offset)
{
	writel(val, crypto_base + offset);
}

#endif
