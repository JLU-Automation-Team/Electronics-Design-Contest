//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机MSP430F149,MSP430开发板,主频8MHZ，晶振8MHZ
//QDtech-TFT液晶驱动 for MSP430 软件SPI
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
//创建日期:2018/8/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
// OLED模块                C51单片机
//   VCC         接       DC 5V/3.3V      //OLED屏电源正
//   GND         接          GND          //OLED屏电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为3线制SPI
// OLED模块                C51单片机
//   D1          接          P31          //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块                C51单片机
//   CS          接          P20          //OLED屏片选控制信号
//   RES         接          P22          //OLED屏复位控制信号
//   D0          接          P33          //OLED屏SPI时钟信号
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
//行列式，低位在前
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __BMP_H
#define __BMP_H
const unsigned char BMP2[] =
{
0x00,0x06,0x0A,0x12,0x22,0xFE,0x22,0x12,0x0A,0x86,0x00,0xC0,0x00,0xE0,0x00,0xF0,
0x00,0x00,0x00,0x00,0x00,0xF8,0x04,0x02,0x02,0x04,0x00,0xFE,0x04,0x08,0x04,0xFE,
0x00,0xF8,0x04,0x02,0x02,0x04,0x00,0xF8,0x04,0x02,0x02,0x04,0x00,0x00,0x00,0x00,
0x00,0x88,0x50,0xFE,0x22,0x54,0x88,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x08,0x44,
0x24,0x12,0x92,0x12,0x24,0x44,0x08,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFA,0x76,0xAE,0xDE,0xDE,0xDE,0xDE,0xDE,0xDE,0xDE,0xDE,0xAE,0x76,0xFA,0xFC,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x88,0x88,0xFE,0x02,0xFA,
0xFA,0x02,0xFA,0xFA,0x02,0xFA,0xFA,0x02,0xFA,0xFA,0x02,0xFA,0xFA,0x02,0xFE,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x03,0x00,0x00,0x00,0x03,
0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x02,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x02,0x02,
0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x60,0x30,0x18,0x0C,0x06,0xFF,0xFF,0x00,0x00,0xFE,0xFF,0x03,0x03,0x03,0x03,
0x03,0x03,0x03,0x03,0x03,0xFF,0xFE,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,
0x00,0xFE,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0x00,0x00,
0xFE,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFE,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x03,0x03,0x03,0x03,
0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,
0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,
0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x80,0x80,0x80,0x00,0x00,0x03,0x83,0x80,0x80,0x81,0x03,0x03,0x03,0x83,0x83,
0x03,0x03,0x03,0x03,0x83,0x83,0x81,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x83,0x83,0x83,0x03,0x03,0x03,0x83,0x83,0x83,0x83,0x03,0x03,0x01,0x00,0x00,
0x01,0x03,0x03,0x83,0x83,0x83,0x83,0x03,0x03,0x03,0x83,0x83,0x81,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,
0x30,0x28,0x24,0x22,0x21,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,0x21,0x20,0x3F,
0x20,0x20,0x00,0x1F,0x24,0x24,0x24,0x24,0x1F,0x00,0x00,0x30,0x30,0x00,0x00,0x1F,
0x20,0x20,0x20,0x20,0x1F,0x00,0x1F,0x24,0x24,0x24,0x24,0x19,0x00,0x00,0x30,0x30,
0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,0x1F,0x24,0x24,0x24,0x24,0x19,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7F,0x02,0x04,0x08,0x04,0x02,0x7F,0x00,0x1C,0x2A,0x49,0x49,0x49,0x4A,0x24,
0x00,0x7F,0x02,0x04,0x08,0x10,0x20,0x7F,0x00,0x1F,0x20,0x40,0x40,0x40,0x20,0x1F,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x7F,0x2A,0x2A,0x2A,0x08,0x08,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x02,0x04,0x08,0x04,0x02,0x7F,0x00,
0x26,0x49,0x49,0x49,0x49,0x49,0x32,0x00,0x7F,0x02,0x04,0x08,0x10,0x20,0x7F,0x00,
};

const unsigned char BMP3[] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x44,0xC4,0x44,0x48,0x30,0x00,0xFC,0x00,0x00,
0x00,0x00,0x00,0x00,0xFC,0x00,0xFC,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0xFC,0x00,
0xFC,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0xFC,0x00,0x04,0xFC,0x04,0x00,0xFC,0x08,
0x10,0x20,0x40,0x80,0x00,0x00,0xFC,0x00,0xF0,0x08,0x04,0x44,0x44,0x44,0x44,0xC8,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x01,0x02,0x04,0x00,0x01,0x02,0x04,
0x04,0x04,0x04,0x02,0x01,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x07,0x00,
0x07,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x07,0x00,0x04,0x07,0x04,0x00,0x07,0x00,
0x00,0x00,0x00,0x00,0x01,0x02,0x07,0x00,0x01,0x02,0x04,0x04,0x04,0x02,0x01,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xF0,0xF8,0x0C,0x06,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x07,0x9E,
0xF8,0xF0,0x00,0x00,0x00,0x00,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xFC,0xFE,0xFF,0xFF,
0xFF,0xFF,0xFE,0xFE,0xFC,0xFC,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFC,0x38,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xC1,0xE3,0x67,0x36,0x1C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1C,0x36,0x63,
0xC1,0x80,0x00,0x00,0x00,0x00,0x0F,0x0F,0x06,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
0x03,0x03,0x06,0x0E,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,
0x07,0x0F,0x1F,0x1F,0x3F,0x7F,0x3F,0x1F,0x1F,0x0F,0x07,0x07,0x03,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x1F,0x3F,0x60,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x60,0x70,
0x3F,0x1F,0x00,0x00,0x00,0x18,0x38,0x70,0x60,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
0xC0,0xC0,0x60,0x30,0x3F,0x0F,0x00,0x00,0x00,0x00,0x00,0xFE,0x10,0x08,0x08,0xF0,
0x00,0xF0,0x10,0x08,0x08,0xF0,0x00,0xF0,0x08,0x08,0xF0,0x10,0x08,0x08,0xF0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x01,0x01,0x01,0x00,
0x00,0x07,0x01,0x01,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x30,0x0C,0x06,0x01,
0x01,0x06,0x78,0x80,0x00,0x00,0x00,0xC0,0x38,0x06,0x01,0x00,0x00,0x00,0x03,0x1C,
0xE0,0x00,0x00,0x00,0x00,0x80,0x70,0x0C,0x03,0x00,0x00,0x03,0x0C,0x30,0x80,0x00,
0x00,0x00,0x00,0xF0,0x0C,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x07,0x18,0x18,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x07,0x18,0x18,0x06,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,
0x10,0x10,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char BMP4[] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x80,0xC0,0x40,0x20,0x20,0x30,0x10,0x10,0x08,0x08,0x08,0x08,0x08,
0x08,0x08,0x08,0x08,0x10,0x10,0x30,0x30,0x20,0x20,0x60,0x40,0x40,0x40,0xC0,0x80,
0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x60,0x18,0x08,0x04,0x06,0x02,0x02,0x01,
0x01,0x01,0x01,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x01,0x03,0x02,0x04,0x0C,0x08,0x10,0x60,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x0F,0x00,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xE0,
0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,
0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,
0xF8,0xF8,0xF0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0xCF,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x3F,0xE0,0x80,0x4F,0xE7,0xF7,0xF7,0xF7,0xF7,
0xB7,0x17,0xB7,0xF7,0xF7,0xF7,0xF7,0xF7,0xEF,0x1F,0x9F,0xDF,0xDF,0xDF,0x1F,0x6F,
0xF7,0xF7,0xF7,0xF7,0xF7,0xB7,0x17,0xB7,0xF7,0xF7,0xF7,0xF7,0xF7,0x6F,0x9F,0xDF,
0xDF,0xDF,0xDF,0xCF,0xE0,0xF0,0xE0,0x02,0x87,0x45,0x49,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0F,0x1E,0x3E,0x7D,0xFD,0xFD,
0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xDE,0x9E,0x9F,0x1F,0x1F,0x1F,0x9F,0x9F,0x9E,
0xDE,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFC,0xFE,0xFE,0x7F,0x7F,
0x3F,0x1F,0x0F,0x0F,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x01,0x03,0x03,0x07,0x07,0x07,0x07,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
0x0F,0x0F,0x07,0x07,0x07,0x07,0x03,0x03,0x03,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x7F,0xCE,
0xCC,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x24,0x24,0x4C,0x48,0x88,0x10,0x10,
0x60,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x28,0x2C,0xE4,0x66,0x76,0x58,0x58,0xD0,0xD8,0x58,0x56,0x62,
0xE6,0x24,0x24,0x20,0x00,0x20,0x2C,0x24,0xE4,0x66,0x5E,0x58,0xD8,0xD8,0x58,0x5E,
0x76,0xE2,0x24,0x24,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x03,0x03,0x06,0x06,0x0E,0x0E,0x0F,0x0F,0x0E,0x04,0x00,0x00,0x03,0x00,0x00,
0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x12,0x12,0x12,0x12,0x13,0x13,0x12,0x12,0x12,
0x13,0x10,0x0C,0x00,0x00,0x00,0x00,0x00,0x0F,0x12,0x12,0x12,0x13,0x13,0x12,0x12,
0x12,0x13,0x10,0x10,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
#endif


