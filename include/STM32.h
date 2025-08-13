#ifndef __STM32_H__
#define __STM32_H__

#include <stddef.h>
#include <stdbool.h>
#include "types.h"

#define SET(addr, value) (addr = value);
#define ADDR(high, low)  ((high << 16) | low)

#define STM_RAM_START ADDR(0x2000, 0x0000)
#define STM_RAM_END   ADDR(0x2000, 0x1FFF)

#define GPIO_BASE ADDR(0x4002, 0x0000)

#define GPIO_A_OFFSET ADDR(0x0000, 0x0000)
#define GPIO_B_OFFSET ADDR(0x0000, 0x0400)
#define GPIO_C_OFFSET ADDR(0x0000, 0x0800)
#define GPIO_D_OFFSET ADDR(0x0000, 0x0C00)
#define GPIO_E_OFFSET ADDR(0x0000, 0x1000)
#define GPIO_H_OFFSET ADDR(0x0000, 0x1C00)

#define RCC_BASE            ADDR(0x4002, 0x3800)
#define RCC_AHB1_ENR_OFFSET ADDR(0x0000, 0x0030)

#define RCC_AHB1_ENR (*(struct RCC_AHB *)(RCC_BASE + RCC_AHB1_ENR_OFFSET))

#define GPIO_A_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_A_OFFSET))
#define GPIO_B_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_B_OFFSET))
#define GPIO_C_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_C_OFFSET))
#define GPIO_D_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_D_OFFSET))
#define GPIO_E_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_E_OFFSET))
#define GPIO_H_MODER (*(struct GPIO_MODE *)(GPIO_BASE + GPIO_H_OFFSET))

#endif /* __STM32_H__ */