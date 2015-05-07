#include "sys.h"
#include "key.h"
#include "delay.h"

void KEY_Init(void){
	RCC->APB2ENR|=1<<6;    	//使能PORTE时钟
	RCC->APB2ENR|=1<<3;		//使能PORTB时钟

	GPIOB->CRL&=0XFFFFFF0F;	//清除1的配置
	GPIOB->CRL|=0X00000080;	//PB1设置为输入
	GPIOB->ODR|=1<<1;		//PB1设置为上拉

	GPIOE->CRH&=0XFFFFFFF0;	//清除8的配置
	GPIOE->CRH|=0X00000008;	//PE8设置为输入
	GPIOE->ODR|=1<<8;		//PE8设置为上拉

	GPIOE->CRH&=0XFFF0FFFF;	//清除12的配置
	GPIOE->CRH|=0X00080000;	//PE12设置为输入
	GPIOE->ODR|=1<<12;		//PE12设置为上拉

	GPIOE->CRH&=0X0FFFFFFF;	//清除15的配置
	GPIOE->CRH|=0X80000000;	//PE15设置为输入
	GPIOE->ODR|=1<<15;		//PE15设置为上拉
}
u8 KEY_Scan(u8 mode){
   	static u8 key_up = 1;//按键松开标志
	if(mode)
		key_up = 1;	//支持连按
	if(key_up && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)){
	 	delay_ms(100);//去抖动
		key_up = 0;
		if(KEY1 == 0)
			return KEY1_PRES;

		else if(KEY2 == 0)
			return KEY2_PRES;

		else if(KEY3 == 0)
			return KEY3_PRES;

		else if(KEY4 == 0)
			return KEY4_PRES;
	}
	else if(KEY1 && KEY2 && KEY3 && ~KEY4)
		key_up=1;
	return 0;//无按键按下
}
