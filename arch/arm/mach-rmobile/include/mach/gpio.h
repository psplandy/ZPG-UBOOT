#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H

#if defined(CONFIG_SH73A0)
#include "sh73a0-gpio.h"
void sh73a0_pinmux_init(void);
#elif defined(CONFIG_R8A7740)
#include "r8a7740-gpio.h"
void r8a7740_pinmux_init(void);
#elif defined(CONFIG_R8A7790)
#include "r8a7790-gpio.h"
void r8a7790_pinmux_init(void);
#elif defined(CONFIG_R8A7791)
#include "r8a7791-gpio.h"
void r8a7791_pinmux_init(void);
#elif defined(CONFIG_R8A7792)
#include "r8a7792-gpio.h"
void r8a7792_pinmux_init(void);
#elif defined(CONFIG_R8A7793)
#include "r8a7793-gpio.h"
void r8a7793_pinmux_init(void);
#elif defined(CONFIG_R8A7794)
#include "r8a7794-gpio.h"
void r8a7794_pinmux_init(void);
#elif defined(CONFIG_R8A7795)
#include "r8a7795-gpio.h"
void r8a7795_pinmux_init(void);
#elif defined(CONFIG_R8A7796)
#include "r8a7796-gpio.h"
void r8a7796_pinmux_init(void);
#endif

#endif /* __ASM_ARCH_GPIO_H */
