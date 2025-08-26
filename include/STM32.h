#ifndef __STM32_H__
#define __STM32_H__

#include "types.h"

#define PERIPH_BASE       (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x00020000UL)
#define GPIOA_OFFSET      (0x0000UL)
#define RCC_OFFSET        (0x3800UL)

#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_BASE      (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define RCC_BASE        (AHB1PERIPH_BASE + RCC_OFFSET)

#define RCC   ((struct RCC *)(RCC_BASE))
#define GPIOA ((struct GPIO *)(GPIOA_BASE))

#define delay(t)                                                               \
    do {                                                                       \
        for (int i = 0; i < t; i++) {                                          \
        }                                                                      \
    } while (0)

#endif /* __STM32_H__ */