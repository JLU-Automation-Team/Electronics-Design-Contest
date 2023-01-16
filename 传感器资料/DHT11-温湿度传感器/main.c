#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "dht11.h" 	 
 
 
/************************************************
 ALIENTEK精英STM32开发板实验29
 DHT11数字温湿度传感器 实验     
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
 
 int main(void)
 {	 
	u8 t=0;			    
	u8 temperature;  	    
	u8 humidity;    	   

	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	  
 
	while(1)
	{	    	    
 							  
			DHT11_Read_Data(&temperature,&humidity);	//读取温湿度值					    
		printf("%d", humidity);	
		delay_ms(20);
      		
		}				   
	 	
	
}




