//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STC12LE5A60S2,����12M  ��Ƭ��������ѹ3.3V��5V
//QDtech-OLEDҺ������ for C51
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
//��������:2018/8/29
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================��Դ����================================================//
// OLEDģ��                C51��Ƭ��
//   VCC         ��       DC 5V/3.3V      //OLED����Դ��
//   GND         ��          GND          //OLED����Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ4����SPI
// OLEDģ��                C51��Ƭ��
//   D1          ��          P15          //OLED��SPIд�ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��                C51��Ƭ��
//   CS          ��          P13          //OLED��Ƭѡ�����ź�
//   RES         ��          P33          //OLED����λ�����ź�
//   DC          ��          P12          //OLED������/����ѡ������ź�
//   D0          ��          P17          //OLED��SPIʱ���ź�
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
#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
 
//--------------OLED��������---------------------
#define PAGE_SIZE    8
#define XLevelL		   0x00
#define XLevelH		   0x10
#define YLevel       0xB0
#define	Brightness	 0xFF 
#define WIDTH 	     128
#define HEIGHT 	     64	

//-------------д��������ݶ���-------------------
#define OLED_CMD     0	//д����
#define OLED_DATA    1	//д���� 
   						  
//-----------------OLED�˿ڶ���----------------
sbit OLED_CS = P1^3;    //Ƭѡ�ź�           P13
sbit OLED_DC = P1^2;   //����/��������ź�  P12
sbit OLED_RST = P3^3;   //��λ�ź�          P33

//-----------------OLED�˿ڲ�������---------------- 
#define OLED_CS_Clr()  OLED_CS = 0
#define OLED_CS_Set()  OLED_CS = 1

#define OLED_DC_Clr()  OLED_DC = 0
#define OLED_DC_Set()  OLED_DC = 1
 					   
#define OLED_RST_Clr()  OLED_RST = 0
#define OLED_RST_Set()  OLED_RST = 1

//OLED�����ú���
void OLED_WR_Byte(unsigned dat,unsigned cmd);     							   		    
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Reset(void);	   							   		    
void OLED_Init(void);
void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color);
void OLED_Display(void);
void OLED_Clear(unsigned dat);  
#endif
