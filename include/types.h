#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ISR_VECTOR   __attribute__((section(".isr_vector_table")))
#define INLINE_FORCE __attribute__((always_inline)) inline
#define NAKED        __attribute__((naked))
#define NORETURN     __attribute__((noreturn))
#define PACKED       __attribute__((packed))
#define UNUSED       __attribute__((unused))

#define SI_FORCE static INLINE_FORCE

enum isr_type
{
    E_STACK_TOP = 0,
    E_RESET_HANDLER,
    E_NMI_HANDLER,
    E_HARD_FAULT_HANDLER,
    E_MEM_MANAGE_HANDLER,
    E_BUS_FAULT_HANDLER,
    E_USAGE_FAULT_HANDLER,
    E_RESERVED1,
    E_RESERVED2,
    E_RESERVED3,
    E_RESERVED4,
    E_SVCALL_HANDLER,
    E_DEBUG_MONITOR_HANDLER,
    E_RESERVED5,
    E_PEND_SV_HANDLER,
    E_SYSTICK_HANDLER,
};

enum GPIO_MODE
{
    E_GPIO_MODE_INPUT  = 0b00,
    E_GPIO_MODE_OUTPUT = 0b01,
    E_GPIO_MODE_ALT    = 0b10,
    E_GPIO_MODE_ANALOG = 0b11,
};

struct RCC
{
    volatile uint8_t  __padding[0x30UL];
    volatile uint32_t AHB1ENR;
};

struct GPIO
{
    volatile uint32_t MODER;   /*offset: 0x00      */
    volatile uint32_t OTYPER;  /*offset: 0x04      */
    volatile uint32_t OSPEEDR; /*offset: 0x08      */
    volatile uint32_t PUPDR;   /*offset: 0x0C      */
    volatile uint32_t IDR;     /*offset: 0x10      */
    volatile uint32_t ODR;     /*offset: 0x14      */
    volatile uint32_t BSRR;    /*offset: 0x18      */
    volatile uint32_t LCKR;    /*offset: 0x1C      */
    volatile uint32_t AFRL;    /*offset: 0x20     */
    volatile uint32_t AFRH;    /*offset: 0x24      */
};

struct SYS_TICK
{
    volatile uint32_t CTRL;  /*offset: 0x00 */
    volatile uint32_t LOAD;  /*offset: 0x04 */
    volatile uint32_t VAL;   /*offset: 0x08 */
    volatile uint32_t CALIB; /*offset: 0x0C */
};

#define memset _memset
#define memcpy _memcpy

SI_FORCE uint8_t *_memcpy(uint8_t *dst, uint8_t *src, uint32_t n)
{
    while (n--) {
        *dst++ = *src++;
    }

    return dst;
}

SI_FORCE uint8_t *_memset(uint8_t *dst, int8_t c, uint32_t n)
{
    while (n--) {
        *dst++ = c;
    }

    return dst;
}

#endif /* __STM32_H__ */