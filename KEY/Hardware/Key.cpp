#include "stm32f10x.h"  
#include "Key.h"
extern "C"
{
#include "Delay.h"
}
Key::Key(uint32_t RCC_APB2Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	this->GPIOx=GPIOx;
	this->GPIO_Pin=GPIO_Pin;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph,ENABLE);
	this->GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_IPU; //上拉输入
	this->GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin;
	this->GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&this->GPIO_InitStructure);
	//GPIO_ResetBits(GPIOx,GPIO_Pin);
}


uint8_t Key::readValue()
{
	if(GPIO_ReadInputDataBit(this->GPIOx,this->GPIO_Pin)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(this->GPIOx,this->GPIO_Pin)==0);
		Delay_ms(20);
		return 0;
	}
	else 
		return 1;
	
}
