#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED_GPIO_Pin   GPIO_Pin_0
#define GPIO_Port      GPIOB

void GPIO_Config(void);

#define ON  1
#define OFF 0

#define LED_G(i) if(i) GPIO_ResetBits(GPIO_Port, LED_GPIO_Pin); else GPIO_SetBits(GPIO_Port, LED_GPIO_Pin);

#endif
