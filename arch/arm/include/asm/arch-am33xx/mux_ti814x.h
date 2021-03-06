/*
 * mux_ti814x.h
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _MUX_TI814X_H_
#define _MUX_TI814X_H_

/* PAD Control Fields */
#define PINCNTL_RSV_MSK	(0x3 << 18) /* Reserved bitmask */
#define PULLUP_EN	(0x1 << 17) /* Pull UP Selection */
#define PULLUDEN	(0x0 << 16) /* Pull up enabled */
#define PULLUDDIS	(0x1 << 16) /* Pull up disabled */
#define MODE(val)	val	/* used for Readability */

#define MUX_CFG(value, offset)				\
{							\
	int tmp;					\
	tmp = __raw_readl(CTRL_BASE + offset);		\
	tmp &= PINCNTL_RSV_MSK;				\
	__raw_writel(tmp | value, (CTRL_BASE + offset));\
}

/*
 * PAD CONTROL OFFSETS
 * Field names corresponds to the pad signal name
 */
struct pad_signals {
	int pincntl1;
	int pincntl2;
	int pincntl3;
	int pincntl4;
	int pincntl5;
	int pincntl6;
	int pincntl7;
	int pincntl8;
	int pincntl9;
	int pincntl10;
	int pincntl11;
	int pincntl12;
	int pincntl13;
	int pincntl14;
	int pincntl15;
	int pincntl16;
	int pincntl17;
	int pincntl18;
	int pincntl19;
	int pincntl20;
	int pincntl21;
	int pincntl22;
	int pincntl23;
	int pincntl24;
	int pincntl25;
	int pincntl26;
	int pincntl27;
	int pincntl28;
	int pincntl29;
	int pincntl30;
	int pincntl31;
	int pincntl32;
	int pincntl33;
	int pincntl34;
	int pincntl35;
	int pincntl36;
	int pincntl37;
	int pincntl38;
	int pincntl39;
	int pincntl40;
	int pincntl41;
	int pincntl42;
	int pincntl43;
	int pincntl44;
	int pincntl45;
	int pincntl46;
	int pincntl47;
	int pincntl48;
	int pincntl49;
	int pincntl50;
	int pincntl51;
	int pincntl52;
	int pincntl53;
	int pincntl54;
	int pincntl55;
	int pincntl56;
	int pincntl57;
	int pincntl58;
	int pincntl59;
	int pincntl60;
	int pincntl61;
	int pincntl62;
	int pincntl63;
	int pincntl64;
	int pincntl65;
	int pincntl66;
	int pincntl67;
	int pincntl68;
	int pincntl69;
	int pincntl70;
	int pincntl71;
	int pincntl72;
	int pincntl73;
	int pincntl74;
	int pincntl75;
	int pincntl76;
	int pincntl77;
	int pincntl78;
	int pincntl79;
	int pincntl80;
	int pincntl81;
	int pincntl82;
	int pincntl83;
	int pincntl84;
	int pincntl85;
	int pincntl86;
	int pincntl87;
	int pincntl88;
	int pincntl89;
	int pincntl90;
	int pincntl91;
	int pincntl92;
	int pincntl93;
	int pincntl94;
	int pincntl95;
	int pincntl96;
	int pincntl97;
	int pincntl98;
	int pincntl99;
	int pincntl100;
	int pincntl101;
	int pincntl102;
	int pincntl103;
	int pincntl104;
	int pincntl105;
	int pincntl106;
	int pincntl107;
	int pincntl108;
	int pincntl109;
	int pincntl110;
	int pincntl111;
	int pincntl112;
	int pincntl113;
	int pincntl114;
	int pincntl115;
	int pincntl116;
	int pincntl117;
	int pincntl118;
	int pincntl119;
	int pincntl120;
	int pincntl121;
	int pincntl122;
	int pincntl123;
	int pincntl124;
	int pincntl125;
	int pincntl126;
	int pincntl127;
	int pincntl128;
	int pincntl129;
	int pincntl130;
	int pincntl131;
	int pincntl132;
	int pincntl133;
	int pincntl134;
	int pincntl135;
	int pincntl136;
	int pincntl137;
	int pincntl138;
	int pincntl139;
	int pincntl140;
	int pincntl141;
	int pincntl142;
	int pincntl143;
	int pincntl144;
	int pincntl145;
	int pincntl146;
	int pincntl147;
	int pincntl148;
	int pincntl149;
	int pincntl150;
	int pincntl151;
	int pincntl152;
	int pincntl153;
	int pincntl154;
	int pincntl155;
	int pincntl156;
	int pincntl157;
	int pincntl158;
	int pincntl159;
	int pincntl160;
	int pincntl161;
	int pincntl162;
	int pincntl163;
	int pincntl164;
	int pincntl165;
	int pincntl166;
	int pincntl167;
	int pincntl168;
	int pincntl169;
	int pincntl170;
	int pincntl171;
	int pincntl172;
	int pincntl173;
	int pincntl174;
	int pincntl175;
	int pincntl176;
	int pincntl177;
	int pincntl178;
	int pincntl179;
	int pincntl180;
	int pincntl181;
	int pincntl182;
	int pincntl183;
	int pincntl184;
	int pincntl185;
	int pincntl186;
	int pincntl187;
	int pincntl188;
	int pincntl189;
	int pincntl190;
	int pincntl191;
	int pincntl192;
	int pincntl193;
	int pincntl194;
	int pincntl195;
	int pincntl196;
	int pincntl197;
	int pincntl198;
	int pincntl199;
	int pincntl200;
	int pincntl201;
	int pincntl202;
	int pincntl203;
	int pincntl204;
	int pincntl205;
	int pincntl206;
	int pincntl207;
	int pincntl208;
	int pincntl209;
	int pincntl210;
	int pincntl211;
	int pincntl212;
	int pincntl213;
	int pincntl214;
	int pincntl215;
	int pincntl216;
	int pincntl217;
	int pincntl218;
	int pincntl219;
	int pincntl220;
	int pincntl221;
	int pincntl222;
	int pincntl223;
	int pincntl224;
	int pincntl225;
	int pincntl226;
	int pincntl227;
	int pincntl228;
	int pincntl229;
	int pincntl230;
	int pincntl231;
	int pincntl232;
	int pincntl233;
	int pincntl234;
	int pincntl235;
	int pincntl236;
	int pincntl237;
	int pincntl238;
	int pincntl239;
	int pincntl240;
	int pincntl241;
	int pincntl242;
	int pincntl243;
	int pincntl244;
	int pincntl245;
	int pincntl246;
	int pincntl247;
	int pincntl248;
	int pincntl249;
	int pincntl250;
	int pincntl251;
	int pincntl252;
	int pincntl253;
	int pincntl254;
	int pincntl255;
	int pincntl256;
	int pincntl257;
	int pincntl258;
	int pincntl259;
	int pincntl260;
	int pincntl261;
	int pincntl262;
	int pincntl263;
	int pincntl264;
	int pincntl265;
	int pincntl266;
	int pincntl267;
	int pincntl268;
	int pincntl269;
	int pincntl270;
};

#endif /* endif _MUX_TI814X_H_ */
