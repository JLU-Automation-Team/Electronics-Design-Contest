#include "openmv.h"
int openmv[5];//stm32接收数据数组
int16_t X=90;
int16_t Y;
int i=0;
void Openmv_Receive_Data(int16_t data)//接收Openmv传过来的数据
{
	static u8 state = 0;
	if(state==0&&data==0x2C)
	{
		state=1;
		openmv[0]=data;
	}
	else if(state==1&&data==0x26)
	{
		state=2;
		openmv[1]=data;
	}
	else if(state==2)
	{
		state=3;
		openmv[2]=data;
	}
	else if(state==3)
	{
		state = 4;
		openmv[3]=data;
	}
	else if(state==4)
	{
        state = 5;
        openmv[4]=data;
	}
	else if(state==4)		//检测是否接受到结束标志
	{
        if(data == 0x5B)
        {
            state = 0;
            openmv[4]=data;
            Openmv_Data();
					
        }
        else if(data != 0x5B)
        {
            state = 0;
            for(i=0;i<5;i++)
            {
                openmv[i]=90;
            }           
        }
	}    
	else
		{
			state = 0;
            for(i=0;i<5;i++)
            {
                openmv[i]=90;
            }
		}
}

void Openmv_Data(void)
{  
    X=openmv[2];
		}

