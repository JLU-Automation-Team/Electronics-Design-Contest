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
//The default data bus type for this module is 3-wire SPI
// OLED Module                  Raspberry PI 
//    D1         connect       19(wiringPi:12)     //OLED spi write signal
//======================================control line wiring==========================================//
// OLED Module                  Raspberry PI 
//    CS         connect       24(wiringPi:10)     //OLED chip selection control signal
//    RES        connect        5(wiringPi:9)      //OLED reset control signal
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
#ifndef __TEST_H__
#define __TEST_H__
void TEST_MainPage(void);
void Test_Color(void);
void Test_Rectangular(void);
void Test_Circle(void);
void Test_Triangle(void);
void TEST_English(void);
void TEST_Number_Character(void);
void TEST_Chinese(void);
void TEST_BMP(void);
void TEST_Menu1(void);
void TEST_Menu2(void);
#endif
