#include"stm32f10x.h"

int main()
{
	//开启时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//设置GPIO口为推挽输出
	*(unsigned int *)0x40010C00 |= (1<<(4*1));
	
	//寄存器写入0
	*(unsigned int *)0x40010C0C &= ~(1<<0);
}


void SystemInit()
{
	//函数体为空，防止报错
}
