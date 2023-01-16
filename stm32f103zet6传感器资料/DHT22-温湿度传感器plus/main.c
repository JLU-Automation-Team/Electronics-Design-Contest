#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "dht22.h"
 
 int main(void)
 {	
	float temperature = 0;  	    
	float humidity = 0;  
	delay_init();	    	 //???????	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //??NVIC????2:2??????,2??????
	uart_init(115200);        //??1,???9600
	delay_ms(1000);
	delay_ms(1000);
	while(DHT22_Init())    //DHT22???,??I/O??
	{
		printf("DHT22_Check Error!\r\n");
	}		
	DHT22_Read_Data(&temperature,&humidity);	//DHT22????????
  while(1)
	{
		/* ??2??? */
		delay_ms(1000);	
		delay_ms(1000);
		/* ??????? */
		DHT22_Read_Data(&temperature,&humidity);	
		/* ?????????(print??????1??) */
		printf("\r\ntemperature =  %.2f\r\n",temperature);	
		printf("humidity    =  %.2f\r\n",humidity);
	}
 }
