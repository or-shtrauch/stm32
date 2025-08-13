#ifndef __TYPES_H__
#define __TYPES_H__

#define INLINE_FORCE __attribute__((always_inline)) inline
#define NAKED        __attribute__((naked))
#define NORETURN     __attribute__((noreturn))
#define PACKED       __attribute__((packed))
#define UNUSED       __attribute__((unused))

#define SI_FORCE static INLINE_FORCE

#define IN
#define OUT
#define INOUT

#define _ADDR(type, x) ((type *)(&x))
#define U8_ADDR(x)     _ADDR(uint8_t, x)

typedef char          int8_t;
typedef unsigned char uint8_t;

typedef short          int16_t;
typedef unsigned short uint16_t;

typedef int          int32_t;
typedef unsigned int uint32_t;

typedef volatile uint32_t* ptr_t;

typedef void (*isr_handler_t)(void);

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

enum
{
    E_GPIO_MODE_INPUT  = 0b00,
    E_GPIO_MODE_OUTPUT = 0b01,
    E_GPIO_MODE_ALT    = 0b10,
    E_GPIO_MODE_ANALOG = 0b11,
};

enum
{
    E_DISABLE = 0b00,
    E_ENABLE  = 0b01,
};

struct RCC_AHB
{
    uint32_t GPIO_A_EN : 1; // bit 0
    uint32_t GPIO_B_EN : 1; // bit 1
    uint32_t GPIO_C_EN : 1; // bit 2
    uint32_t GPIO_D_EN : 1; // bit 3
    uint32_t GPIO_E_EN : 1; // bit 4
    uint32_t RESERVED1 : 2; // bit 5 - 6
    uint32_t GPIO_H_EN : 1; // bit 7
    uint32_t RESERVED2 : 4; // bit 8 - 11
    uint32_t CRC_EN : 1;    // bit 12
    uint32_t RESERVED3 : 8; // bit 13 - 20
    uint32_t DMA1_EN : 1;   // bit 21
    uint32_t DMA2_EN : 1;   // bit 22
    uint32_t RESERVED4 : 9; // bit 23 - 31
};

struct GPIO_MODE
{
    uint32_t PORT_0 : 2;  // bits 0, 1
    uint32_t PORT_1 : 2;  // bits 2, 3
    uint32_t PORT_2 : 2;  // bits 4, 5
    uint32_t PORT_3 : 2;  // bits 6, 7
    uint32_t PORT_4 : 2;  // bits 8, 9
    uint32_t PORT_5 : 2;  // bits 10, 11
    uint32_t PORT_6 : 2;  // bits 12, 13
    uint32_t PORT_7 : 2;  // bits 14, 15
    uint32_t PORT_8 : 2;  // bits 16, 17
    uint32_t PORT_9 : 2;  // bits 18, 19
    uint32_t PORT_10 : 2; // bits 20, 21
    uint32_t PORT_11 : 2; // bits 22, 23
    uint32_t PORT_12 : 2; // bits 24, 25
    uint32_t PORT_13 : 2; // bits 26, 27
    uint32_t PORT_14 : 2; // bits 28, 29
    uint32_t PORT_15 : 2; // bits 30, 31
};


SI_FORCE uint8_t *_memcpy(uint8_t *dst, uint8_t *src, size_t n);
SI_FORCE uint8_t *_memset(uint8_t *dst, int8_t c, size_t n);

#define memset _memset
#define memcpy _memcpy

SI_FORCE uint8_t *_memcpy(uint8_t *dst, uint8_t *src, size_t n)
{
    while (n--) {
        *dst++ = *src++;
    }

    return dst;
}

SI_FORCE uint8_t *_memset(uint8_t *dst, int8_t c, size_t n)
{
    while (n--) {
        *dst++ = c;
    }

    return dst;
}

#endif /* __TYPES_H__ */