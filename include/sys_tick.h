#ifndef __SYS_TICK_H__
#define __SYS_TICK_H__

#include "types.h"

void sys_tick_delay_sync(struct SYS_TICK *systick, uint32_t ms);

#endif /* __SYS_TICK_H__ */