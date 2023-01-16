//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STM32F767IGT6,����ԭ��Apollo STM32F4/F7������,��Ƶ216MHZ������25MHZ
//QDtech-OLEDҺ������ for STM32
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtft.com
//�Ա���վ��http://qdtech.taobao.com
//wiki������վ��http://www.lcdwiki.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//����֧��QQ:3002773612  3002778157
//��������QQȺ:324828016
//��������:2018/8/27
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================��Դ����================================================//
// OLEDģ��               STM32��Ƭ��
//   VCC         ��       DC 5V/3.3V      //OLED����Դ��
//   GND         ��          GND          //OLED����Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ4����SPI
// OLEDģ��               STM32��Ƭ��
//   D1          ��          PB15         //OLED��SPIд�ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��               STM32��Ƭ��
//   CS          ��          PD11         //OLED��Ƭѡ�����ź�
//   RES         ��          PD12         //OLED����λ�����ź�
//   DC          ��          PD5          //OLED������/����ѡ������ź�
//   D0          ��          PB13         //OLED��SPIʱ���ź�
//=========================================����������=========================================//
//��ģ�鲻���������ܣ����Բ���Ҫ����������
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

//�����Գ���ʹ�õ���ģ��SPI�ӿ�����
//�����ɸ��Ľӿ�IO���ã�ʹ����������4 IO������ɱ���Һ��������ʾ
/******************************************************************************
�ӿڶ�����lcd.h�ڶ��壬����ݽ����޸Ĳ��޸���ӦIO��ʼ��LCD_GPIO_Init()
*******************************************************************************/

//PB13--->>TFT --SCL/SCK	
//PB15 MOSI--->>TFT --SDA/DIN
#define MOSI  GPIO_PIN_15
#define SCLK  GPIO_PIN_13

//Һ�����ƿ���1�������궨��
#define	SPI_MOSI_SET  	HAL_GPIO_WritePin(GPIOB,MOSI,GPIO_PIN_SET) //LCD_CTRL->BSRR=SPI_MOSI    
#define	SPI_SCLK_SET  	HAL_GPIO_WritePin(GPIOB,SCLK,GPIO_PIN_SET) //LCD_CTRL->BSRR=SPI_SCLK    

//Һ�����ƿ���0�������궨��
#define	SPI_MOSI_CLR  	HAL_GPIO_WritePin(GPIOB,MOSI,GPIO_PIN_RESET) //LCD_CTRL->BRR=SPI_MOSI    
#define	SPI_SCLK_CLR  	HAL_GPIO_WritePin(GPIOB,SCLK,GPIO_PIN_RESET) //LCD_CTRL->BRR=SPI_SCLK    

void  SPI_WriteData(u8 Data);


#endif
