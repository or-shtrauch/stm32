#include "STM32.h"

int main(void)
{
    SET(RCC_AHB1_ENR.GPIO_A_EN, E_ENABLE);
    SET(GPIO_A_MODER.PORT_5, E_GPIO_MODE_OUTPUT);

    while (true)
        ;
}