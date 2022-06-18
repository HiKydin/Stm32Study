#ifndef _STM32F10X_GPIO_H
#define _STM32F10X_GPIO_H

#include"stm32f10x.h"

#define GPIO_Pin_0    ((u16)0x0001)  /*!< Pin0 */    //(00000000 00000001)b
#define GPIO_Pin_1    ((u16)0x0002)  /*!< Pin1 */    //(00000000 00000010)b
#define GPIO_Pin_2    ((u16)0x0004)  /*!< Pin2 */    //(00000000 00000100)b
#define GPIO_Pin_3    ((u16)0x0008)  /*!< Pin3 */    //(00000000 00001000)b
#define GPIO_Pin_4    ((u16)0x0010)  /*!< Pin4 */    //(00000000 00010000)b
#define GPIO_Pin_5    ((u16)0x0020)  /*!< Pin5 */    //(00000000 00100000)b
#define GPIO_Pin_6    ((u16)0x0040)  /*!< Pin6 */    //(00000000 01000000)b
#define GPIO_Pin_7    ((u16)0x0080)  /*!< Pin7 */    //(00000000 10000000)b

#define GPIO_Pin_8    ((u16)0x0100)  /*!< Pin8 */    //(00000001 00000000)b
#define GPIO_Pin_9    ((u16)0x0200)  /*!< Pin9 */    //(00000010 00000000)b
#define GPIO_Pin_10   ((u16)0x0400)  /*!< Pin10 */   //(00000100 00000000)b
#define GPIO_Pin_11   ((u16)0x0800)  /*!< Pin11 */   //(00001000 00000000)b
#define GPIO_Pin_12   ((u16)0x1000)  /*!< Pin12 */   //(00010000 00000000)b
#define GPIO_Pin_13   ((u16)0x2000)  /*!< Pin13 */   //(00100000 00000000)b
#define GPIO_Pin_14   ((u16)0x4000)  /*!< Pin14 */   //(01000000 00000000)b
#define GPIO_Pin_15   ((u16)0x8000)  /*!< Pin15 */   //(10000000 00000000)b
#define GPIO_Pin_All  ((u16)0xFFFF)  /*!< 选择全部引脚*/ //(11111111 11111111)b

typedef unsigned short u16;

typedef enum
{
    GPIO_Speed_10MHZ =1,
    GPIO_Speed_2MHZ,
    GPIO_Speed_50MHZ
}GPIOSpeed_TypeDef;

typedef struct
{
    u16 GPIO_Pin;
    u16 GPIO_Speed;
    u16 GPIO_Mode;
}GPIO_InitTypeDef;


void GPIO_SetBits(GPIO_TypeDef *GPIOx,u16 GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,u16 GPIO_Pin);

#endif 
