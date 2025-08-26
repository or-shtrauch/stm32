#include <stdint.h>
#include <stddef.h>

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
    [E_NMI_HANDLER]           = (uint32_t)NULL,
    [E_HARD_FAULT_HANDLER]    = (uint32_t)NULL,
    [E_MEM_MANAGE_HANDLER]    = (uint32_t)NULL,
    [E_BUS_FAULT_HANDLER]     = (uint32_t)NULL,
    [E_USAGE_FAULT_HANDLER]   = (uint32_t)NULL,
    [E_RESERVED1]             = (uint32_t)NULL,
    [E_RESERVED2]             = (uint32_t)NULL,
    [E_RESERVED3]             = (uint32_t)NULL,
    [E_RESERVED4]             = (uint32_t)NULL,
    [E_SVCALL_HANDLER]        = (uint32_t)NULL,
    [E_DEBUG_MONITOR_HANDLER] = (uint32_t)NULL,
    [E_RESERVED5]             = (uint32_t)NULL,
    [E_PEND_SV_HANDLER]       = (uint32_t)NULL,
    [E_SYSTICK_HANDLER]       = (uint32_t)NULL,
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
