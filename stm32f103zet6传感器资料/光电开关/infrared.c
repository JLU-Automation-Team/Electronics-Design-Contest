
#include "stm32f10x.h"
#include "usart.h"
#include "sys.h"
#include "infrared.h"

void infrared_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//
	
	RCC_APB2PeriphClockCmd(infrared_RCC,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=infrared_PIN;  //
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //
	GPIO_Init(infrared_PORT,&GPIO_InitStructure); 	   /**/
}
