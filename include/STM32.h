#ifndef __STM32_H__
#define __STM32_H__

#include "types.h"
#include "gpio.h"

#define PERIPH_BASE       (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x00020000UL)
#define GPIOA_OFFSET      (0x0000UL)
#define GPIOB_OFFSET      (0x0400UL)
#define GPIOC_OFFSET      (0x0800UL)
#define RCC_OFFSET        (0x3800UL)

#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIO_BASE       (AHB1PERIPH_BASE)
#define RCC_BASE        (AHB1PERIPH_BASE + RCC_OFFSET)

#define RCC   ((struct RCC *)(RCC_BASE))
#define GPIO_A ((struct GPIO *)(GPIO_BASE + GPIOA_OFFSET))
#define GPIO_B ((struct GPIO *)(GPIO_BASE + GPIOB_OFFSET))
#define GPIO_C ((struct GPIO *)(GPIO_BASE + GPIOC_OFFSET))

#define delay(t)                                                               \
    do {                                                                       \
        for (uint32_t i = 0; i < t; i++) {                                     \
        }                                                                      \
    } while (0)

#endif /* __STM32_H__ */