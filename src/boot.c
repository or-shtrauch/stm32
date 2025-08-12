#include "STM32.h"

#define ISR_VECTOR __attribute__((section(".isr_vector")))

extern int main(void);
NAKED void __reset_handler(void);

/* Symbols defined in the linker script */
extern uint32_t __end_text;
extern uint32_t __start_data;
extern uint32_t __end_data;
extern uint32_t __start_bss;
extern uint32_t __end_bss;
extern uint32_t __stack_top;

/* Interrupt vector table */
ISR_VECTOR isr_handler_t vector_table[] = {
    [E_STACK_TOP]             = (void *)&__stack_top, /* The stack pointer */
    [E_RESET_HANDLER]         = __reset_handler,      /* The reset handler */
    [E_NMI_HANDLER]           = NULL,                 /* NMI handler */
    [E_HARD_FAULT_HANDLER]    = NULL,                 /* Hard fault handler */
    [E_MEM_MANAGE_HANDLER]    = NULL, /* MemManage fault handler */
    [E_BUS_FAULT_HANDLER]     = NULL, /* BusFault handler */
    [E_USAGE_FAULT_HANDLER]   = NULL, /* UsageFault handler */
    [E_RESERVED1]             = NULL, /* Reserved */
    [E_RESERVED2]             = NULL, /* Reserved */
    [E_RESERVED3]             = NULL, /* Reserved */
    [E_RESERVED4]             = NULL, /* Reserved */
    [E_SVCALL_HANDLER]        = NULL, /* SVCall handler */
    [E_DEBUG_MONITOR_HANDLER] = NULL, /* Debug monitor handler */
    [E_RESERVED5]             = NULL, /* Reserved */
    [E_PEND_SV_HANDLER]       = NULL, /* PendSV handler */
    [E_SYSTICK_HANDLER]       = NULL, /* SysTick handler */
};

void __reset_handler(void)
{
    size_t data_size = (size_t)&__end_data - (size_t)&__start_data;
    size_t bss_size  = (size_t)&__end_bss - (size_t)&__start_bss;

    memcpy(U8_ADDR(__start_data), U8_ADDR(__end_text), data_size);
    memset(U8_ADDR(__start_bss), 0, bss_size);

    main();

    while (1) {
    }
}