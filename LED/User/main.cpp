#include "stm32f10x.h"                  // Device header
#include "LED.h"
extern "C"	//cpp项目不写这个可能会出错
{
#include "Delay.h"
}

int main(void)
{
	Led led1(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0);
	Led led2(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_1);
	Led led3(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_2);
	Led led4(RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_3);
	Led leds[4]={led1,led2,led3,led4};
	while(1)
	{
		for(int x=0;x<4;x++)
		{
			leds[x].setValue(1);
			Delay_ms(500);
			leds[x].setValue(0);
		}
	}
}
