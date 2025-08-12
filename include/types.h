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