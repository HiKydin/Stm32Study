#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"
    
#define LED_GPIO_Pin       GPIO_Pin_0             //�궨��GPIO�˿�����
#define LED_GPIO_Port      GPIOB                  //����GPIO�˿�
#define LED_GPIO_CLK       RCC_APB2Periph_GPIOB   //ʱ��

#define LED_R_GPIO_Pin     GPIO_Pin_5             //�궨��GPIO�˿�����
#define LED_R_GPIO_Port    GPIOB                  //����GPIO�˿�
#define LED_R_GPIO_CLK     RCC_APB2Periph_GPIOB   //ʱ��


void GPIO_Config(void);

#define ON  1
#define OFF 0

#define LED_G(i) if(i) GPIO_ResetBits(LED_GPIO_Port, LED_GPIO_Pin); else GPIO_SetBits(LED_GPIO_Port, LED_GPIO_Pin);

//��תLED״̬
//�궨�庯���﷨ #define  ������ {����;}
//^ ��1���ı� ��0��򲻱�

#define LED_G_TOGGLE {LED_GPIO_Port->ODR ^=LED_GPIO_Pin;}

#endif
