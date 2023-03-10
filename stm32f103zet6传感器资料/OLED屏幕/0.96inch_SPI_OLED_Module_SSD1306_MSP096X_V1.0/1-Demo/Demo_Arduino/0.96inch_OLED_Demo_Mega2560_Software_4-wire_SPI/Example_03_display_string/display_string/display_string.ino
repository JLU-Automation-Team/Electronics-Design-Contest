// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of displaying string

//Set the pins to the correct ones for your development shield or breakout board.
//when using the BREAKOUT BOARD only and using these software spi lines to the LCD,
//You can use any free pin to define the pins,
//if you don't need to control the LED pin,you can set it to 3.3Vand set the pin definition to -1.
//for example
//pin usage as follow:
//                  CS   DC   RES   D1   D0     VCC     GND    
//Arduino Mega2560  A5   A3   A4    51   52   5V/3.3V   GND

//Remember to set the pins to suit your display module!
/********************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE 
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**********************************************************************************/
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include "font.h"

//paramters define
#define MODEL SSD1306
#define CS    A5
#define DC    A3  
#define D1    51   
#define D0    52   
#define RES   A4
#define LED   -1   //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

//the definiens of software spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI myoled(MODEL,CS,DC,-1,D1,RES,D0,LED);

void screen_clear(unsigned char color)
{
  myoled.Fill_Screen(color);
  myoled.SH1106_Display();      
}

void show_string(unsigned char x,unsigned char y,unsigned char fc,unsigned char bc,unsigned fsize,unsigned char mode,unsigned char *string)
{
  myoled.Set_Text_colour(fc);   
  myoled.Set_Text_Size(fsize);
  myoled.Set_Text_Mode(mode);  
  myoled.Set_Text_Back_colour(bc);
  myoled.Print_String(string, x, y);
  myoled.SH1106_Display();
}

void ShowFont16(unsigned char x,unsigned char y,unsigned char *s,unsigned char mode)
{
  unsigned char i,j,k,tmp;
  unsigned short num;
  num = sizeof(cfont16)/sizeof(typFNT_GB16);
  for(i=0;i<num;i++)
  {
    if((pgm_read_byte(&cfont16[i].Index[0])==*s)&&(pgm_read_byte(&cfont16[i].Index[1])==*(s+1)))
    {
      for(j=0;j<32;j++)
      {
        if(mode)
        {
          tmp = pgm_read_byte(&cfont16[i].Msk[j]);
        }
        else
        {
          tmp = ~(pgm_read_byte(&cfont16[i].Msk[j]));
        }
        for(k=0;k<8;k++)
        {
          if(tmp&(0x80>>k))
          {
            myoled.Draw_Pixe(x+(j%2)*8+k, y+j/2,1);
          }
          else
          {
            myoled.Draw_Pixe(x+(j%2)*8+k, y+j/2,0);
          }
        }
      } 
      break;
    } 
  }
  myoled.SH1106_Display();
}

void ShowFont24(unsigned char x,unsigned char y,unsigned char *s,unsigned char mode)
{
  unsigned char i,j,k,tmp;
  unsigned short num;
  num = sizeof(cfont24)/sizeof(typFNT_GB24);
  for(i=0;i<num;i++)
  {
    if((pgm_read_byte(&cfont24[i].Index[0])==*s)&&(pgm_read_byte(&cfont24[i].Index[1])==*(s+1)))
    {
      for(j=0;j<72;j++)
      {
        if(mode)
        {
          tmp = pgm_read_byte(&cfont24[i].Msk[j]);
        }
        else
        {
          tmp = ~(pgm_read_byte(&cfont24[i].Msk[j]));
        }
        for(k=0;k<8;k++)
        {
          if(tmp&(0x80>>k))
          {
            myoled.Draw_Pixe(x+(j%3)*8+k, y+j/3,1);
          }
          else
          {
            myoled.Draw_Pixe(x+(j%3)*8+k, y+j/3,0);
          }
        }
      } 
      break;
    } 
  }
   myoled.SH1106_Display();
}

void ShowFont32(unsigned char x,unsigned char y,unsigned char *s,unsigned char mode)
{
  unsigned char i,j,k,tmp;
  unsigned short num;
  num = sizeof(cfont32)/sizeof(typFNT_GB32);
  for(i=0;i<num;i++)
  {
    if((pgm_read_byte(&cfont32[i].Index[0])==*s)&&(pgm_read_byte(&cfont32[i].Index[1])==*(s+1)))
    {
      for(j=0;j<128;j++)
      {
        if(mode)
        {
          tmp = pgm_read_byte(&cfont32[i].Msk[j]);
        }
        else
        {
          tmp = ~(pgm_read_byte(&cfont32[i].Msk[j]));
        }
        for(k=0;k<8;k++)
        {
          if(tmp&(0x80>>k))
          {
            myoled.Draw_Pixe(x+(j%4)*8+k, y+j/4,1);
          }
          else
          {
            myoled.Draw_Pixe(x+(j%4)*8+k, y+j/4,0);
          }
        }
      } 
      break;
    } 
  }
   myoled.SH1106_Display();
}

void show_string(void)
{
   show_string(0,0,1,1,1,1,"Hello"); 
   show_string(0,10,1,1,2,1,"Hello"); 
   show_string(0,28,1,1,3,1,"Hello"); 
   delay(1000);
   screen_clear(0);
   myoled.Set_Text_Size(1);
   myoled.Print_Number_Float(01234.56789, 2, 0, 0, '.', 0, ' ');
   myoled.SH1106_Display();
   myoled.Set_Text_Size(2);  
   myoled.Print_Number_Float(01234.56789, 2, 0, 10, '.', 0, ' ');
   myoled.SH1106_Display();
   myoled.Set_Text_Size(3);
   myoled.Print_Number_Float(01234.56789, 2, 0, 28, '.', 0, ' ');
   myoled.SH1106_Display();
   delay(1000);
   screen_clear(0);
   myoled.Set_Text_Size(1);
   myoled.Print_Number_Int(0xDEADBEF, 0, 0, 0, ' ',16); 
   myoled.SH1106_Display();
   myoled.Set_Text_Size(2);
   myoled.Print_Number_Int(0xDEADBEF, 0, 10, 0, ' ',16);
   myoled.SH1106_Display();
   myoled.Set_Text_Size(3);  
   myoled.Print_Number_Int(0xDEADBEF, 0, 28, 0, ' ',16);
   myoled.SH1106_Display(); 
   delay(1000); 
   screen_clear(0); 
}

void ShowCHinese(unsigned char x,unsigned char y,unsigned char hsize,unsigned char *str,unsigned char mode)
{ 
  while(*str!='\0')
  {
    if(hsize == 16)
    {
      ShowFont16(x,y,str,mode);
    }
    else if(hsize == 24)
    {
      ShowFont24(x,y,str,mode);
    }
    else if(hsize == 32)
    {
      ShowFont32(x,y,str,mode);
    }
    else
    {
      return;
    }
    x+=hsize;
    if(x>myoled.Get_Display_Width()-hsize)
    {
      x=0;
      y+=hsize;
    }
    str+=3;
  }     
}

void show_chinese(void)
{
   show_string(48,0,1,1,1,1,"16X16"); 
   myoled.Set_Draw_color(0); 
   myoled.Fill_Rectangle(0, 10, myoled.Get_Display_Width()-1, 36);
   myoled.SH1106_Display();
   ShowCHinese(16,15,16,"??????????????????",1);
   delay(1500);
   screen_clear(0);
   show_string(48,0,1,1,1,1,"24X24"); 
   ShowCHinese(16,25,24,"????????????",1);
   delay(1500);
   screen_clear(0);
   show_string(48,0,1,1,1,1,"32X32"); 
   ShowCHinese(0,21,32,"????????????",1);
   delay(1500);
   screen_clear(0);
}
void setup() 
{
  myoled.Init_LCD();
  myoled.Fill_Screen(0);
}

void loop() 
{
  show_string();
  show_chinese();
}
