//////////////////////////////////////////////////////////////////////////////////////////////////////	 
//This program is for learning only,Not to be used for any other purpose 
//without the permission of the author
//Testing Hardware:Raspberry PI,  basic frequency:1GHz
//QDtech-OLED liquid crystal driver for Raspberry PI
//xiaofeng@ShenZhen QDtech co.,LTD
//Company Website:www.qdtft.com
//Taobao Website:http://qdtech.taobao.com
//wiki Technology Website:http://www.lcdwiki.com
//We provide technical support,Any technical questions are welcome to 
//exchange and study at any time
//Fixed telephone (fax):+86 0755-23594567 
//cell-phone:15989313508(Mr Feng)
//E-mail:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//Technical Support QQ:3002773612  3002778157
//Technical Exchange QQ group:324828016
//Date:2018/9/6
//Version:V1.0
//Copyright reserved, piracy must be investigated
//Copyright(C) ShenZhen QDtech co.,LTD 2018-2028
//All rights reserved
/****************************************************************************************************
//This program uses the wiringPi gpio library,
//so the pin definition using wiringPi coding
//=====================================power supply wiring===========================================//
// OLED Module                  Raspberry PI    
//    VCC        connect         DC 5V/3.3V        //OLED power positive, Physical pin 1,2,4
//    GND        connect            GND            //OLED power ground,Physical pin 6,9,14,20,25,30,34,39
//======================================data line wiring=============================================//
//The default data bus type for this module is 4-wire SPI
// OLED Module                  Raspberry PI 
//    D1         connect       19(wiringPi:12)     //OLED spi write signal
//======================================control line wiring==========================================//
// OLED Module                  Raspberry PI 
//    CS         connect       24(wiringPi:10)     //OLED chip selection control signal
//    RES        connect        5(wiringPi:9)      //OLED reset control signal
//    DC         connect        3(wiringPi:8)      //OLED data or command selection control signal
//    D0         connect       23(wiringPi:14)     //OLED spi colck signal
//========================================touch screen wiring========================================//
//This module has no touch function,so it don't need touch screen wiring
*****************************************************************************************************/	
/****************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************************************/		
#include <stdlib.h>
#include <stdio.h>
#include "oled.h"
#include "delay.h"
#include "gui.h"
#include "type.h"
#include "test.h"
#include "bmp.h"

/*****************************************************************************
 * @name       :void TEST_MainPage(void)
 * @date       :2018-08-27 
 * @function   :Drawing the main Interface of the Comprehensive Test Program
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_MainPage(void)
{	
	GUI_ShowString(28,0,"OLED TEST",16,1);
	GUI_ShowString(12,16,"0.96\" SSD1306",16,1);
	GUI_ShowString(40,32,"64X128",16,1);
	GUI_ShowString(4,48,"www.lcdwiki.com",16,1);
	delay_ms(1500);		
	delay_ms(1500);
}

/*****************************************************************************
 * @name       :void Test_Color(void)
 * @date       :2018-08-27 
 * @function   :Color fill test(white,black)
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Color(void)
{
	 GUI_Fill(0,0,WIDTH-1,HEIGHT-1,0);
	 GUI_ShowString(10,10,"BLACK",16,1);
	 delay_ms(1000);	
	 GUI_Fill(0,0,WIDTH-1,HEIGHT-1,1);
	 delay_ms(1500);
}

/*****************************************************************************
 * @name       :void Test_Rectangular(void))
 * @date       :2018-08-27
 * @function   :Rectangular display and fill test
				Display black,white rectangular boxes in turn,1000 
				milliseconds later,Fill the rectangle in black,white in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Rectangular(void)
{
	GUI_Fill(0,0,WIDTH/2-1,HEIGHT-1,0);
	GUI_Fill(WIDTH/2,0,WIDTH-1,HEIGHT-1,1);
	GUI_DrawRectangle(5, 5, WIDTH/2-1-5, HEIGHT-1-5,1);
	GUI_DrawRectangle(WIDTH/2-1+5, 5, WIDTH-1-5, HEIGHT-1-5,0);
	delay_ms(1000);
	GUI_FillRectangle(5, 5, WIDTH/2-1-5, HEIGHT-1-5,1);
	GUI_FillRectangle(WIDTH/2-1+5, 5, WIDTH-1-5, HEIGHT-1-5,0);
	delay_ms(1500);
}


/*****************************************************************************
 * @name       :void Test_Circle(void)
 * @date       :2018-08-27 
 * @function   :circular display and fill test
				Display black,white circular boxes in turn,1000 
				milliseconds later,Fill the circular in black,white in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Circle(void)
{
	GUI_Fill(0,0,WIDTH/2-1,HEIGHT-1,0);
	GUI_Fill(WIDTH/2,0,WIDTH-1,HEIGHT-1,1);
	GUI_DrawCircle(WIDTH/2/2-1, HEIGHT/2-1, 1, 27);
	GUI_DrawCircle(WIDTH/2+WIDTH/2/2-1, HEIGHT/2-1, 0, 27);
	delay_ms(1000);
	GUI_FillCircle(WIDTH/2/2-1, HEIGHT/2-1, 1, 27);
	GUI_FillCircle(WIDTH/2+WIDTH/2/2-1, HEIGHT/2-1, 0, 27);
	delay_ms(1500);
}

/*****************************************************************************
 * @name       :void Test_Triangle(void)
 * @date       :2018-08-27 
 * @function   :triangle display and fill test
				Display black,white triangle boxes in turn,1000 
				milliseconds later,Fill the triangle in black,white in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Triangle(void)
{
	GUI_Fill(0,0,WIDTH/2-1,HEIGHT-1,0);
	GUI_Fill(WIDTH/2,0,WIDTH-1,HEIGHT-1,1);
	GUI_DrawTriangel(5,HEIGHT-1-5,WIDTH/2/2-1,5,WIDTH/2-1-5,HEIGHT-1-5,1);
	GUI_DrawTriangel(WIDTH/2-1+5,HEIGHT-1-5,WIDTH/2+WIDTH/2/2-1,5,WIDTH-1-5,HEIGHT-1-5,0);
	delay_ms(1000);
	GUI_FillTriangel(5,HEIGHT-1-5,WIDTH/2/2-1,5,WIDTH/2-1-5,HEIGHT-1-5,1);
	GUI_FillTriangel(WIDTH/2-1+5,HEIGHT-1-5,WIDTH/2+WIDTH/2/2-1,5,WIDTH-1-5,HEIGHT-1-5,0);
	delay_ms(1500);
}


/*****************************************************************************
 * @name       :void TEST_English(void)
 * @date       :2018-08-27 
 * @function   :English display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_English(void)
{
	GUI_ShowString(0,5,"6x8:abcdefghijklmnopqrstuvwxyz",8,1);
	GUI_ShowString(0,25,"8x16:abcdefghijklmnopqrstuvwxyz",16,1);
	delay_ms(1000);
	GUI_ShowString(0,5,"6x8:ABCDEFGHIJKLMNOPQRSTUVWXYZ",8,1);
	GUI_ShowString(0,25,"8x16:ABCDEFGHIJKLMNOPQRSTUVWXYZ",16,1);
	delay_ms(1500);
}

/*****************************************************************************
 * @name       :void TEST_Number_Character(void) 
 * @date       :2018-08-27 
 * @function   :number and character display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_Number_Character(void) 
{
	GUI_Fill(0,0,WIDTH-1,HEIGHT/2-1,0);
	GUI_ShowString(0,0,"6x8:!\"#$%&'()*+,-./:;<=>?@[]\\^_`~{}|",8,1);
	GUI_ShowNum(30,16,1234567890,10,8,1);
	delay_ms(1000);
	OLED_Clear(0); 
  GUI_ShowString(0,0,"8x16:!\"#$%&'()*+,-./:;<=>?@[]\\^_`~{}|",16,1);
	GUI_ShowNum(40,32,1234567890,10,16,1);
	delay_ms(1500);
	OLED_Clear(0);
}

/*****************************************************************************
 * @name       :void TEST_Chinese(void)
 * @date       :2018-08-27
 * @function   :chinese display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_Chinese(void)
{	
	GUI_ShowString(45,0,"16x16",8,1);
	GUI_ShowCHinese(16,20,16,"全动电子技术",1);
	delay_ms(1000);
	OLED_Clear(0);
	GUI_ShowString(45,0,"24x24",8,1);
	GUI_ShowCHinese(16,20,24,"全动电子",1);
	delay_ms(1000);
	OLED_Clear(0);
	GUI_ShowString(45,0,"32x32",8,1);
	GUI_ShowCHinese(0,20,32,"全动电子",1);	
  delay_ms(1000);
	OLED_Clear(0);
}

/*****************************************************************************
 * @name       :void TEST_BMP(void)
 * @date       :2018-08-27 
 * @function   :BMP monochromatic picture display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_BMP(void)
{
	GUI_DrawBMP(0,0,128,64, BMP2, 1);
	delay_ms(1000);
	GUI_DrawBMP(0,0,128,64, BMP3, 1);
	delay_ms(1000);
	GUI_DrawBMP(0,0,128,64, BMP4, 1);
	delay_ms(1000);
}

/*****************************************************************************
 * @name       :void TEST_Menu1(void)
 * @date       :2018-08-27 
 * @function   :Chinese selection menu display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_Menu1(void)
{ 
	GUI_Fill(0,0,WIDTH-1,15,1);
	GUI_ShowCHinese(32,0,16,"系统设置",0);
	GUI_DrawCircle(10, 24, 1,6);
	GUI_DrawCircle(10, 24, 1,3);
	GUI_DrawCircle(10, 40, 1,6);
	GUI_DrawCircle(10, 40, 1,3);
	GUI_DrawCircle(10, 56, 1,6);
	GUI_DrawCircle(10, 56, 1,3);
	GUI_ShowString(20,16,"A.",16,1);
	GUI_ShowCHinese(36,16,16,"音量设置",1);
	GUI_ShowString(20,32,"B.",16,1);
	GUI_ShowCHinese(36,32,16,"颜色设置",1);
	GUI_ShowString(20,48,"C.",16,1);
	GUI_ShowCHinese(36,48,16,"网络设置",1);
	GUI_DrawRectangle(0, 0,WIDTH-1,HEIGHT-1,1);
	GUI_DrawLine(WIDTH-1-10, 15, WIDTH-1-10, HEIGHT-1,1);
	GUI_FillTriangel(WIDTH-1-9,20,WIDTH-1-5,16,WIDTH-1-1,20,1);
	GUI_FillTriangel(WIDTH-1-9,HEIGHT-1-5,WIDTH-1-5,HEIGHT-1-1,WIDTH-1-1,HEIGHT-1-5,1);
	GUI_FillCircle(10, 24, 1,3);
	GUI_Fill(20,16,99,31,1);
	GUI_ShowString(20,16,"A.",16,0);
	GUI_ShowCHinese(36,16,16,"音量设置",0);
	GUI_Fill(WIDTH-1-9,23,WIDTH-1-1,28,1);
	delay_ms(1500);
	GUI_FillCircle(10, 24, 0,3);
	GUI_DrawCircle(10, 24, 1,3);
	GUI_Fill(20,16,99,31,0);
	GUI_ShowString(20,16,"A.",16,1);
	GUI_ShowCHinese(36,16,16,"音量设置",1);
	GUI_Fill(WIDTH-1-9,23,WIDTH-1-1,28,0);
	GUI_FillCircle(10, 40, 1,3);
	GUI_Fill(20,32,99,47,1);
	GUI_ShowString(20,32,"B.",16,0);
	GUI_ShowCHinese(36,32,16,"颜色设置",0);
	GUI_Fill(WIDTH-1-9,37,WIDTH-1-1,42,1);
	delay_ms(1500);
	GUI_FillCircle(10, 40, 0,3);
	GUI_DrawCircle(10, 40, 1,3);
	GUI_Fill(20,32,99,47,0);
	GUI_ShowString(20,32,"B.",16,1);
	GUI_ShowCHinese(36,32,16,"颜色设置",1);
	GUI_Fill(WIDTH-1-9,37,WIDTH-1-1,42,0);
	GUI_FillCircle(10, 56, 1,3);
	GUI_Fill(20,48,99,63,1);
	GUI_ShowString(20,48,"C.",16,0);
	GUI_ShowCHinese(36,48,16,"网络设置",0);
	GUI_Fill(WIDTH-1-9,HEIGHT-1-13,WIDTH-1-1,HEIGHT-1-8,1);
	delay_ms(1500);
}

/*****************************************************************************
 * @name       :void TEST_Menu2(void)
 * @date       :2018-08-27 
 * @function   :English weather interface display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TEST_Menu2(void)
{
	uint8_t i;
	srand(123456);
	GUI_DrawLine(0, 10, WIDTH-1, 10,1);
	GUI_DrawLine(WIDTH/2-1,11,WIDTH/2-1,HEIGHT-1,1);
	GUI_DrawLine(WIDTH/2-1,10+(HEIGHT-10)/2-1,WIDTH-1,10+(HEIGHT-10)/2-1,1);
	GUI_ShowString(0,1,"2018-08-25",8,1);
	GUI_ShowString(78,1,"Saturday",8,1);
	GUI_ShowString(14,HEIGHT-1-10,"Cloudy",8,1);
	GUI_ShowString(WIDTH/2-1+2,13,"TEMP",8,1);
	GUI_DrawCircle(WIDTH-1-19, 25, 1,2);
	GUI_ShowString(WIDTH-1-14,20,"C",16,1);
	GUI_ShowString(WIDTH/2-1+9,20,"32.5",16,1);
	GUI_ShowString(WIDTH/2-1+2,39,"PM2.5",8,1);
	GUI_ShowString(WIDTH/2-1+5,46,"90ug/m3",16,1);
	GUI_DrawBMP(6,16,51,32, BMP5, 1);
	for(i=0;i<15;i++)
	{
		GUI_ShowNum(WIDTH/2-1+9,20,rand()%4,1,16,1);
		GUI_ShowNum(WIDTH/2-1+9+8,20,rand()%10,1,16,1);
		GUI_ShowNum(WIDTH/2-1+9+8+16,20,rand()%10,1,16,1);
		GUI_ShowNum(WIDTH/2-1+5,46,rand()%10,1,16,1);
		GUI_ShowNum(WIDTH/2-1+5+8,46,rand()%10,1,16,1);
    	delay_ms(500);	
	}
}



