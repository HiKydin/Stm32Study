#include"stm32f10x.h"
void delay();

//��ҵ��rgb��ˮ��

int main()
{
	//����ʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	//GPIO�������
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*0));
	*(unsigned int *)0x40010C00 |= (1<<(4*0));
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*1));
	*(unsigned int *)0x40010C00 |= (1<<(4*1));
	*(unsigned int *)0x40010C00 &= ~((0x0f)<<(4*5));
	*(unsigned int *)0x40010C00 |= (1<<(4*5));
	
	while(1)
	{
		//�� 
		*(unsigned int *)0x40010C0C &= ~(1<<0);//�̵���
		*(unsigned int *)0x40010C0C |= (1<<1);//������
		*(unsigned int *)0x40010C0C |= (1<<5);//�����
		
		delay();//��ʱ
		
		//��
		*(unsigned int *)0x40010C0C |= (1<<0);//�̵���
		*(unsigned int *)0x40010C0C &= ~(1<<1);//������
		*(unsigned int *)0x40010C0C |= (1<<5);//�����
		
		delay();//��ʱ
		
		//��
		*(unsigned int *)0x40010C0C |= (1<<0);//�̵���
		*(unsigned int *)0x40010C0C |= (1<<1);//������
		*(unsigned int *)0x40010C0C &= ~(1<<5);//�����
		
		delay();//��ʱ
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
	//������Ϊ�գ���ֹ����
}
