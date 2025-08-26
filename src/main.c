#include "STM32.h"

#define LED_PIN    5
#define BUTTON_PIN 13

int main(void)
{
    gpio_pin_init(GPIO_A, LED_PIN, E_GPIO_MODE_OUTPUT);

    while (true) {
        sys_tick_delay_sync(SYSTICK, 500);
        gpio_pin_toggle(GPIO_A, LED_PIN);
    }
}