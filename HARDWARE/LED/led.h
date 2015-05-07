#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED1 PEout(9)   //PE9
#define LED2 PEout(11)  //PE11
#define LED3 PEout(13)  //PE13
#define LED4 PEout(14)  //PE14	

void LED_Init(void);

#define up 0;
#define done 1;
 				    
#endif
