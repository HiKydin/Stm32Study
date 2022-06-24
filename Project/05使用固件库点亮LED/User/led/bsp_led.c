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
