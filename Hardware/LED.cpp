#include "stm32f10x.h"  
#include "LED.h"

Led::Led(uint32_t RCC_APB2Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	this->GPIOx=GPIOx;
	this->GPIO_Pin=GPIO_Pin;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph,ENABLE);
	this->GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_Out_PP; //推挽输出模式
	this->GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin;
	this->GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&this->GPIO_InitStructure);
	GPIO_ResetBits(GPIOx,GPIO_Pin);//默认为低电平
	this->value=1;
	//GPIO_ResetBits(GPIOx,GPIO_Pin);
}

void Led::setValue(uint8_t v)
{
	if(v) 	
	{
		GPIO_SetBits(this->GPIOx,this->GPIO_Pin);
		this->value=1;
	}
	else
	{
		GPIO_ResetBits(this->GPIOx,this->GPIO_Pin);
		this->value=0;
	}
}

uint8_t Led::readValue()
{
	return this->value;
}
