#include"stm32f10x.h"
int main()
{
	RCC_APB2ENR |= (1<<3);
    
    GPIOB_CRL &= ~(0x0f)<<(4*0);
    GPIOB->CRL |= (1)<<(4*0);
    
    GPIOB->ODR &= ~(1<<0);
    //GPIOB->ODR |= (1<<0);
}

void SystemInit()
{
	//函数体为空，防止报错
}
