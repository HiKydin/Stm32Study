#include "bsp_key.h"

//���ð���1
void KEY1_GPIO_Config(void)
{
	GPIO_InitTypeDef KEY_GPIO_ConfigStruct;//GPIO���ýṹ��
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);//ʹ��ʱ��
		
	KEY_GPIO_ConfigStruct.GPIO_Pin = KEY1_GPIO_Pin;//��������
	KEY_GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//����GPIOģʽ

	GPIO_Init(KEY1_GPIO_Port,&KEY_GPIO_ConfigStruct);//��ʼ��GPIO
}
//���ð���2
void KEY2_GPIO_Config(void)
{
	GPIO_InitTypeDef KEY_GPIO_ConfigStruct;//GPIO���ýṹ��
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);//ʹ��ʱ��
		
	KEY_GPIO_ConfigStruct.GPIO_Pin = KEY2_GPIO_Pin;//��������
	KEY_GPIO_ConfigStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//����GPIOģʽ

	GPIO_Init(KEY2_GPIO_Port,&KEY_GPIO_ConfigStruct);//��ʼ��GPIO
}

//����ɨ��
uint8_t Key_Scan(GPIO_TypeDef *GPIOx , uint16_t GPIO_Pin)
{
    if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
    {
        //���ּ��
        while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);//��������ʱ��һֱѭ����
        return KEY_ON;//�����˾ͷ���
    }
    else
    {
        return KEY_OFF;
    }
}







