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
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"

int main(void)
{	
   Cache_Enable();                 //��L1-Cache
   HAL_Init();				        //��ʼ��HAL��
   Stm32_Clock_Init(432,25,2,9);   //����ʱ��,216Mhz 
   delay_init(216);                //��ʱ��ʼ��
    OLED_Init();	                //��ʼ��OLED
	  OLED_Clear(0);                  //������ȫ�ڣ�
    while(1)
    {
		TEST_MainPage();         //��������ʾ����
		OLED_Clear(0); 
		Test_Color();            //ˢ������
		OLED_Clear(0); 
		Test_Rectangular();      //���λ��Ʋ���
		OLED_Clear(0); 
		Test_Circle();           //Բ�λ��Ʋ���
		OLED_Clear(0); 
		Test_Triangle();         //�����λ��Ʋ���
		OLED_Clear(0);  
		TEST_English();          //Ӣ����ʾ����
		OLED_Clear(0); 
		TEST_Number_Character(); //���ֺͷ�����ʾ����
		OLED_Clear(0); 
		TEST_Chinese();          //������ʾ����
		OLED_Clear(0); 
		TEST_BMP();              //BMP��ɫͼƬ��ʾ����
		OLED_Clear(0); 
		TEST_Menu1();            //�˵�1��ʾ����
		OLED_Clear(0); 
		TEST_Menu2();            //�˵�2��ʾ����
		OLED_Clear(0); 
	}
}

