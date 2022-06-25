#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"
    
#define LED_GPIO_Pin       GPIO_Pin_0             //宏定义GPIO端口引脚
#define LED_GPIO_Port      GPIOB                  //定义GPIO端口
#define LED_GPIO_CLK       RCC_APB2Periph_GPIOB   //时钟

#define LED_R_GPIO_Pin     GPIO_Pin_5             //宏定义GPIO端口引脚
#define LED_R_GPIO_Port    GPIOB                  //定义GPIO端口
#define LED_R_GPIO_CLK     RCC_APB2Periph_GPIOB   //时钟


void GPIO_Config(void);

#define ON  1
#define OFF 0

#define LED_G(i) if(i) GPIO_ResetBits(LED_GPIO_Port, LED_GPIO_Pin); else GPIO_SetBits(LED_GPIO_Port, LED_GPIO_Pin);

//翻转LED状态
//宏定义函数语法 #define  函数名 {内容;}
//^ 与1异或改变 与0异或不变

#define LED_G_TOGGLE {LED_GPIO_Port->ODR ^=LED_GPIO_Pin;}

#endif
