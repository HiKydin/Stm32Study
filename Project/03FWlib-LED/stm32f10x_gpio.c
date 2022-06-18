#include"stm32f10x_gpio.h"

void GPIO_SetBits(GPIO_TypeDef *GPIOx,u16 GPIO_Pin)
{
    GPIOx->BSRR |= GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef *GPIOx,u16 GPIO_Pin)
{
    GPIOx->BRR |= GPIO_Pin;
}