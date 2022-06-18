#include"stm32f10x.h"
//实现RCC这个外设的寄存器结构体声明，吧时钟相关的代码改成寄存器结构体操作的方式

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
	//函数体为空，防止报错
}
