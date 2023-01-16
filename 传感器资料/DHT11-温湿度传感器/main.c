#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "dht11.h" 	 
 
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��29
 DHT11������ʪ�ȴ����� ʵ��     
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
 
 int main(void)
 {	 
	u8 t=0;			    
	u8 temperature;  	    
	u8 humidity;    	   

	delay_init();	    	 //��ʱ������ʼ��	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	  
 
	while(1)
	{	    	    
 							  
			DHT11_Read_Data(&temperature,&humidity);	//��ȡ��ʪ��ֵ					    
		printf("%d", humidity);	
		delay_ms(20);
      		
		}				   
	 	
	
}




