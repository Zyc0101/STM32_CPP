#ifndef __Key_H
#define __Key_H

class Key
{
	private:
		GPIO_InitTypeDef 	GPIO_InitStructure;
		GPIO_TypeDef* 		GPIOx;
		uint16_t 			GPIO_Pin;
	
	public:
		Key(uint32_t RCC_APB2Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
		uint8_t		readValue();
};

#endif
