#include"stm32f10x.h"
#include"stm32f10x_gpio.h"

void delay()
{
    int i;
    for(i = 0;i<1000000;i++)
    {
        
    }
}

int main()
{
	RCC->APB2ENR |= (1<<3);
    
    //GPIOB->CRL &= ~(0x0f)<<(4*0);
    //GPIOB->CRL |= (1)<<(4*0);

    GPIO_SetBits(GPIOB,GPIO_Pin_10);
    
    while(1)
    {
        GPIOB->CRL &= ~(0x0f)<<(4*5);
        GPIOB->CRL |= (1)<<(4*5);
        GPIO_SetBits(GPIOB,GPIO_Pin_10);
        GPIO_ResetBits(GPIOB,GPIO_Pin_5);
        delay();
        
        GPIOB->CRL &= ~(0x0f)<<(4*1);
        GPIOB->CRL |= (1)<<(4*1);
        GPIO_SetBits(GPIOB,GPIO_Pin_5);
        GPIO_ResetBits(GPIOB,GPIO_Pin_10);
        delay(); 
    }
}

void SystemInit()
{
	//函数体为空，防止报错
}
