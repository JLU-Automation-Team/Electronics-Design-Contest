// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of clearing screen to display black,white,red,green,blue.

//Set the pins to the correct ones for your development shield or breakout board.
//when using the BREAKOUT BOARD only and using these software spi lines to the LCD,
//You can use any free pin to define the pins,
//if you don't need to control the LED pin,you can set it to 3.3Vand set the pin definition to -1.
//for example
//pin usage as follow:
//             CS   DC   RES   D1   D0     VCC     GND    
//Arduino Uno  A5   A3   A4    11   13   5V/3.3V   GND

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
#define D1    11   
#define D0    13   
#define RES   A4
#define LED   -1   //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

//the definiens of software spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI myoled(MODEL,CS,DC,-1,D1,RES,D0,LED);

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
