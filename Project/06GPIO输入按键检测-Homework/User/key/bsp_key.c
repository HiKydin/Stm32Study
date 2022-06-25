#include "bsp_key.h"

//配置按键1
void KEY1_GPIO_Config(void)
{
	GPIO_InitTypeDef KEY_GPIO_ConfigStruct;//GPIO配置结构体
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);//使能时钟
		
	KEY_GPIO_ConfigStruct.GPIO_Pin = KEY1_GPIO_Pin;//配置引脚
	KEY_GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//配置GPIO模式

	GPIO_Init(KEY1_GPIO_Port,&KEY_GPIO_ConfigStruct);//初始化GPIO
}
//配置按键2
void KEY2_GPIO_Config(void)
{
	GPIO_InitTypeDef KEY_GPIO_ConfigStruct;//GPIO配置结构体
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);//使能时钟
		
	KEY_GPIO_ConfigStruct.GPIO_Pin = KEY2_GPIO_Pin;//配置引脚
	KEY_GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//配置GPIO模式

	GPIO_Init(KEY2_GPIO_Port,&KEY_GPIO_ConfigStruct);//初始化GPIO
}

//按键扫描
uint8_t Key_Scan(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin)
{
    if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
    {
        //松手检测
        while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);//当不松手时，一直循环着
        return KEY_ON;//松手了就返回
    }
    else
    {
        return KEY_OFF;
    }
}







