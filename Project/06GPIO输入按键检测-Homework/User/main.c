#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
int main()
{
    //来到这里的时候，系统时钟已经被配置成72M
    
    GPIO_Config();
    KEY1_GPIO_Config();
    KEY2_GPIO_Config();
    //无限循环按键检测
    
    while(1)
    {
        if(Key_Scan(KEY1_GPIO_Port,KEY1_GPIO_Pin) == KEY_ON )//如果按键按下了
        {
            LED_G_TOGGLE;//翻转LED状态
        }
        if(Key_Scan(KEY2_GPIO_Port,KEY2_GPIO_Pin) == KEY_ON )
        {
            LED_G_TOGGLE;//翻转LED状态
        }
    }
}

//作业：
//实现按键2的检测 使得红灯跟随按钮按下点亮熄灭
