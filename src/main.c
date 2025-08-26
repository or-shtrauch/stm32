#include "STM32.h"

#define LED_PIN    5
#define BUTTON_PIN 13

int main(void)
{
    gpio_pin_init(GPIO_A, LED_PIN, E_GPIO_MODE_OUTPUT);
    gpio_pin_init(GPIO_C, BUTTON_PIN, E_GPIO_MODE_INPUT);

    while (true) {
        gpio_pin_set(GPIO_A, LED_PIN, gpio_pin_get(GPIO_C, BUTTON_PIN));
    }
}