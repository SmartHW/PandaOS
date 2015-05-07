#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
 
#define KEY1_PRES 1		//KEY1按下
#define KEY2_PRES 2		//KEY2按下
#define KEY3_PRES 3		//KEY3按下
#define KEY4_PRES 4		//KEY4按下

#define KEY1 PBin(1)	//PB1
#define KEY2 PEin(8)	//PE8
#define KEY3 PEin(12)	//PE12
#define KEY4 PEin(15)	//PE15
	
void KEY_Init(void);	//IO初始化
u8 KEY_Scan(u8 mode);	//按键扫描函数
 				    
#endif
