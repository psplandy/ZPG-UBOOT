/*
 * Copyright (c) 2014 Google, Inc
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <i2c.h>

UCLASS_DRIVER(i2c_emul) = {
	.id		= UCLASS_I2C_EMUL,
	.name		= "i2c_emul",
};
