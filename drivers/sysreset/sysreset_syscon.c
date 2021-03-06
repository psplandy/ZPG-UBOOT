/*
 * Copyright (C) 2017 Álvaro Fernández Rojas <noltari@gmail.com>
 *
 * Derived from linux/drivers/power/reset/syscon-reboot.c:
 *	Copyright (C) 2013, Applied Micro Circuits Corporation
 *	Author: Feng Kan <fkan@apm.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <regmap.h>
#include <sysreset.h>
#include <syscon.h>

DECLARE_GLOBAL_DATA_PTR;

struct syscon_reboot_priv {
	struct regmap *regmap;
	unsigned int offset;
	unsigned int mask;
};

static int syscon_reboot_request(struct udevice *dev, enum sysreset_t type)
{
	struct syscon_reboot_priv *priv = dev_get_priv(dev);

	regmap_write(priv->regmap, priv->offset, priv->mask);

	return -EINPROGRESS;
}

static struct sysreset_ops syscon_reboot_ops = {
	.request = syscon_reboot_request,
};

int syscon_reboot_probe(struct udevice *dev)
{
	struct udevice *syscon;
	struct syscon_reboot_priv *priv = dev_get_priv(dev);
	int err;

	err = uclass_get_device_by_phandle(UCLASS_SYSCON, dev,
					   "regmap", &syscon);
	if (err) {
		pr_err("unable to find syscon device\n");
		return err;
	}

	priv->regmap = syscon_get_regmap(syscon);
	if (!priv->regmap) {
		pr_err("unable to find regmap\n");
		return -ENODEV;
	}

	priv->offset = fdtdec_get_uint(gd->fdt_blob, dev_of_offset(dev),
				       "offset", 0);
	priv->mask = fdtdec_get_uint(gd->fdt_blob, dev_of_offset(dev),
				       "mask", 0);

	return 0;
}

static const struct udevice_id syscon_reboot_ids[] = {
	{ .compatible = "syscon-reboot" },
	{ /* sentinel */ }
};

U_BOOT_DRIVER(syscon_reboot) = {
	.name = "syscon_reboot",
	.id = UCLASS_SYSRESET,
	.of_match = syscon_reboot_ids,
	.probe = syscon_reboot_probe,
	.priv_auto_alloc_size = sizeof(struct syscon_reboot_priv),
	.ops = &syscon_reboot_ops,
};
