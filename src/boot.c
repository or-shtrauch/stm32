#include <stdint.h>

#include "STM32.h"

extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void __reset_handler(void);
int  main(void);

ISR_VECTOR uint32_t vector_tbl[] = {

    [E_STACK_TOP]             = (uint32_t)&_estack,
    [E_RESET_HANDLER]         = (uint32_t)&__reset_handler,
    [E_NMI_HANDLER]           = 0,
    [E_HARD_FAULT_HANDLER]    = 0,
    [E_MEM_MANAGE_HANDLER]    = 0,
    [E_BUS_FAULT_HANDLER]     = 0,
    [E_USAGE_FAULT_HANDLER]   = 0,
    [E_RESERVED1]             = 0,
    [E_RESERVED2]             = 0,
    [E_RESERVED3]             = 0,
    [E_RESERVED4]             = 0,
    [E_SVCALL_HANDLER]        = 0,
    [E_DEBUG_MONITOR_HANDLER] = 0,
    [E_RESERVED5]             = 0,
    [E_PEND_SV_HANDLER]       = 0,
    [E_SYSTICK_HANDLER]       = 0,
};

void __reset_handler(void)
{
    uint32_t data_mem_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t bss_mem_size  = (uint32_t)&_ebss - (uint32_t)&_sbss;

    memcpy((uint8_t *)&_sdata, (uint8_t *)&_etext, data_mem_size);
    memset((uint8_t *)&_sbss, 0, bss_mem_size);

    main();

    while (true) {
    }
}
