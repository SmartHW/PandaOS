#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"
#include "key.h" 

#define DEVICEID 07

int main(void){		 
		u8 t;u8 len;u8 try = 0;u8 flag = 0;
		u16 times = 0,time = 0,time1 = 0,time2 = 0,time3 = 0,time4 = 0,HBNum = 0,SDNum = 0;
	
		Stm32_Clock_Init(9);

		delay_init(72);
		
 		uart_init(72,115200);
		
		LED_Init();
	

		KEY_Init();
		delay_ms(4000);
	//	delay_ms(3600);
		printf("\r\n");
		printf("      ,:::                               ;B@          \r\n");
		printf("     B@B@B@BZ                            7@B          \r\n");
		printf("     @BJ   @B5  rXO8L.   rL ,qP7     ;PE,rB@   7kOZY. \r\n");
		printf("     @@7   B@J X@EuU@BJ  B@B@B@@@   @B@B@B@B  GBZY5B@,\r\n");
		printf("     @B@B@B@P       Z@B  @BO   @Bi PB@   YB@       MBu\r\n");
		printf("     B@Orr:    2@BEu@BB  B@u   @@: M@M   :@B  kB@NUB@v\r\n");
		printf("     @B2       @@r  B@B  @BZ   @B; rB@r r@B@  B@:  @BU\r\n");
		printf("     B@u       7@B@@PBM  B@1   B@:  vB@B@7@B  vB@B@P@L\r\n");
		printf("                          .::::::.                \r\n");
		printf("                      :uk00Ur:   .., UB@r         \r\n");
		printf("                   v@BO7.      ,.     :P@.        \r\n");
		printf("                 1@M:        MB@B@.               \r\n");
		printf("               i@G         .@B@B@B,       @7      \r\n");
		printf("              F@.          @B@@u          ..      \r\n");
		printf("             qM            ,@Mi     ZB@L          \r\n");
		printf("            LN                     1B@F    r7     \r\n");
		printf("            q                       Gi     ,,  r  \r\n");
		printf("           :.                                  @  \r\n");
		printf("                 .u@@B@B@Er                   ,Br \r\n");
		printf("               :B@@@@@B@B@@@F                 B@k \r\n");
		printf("              LB@B@B@B@B@B@B@B:             ,B@@N \r\n");
		printf("             .B@B@@@@@B@@@@@B@BBi         iBB@B@r \r\n");
		printf("             B@B@B@B@B@B@B@B@B@B@B@0k5S0@B@B@B@B  \r\n");
		printf("            ,@@@B@B@B@B@B@B@B@B@B@B@@@B@B@@@B@BL  \r\n");
		printf("            .B@B@B@B@B@B@B@B@B@B@B@B@@@B@B@B@BM   \r\n");
		printf("             .B@@@B@B@B@B@@@B@@@B@B@B@B@B@@@B@    \r\n");
		printf("               B@@@B@B@@@B@@@B@B@B@B@B@B@B@B0     \r\n");
		printf("                u@B@B@B@@@B@@@B@@@B@B@B@B@B:      \r\n");
		printf("                  FB@B@B@B@B@B@B@MB@@B@B@i        \r\n");
		printf("                    :ZB@B@B@@@B@B@B@BBY.          \r\n");
		printf("                         :77vi:,..                \r\n");
//		delay_ms(2000);



		printf("Stm32_Clock_Init(72MHz).\r\n\r\n");
		delay_ms(200);
		printf("delay_init.\r\n\r\n");
		delay_ms(200);
		printf("uart_init(115200).\r\n\r\n");
		delay_ms(200);
		printf("LED_Init.\r\n\r\n");
		delay_ms(200);
		printf("KEY_Init.\r\n\r\n");
		delay_ms(300);
		printf("SYS Boot completly!.\r\n\r\n");







		

		printf("\r\n");
		printf("\r\n");
		printf("\r\n");
		printf("\r\n");
		printf("\r\n");
		printf("--------Help--------\r\n\r\n");
		printf("Panda>");
		while(1){
		 	if(USART_RX_STA&0x8000){
				len = USART_RX_STA&0x3fff;

				for(t = 0;t < len;t ++){
					USART1 -> DR = USART_RX_BUF[t];
					while((USART1 -> SR & 0X40) == 0);
				}
				printf("\r\nPanda>");
				if(((USART_RX_BUF[0]=='h' || USART_RX_BUF[0]=='H' )&& USART_RX_BUF[1]=='e' && USART_RX_BUF[2]=='l' && USART_RX_BUF[3]=='p' )&& len == 4){
					printf("	1.'L'to control LED e.g.L1up Lalldown\r\n");
					printf("	2.Press buttons on the board\r\n");
					printf("	3.'V'to check version\r\n");
					printf("Panda>");
					time ++;
				}
				if((USART_RX_BUF[0]=='l' || USART_RX_BUF[0]=='L') && (len == 4 || len == 6 || len == 8)){
					
					if(USART_RX_BUF[1]=='1'){
						if((USART_RX_BUF[2]=='u' || USART_RX_BUF[2]=='U') && len == 4){
							LED1 = 0;
							time ++;
						}else if((USART_RX_BUF[2]=='d' || USART_RX_BUF[2]=='D') && len == 6){
						 	LED1 = 1;
							time ++;
						}
						
					}
					if(USART_RX_BUF[1]=='2'){
						if((USART_RX_BUF[2]=='u' || USART_RX_BUF[2]=='U') && len == 4){
							LED2 = 0;
							time ++;
						}else if((USART_RX_BUF[2]=='d' || USART_RX_BUF[2]=='D') && len == 6){
						 	LED2 = 1;
							time ++;
						}
						
					}
					if(USART_RX_BUF[1]=='3'){
						if((USART_RX_BUF[2]=='u' || USART_RX_BUF[2]=='U') && len == 4){
							LED3 = 0;
							time ++;
						}else if((USART_RX_BUF[2]=='d' || USART_RX_BUF[2]=='D') && len == 6){
						 	LED3 = 1;
							time ++;
						}
					}
					if(USART_RX_BUF[1]=='4'){
						if((USART_RX_BUF[2]=='u' || USART_RX_BUF[2]=='U') && len == 4){
							LED4 = 0;
							time ++;
						}else if((USART_RX_BUF[2]=='d' || USART_RX_BUF[2]=='D') && len == 6){
						 	LED4 = 1;
							time ++;
						}
					}
					if((USART_RX_BUF[1]=='a' || USART_RX_BUF[1]=='A') && (len == 6 || len == 8)){
						if((USART_RX_BUF[4]=='u' || USART_RX_BUF[4]=='U') && len == 6){
							LED1 = 0;
							LED2 = 0;
							LED3 = 0;
							LED4 = 0;
							time ++;
						}else if((USART_RX_BUF[4]=='d' || USART_RX_BUF[4]=='D') && len == 8){
						 	LED1 = 1;
							LED2 = 1;
							LED3 = 1;
							LED4 = 1;
							time ++;
						}
					}
				//	printf("unknow command.");
					printf("\r\nPanda>");
				}
				if((USART_RX_BUF[0]=='v' || USART_RX_BUF[0]=='V' ) && len == 1){
					printf("	Panda V0.3 2015.5");
					printf("\r\nPanda>");
					time ++;
				}
				if((USART_RX_BUF[0]=='p' && USART_RX_BUF[1]=='a' && USART_RX_BUF[2]=='n' && USART_RX_BUF[3]=='d' && USART_RX_BUF[4]=='a' ) && len == 5){
					printf("	Designed by Joe.\r\n");
					printf("	Wait for more fun!");
					printf("\r\nPanda>");
					time ++;
				}
				if((USART_RX_BUF[0]=='l' && USART_RX_BUF[1]=='s' ) && len == 2){
					printf("	.");
					printf("\r\nPanda>");
					time ++;
				}
				if(time == 0){
					printf("unknow command!");
					printf("\r\nPanda>");

				}
				
				time = 0;
				USART_RX_STA = 0;
			}else{
				times ++;
				if(times % 20 == 0){
				//	time ++;
					t = KEY_Scan(1);
					if(t == KEY1_PRES){
						time1++;
						printf("KEY1_PRES %dtimes",time1);
						printf("\r\nPanda>");
					}
					if(t == KEY2_PRES){
						time2++;
						printf("KEY2_PRES %dtimes",time2);
						printf("\r\nPanda>");
					}
					if(t == KEY3_PRES){
						time3++;
						printf("KEY3_PRES %dtimes",time3);
						printf("\r\nPanda>");
					}
					if(t == KEY4_PRES){
						time4++;
						printf("KEY4_PRES %dtimes",time4);
						printf("\r\nPanda>");
					}
				//	printf("\r\nqiaosiyi\r\n");
				}
				if(times % 5000 == 0){	//if you want send bumb packet frequently ,set this parami by 200
					//missions
				}

				if(times % 30 == 0){
					//missions
				}
				delay_ms(10);
			}
		}
}
