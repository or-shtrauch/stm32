#ifndef __GPIO_H__
#define __GPIO_H__

#include "types.h"

void gpio_pin_init(struct GPIO *gpio_port, uint8_t pin_no, enum GPIO_MODE mode);
void gpio_pin_set(struct GPIO *gpio_port, uint8_t pin_no, bool state);
bool gpio_pin_get(struct GPIO *gpio_port, uint8_t pin_no);

#endif /* __GPIO_H__ */