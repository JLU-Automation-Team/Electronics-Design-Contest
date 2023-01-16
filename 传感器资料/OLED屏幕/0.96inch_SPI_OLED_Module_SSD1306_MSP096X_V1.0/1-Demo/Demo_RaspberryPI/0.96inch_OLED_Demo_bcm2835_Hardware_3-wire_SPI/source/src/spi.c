//////////////////////////////////////////////////////////////////////////////////////////////////////	 
//This program is for learning only,Not to be used for any other purpose 
//without the permission of the author
//Testing Hardware:Raspberry PI ,  basic frequency:1GHz
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
//This program uses the bcm2835 gpio library,
//so the pin definition using BCM coding
//=====================================power supply wiring===========================================//
// OLED Module                Raspberry PI    
//    VCC        connect       DC 5V/3.3V      //OLED power positive, Physical pin 1,2,4
//    GND        connect          GND          //OLED power ground,Physical pin 6,9,14,20,25,30,34,39
//======================================data line wiring=============================================//
//The default data bus type for this module is 3-wire SPI
// OLED Module                Raspberry PI 
//    D1         connect       19(bcm:10)      //OLED spi write signal
//======================================control line wiring==========================================//
// OLED Module                Raspberry PI 
//    CS         connect       24(bcm:8)       //OLED chip selection control signal
//    RES        connect        5(bcm:3)       //OLED reset control signal
//    D0         connect       23(bcm:11)      //OLED spi colck signal
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
#include "spi.h"

/*****************************************************************************
 * @name       :void SPI_WriteByte(uint8_t byte, uint8_t cmd)
 * @date       :2018-08-27 
 * @function   :Write a byte of data using RaspberryPi hardware SPI
 * @parameters :Byte:Data to be written 
                cmd:0-command
                    1-data				
 * @retvalue   :Data received by the bus
******************************************************************************/
void SPI_WriteByte(uint8_t byte, uint8_t cmd)
{
	uint16_t data=0;
	char txbuf[2]={0};
	data=((cmd<<15)|(byte<<7));
	txbuf[0]=(char)(data>>8);
	txbuf[1]=(char)(data&0xFF);
    	bcm2835_spi_transfern(txbuf,2);	
}

/*****************************************************************************
 * @name       :void SPI_SetSpeed(uint16_t divider)
 * @date       :2018-08-27 
 * @function   :Set hardware SPI Speed
 * @parameters :divider:the speed value
 * @retvalue   :None
******************************************************************************/
void SPI_SetSpeed(uint16_t divider)
{
	bcm2835_spi_setClockDivider(divider);
} 

/*****************************************************************************
 * @name       :void SPI_Init(void)	
 * @date       :2018-08-27
 * @function   :Initialize the RaspberryPi hardware SPI
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void SPI_Init(void)	
{
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);     //The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                  //The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8);    //The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                     //The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);     //the default   
}
