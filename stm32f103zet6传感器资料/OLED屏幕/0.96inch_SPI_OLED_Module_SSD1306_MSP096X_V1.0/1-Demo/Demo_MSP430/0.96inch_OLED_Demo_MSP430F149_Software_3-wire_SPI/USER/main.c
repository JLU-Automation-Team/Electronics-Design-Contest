//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��MSP430F149,MSP430������,��Ƶ8MHZ������8MHZ
//QDtech-TFTҺ������ for MSP430 ���SPI
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
//��ģ��Ĭ��������������Ϊ3����SPI
// OLEDģ��                C51��Ƭ��
//   D1          ��          P31          //OLED��SPIд�ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��                C51��Ƭ��
//   CS          ��          P20          //OLED��Ƭѡ�����ź�
//   RES         ��          P22          //OLED����λ�����ź�
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
#include  <msp430x14x.h>
#include "oled.h"
#include "gui.h"
#include "test.h"
#include "delay.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  CLOCK_Init();   //��ʼ��ʱ��ϵͳ
  OLED_Init();			         //��ʼ��OLED  
  OLED_Clear(0);             //������ȫ�ڣ�
  while(1) 
  {	
    TEST_MainPage();         //��������ʾ����
    OLED_Clear(0); 
    Test_Color();            //ˢ������
    OLED_Clear(0); 
    TEST_English();          //Ӣ����ʾ����
    OLED_Clear(0); 
    TEST_Number_Character(); //���ֺͷ�����ʾ����
    OLED_Clear(0); 
    TEST_Chinese();          //������ʾ����
    OLED_Clear(0); 
    TEST_BMP();              //BMP��ɫͼƬ��ʾ����
    OLED_Clear(0); 
  }
}
