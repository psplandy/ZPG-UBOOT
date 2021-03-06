#
# (C) Copyright 2002
# Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
#
# SPDX-License-Identifier:	GPL-2.0+
#

# On supported platforms we set the bit which causes us to trap on unaligned
# memory access.  This is the opposite of what the compiler expects to be
# the default so we must pass in -mno-unaligned-access so that it is aware
# of our decision.
PF_NO_UNALIGNED := $(call cc-option, -mno-unaligned-access,)
PLATFORM_CPPFLAGS += $(PF_NO_UNALIGNED)

ifeq ($(CONFIG_SPL_BUILD)$(CONFIG_TPL_BUILD),)
PLATFORM_CPPFLAGS += -mabi=aapcs-linux -funwind-tables
endif
