//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32H743IIT6,正点原子Apollo STM32F4/F7开发板,主频400MHZ，晶振25MHZ
//QDtech-OLED液晶驱动 for STM32
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtft.com
//淘宝网站：http://qdtech.taobao.com
//wiki技术网站：http://www.lcdwiki.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//技术支持QQ:3002773612  3002778157
//技术交流QQ群:324828016
//创建日期:2018/8/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
// OLED模块               STM32单片机
//   VCC         接       DC 5V/3.3V      //OLED屏电源正
//   GND         接          GND          //OLED屏电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为4线制SPI
// OLED模块               STM32单片机
//   D1          接          PB15         //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块               STM32单片机
//   CS          接          PD11         //OLED屏片选控制信号
//   RES         接          PD12         //OLED屏复位控制信号
//   DC          接          PD5          //OLED屏数据/命令选择控制信号
//   D0          接          PB13         //OLED屏SPI时钟信号
//=========================================触摸屏接线=========================================//
//本模块不带触摸功能，所以不需要触摸屏接线
****************************************************************************************************/	
/***************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
****************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////	 
//
//存储图片数据，图片大小为128*64像素
//逐行式，顺向（高位在前）
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __BMP_H
#define __BMP_H
unsigned char BMP2[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7F,0xE0,0x03,0x91,0x1C,0x38,0x18,0x00,0x70,0x00,0xFF,0xFC,0x00,0x07,0xFF,0xFE,
	0x66,0x60,0x04,0x5B,0x22,0x44,0x14,0x01,0x8C,0x01,0x7F,0xFA,0x00,0x04,0x00,0x02,
	0x36,0xC0,0x08,0x15,0x40,0x80,0x52,0x02,0x02,0x01,0xBF,0xF6,0x00,0x3D,0xB6,0xDA,
	0x1F,0x80,0x88,0x11,0x40,0x80,0x34,0x04,0x71,0x01,0xDF,0xEE,0x00,0x25,0xB6,0xDA,
	0x0F,0x02,0x88,0x11,0x40,0x80,0x18,0x00,0x88,0x01,0xE0,0x1E,0x00,0x25,0xB6,0xDA,
	0x06,0x0A,0x88,0x11,0x40,0x80,0x34,0x01,0x04,0x01,0xDF,0xEE,0x00,0x25,0xB6,0xDA,
	0x06,0x2A,0x88,0x11,0x40,0x80,0x52,0x00,0x20,0x01,0xBF,0xF6,0x00,0x3D,0xB6,0xDA,
	0x06,0xAA,0x84,0x51,0x22,0x44,0x14,0x00,0x70,0x01,0x7F,0xFA,0x00,0x04,0x00,0x02,
	0x06,0xAA,0x83,0x91,0x1C,0x38,0x18,0x00,0x20,0x00,0xFF,0xFC,0x00,0x07,0xFF,0xFE,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x1F,0xFC,0x00,0x3F,0xFC,0x7F,0xF0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x3F,0xFE,0x00,0x7F,0xFC,0xFF,0xF8,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x30,0x06,0x00,0x60,0x00,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x1B,0x30,0x06,0x00,0x60,0x00,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x33,0x30,0x06,0x00,0x60,0x00,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x63,0x30,0x06,0x18,0x60,0x00,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xC3,0x30,0x06,0x18,0x7F,0xFC,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x83,0x30,0x06,0x00,0x7F,0xFC,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x3F,0xFE,0x00,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x3F,0xFE,0x00,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x00,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x18,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x18,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x00,0x00,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x00,0x60,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x30,0x06,0x00,0x60,0x0C,0xC0,0x18,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x3F,0xFE,0x00,0x7F,0xFC,0xFF,0xF8,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x1F,0xFC,0x00,0x3F,0xF8,0x7F,0xF0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xF9,0xE3,0x0F,0x00,0xF1,0xE0,0x1E,0x3C,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0x0A,0x15,0x10,0x81,0x0A,0x10,0x21,0x42,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x12,0x11,0x10,0x81,0x0A,0x00,0x21,0x40,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x22,0x11,0x1F,0x81,0x0B,0xE0,0x21,0x7C,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x42,0x11,0x10,0x81,0x0A,0x10,0x21,0x42,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x82,0x11,0x10,0x99,0x0A,0x13,0x21,0x42,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0xF9,0xE7,0xCF,0x18,0xF1,0xE3,0x1E,0x3C,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x41,0x1C,0x41,0x41,0x00,0x00,0x00,0x00,0x81,0x00,0x00,0x00,0x00,0x82,0x7C,0x82,
	0x63,0x22,0x61,0x41,0x00,0x00,0x00,0x00,0xF1,0x00,0x00,0x00,0x00,0xC6,0x82,0xC2,
	0x55,0x41,0x51,0x41,0x00,0x00,0x00,0x00,0x81,0x00,0x00,0x00,0x00,0xAA,0x80,0xA2,
	0x49,0x7E,0x49,0x41,0x00,0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0x00,0x92,0x7C,0x92,
	0x41,0x40,0x45,0x41,0x00,0x00,0x00,0x00,0x81,0x00,0x00,0x00,0x00,0x82,0x02,0x8A,
	0x41,0x21,0x43,0x22,0x00,0x00,0x00,0x00,0xF1,0x00,0x00,0x00,0x00,0x82,0x82,0x86,
	0x41,0x1E,0x41,0x1C,0x00,0x00,0x00,0x00,0x81,0x00,0x00,0x00,0x00,0x82,0x7C,0x82,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char BMP3[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0xF8,0x03,0xFF,0xF8,0x03,0xC0,0xF0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xFE,0x03,0xFF,0xF8,0x07,0xF3,0xFC,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x18,0x03,0x03,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x01,0x83,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x00,0x00,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x00,0x00,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x01,0x83,0x7F,0xC0,0x07,0xFF,0xFC,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x03,0x03,0xFF,0xF0,0x03,0xFF,0xF8,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x18,0x06,0x03,0x80,0x38,0x01,0xFF,0xF0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xFC,0x03,0x00,0x18,0x00,0x7F,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x1F,0xFF,0x00,0x00,0x0C,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x01,0x80,0x00,0x0C,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x00,0x0C,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x00,0x0C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x00,0x0C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC6,0x00,0x0C,0x1E,0x38,0xCC,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x60,0x00,0xC7,0x00,0x1C,0x11,0x45,0x32,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x01,0x83,0x80,0x38,0x11,0x45,0x22,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x1F,0xFF,0x01,0xFF,0xF0,0x11,0x45,0x22,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xFE,0x00,0x7F,0xC0,0x11,0x45,0x22,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x79,0x22,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x22,0x00,0x90,0x04,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x02,0x40,0x42,0x00,0x90,0x04,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x06,0x40,0x41,0x01,0x08,0x08,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x04,0x20,0x81,0x01,0x08,0x08,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x08,0x20,0x81,0x02,0x04,0x10,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x08,0x20,0x80,0x82,0x04,0x10,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x10,0x21,0x00,0x82,0x02,0x10,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x20,0x11,0x00,0x84,0x02,0x10,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x40,0x12,0x00,0x44,0x02,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x80,0x12,0x00,0x48,0x01,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x48,0x01,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x30,0x01,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x30,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

unsigned char BMP4[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x00,0x0F,0xC0,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x00,0x1F,0xFE,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x00,0x3F,0xFF,0xFF,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x00,0x7F,0xFF,0xFF,0xFF,0xC0,0x10,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x00,0xFF,0xFF,0xFF,0xFF,0xE0,0x10,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x03,0xFF,0xFF,0xFF,0xFF,0xE0,0x20,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0,0x60,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x3F,0xFF,0xFF,0xFF,0xFF,0xF0,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x3C,0x3F,0xFF,0xF8,0x7F,0xF1,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x3F,0xFF,0xFF,0xFF,0xFF,0xF1,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x3F,0xFF,0xFF,0xFF,0xFF,0xF3,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x20,0x00,0xFF,0x00,0x07,0xF2,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x0F,0xFF,0x7E,0xFF,0xFB,0xE7,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x9F,0x7F,0x81,0xFD,0xFC,0x0F,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0xBE,0x3F,0x9D,0xF8,0xFD,0xFF,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xDF,0x7F,0xBC,0xFD,0xFB,0xFF,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x67,0xFE,0x7E,0x7F,0xE3,0xFF,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x38,0x01,0xFF,0x80,0x0F,0xFE,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0xFE,0x00,0x7F,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xC7,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0F,0x80,0x00,0x00,0x00,0x01,0x83,0x80,0x61,0xC0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0F,0x80,0xF0,0x00,0x00,0x07,0x82,0xE3,0xE1,0xB0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0F,0x80,0x1C,0x00,0x00,0x0C,0x6C,0x02,0x3F,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0E,0x00,0x03,0x00,0x00,0x00,0xFE,0x00,0x3F,0x80,0x00,0x00,0x00,
	0x00,0x00,0x00,0x06,0x00,0xF1,0x80,0x00,0x0F,0x81,0xF7,0xC0,0x7C,0x00,0x00,0x00,
	0x00,0x00,0x00,0x03,0x80,0x18,0x80,0x00,0x03,0xFF,0x80,0xFF,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0xC0,0x0C,0x40,0x00,0x02,0x18,0x81,0x8C,0x60,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xE1,0x84,0x40,0x00,0x02,0x18,0x81,0x8C,0x60,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7F,0xC2,0x40,0x00,0x03,0xFF,0x81,0xFF,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3F,0xE2,0x40,0x00,0x02,0x00,0x31,0x80,0x0C,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x03,0xFF,0xF0,0xFF,0xFC,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xC0,0x7F,0xF0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

//////////////////////////////////////////////////////////////////////////////////	 
//
//存储图片数据，图片大小为51*32像素
//逐行式，顺向（高位在前）
//
/////////////////////////////////////////////////////////////////////////////////
unsigned char BMP5[] =
{
	0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0E,0x00,0x00,0x00,0x00,0x01,0x80,0x0E,0x00,0x20,0x00,0x00,0x01,0xC0,0x00,0x00,
	0x70,0x00,0x00,0x00,0xC0,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x3F,0x81,0xC0,0x00,
	0x00,0x00,0x61,0xFF,0xF0,0x80,0x00,0x00,0x00,0x03,0xC0,0xF8,0x00,0x00,0x00,0x00,
	0x07,0x00,0x1C,0x00,0x00,0x00,0x00,0x1E,0x00,0x0F,0x00,0x00,0x00,0x7C,0x1C,0x00,
	0x03,0x1F,0x80,0x00,0x7C,0x1C,0x07,0xFF,0x1F,0x80,0x00,0x7C,0x1C,0x1F,0xFF,0x9F,
	0x80,0x00,0x00,0x1C,0x7C,0x03,0xF8,0x00,0x00,0x00,0x0F,0xF0,0x00,0x7C,0x00,0x00,
	0x03,0xFF,0x00,0x00,0x0F,0xE0,0x00,0x0F,0xF2,0x00,0x00,0x07,0xFE,0x00,0x1F,0x80,
	0x00,0x00,0x00,0x7F,0x80,0x3C,0x00,0x00,0x00,0x00,0x03,0x80,0x7C,0x00,0x00,0x00,
	0x00,0x03,0xC0,0x70,0x00,0x00,0x00,0x00,0x01,0xC0,0x70,0x00,0x00,0x00,0x00,0x01,
	0xC0,0x78,0x00,0x00,0x00,0x00,0x01,0xC0,0x7C,0x00,0x00,0x00,0x00,0x03,0xC0,0x3C,
	0x00,0x00,0x00,0x00,0x07,0x80,0x3E,0x00,0x00,0x00,0x00,0x3F,0x80,0x0F,0xE1,0xC0,
	0x00,0x1F,0xFC,0x00,0x03,0xFF,0xFC,0x03,0xFF,0xF0,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
	0x00,0x00,0x00,0x00,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x01,0xFC,0x00,0x00,0x00,
};
#endif


