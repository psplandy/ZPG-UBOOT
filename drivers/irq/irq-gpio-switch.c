/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <dm.h>
#include "irq-internal.h"

DECLARE_GLOBAL_DATA_PTR;

static struct gpio_bank gpio_banks[GPIO_BANK_NUM] = {
#if GPIO_BANK_NUM >= 1
	GPIO_BANK_REGISTER(0, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 2
	GPIO_BANK_REGISTER(1, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 3
	GPIO_BANK_REGISTER(2, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 4
	GPIO_BANK_REGISTER(3, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 5
	GPIO_BANK_REGISTER(4, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 6
	GPIO_BANK_REGISTER(5, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 7
	GPIO_BANK_REGISTER(6, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 8
	GPIO_BANK_REGISTER(7, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 9
	GPIO_BANK_REGISTER(8, GPIO_BANK_PINS),
#endif
#if GPIO_BANK_NUM >= 10
	GPIO_BANK_REGISTER(9, GPIO_BANK_PINS),
#endif
};

static int gpio_is_valid(u32 gpio)
{
	if ((gpio == EINVAL_GPIO) ||
	    !GPIO_BANK_VALID(gpio) ||
	    !GPIO_PIN_VALID(gpio)) {
		IRQ_E("gpio-%d(bank-%d, pin-%d) is invalid!\n",
		      gpio, GPIO_BANK(gpio), GPIO_PIN(gpio));
		return 0;
	}

	return 1;
}

static int __hard_gpio_to_irq(u32 gpio)
{
	int idx, bank = 0, pin = 0;
	int irq;

	if (!gpio_is_valid(gpio))
		return -EINVAL;

	bank = (gpio & GPIO_BANK_MASK) >> GPIO_BANK_OFFSET;
	pin = (gpio & GPIO_PIN_MASK) >> GPIO_PIN_OFFSET;

	for (idx = 0; idx < ARRAY_SIZE(gpio_banks); idx++) {
		if (gpio_banks[idx].id == bank) {
			irq = (gpio_banks[idx].irq_base + pin);
			if (irq_is_busy(irq))
				return -EBUSY;
			return irq;
		}
	}

	return -EINVAL;
}

static int __phandle_gpio_to_irq(u32 gpio_phandle, u32 offset)
{
	int irq_gpio, bank, ret = EINVAL_GPIO;
	const char *name;
	char *name_tok;
	bool found;
	int node;

	node = fdt_node_offset_by_phandle(gd->fdt_blob, gpio_phandle);
	if (node < 0) {
		IRQ_E("Can't find node by gpio_phandle=%d, ret=%d\n",
		      gpio_phandle, node);
		return EINVAL_GPIO;
	}

	name = fdt_get_name(gd->fdt_blob, node, NULL);
	if (!name) {
		IRQ_E("Can't find gpio bank for phandle=%d\n", gpio_phandle);
		return EINVAL_GPIO;
	}

	name_tok = strdup(name);
	if (!name_tok) {
		IRQ_E("Strdup '%s' failed!\n", name);
		return -ENOMEM;
	}

	name = strtok(name_tok, "@");
	if (!name) {
		IRQ_E("Can't strtok '@' for '%s'\n", name_tok);
		goto out;
	}

	for (bank = 0; bank < ARRAY_SIZE(gpio_banks); bank++) {
		if (!strcmp(gpio_banks[bank].name, name)) {
			found = true;
			break;
		}
	}

	if (!found) {
		IRQ_E("GPIO irq framework can't find '%s'\n", name);
		goto out;
	}

	IRQ_D("%s: gpio%d-%d\n", __func__, bank, offset);
	irq_gpio = RK_IRQ_GPIO(bank, offset);
	if (!gpio_is_valid(irq_gpio))
		goto out;

	free(name_tok);
	return __hard_gpio_to_irq(irq_gpio);

out:
	free(name_tok);
	return ret;
}

static int __irq_to_gpio(int irq)
{
	int bank, pin, idx;

	bank = (irq - PIN_BASE) / GPIO_BANK_PINS;
	pin = (irq - PIN_BASE) % GPIO_BANK_PINS;

	for (idx = 0; idx < ARRAY_SIZE(gpio_banks); idx++) {
		if (gpio_banks[idx].id == bank) {
			return (bank << GPIO_BANK_OFFSET) |
				(pin << GPIO_PIN_OFFSET);
		}
	}

	return -EINVAL;
}

int gpio_to_irq(struct gpio_desc *gpio)
{
	int irq_gpio, bank, ret = EINVAL_GPIO;
	char *name, *name_tok;
	bool found;

	if (!gpio->dev->name) {
		IRQ_E("Can't find dev name for gpio bank\n");
		return EINVAL_GPIO;
	}

	name_tok = strdup(gpio->dev->name);
	if (!name_tok) {
		IRQ_E("Strdup '%s' failed!\n", gpio->dev->name);
		return -ENOMEM;
	}

	name = strtok(name_tok, "@");
	if (!name) {
		IRQ_E("Can't strtok '@' for '%s'\n", name_tok);
		goto out;
	}

	for (bank = 0; bank < ARRAY_SIZE(gpio_banks); bank++) {
		if (!strcmp(gpio_banks[bank].name, name)) {
			found = true;
			break;
		}
	}

	if (!found) {
		IRQ_E("GPIO irq framework can't find '%s'\n", name);
		goto out;
	}

	irq_gpio = RK_IRQ_GPIO(bank, gpio->offset);
	if (!gpio_is_valid(irq_gpio))
		goto out;

	free(name_tok);
	return __hard_gpio_to_irq(irq_gpio);

out:
	free(name_tok);
	return ret;
}

int hard_gpio_to_irq(u32 gpio)
{
	if (!gpio_is_valid(gpio))
		return EINVAL_GPIO;

	return __hard_gpio_to_irq(gpio);
}

int phandle_gpio_to_irq(u32 gpio_phandle, u32 pin)
{
	if (gpio_phandle < 0)
		return EINVAL_GPIO;

	return __phandle_gpio_to_irq(gpio_phandle, pin);
}

int irq_to_gpio(int irq)
{
	return __irq_to_gpio(irq);
}

struct gpio_bank *gpio_id_to_bank(u32 id)
{
	int idx;

	for (idx = 0; idx < ARRAY_SIZE(gpio_banks); idx++) {
		if (gpio_banks[idx].id == id)
			return &gpio_banks[idx];
	}

	return NULL;
}

struct gpio_bank *gpio_to_bank(u32 gpio)
{
	int id;

	if (!gpio_is_valid(gpio))
		return NULL;

	id = (gpio & GPIO_BANK_MASK) >> GPIO_BANK_OFFSET;

	return gpio_id_to_bank(id);
}
