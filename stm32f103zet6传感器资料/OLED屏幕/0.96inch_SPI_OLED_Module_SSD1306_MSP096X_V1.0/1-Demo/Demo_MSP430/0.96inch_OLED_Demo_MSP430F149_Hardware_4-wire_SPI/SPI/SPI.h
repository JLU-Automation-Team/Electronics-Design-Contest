//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机MSP430F149,MSP430开发板,主频8MHZ，晶振8MHZ
//QDtech-TFT液晶驱动 for MSP430 硬件SPI
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
//本模块默认数据总线类型为4线制SPI
// OLED模块                C51单片机
//   D1          接          P31          //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块                C51单片机
//   CS          接          P20          //OLED屏片选控制信号
//   RES         接          P22          //OLED屏复位控制信号
//   DC          接          P21          //OLED屏数据/命令选择控制信号
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
#include  <msp430x14x.h>
#include "type.h"

#ifndef _SPI_H_
#define _SPI_H_

//本测试程序使用的是硬件SPI接口驱动
//除了SPI时钟信号以及SPI读、写信号引脚不可更改，其他引脚都可以更改
//SPI的时钟引脚定义固定为P33
//SPI的写数据引脚定义固定为P31
 
u8 SPI_WriteByte(u8 Byte);
void SPI_Init(void);

#endif
