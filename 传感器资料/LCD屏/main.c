#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"

 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��13
 TFTLCD��ʾʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 int main(void)
 {	 
 	u8 x=0;
	u8 lcd_id[12];			//���LCD ID�ַ���
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	LCD_Init();
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
  	while(1) 
	{		 
	  
		LCD_ShowNum(30,40,114514,6,24); 
		LCD_ShowString(30,70,200,16,16,"TEST:++");    					 
		LCD_ShowNum(30,90,x,3,24);    					 
	  delay_ms(1000);	
		LCD_Clear(WHITE);
		x++;
	} 
}
 