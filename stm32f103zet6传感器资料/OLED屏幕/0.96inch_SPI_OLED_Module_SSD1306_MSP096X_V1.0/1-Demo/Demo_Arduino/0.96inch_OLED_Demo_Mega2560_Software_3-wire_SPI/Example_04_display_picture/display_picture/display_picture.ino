// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of how to display BMP Monochrome picture 

//Set the pins to the correct ones for your development shield or breakout board.
//when using the BREAKOUT BOARD only and using these software spi lines to the LCD,
//You can use any free pin to define the pins,
//if you don't need to control the LED pin,you can set it to 3.3Vand set the pin definition to -1.
//for example
//pin usage as follow:
//                  CS   RES   D1   D0     VCC     GND    
//Arduino Mega2560  A5   A4    51   52   5V/3.3V   GND

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
#include "bmp.h"

//paramters define
#define MODEL SSD1306
#define CS    A5
#define DC    -1  //if you use 3-wire spi,you should set the DC to -1
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

void show_bmp(void)
{
   myoled.SH1106_Draw_Bitmap(0,0,128, 64, BMP1,1);  
   myoled.SH1106_Display();
   delay(1000);
   myoled.SH1106_Draw_Bitmap(0,0,128, 64, BMP2,1);  
   myoled.SH1106_Display();
   delay(1000);
   myoled.SH1106_Draw_Bitmap(0,0,128, 64, BMP3,1);  
   myoled.SH1106_Display();  
   delay(1000);    
}

void show_menu(void)
{
   u8 i;
  srand(123456);
  myoled.Set_Draw_color(1); 
  myoled.Draw_Fast_HLine(0, 10, myoled.Get_Display_Width()-1);
  myoled.SH1106_Display(); 
  myoled.Draw_Fast_VLine(myoled.Get_Display_Width()/2-1,11,myoled.Get_Display_Height()-10);
  myoled.SH1106_Display();
  myoled.Draw_Fast_HLine(myoled.Get_Display_Width()/2-1,10+(myoled.Get_Display_Height()-10)/2-1,myoled.Get_Display_Width()/2);
  myoled.SH1106_Display();
  show_string(0,1,1,0,1,1,"2018-08-25");
  show_string(78,1,1,0,1,1,"Saturday");
  show_string(14,myoled.Get_Display_Height()-1-10,1,0,1,1,"Cloudy");
  show_string(myoled.Get_Display_Width()/2-1+2,13,1,0,1,1,"TEMP");
  myoled.Draw_Circle(myoled.Get_Display_Width()-1-16, 27, 2);
  myoled.SH1106_Display();
  show_string(myoled.Get_Display_Width()-1-11,27,1,0,1,1,"C");
  show_string(myoled.Get_Display_Width()/2-1+14,21,1,0,2,1,"32");
  show_string(myoled.Get_Display_Width()/2-1+2,39,1,0,1,1,"PM2.5");
  show_string(myoled.Get_Display_Width()/2-1+5,48,1,0,2,1,"90");
  show_string(myoled.Get_Display_Width()/2-1+32,54,1,0,1,1,"ug/m3");
  myoled.SH1106_Draw_Bitmap(6,16,51, 32, BMP4,1);  
  myoled.SH1106_Display();  
  for(i=0;i<15;i++)
  {
    myoled.Set_Text_Size(2);
    myoled.Set_Draw_color(0);
    myoled.Fill_Rectangle(myoled.Get_Display_Width()/2-1+14, 21, myoled.Get_Display_Width()/2-1+14+16-1, 35);
    myoled.SH1106_Display(); 
    myoled.Fill_Rectangle(myoled.Get_Display_Width()/2-1+14+16, 21, myoled.Get_Display_Width()/2-1+14+16+16-1, 35);
    myoled.SH1106_Display(); 
    myoled.Fill_Rectangle(myoled.Get_Display_Width()/2-1+5, 48, myoled.Get_Display_Width()/2-1+5+16-1, 63);
    myoled.SH1106_Display();
    myoled.Fill_Rectangle(myoled.Get_Display_Width()/2-1+5+16, 48, myoled.Get_Display_Width()/2-1+5+16+16-1, 63);
    myoled.SH1106_Display();
    myoled.Set_Draw_color(1);
    myoled.Print_Number_Int(rand()%4, myoled.Get_Display_Width()/2-1+14, 21, 0, ' ',10);
    myoled.SH1106_Display(); 
    myoled.Print_Number_Int(rand()%10, myoled.Get_Display_Width()/2-1+14+16, 21, 0, ' ',10);
    myoled.SH1106_Display();   
    myoled.Print_Number_Int(rand()%10, myoled.Get_Display_Width()/2-1+5, 48, 0, ' ',10);
    myoled.SH1106_Display(); 
    myoled.Print_Number_Int(rand()%10, myoled.Get_Display_Width()/2-1+5+16, 48, 0, ' ',10);
    myoled.SH1106_Display();   
    delay(500);  
  } 
}

void setup() 
{
  myoled.Init_LCD();
  screen_clear(0);
}

void loop() 
{
  show_bmp();
  screen_clear(0);
  show_menu();
  screen_clear(0);
}
