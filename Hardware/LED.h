#ifndef __LED_H
#define __LED_H

class Led
{
	private:
		GPIO_InitTypeDef 	GPIO_InitStructure;
		GPIO_TypeDef* 		GPIOx;
		uint16_t 			GPIO_Pin;
		uint8_t				value;
	public:
		Led(uint32_t RCC_APB2Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);//构造
		void 		setValue(uint8_t v);
		uint8_t		readValue();
};

#endif
