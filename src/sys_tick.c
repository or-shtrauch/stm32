#include "STM32.h"

#define CTRL_EN         (1U << 0)
#define CTRL_CLCKSRC    (1U << 2)
#define CTRL_COUNT_FLAG (1U << 16)

#define ONE_MS (16000)

void sys_tick_delay_sync(struct SYS_TICK *systick, uint32_t ms)
{
    systick->LOAD = ONE_MS - 1;
    systick->VAL  = 0;
    systick->CTRL = CTRL_CLCKSRC | CTRL_EN;

    while (ms--) {
        while ((systick->CTRL & CTRL_COUNT_FLAG) == 0) {
        }
    }

    systick->CTRL = 0;
}