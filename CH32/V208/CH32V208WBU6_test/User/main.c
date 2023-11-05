#include "debug.h"

void led_init(void)
{
    GPIO_InitTypeDef gpio_init;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

    gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_init.GPIO_Pin = GPIO_Pin_3;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&gpio_init);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    led_init();
    while(1)
    {
        GPIO_ResetBits(GPIOC,GPIO_Pin_3);
        Delay_Ms(1000);
        GPIO_SetBits(GPIOC,GPIO_Pin_3);
        Delay_Ms(1000);


    }
}
