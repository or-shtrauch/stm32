#include "STM32.h"

#define PIN_COUNT               16
#define GET_PORT_NUM(port_base) (((uint32_t)port_base - GPIO_BASE) / 0x400UL)

void gpio_pin_init(struct GPIO *gpio_port, uint8_t pin_no, enum GPIO_MODE mode)
{
    RCC->AHB1ENR |= (1U << GET_PORT_NUM(gpio_port));
    gpio_port->MODER &= ~(3U << (pin_no * 2));

    switch (mode) {
    case E_GPIO_MODE_INPUT:
        gpio_port->MODER &= ~(1U << pin_no * 2);
        gpio_port->MODER &= ~(1U << ((pin_no * 2) + 1));
        break;
    case E_GPIO_MODE_OUTPUT:
        gpio_port->MODER |= (1U << pin_no * 2);
        gpio_port->MODER &= ~(1U << ((pin_no * 2) + 1));
        break;
    case E_GPIO_MODE_ALT:
        gpio_port->MODER &= ~(1U << pin_no * 2);
        gpio_port->MODER |= (1U << ((pin_no * 2) + 1));
        break;
    case E_GPIO_MODE_ANALOG:
        gpio_port->MODER |= (1U << pin_no * 2);
        gpio_port->MODER |= (1U << ((pin_no * 2) + 1));
        break;
    default:
        break;
    };
}

void gpio_pin_set(struct GPIO *gpio_port, uint8_t pin_no, bool state)
{
    if (state) {
        gpio_port->BSRR |= (1U << pin_no);
    } else {
        gpio_port->BSRR |= (1U << (pin_no + PIN_COUNT));
    }
}

bool gpio_pin_get(struct GPIO *gpio_port, uint8_t pin_no)
{
    return !(gpio_port->IDR & (1U << pin_no));
}

void gpio_pin_toggle(struct GPIO *gpio_port, uint8_t pin_no)
{
    gpio_port->ODR ^= (1U << pin_no);
}