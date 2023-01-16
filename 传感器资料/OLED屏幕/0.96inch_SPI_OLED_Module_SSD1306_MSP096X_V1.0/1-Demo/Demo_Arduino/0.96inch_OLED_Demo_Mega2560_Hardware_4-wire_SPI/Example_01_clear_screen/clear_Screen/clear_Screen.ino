// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of clearing screen to display black,white,red,green,blue.

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

void setup() 
{
    myoled.Init_LCD();
}

void loop() 
{    
    myoled.Fill_Screen(0,0,0);
    myoled.SH1106_Display();
    myoled.Fill_Screen(255,255,255);
    myoled.SH1106_Display();
    delay(3000);
    myoled.Fill_Screen(0,0,0);
    myoled.SH1106_Display();
    delay(1000);
    myoled.Fill_Screen(255,255,255);
    myoled.SH1106_Display();
    delay(1000);
    myoled.Fill_Screen(0);
    myoled.SH1106_Display();
    delay(1000);
    myoled.Fill_Screen(1);
    myoled.SH1106_Display();
   delay(3000);
}
