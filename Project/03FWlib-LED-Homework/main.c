#include"stm32f10x.h"
//ʵ��RCC�������ļĴ����ṹ����������ʱ����صĴ���ĳɼĴ����ṹ������ķ�ʽ

int main()
{
	RCC->APB2ENR |= (1<<3);
    
    GPIOB->CRL &= ~(0x0f)<<(4*0);
    GPIOB->CRL |= (1)<<(4*0);
    
    GPIOB->ODR &= ~(1<<0);
    //GPIOB->ODR |= (1<<0);
}

void SystemInit()
{
	//������Ϊ�գ���ֹ����
}
