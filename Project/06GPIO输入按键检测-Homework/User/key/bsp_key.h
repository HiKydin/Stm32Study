#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_Pin       GPIO_Pin_0              //Pin��
#define KEY1_GPIO_Port      GPIOA                   //GPIO��
#define KEY1_GPIO_CLK       RCC_APB2Periph_GPIOA    //GPIO�ڵ�ʱ��

#define KEY2_GPIO_Pin       GPIO_Pin_13             //Pin��
#define KEY2_GPIO_Port      GPIOC                   //GPIO��
#define KEY2_GPIO_CLK       RCC_APB2Periph_GPIOC    //GPIO�ڵ�ʱ��

void KEY1_GPIO_Config(void); //���ð���
void KEY2_GPIO_Config(void); //���ð���
uint8_t Key_Scan(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin); //����ɨ��

#define KEY_ON  1 //�궨�� ���°���
#define KEY_OFF 0

#endif

