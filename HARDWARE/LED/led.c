#include "sys.h"   
#include "led.h" 

void LED_Init(void)

{

	RCC->APB2ENR|=1<<6;    	//使能PORTE时钟

	GPIOE->CRH&=0XFFFFFF0F; //清除9的配置
	GPIOE->CRH|=0X00000030;//PE9 推挽输出   	 
    GPIOE->ODR|=1<<9;      //PE9 输出高

	GPIOE->CRH&=0XFFFF0FFF; //清除11的配置
	GPIOE->CRH|=0X00003000;//PE11 推挽输出   	 
    GPIOE->ODR|=1<<11;      //PE11 输出高

	GPIOE->CRH&=0XFF0FFFFF; //清除13的配置
	GPIOE->CRH|=0X00300000;//PE13 推挽输出   	 
    GPIOE->ODR|=1<<13;      //PE13 输出高

	GPIOE->CRH&=0XF0FFFFFF; //清除14的配置
	GPIOE->CRH|=0X03000000;//PE14 推挽输出   	 
    GPIOE->ODR|=1<<14;      //PE14 输出高

}

