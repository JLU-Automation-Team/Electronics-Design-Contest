//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32F767IGT6,正点原子Apollo STM32F4/F7开发板,主频216MHZ，晶振25MHZ
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
//本模块默认数据总线类型为3线制SPI
// OLED模块               STM32单片机
//   D1          接          PB15         //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块               STM32单片机
//   CS          接          PD11         //OLED屏片选控制信号
//   RES         接          PD12         //OLED屏复位控制信号
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
#include "sys.h"

#ifndef _SPI_H_
#define _SPI_H_

//本测试程序使用的是模拟SPI接口驱动
//可自由更改接口IO配置，使用任意最少4 IO即可完成本款液晶驱动显示
/******************************************************************************
接口定义在lcd.h内定义，请根据接线修改并修改相应IO初始化LCD_GPIO_Init()
*******************************************************************************/

//PB13--->>TFT --SCL/SCK	
//PB15 MOSI--->>TFT --SDA/DIN
#define MOSI  GPIO_PIN_15
#define SCLK  GPIO_PIN_13

//液晶控制口置1操作语句宏定义
#define	SPI_MOSI_SET  	HAL_GPIO_WritePin(GPIOB,MOSI,GPIO_PIN_SET) //LCD_CTRL->BSRR=SPI_MOSI    
#define	SPI_SCLK_SET  	HAL_GPIO_WritePin(GPIOB,SCLK,GPIO_PIN_SET) //LCD_CTRL->BSRR=SPI_SCLK    

//液晶控制口置0操作语句宏定义
#define	SPI_MOSI_CLR  	HAL_GPIO_WritePin(GPIOB,MOSI,GPIO_PIN_RESET) //LCD_CTRL->BRR=SPI_MOSI    
#define	SPI_SCLK_CLR  	HAL_GPIO_WritePin(GPIOB,SCLK,GPIO_PIN_RESET) //LCD_CTRL->BRR=SPI_SCLK    

void SPI_WriteData(u8 data,u8 Cmd);


#endif
