#include"stm32f10x.h"

int main()
{
	//����ʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//����GPIO��Ϊ�������
	*(unsigned int *)0x40010C00 |= (1<<(4*1));
	
	//�Ĵ���д��0
	*(unsigned int *)0x40010C0C &= ~(1<<0);
}


void SystemInit()
{
	//������Ϊ�գ���ֹ����
}
