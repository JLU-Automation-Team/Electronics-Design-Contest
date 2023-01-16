#include "matrix_key.h"
#include "delay.h"
#include "sys.h"

/************************************
        按键表盘为：		1  2  3  4 
							5  6  7  8
							9  0  A  B
							C  D  E  F 
************************************/

int16_t num=0;
int16_t N=0;
unsigned char Y1,Y2,Y3,Y4;

void Matrix_Key_Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;   
   RCC_APB2PeriphClockCmd(X1_RCC|X2_RCC|X3_RCC|X4_RCC|Y1_RCC|Y2_RCC|Y3_RCC|Y4_RCC|RCC_APB2Periph_AFIO, ENABLE);
   GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	
/*****************************4行输出*********************************************/
   GPIO_InitStructure.GPIO_Pin =  X1_GPIO_PIN ;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(X1_GPIO_PORT, &GPIO_InitStructure);
    
   GPIO_InitStructure.GPIO_Pin =  X2_GPIO_PIN ;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(X2_GPIO_PORT, &GPIO_InitStructure);
    
   GPIO_InitStructure.GPIO_Pin =  X3_GPIO_PIN ;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(X3_GPIO_PORT, &GPIO_InitStructure);
	
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Pin = X4_GPIO_PIN ;    
   GPIO_Init(X4_GPIO_PORT, &GPIO_InitStructure);
   
/**************************************4列输入*************************************/
   GPIO_InitStructure.GPIO_Pin =  Y1_GPIO_PIN ;   
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(Y1_GPIO_PORT, &GPIO_InitStructure);	
   
   GPIO_InitStructure.GPIO_Pin =  Y2_GPIO_PIN ;   
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(Y2_GPIO_PORT, &GPIO_InitStructure);	
   
   GPIO_InitStructure.GPIO_Pin =  Y3_GPIO_PIN ;   
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(Y3_GPIO_PORT, &GPIO_InitStructure);	
	
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Pin = Y4_GPIO_PIN;      
   GPIO_Init(Y4_GPIO_PORT, &GPIO_InitStructure);	
}

int Matrix_Key_Scan(void)
{
	uchar KeyVal = KEY_ERR;
	static char key_down = 0;
	GPIO_SetBits(X1_GPIO_PORT,X1_GPIO_PIN);  //先让X1输出高
	GPIO_SetBits(X2_GPIO_PORT,X2_GPIO_PIN);  //先让X2输出高
	GPIO_SetBits(X3_GPIO_PORT,X3_GPIO_PIN);  //先让X3输出高
	GPIO_SetBits(X4_GPIO_PORT,X4_GPIO_PIN);  //先让X4输出高

	if ((GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y2_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y3_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y4_GPIO_PIN)==1))
	{
		delay_ms(10);//去抖动 
		if ((GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y2_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y3_GPIO_PIN)==1) || (GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y4_GPIO_PIN)==1))
		{
			if (key_down == 0)
			{	
				key_down = 1;		//重复按标志位
				
				GPIO_SetBits(X1_GPIO_PORT,X1_GPIO_PIN);
				GPIO_ResetBits(X2_GPIO_PORT,X2_GPIO_PIN);
				GPIO_ResetBits(X3_GPIO_PORT,X3_GPIO_PIN);
				GPIO_ResetBits(X4_GPIO_PORT,X4_GPIO_PIN);
					 
				Y1=GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN);
				Y2=GPIO_ReadInputDataBit(Y2_GPIO_PORT,Y2_GPIO_PIN);
				Y3=GPIO_ReadInputDataBit(Y3_GPIO_PORT,Y3_GPIO_PIN);
				Y4=GPIO_ReadInputDataBit(Y4_GPIO_PORT,Y4_GPIO_PIN);
				
				if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=4;
				if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=8;
				if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=12;
				if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=16;
/**************************************************/		
				
				GPIO_ResetBits(X1_GPIO_PORT,X1_GPIO_PIN);
				GPIO_SetBits(X2_GPIO_PORT,X2_GPIO_PIN);
				GPIO_ResetBits(X3_GPIO_PORT,X3_GPIO_PIN);
				GPIO_ResetBits(X4_GPIO_PORT,X4_GPIO_PIN);
								
				Y1=GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN);
				Y2=GPIO_ReadInputDataBit(Y2_GPIO_PORT,Y2_GPIO_PIN);
				Y3=GPIO_ReadInputDataBit(Y3_GPIO_PORT,Y3_GPIO_PIN);
				Y4=GPIO_ReadInputDataBit(Y4_GPIO_PORT,Y4_GPIO_PIN);
				
				if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=3;
				if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=7;
				if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=11;
				if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=15;
			
/**************************************************/
				
				GPIO_ResetBits(X1_GPIO_PORT,X1_GPIO_PIN);
				GPIO_ResetBits(X2_GPIO_PORT,X2_GPIO_PIN);
				GPIO_SetBits(X3_GPIO_PORT,X3_GPIO_PIN);
				GPIO_ResetBits(X4_GPIO_PORT,X4_GPIO_PIN);   

				Y1=GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN);
				Y2=GPIO_ReadInputDataBit(Y2_GPIO_PORT,Y2_GPIO_PIN);
				Y3=GPIO_ReadInputDataBit(Y3_GPIO_PORT,Y3_GPIO_PIN);
				Y4=GPIO_ReadInputDataBit(Y4_GPIO_PORT,Y4_GPIO_PIN);
				
				if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=2;
				if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=6;
				if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=10;
				if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=14;	
				
/**************************************************/
				
				GPIO_ResetBits(X1_GPIO_PORT,X1_GPIO_PIN);
				GPIO_ResetBits(X2_GPIO_PORT,X2_GPIO_PIN); 
				GPIO_ResetBits(X3_GPIO_PORT,X3_GPIO_PIN); 
				GPIO_SetBits(X4_GPIO_PORT,X4_GPIO_PIN); 
				
				Y1=GPIO_ReadInputDataBit(Y1_GPIO_PORT,Y1_GPIO_PIN);
				Y2=GPIO_ReadInputDataBit(Y2_GPIO_PORT,Y2_GPIO_PIN);
				Y3=GPIO_ReadInputDataBit(Y3_GPIO_PORT,Y3_GPIO_PIN);
				Y4=GPIO_ReadInputDataBit(Y4_GPIO_PORT,Y4_GPIO_PIN);
				
				if(Y1==1&&Y2==0&&Y3==0&&Y4==0)
					KeyVal=1;
				if(Y1==0&&Y2==1&&Y3==0&&Y4==0)
					KeyVal=5;
				if(Y1==0&&Y2==0&&Y3==0&&Y4==1)
					KeyVal=13;
				if(Y1==0&&Y2==0&&Y3==1&&Y4==0)
					KeyVal=9;
			}
		}
	}
	else
	{
		key_down = 0;	//没有检测到有按键按下，则让连按标志位归0
	}
	
	return KeyVal;
}

void Matrix_Key_Test(void) 
{

	  num = Matrix_Key_Scan();
	  switch(num)
	  { 
				case KEY_ERR:break;
        case 1: {printf("%d",num); 
					       N=1;
					       break;	}				  				      
				case 2: {printf("%d",num); 
					       N=2;
					       break;	}		  				       
				case 3:{printf("%d",num); 
					       N=3;
					       break;	}					  				     
				case 4: {printf("%d",num); 
					       N=4;
					       break;	}	    
				case 5: {printf("%d",num); 
					       N=5;
					       break;	}	
				case 6: {printf("%d",num); 
					       N=6;
					       break;	}	     
				case 7: {printf("%d",num); 
					       N=7;
					       break;	}	
				case 8: {printf("%d",num); 
					       N=8;
					       break;	}	
				case 9: {printf("%d",num); 
					       N=9;
					       break;	}	 		       
				case 10: {printf("%d",num); 
					       N=10;
					       break;	}		     	
        case 11: {printf("%d",num); 
					       N=11;
					       break;	}	   		
				case 12: {printf("%d",num); 
					       N=12;
					       break;	}	
				case 13: {printf("%d",num); 
					       N=13;
					       break;	}				      	
        case 14: {printf("%d",num); 
					       N=14;
					       break;	}		 				       	
				case 15: {printf("%d",num); 
					       N=15;
					       break;	}	     
				case 16: {printf("%d",num); 
					       N=16;
					       break;	}	
      }
	
}
