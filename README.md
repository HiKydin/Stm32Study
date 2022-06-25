# Stm32Study
学习嵌入式开发，stm32板子的学习笔记和文档、程序

### 推挽输出

1、可以输出高低电平，用于连接数字器件，高电平由VDD决定，低电平由VSS决定

2、推挽结构指两个三极管受两路互补信号控制，总是在一个导通的时候另一个截至，优点是**开关效率高，电流大，驱动能力强**

3、输出高电平时，电流输出到负载，叫灌电流，可以理解成推。输出低电平时，负载电流流向芯片，叫拉电流，即挽

### 开漏输出

1、只能输出低电平，不能输出高电平

2、如果要输出高电平，则需要外接上拉

3、开漏输出具有“线与”功能，一个为低，全部为低，多用于I2C、SMBUS总线

### 用固件库编程点亮LED

新建文件bsp_led.c和bsp_led.h

在bsp_led.h中

~~~c
#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED_GPIO_Pin   GPIO_Pin_0 //宏定义端口引脚
#define GPIO_Port      GPIOB	  //宏定义GPIO端口

void GPIO_Config(void);           //端口配置函数

#endif

~~~

在bsp_led.c中，实现函数

~~~c
//bsp : board support package 板级支持包
#include"bsp_led.h"

void GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_ConfigStruct;//声明结构体
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能时钟
	
    //配置时钟
	GPIO_ConfigStruct.GPIO_Pin = LED_GPIO_Pin;
	GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_ConfigStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIO_Port,&GPIO_ConfigStruct);
	
	GPIO_SetBits(GPIO_Port, LED_GPIO_Pin);//位赋值
	GPIO_ResetBits(GPIO_Port, LED_GPIO_Pin);//位清零
}

~~~

这样我们就实现了通过固件库编程点亮LED

如果进一步提高可读性，我们可以通过c语言的带参宏定义来实现进一步封装

在bsp_led.h中声明

~~~C
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

~~~

在bsp_led.c中

~~~c
//bsp : board support package 板级支持包
#include"bsp_led.h"

void GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_ConfigStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		
	GPIO_ConfigStruct.GPIO_Pin = LED_GPIO_Pin;
	GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_ConfigStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIO_Port,&GPIO_ConfigStruct);
	
	//GPIO_SetBits(GPIO_Port, LED_GPIO_Pin);
    LED_G(OFF);
	//GPIO_ResetBits(GPIO_Port, LED_GPIO_Pin);
    LED_G(ON);
}

~~~

### C语言宏定义函数

语法 `#define 函数名 {内容;}`

例如，我们定义一个翻转LED灯亮灭的宏

~~~c
#define LED_G_TOGGLE {LED_GPIO_Port->ODR ^= LED_GPIO_Pin;}
~~~

LED_GPIO_Pin是LED绿灯，对应板子的端口就是GPIOB的PB0，15个0和一个1

异或上ODR寄存器当前的值，默认全为0

`^ 与1异或改变 与0异或不变`

所以就会翻转PB0的值，熄灭PB0。（PB0为低电平点亮）

