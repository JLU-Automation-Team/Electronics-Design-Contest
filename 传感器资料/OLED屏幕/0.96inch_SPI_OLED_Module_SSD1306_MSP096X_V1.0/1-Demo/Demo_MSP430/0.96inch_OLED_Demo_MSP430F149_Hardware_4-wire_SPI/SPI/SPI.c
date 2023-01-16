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
#include "spi.h"

/*****************************************************************************
 * @name       :u8 SPI_WriteByte(SPI_TypeDef* SPIx,u8 Byte)
 * @date       :2018-08-09 
 * @function   :Write a byte of data using STM32's hardware SPI
 * @parameters :SPIx: SPI type,x for 1,2,3
                Byte:Data to be written
 * @retvalue   :Data received by the bus
******************************************************************************/
u8 SPI_WriteByte(u8 Byte)
{
  while ((IFG1&UTXIFG0) ==0);   // wait while not ready / for RX
  U0TXBUF = Byte;
  while ((IFG1&URXIFG0)==0);   // wait for RX buffer (full)
  return (U0RXBUF);
} 

/*****************************************************************************
 * @name       :void SPI_Init(void)	
 * @date       :2018-08-09 
 * @function   :Initialize the STM32 hardware SPI2
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void SPI_Init(void)	
{
  P3SEL |= 0x0E;                        //P3.1,2,3 SPI option select
  P3DIR |= 0x0A;
  P3OUT |= 0x0A;
  U0CTL |= SWRST;                            // 8-bit SPI Master **SWRST**
  U0CTL |= CHAR+SYNC+MM ;         // 8-bit SPI Master **SWRST**
  U0TCTL |= SSEL0+SSEL1+STC;      // SMCLK, 3-pin mode, clock idle low, data valid on rising edge, UCLK delayed
  U0TCTL &= ~CKPH;
  U0TCTL &= ~CKPL;
  U0BR0 |= 0x00;                             // 0x02: UCLK/2 (4 MHz), works also with 3 and 4
  U0BR1 |= 0x00;                             // -"-
  U0MCTL |= 0x00;                            // no modulation
  ME1 |= USPIE0;                            // Enable USART1 SPI mode  
  U0CTL &= ~SWRST;                          // clear SWRST 
  IE1 |= URXIE0+UTXIE0;     //receive enable  
}
