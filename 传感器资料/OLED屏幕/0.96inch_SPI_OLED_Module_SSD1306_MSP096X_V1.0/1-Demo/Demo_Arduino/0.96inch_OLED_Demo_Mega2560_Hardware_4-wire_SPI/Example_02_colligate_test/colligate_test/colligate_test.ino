// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of how to use most of the functions 
//of the library with a supported display modules.

//when using the BREAKOUT BOARD only and using these hardware spi lines to the LCD,
//the SDA pin and SCK pin is defined by the system and can't be modified.
//if you don't need to control the LED pin,you can set it to 3.3V and set the pin definition to -1.
//other pins can be defined by youself,for example
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

//paramters define
#define MODEL SSD1306
#define CS    A5
#define DC    A3   
#define RES   A4
#define LED   -1   //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

//the definiens of hardware spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI myoled(MODEL,CS,DC,RES,LED);

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

void show_text(void)
{
    show_string(10,0,1,0,2,1,"OLED TEST");
    show_string(22,18,1,0,2,1,"SSD1306");
    show_string(28,36,1,0,2,1,"64X128");
    show_string(19,52,1,0,1,1,"www.lcdwiki.com");
    delay(1500);
}

void draw_rectangle(void)
{
   unsigned char i; 
   myoled.Set_Draw_color(1); 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      myoled.Draw_Rectangle(i, i/2, myoled.Get_Display_Width()-1-i, myoled.Get_Display_Height()-1-i/2);
      myoled.SH1106_Display();
   }
   myoled.Fill_Screen(1);
   myoled.SH1106_Display(); 
   myoled.Set_Draw_color(0); 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      myoled.Draw_Rectangle(myoled.Get_Display_Width()/2-1-2-i, myoled.Get_Display_Height()/2-1-1-i/2, myoled.Get_Display_Width()/2-1+2+i, myoled.Get_Display_Height()/2-1+1+i/2);
      myoled.SH1106_Display();
   }
}

void fill_rectangle(void)
{
   unsigned char i; 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      if(!((i/4)%2))
      {
         myoled.Set_Draw_color(1);  
      }
      else
      {
        myoled.Set_Draw_color(0);   
      }
      myoled.Fill_Rectangle(i, i/2, myoled.Get_Display_Width()-1-i, myoled.Get_Display_Height()-1-i/2);
      myoled.SH1106_Display();
   } 
}

void draw_round_rectangle(void)
{
    unsigned char i; 
   myoled.Set_Draw_color(1); 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      myoled.Draw_Round_Rectangle(i, i/2, myoled.Get_Display_Width()-1-i, myoled.Get_Display_Height()-1-i/2,5);
      myoled.SH1106_Display();
   }
   myoled.Fill_Screen(1);
   myoled.SH1106_Display(); 
   myoled.Set_Draw_color(0); 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      myoled.Draw_Round_Rectangle(myoled.Get_Display_Width()/2-1-2-i, myoled.Get_Display_Height()/2-1-1-i/2, myoled.Get_Display_Width()/2-1+2+i, myoled.Get_Display_Height()/2-1+1+i/2,5);
      myoled.SH1106_Display();
   }  
}

void fill_round_rectangle(void)
{
   unsigned char i; 
   for(i=0;i<myoled.Get_Display_Width()/2;i+=4)
   {
      if(!((i/4)%2))
      {
         myoled.Set_Draw_color(1);  
      }
      else
      {
        myoled.Set_Draw_color(0);   
      }
      myoled.Fill_Round_Rectangle(i, i/2, myoled.Get_Display_Width()-1-i, myoled.Get_Display_Height()-1-i/2,5);
      myoled.SH1106_Display();
   } 
}

void draw_circle(void)
{
   unsigned char i; 
   myoled.Set_Draw_color(1); 
   for(i=0;i<myoled.Get_Display_Height()/2;i+=4)
   {
      myoled.Draw_Circle(myoled.Get_Display_Width()/2-1, myoled.Get_Display_Height()/2-1, myoled.Get_Display_Height()/2-i);
      myoled.SH1106_Display();
   }
   myoled.Fill_Screen(1);
   myoled.SH1106_Display(); 
   myoled.Set_Draw_color(0); 
   for(i=0;i<myoled.Get_Display_Height()/2-2;i+=4)
   {
      myoled.Draw_Circle(myoled.Get_Display_Width()/2-1, myoled.Get_Display_Height()/2-1,i+2);
      myoled.SH1106_Display();
   } 
}

void fill_circle(void)
{
   unsigned char i; 
   for(i=0;i<myoled.Get_Display_Height()/2;i+=4)
   {
      if((i/4)%2)
      {
         myoled.Set_Draw_color(1);  
      }
      else
      {
        myoled.Set_Draw_color(0);   
      }
      myoled.Fill_Circle(myoled.Get_Display_Width()/2-1, myoled.Get_Display_Height()/2-1,myoled.Get_Display_Height()/2-i);
      myoled.SH1106_Display();
   } 
}

void draw_triangle(void)
{
   unsigned char i; 
   myoled.Set_Draw_color(1); 
   for(i=0;i<myoled.Get_Display_Width()/4;i+=4)
   {
      myoled.Draw_Triangle(myoled.Get_Display_Width()/2-myoled.Get_Display_Width()/2/2-1+i, myoled.Get_Display_Height()-1-i, myoled.Get_Display_Width()/2-1, i,myoled.Get_Display_Width()/2+myoled.Get_Display_Width()/2/2-1-i,myoled.Get_Display_Height()-1-i);
      myoled.SH1106_Display();
   }
   myoled.Fill_Screen(1);
   myoled.SH1106_Display(); 
   myoled.Set_Draw_color(0); 
   for(i=0;i<myoled.Get_Display_Width()/4;i+=4)
   {
      myoled.Draw_Triangle(myoled.Get_Display_Width()/2-1-i, myoled.Get_Display_Height()/2-1+i, myoled.Get_Display_Width()/2-1, myoled.Get_Display_Height()/2-1-i,myoled.Get_Display_Width()/2-1+i,myoled.Get_Display_Height()/2-1+i);
      myoled.SH1106_Display();
   }
}

void fill_triangle(void)
{
  unsigned char i; 
   for(i=0;i<myoled.Get_Display_Width()/4;i+=4)
   {
      if((i/4)%2)
      {
         myoled.Set_Draw_color(1);  
      }
      else
      {
        myoled.Set_Draw_color(0);   
      }
      myoled.Fill_Triangle(myoled.Get_Display_Width()/2-myoled.Get_Display_Width()/2/2-1+i, myoled.Get_Display_Height()-1-i, myoled.Get_Display_Width()/2-1, i,myoled.Get_Display_Width()/2+myoled.Get_Display_Width()/2/2-1-i,myoled.Get_Display_Height()-1-i);
      myoled.SH1106_Display();
   }   
}

void draw_lines(void)
{
  unsigned char i; 
  myoled.Set_Draw_color(1);  
  for(i=8;i<myoled.Get_Display_Width();i+=8)
  {
      myoled.Draw_Fast_VLine(i, 0, myoled.Get_Display_Height());
      myoled.Draw_Fast_HLine(0, i/2, myoled.Get_Display_Width());
      myoled.SH1106_Display();
  }
  delay(1000);
  myoled.Invert_Display(1);
  delay(1000);
  myoled.Invert_Display(0);
}

unsigned long (*show_function[])(void) = 
{
    show_text,
    draw_rectangle,
    fill_rectangle,
    draw_round_rectangle,
    fill_round_rectangle,
    draw_circle,
    fill_circle,
    draw_triangle,
    fill_triangle,
    draw_lines,
};                                        
  
unsigned long show_total_time(void)
{
     uint16_t i;
     unsigned long time_start = micros();
     for(i = 0;i< 10;i++)
     {
        show_function[i](); 
        screen_clear(0); 
     }    
     return micros()- time_start; 
}

void show_end(unsigned long run_time)
{
    screen_clear(1); 
    myoled.Set_Draw_color(0);
    myoled.Fill_Round_Rectangle(5, 5, myoled.Get_Display_Width()-1-5, myoled.Get_Display_Height()-1-5,5);
    myoled.SH1106_Display();
    show_string(25,8,1,0,1,1,"Running over!");
    show_string(34,18,1,0,1,1,"That's ok!");
    show_string(16,28,1,0,1,1,"it will restart.");
    show_string(28,38,1,0,1,1,"runtime(us):");
    myoled.Print_Number_Int(run_time, 37, 48, 0, ' ', 10);
    myoled.SH1106_Display();
    delay(10000);   
    screen_clear(0); 
}

void setup() 
{
  myoled.Init_LCD();
  screen_clear(0);   
}

void loop() 
{
    unsigned long total_time;
    total_time = show_total_time();
    show_end(total_time); 
}
