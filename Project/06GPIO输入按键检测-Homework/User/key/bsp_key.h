#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_Pin       GPIO_Pin_0              //Pin口
#define KEY1_GPIO_Port      GPIOA                   //GPIO口
#define KEY1_GPIO_CLK       RCC_APB2Periph_GPIOA    //GPIO口的时钟

#define KEY2_GPIO_Pin       GPIO_Pin_13             //Pin口
#define KEY2_GPIO_Port      GPIOC                   //GPIO口
#define KEY2_GPIO_CLK       RCC_APB2Periph_GPIOC    //GPIO口的时钟

void KEY1_GPIO_Config(void); //配置按键
void KEY2_GPIO_Config(void); //配置按键
uint8_t Key_Scan(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin); //按键扫描

#define KEY_ON  1 //宏定义 按下按键
#define KEY_OFF 0

#endif

