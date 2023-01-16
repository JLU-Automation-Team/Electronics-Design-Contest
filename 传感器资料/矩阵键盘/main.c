#include "led.h"
#include "delay.h"

#include "sys.h"
#include "usart.h"
#include "matrix_key.h"


 int main(void)
 {int a;		
	delay_init();	    	 //???????	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //??NVIC????2:2??????,2??????
	uart_init(115200);	 //??????115200
 	LED_Init();			     //LED?????
	 Matrix_Key_Init();
	 printf("ok\r\n");
 	while(1)
	{
		delay_ms(50);
		Matrix_Key_Test();
		a=num;
		
		printf("%d",N);
	}	 
 }
