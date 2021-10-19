/*
 * This header provides constants for binding nvidia,tegra210-car.
 *
 * The first 224 clocks are numbered to match the bits in the CAR's CLK_OUT_ENB
 * registers. These IDs often match those in the CAR's RST_DEVICES registers,
 * but not in all cases. Some bits in CLK_OUT_ENB affect multiple clocks. In
 * this case, those clocks are assigned IDs above 224 in order to highlight
 * this issue. Implementations that interpret these clock IDs as bit values
 * within the CLK_OUT_ENB or RST_DEVICES registers should be careful to
 * explicitly handle these special cases.
 *
 * The balance of the clocks controlled by the CAR are assigned IDs of 224 and
 * above.
 */

#ifndef _DT_BINDINGS_CLOCK_TEGRA210_CAR_H
#define _DT_BINDINGS_CLOCK_TEGRA210_CAR_H

/* 0 */
/* 1 */
/* 2 */
#define TEGRA210_CLK_ISPB 3
#define TEGRA210_CLK_RTC 4
#define TEGRA210_CLK_TIMER 5
#define TEGRA210_CLK_UARTA 6
/* 7 (register bit affects uartb and vfir) */
#define TEGRA210_CLK_GPIO 8
#define TEGRA210_CLK_SDMMC2 9
/* 10 (register bit affects spdif_in and spdif_out) */
#define TEGRA210_CLK_I2S1 11
#define TEGRA210_CLK_I2C1 12
/* 13 */
#define TEGRA210_CLK_SDMMC1 14
#define TEGRA210_CLK_SDMMC4 15
/* 16 */
#define TEGRA210_CLK_PWM 17
#define TEGRA210_CLK_I2S2 18
/* 19 */
/* 20 (register bit affects vi and vi_sensor) */
/* 21 */
#define TEGRA210_CLK_USBD 22
#define TEGRA210_CLK_ISP 23
/* 24 */
/* 25 */
#define TEGRA210_CLK_DISP2 26
#define TEGRA210_CLK_DISP1 27
#define TEGRA210_CLK_HOST1X 28
/* 29 */
#define TEGRA210_CLK_I2S0 30
/* 31 */

#define TEGRA210_CLK_MC 32
#define TEGRA210_CLK_AHBDMA 33
#define TEGRA210_CLK_APBDMA 34
/* 35 */
/* 36 */
/* 37 */
#define TEGRA210_CLK_PMC 38
/* 39 (register bit affects fuse and fuse_burn) */
#define TEGRA210_CLK_KFUSE 40
#define TEGRA210_CLK_SBC1 41
/* 42 */
/* 43 */
#define TEGRA210_CLK_SBC2 44
/* 45 */
#define TEGRA210_CLK_SBC3 46
#define TEGRA210_CLK_I2C5 47
#define TEGRA210_CLK_DSIA 48
/* 49 */
/* 50 */
/* 51 */
#define TEGRA210_CLK_CSI 52
/* 53 */
#define TEGRA210_CLK_I2C2 54
#define TEGRA210_CLK_UARTC 55
#define TEGRA210_CLK_MIPI_CAL 56
#define TEGRA210_CLK_EMC 57
#define TEGRA210_CLK_USB2 58
/* 59 */
/* 60 */
/* 61 */
/* 62 */
#define TEGRA210_CLK_BSEV 63

/* 64 */
#define TEGRA210_CLK_UARTD 65
/* 66 */
#define TEGRA210_CLK_I2C3 67
#define TEGRA210_CLK_SBC4 68
#define TEGRA210_CLK_SDMMC3 69
#define TEGRA210_CLK_PCIE 70
#define TEGRA210_CLK_OWR 71
#define TEGRA210_CLK_AFI 72
#define TEGRA210_CLK_CSITE 73
/* 74 */
/* 75 */
/* 76 */
/* 77 */
#define TEGRA210_CLK_SOC_THERM 78
#define TEGRA210_CLK_DTV 79
/* 80 */
#define TEGRA210_CLK_I2CSLOW 81
#define TEGRA210_CLK_DSIB 82
#define TEGRA210_CLK_TSEC 83
/* 84 */
/* 85 */
/* 86 */
/* 87 */
/* 88 */
#define TEGRA210_CLK_XUSB_HOST 89
/* 90 */
/* 91 */
#define TEGRA210_CLK_CSUS 92
/* 93 */
/* 94 */
/* 95 (bit affects xusb_dev and xusb_dev_src) */

/* 96 */
/* 97 */
/* 98 */
#define TEGRA210_CLK_MSELECT 99
#define TEGRA210_CLK_TSENSOR 100
#define TEGRA210_CLK_I2S3 101
#define TEGRA210_CLK_I2S4 102
#define TEGRA210_CLK_I2C4 103
/* 104 */
/* 105 */
#define TEGRA210_CLK_D_AUDIO 106
#define TEGRA210_CLK_APB2APE 107
/* 108 */
/* 109 */
/* 110 */
#define TEGRA210_CLK_HDA2CODEC_2X 111
/* 112 */
/* 113 */
/* 114 */
/* 115 */
/* 116 */
/* 117 */
#define TEGRA210_CLK_SPDIF_2X 118
#define TEGRA210_CLK_ACTMON 119
#define TEGRA210_CLK_EXTERN1 120
#define TEGRA210_CLK_EXTERN2 121
#define TEGRA210_CLK_EXTERN3 122
#define TEGRA210_CLK_SATA_OOB 123
#define TEGRA210_CLK_SATA 124
#define TEGRA210_CLK_HDA 125
/* 126 */
/* 127 */

#define TEGRA210_CLK_HDA2HDMI 128
/* 129 */
/* 130 */
/* 131 */
/* 132 */
/* 133 */
/* 134 */
/* 135 */
/* 136 */
/* 137 */
/* 138 */
/* 139 */
/* 140 */
/* 141 */
/* 142 */
/* (bit affects xusb_falcon_src, xusb_fs_src, xusb_host_src and xusb_ss_src) */
#define TEGRA210_CLK_XUSB_GATE 143
#define TEGRA210_CLK_CILAB 144
#define TEGRA210_CLK_CILCD 145
#define TEGRA210_CLK_CILE 146
#define TEGRA210_CLK_DSIALP 147
#define TEGRA210_CLK_DSIBLP 148
#define TEGRA210_CLK_ENTROPY 149
/* 150 */
/* 151 */
/* 152 */
/* 153 */
/* 154 */
/* 155 (bit affects dfll_ref and dfll_soc) */
#define TEGRA210_CLK_XUSB_SS 156
/* 157 */
/* 158 */
/* 159 */

/* 160 */
#define TEGRA210_CLK_DMIC1 161
#define TEGRA210_CLK_DMIC2 162
/* 163 */
/* 164 */
/* 165 */
#define TEGRA210_CLK_I2C6 166
/* 167 */
/* 168 */
/* 169 */
/* 170 */
#define TEGRA210_CLK_VIM2_CLK 171
/* 172 */
#define TEGRA210_CLK_MIPIBIF 173
/* 174 */
/* 175 */
/* 176 */
#define TEGRA210_CLK_CLK72MHZ 177
#define TEGRA210_CLK_VIC03 178
/* 179 */
/* 180 */
#define TEGRA210_CLK_DPAUX 181
#define TEGRA210_CLK_SOR0 182
#define TEGRA210_CLK_SOR1 183
#define TEGRA210_CLK_GPU 184
#define TEGRA210_CLK_DBGAPB 185
/* 186 */
#define TEGRA210_CLK_PLL_P_OUT_ADSP 187
/* 188 */
#define TEGRA210_CLK_PLL_G_REF 189
/* 190 */
/* 191 */

/* 192 */
#define TEGRA210_CLK_SDMMC_LEGACY 193
#define TEGRA210_CLK_NVDEC 194
#define TEGRA210_CLK_NVJPG 195
/* 196 */
#define TEGRA210_CLK_DMIC3 197
#define TEGRA210_CLK_APE 198
/* 199 */
/* 200 */
/* 201 */
#define TEGRA210_CLK_MAUD 202
/* 203 */
/* 204 */
/* 205 */
#define TEGRA210_CLK_TSECB 206
#define TEGRA210_CLK_DPAUX1 207
#define TEGRA210_CLK_VI_I2C 208
#define TEGRA210_CLK_HSIC_TRK 209
#define TEGRA210_CLK_USB2_TRK 210
#define TEGRA210_CLK_QSPI 211
#define TEGRA210_CLK_UARTAPE 212
/* 213 */
/* 214 */
/* 215 */
/* 216 */
/* 217 */
/* 218 */
#define TEGRA210_CLK_NVENC 219
/* 220 */
/* 221 */
#define TEGRA210_CLK_SOR_SAFE 222
#define TEGRA210_CLK_PLL_P_OUT_CPU 223


#define TEGRA210_CLK_UARTB 224
#define TEGRA210_CLK_VFIR 225
#define TEGRA210_CLK_SPDIF_IN 226
#define TEGRA210_CLK_SPDIF_OUT 227
#define TEGRA210_CLK_VI 228
#define TEGRA210_CLK_VI_SENSOR 229
#define TEGRA210_CLK_FUSE 230
#define TEGRA210_CLK_FUSE_BURN 231
#define TEGRA210_CLK_CLK_32K 232
#define TEGRA210_CLK_CLK_M 233
#define TEGRA210_CLK_CLK_M_DIV2 234
#define TEGRA210_CLK_CLK_M_DIV4 235
#define TEGRA210_CLK_PLL_REF 236
#define TEGRA210_CLK_PLL_C 237
#define TEGRA210_CLK_PLL_C_OUT1 238
#define TEGRA210_CLK_PLL_C2 239
#define TEGRA210_CLK_PLL_C3 240
#define TEGRA210_CLK_PLL_M 241
#define TEGRA210_CLK_PLL_M_OUT1 242
#define TEGRA210_CLK_PLL_P 243
#define TEGRA210_CLK_PLL_P_OUT1 244
#define TEGRA210_CLK_PLL_P_OUT2 245
#define TEGRA210_CLK_PLL_P_OUT3 246
#define TEGRA210_CLK_PLL_P_OUT4 247
#define TEGRA210_CLK_PLL_A 248
#define TEGRA210_CLK_PLL_A_OUT0 249
#define TEGRA210_CLK_PLL_D 250
#define TEGRA210_CLK_PLL_D_OUT0 251
#define TEGRA210_CLK_PLL_D2 252
#define TEGRA210_CLK_PLL_D2_OUT0 253
#define TEGRA210_CLK_PLL_U 254
#define TEGRA210_CLK_PLL_U_480M 255

#define TEGRA210_CLK_PLL_U_60M 256
#define TEGRA210_CLK_PLL_U_48M 257
/* 258 */
#define TEGRA210_CLK_PLL_X 259
#define TEGRA210_CLK_PLL_X_OUT0 260
#define TEGRA210_CLK_PLL_RE_VCO 261
#define TEGRA210_CLK_PLL_RE_OUT 262
#define TEGRA210_CLK_PLL_E 263
#define TEGRA210_CLK_SPDIF_IN_SYNC 264
#define TEGRA210_CLK_I2S0_SYNC 265
#define TEGRA210_CLK_I2S1_SYNC 266
#define TEGRA210_CLK_I2S2_SYNC 267
#define TEGRA210_CLK_I2S3_SYNC 268
#define TEGRA210_CLK_I2S4_SYNC 269
#define TEGRA210_CLK_VIMCLK_SYNC 270
#define TEGRA210_CLK_AUDIO0 271
#define TEGRA210_CLK_AUDIO1 272
#define TEGRA210_CLK_AUDIO2 273
#define TEGRA210_CLK_AUDIO3 274
#define TEGRA210_CLK_AUDIO4 275
#define TEGRA210_CLK_SPDIF 276
#define TEGRA210_CLK_CLK_OUT_1 277
#define TEGRA210_CLK_CLK_OUT_2 278
#define TEGRA210_CLK_CLK_OUT_3 279
#define TEGRA210_CLK_BLINK 280
/* 281 */
/* 282 */
/* 283 */
#define TEGRA210_CLK_XUSB_HOST_SRC 284
#define TEGRA210_CLK_XUSB_FALCON_SRC 285
#define TEGRA210_CLK_XUSB_FS_SRC 286
#define TEGRA210_CLK_XUSB_SS_SRC 287

#define TEGRA210_CLK_XUSB_DEV_SRC 288
#define TEGRA210_CLK_XUSB_DEV 289
#define TEGRA210_CLK_XUSB_HS_SRC 290
#define TEGRA210_CLK_SCLK 291
#define TEGRA210_CLK_HCLK 292
#define TEGRA210_CLK_PCLK 293
#define TEGRA210_CLK_CCLK_G 294
#define TEGRA210_CLK_CCLK_LP 295
#define TEGRA210_CLK_DFLL_REF 296
#define TEGRA210_CLK_DFLL_SOC 297
#define TEGRA210_CLK_VI_SENSOR2 298
#define TEGRA210_CLK_PLL_P_OUT5 299
#define TEGRA210_CLK_CML0 300
#define TEGRA210_CLK_CML1 301
#define TEGRA210_CLK_PLL_C4 302
#define TEGRA210_CLK_PLL_DP 303
#define TEGRA210_CLK_PLL_E_MUX 304
#define TEGRA210_CLK_PLL_MB 305
#define TEGRA210_CLK_PLL_A1 306
#define TEGRA210_CLK_PLL_D_DSI_OUT 307
#define TEGRA210_CLK_PLL_C4_OUT0 308
#define TEGRA210_CLK_PLL_C4_OUT1 309
#define TEGRA210_CLK_PLL_C4_OUT2 310
#define TEGRA210_CLK_PLL_C4_OUT3 311
#define TEGRA210_CLK_PLL_U_OUT 312
#define TEGRA210_CLK_PLL_U_OUT1 313
#define TEGRA210_CLK_PLL_U_OUT2 314
#define TEGRA210_CLK_USB2_HSIC_TRK 315
#define TEGRA210_CLK_PLL_P_OUT_HSIO 316
#define TEGRA210_CLK_PLL_P_OUT_XUSB 317
#define TEGRA210_CLK_XUSB_SSP_SRC 318
#define TEGRA210_CLK_PLL_RE_OUT1 319
/* 320 */
/* 321 */
/* 322 */
/* 323 */
/* 324 */
/* 325 */
/* 326 */
/* 327 */
/* 328 */
/* 329 */
/* 330 */
/* 331 */
/* 332 */
/* 333 */
/* 334 */
/* 335 */
/* 336 */
/* 337 */
/* 338 */
/* 339 */
/* 340 */
/* 341 */
/* 342 */
/* 343 */
/* 344 */
/* 345 */
/* 346 */
/* 347 */
/* 348 */
/* 349 */

#define TEGRA210_CLK_AUDIO0_MUX 350
#define TEGRA210_CLK_AUDIO1_MUX 351
#define TEGRA210_CLK_AUDIO2_MUX 352
#define TEGRA210_CLK_AUDIO3_MUX 353
#define TEGRA210_CLK_AUDIO4_MUX 354
#define TEGRA210_CLK_SPDIF_MUX 355
#define TEGRA210_CLK_CLK_OUT_1_MUX 356
#define TEGRA210_CLK_CLK_OUT_2_MUX 357
#define TEGRA210_CLK_CLK_OUT_3_MUX 358
#define TEGRA210_CLK_DSIA_MUX 359
#define TEGRA210_CLK_DSIB_MUX 360
#define TEGRA210_CLK_SOR0_LVDS 361
#define TEGRA210_CLK_XUSB_SS_DIV2 362

#define TEGRA210_CLK_PLL_M_UD 363
#define TEGRA210_CLK_PLL_C_UD 364
#define TEGRA210_CLK_SCLK_MUX 365

#define TEGRA210_CLK_CLK_MAX 366

#endif	/* _DT_BINDINGS_CLOCK_TEGRA210_CAR_H */
