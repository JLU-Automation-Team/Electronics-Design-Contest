#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "adc.h"
 
/************************************************
 ALIENTEK精英STM32开发板实验17
 ADC 实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

   
 int main(void)
 {	 
  u16 adcx;
	float temp;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();			 	
 	Adc_Init();		  		//ADC初始化

	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,130,200,16,16,"ADC_CH0_VAL:");	      	       
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_0,10);
		LCD_ShowxNum(156,130,adcx,4,16,0);//显示ADC的值
		delay_ms(250);	
	}
 }

