#include"stm32f10x.h"
void delay();

//×÷Òµ£ºrgbÁ÷Ë®µÆ

int main()
{
	//¿ªÆôÊ±ÖÓ
	*(unsigned int *)0x40021018 |= (1<<3);
	//GPIOÍÆÍìÊä³ö
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*0));
	*(unsigned int *)0x40010C00 |= (1<<(4*0));
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*1));
	*(unsigned int *)0x40010C00 |= (1<<(4*1));
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*5));
	*(unsigned int *)0x40010C00 |= (1<<(4*5));
	
	while(1)
	{
		//ÂÌ 
		*(unsigned int *)0x40010C0C &= ~(1<<0);//ÂÌµÆÁÁ
		*(unsigned int *)0x40010C0C |= (1<<1);//À¶µÆÃğ
		*(unsigned int *)0x40010C0C |= (1<<5);//ºìµÆÃğ
		
		delay();//ÑÓÊ±
		
		//À¶
		*(unsigned int *)0x40010C0C |= (1<<0);//ÂÌµÆÃğ
		*(unsigned int *)0x40010C0C &= ~(1<<1);//À¶µÆÁÁ
		*(unsigned int *)0x40010C0C |= (1<<5);//ºìµÆÃğ
		
		delay();//ÑÓÊ±
		
		//ºì
		*(unsigned int *)0x40010C0C |= (1<<0);//ÂÌµÆÃğ
		*(unsigned int *)0x40010C0C |= (1<<1);//À¶µÆÃğ
		*(unsigned int *)0x40010C0C &= ~(1<<5);//ºìµÆÁÁ
		
		delay();//ÑÓÊ±
	}
}

void delay()
{
	int i=0;
	for(i=0;i<1000000;i++)
	{
		
	}
}

void SystemInit()
{
	//º¯ÊıÌåÎª¿Õ£¬·ÀÖ¹±¨´í
}
