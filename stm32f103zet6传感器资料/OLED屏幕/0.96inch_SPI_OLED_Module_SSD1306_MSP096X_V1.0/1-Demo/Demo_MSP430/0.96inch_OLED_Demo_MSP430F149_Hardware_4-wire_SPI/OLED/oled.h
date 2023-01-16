//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��MSP430F149,MSP430������,��Ƶ8MHZ������8MHZ
//QDtech-TFTҺ������ for MSP430 Ӳ��SPI
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
//   D1          ��          P31          //OLED��SPIд�ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��                C51��Ƭ��
//   CS          ��          P20          //OLED��Ƭѡ�����ź�
//   RES         ��          P22          //OLED����λ�����ź�
//   DC          ��          P21          //OLED������/����ѡ������ź�
//   D0          ��          P33          //OLED��SPIʱ���ź�
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
#include  <msp430x14x.h>
 
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
#define OLED_CS   BIT0    //Ƭѡ�ź�           P20
#define OLED_DC   BIT1   //����/��������ź�  P21
#define OLED_RST  BIT2   //��λ�ź�          P22

//-----------------OLED�˿ڲ�������---------------- 
#define OLED_CS_Clr  P2OUT &= ~OLED_CS
#define OLED_CS_Set  P2OUT |= OLED_CS

#define OLED_DC_Clr  P2OUT &= ~OLED_DC
#define OLED_DC_Set  P2OUT |= OLED_DC
 					   
#define OLED_RST_Clr  P2OUT &= ~OLED_RST
#define OLED_RST_Set  P2OUT |= OLED_RST

//OLED�����ú���
void OLED_WR_Byte(unsigned dat,unsigned cmd);     							   		    
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Reset(void);	   							   		    
void OLED_Init(void);
void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color);
void OLED_Display(void);
void OLED_Clear(unsigned dat);  
#endif
