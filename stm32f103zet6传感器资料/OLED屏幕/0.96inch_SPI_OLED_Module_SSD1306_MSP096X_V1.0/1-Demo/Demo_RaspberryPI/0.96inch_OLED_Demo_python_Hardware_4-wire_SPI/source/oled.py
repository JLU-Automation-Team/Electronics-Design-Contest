# This program is for learning only,Not to be used for any other purpose 
# without the permission of the author
# Testing Hardware:Raspberry PI 3 ,  basic frequency:1GHz
# QDtech-OLED liquid crystal driver for Raspberry PI
# xiaofeng@ShenZhen QDtech co.,LTD
# Company Website:www.qdtft.com
# Taobao Website:http://qdtech.taobao.com
# wiki Technology Website:http://www.lcdwiki.com
# We provide technical support,Any technical questions are welcome to 
# exchange and study at any time
# Fixed telephone (fax):+86 0755-23594567 
# cell-phone:15989313508(Mr Feng)
# E-mail:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
# Technical Support QQ:3002773612  3002778157
# Technical Exchange QQ group:324828016
# Date:2018/9/6
# Version:V1.0
# Copyright reserved, piracy must be investigated
# Copyright(C) ShenZhen QDtech co.,LTD 2018-2028
# All rights reserved
#****************************************************************************************************
# This program uses the bcm2835 gpio library,
# so the pin definition using BCM coding
#=====================================power supply wiring===========================================//
# OLED Module                Raspberry PI    
#    VCC        connect       DC 5V/3.3V      //OLED power positive, Physical pin 1,2,4
#    GND        connect          GND          //OLED power ground,Physical pin 6,9,14,20,25,30,34,39
#======================================data line wiring=============================================//
# The default data bus type for this module is 4-wire SPI
#  OLED Module                Raspberry PI 
#    D1         connect       19(bcm:10)      //OLED spi write signal
#======================================control line wiring==========================================//
# OLED Module                Raspberry PI 
#    CS         connect       24(bcm:8)       //OLED chip selection control signal
#    RES        connect        5(bcm:3)       //OLED reset control signal
#    DC         connect        3(bcm:2)       //OLED data or command selection control signal
#    D0         connect       23(bcm:11)      //OLED spi colck signal
#========================================touch screen wiring========================================//
#This module has no touch function,so it don't need touch screen wiring
#*****************************************************************************************************/	
#****************************************************************************************************
# @attention
#
# THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
# WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
# TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
# DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
# FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
# CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
#*****************************************************************************************************/

import spidev
import RPi.GPIO as GPIO
import time

OLED_COMMAND = 0
OLED_DATA = 1

class SSD1306(object):
	"""class for SSD1306 64*128 1.3inch SPI OLED module."""

	def __init__(self,cs,res,dc,spi):
		# set oled display parameter 
		self.width = 128
		self.height = 64
		self.pagesize = 8
		self.ylevel = 0xB0
		self.xlevell = 0x00
		self.xlevelh = 0x10
		self.oledbuffer = [0]*(self.width*self.pagesize)
		# Initialize oled pin
		self.oledcs = cs
		self.oledres = res
		self.oleddc = dc
		GPIO.setmode(GPIO.BCM)
		GPIO.setwarnings(False)
		GPIO.setup(self.oledcs,GPIO.OUT)
		GPIO.setup(self.oledres,GPIO.OUT)
		GPIO.setup(self.oleddc,GPIO.OUT)
		# Initialize spi
		self.oledspi = spi
	def writebyte(self,val,flag):
		"""send one byte data to oled module"""
		if flag == OLED_COMMAND:
			GPIO.output(self.oleddc,GPIO.LOW)
		else:
			GPIO.output(self.oleddc,GPIO.HIGH)
		GPIO.output(self.oledcs,GPIO.LOW)
		self.oledspi.writebytes([val])
		self.oledspi.xfer([val],8000000)
		GPIO.output(self.oledcs,GPIO.HIGH)
	def oledreset(self):
		"""reset the oled module"""
		GPIO.output(self.oledres,GPIO.HIGH)
		time.sleep(0.01)
		GPIO.output(self.oledres,GPIO.LOW)
		time.sleep(0.01)
		GPIO.output(self.oledres,GPIO.HIGH)
	def oledinit(self):
		self.oledreset()
		"""init SSD1306"""	
		self.writebyte(0xAE,OLED_COMMAND); #display off
		self.writebyte(0x00,OLED_COMMAND); #set lower column address
		self.writebyte(0x10,OLED_COMMAND); #set higher column address
		self.writebyte(0x40,OLED_COMMAND); #set display start line
		self.writebyte(0xB0,OLED_COMMAND); #set page address
		self.writebyte(0x81,OLED_COMMAND); #contract control
		self.writebyte(0xFF,OLED_COMMAND); #128
		self.writebyte(0xA1,OLED_COMMAND); #set segment remap 
		self.writebyte(0xA6,OLED_COMMAND); #normal / reverse
		self.writebyte(0xA8,OLED_COMMAND); #multiplex ratio 
		self.writebyte(0x3F,OLED_COMMAND); #duty = 1/64
		self.writebyte(0xC8,OLED_COMMAND); #Com scan direction
		self.writebyte(0xD3,OLED_COMMAND); #set display offset 
		self.writebyte(0x00,OLED_COMMAND);
		self.writebyte(0xD5,OLED_COMMAND); #set osc division
		self.writebyte(0x80,OLED_COMMAND);
		self.writebyte(0xD9,OLED_COMMAND); #set pre-charge period
		self.writebyte(0XF1,OLED_COMMAND);
		self.writebyte(0xDA,OLED_COMMAND); #set COM pins 
		self.writebyte(0x12,OLED_COMMAND);
		self.writebyte(0xDB,OLED_COMMAND); #set vcomh 
		self.writebyte(0x30,OLED_COMMAND);
		self.writebyte(0x8D,OLED_COMMAND); #set charge pump disable 
		self.writebyte(0x14,OLED_COMMAND);
		self.writebyte(0xAF,OLED_COMMAND); #display ON
	def oledclear(self,val):
		"""clear oled image buffer"""
		if val == 1:
			self.oledbuffer = [0xff]*(self.width*self.pagesize)
		else:
			self.oledbuffer = [0]*(self.width*self.pagesize)
	def oleddisplay(self):
		"""send oled image buffer data to oled module"""
		for i in range(self.pagesize):
			self.writebyte(self.ylevel+i,OLED_COMMAND)
			self.writebyte(self.xlevell,OLED_COMMAND)
			self.writebyte(self.xlevelh,OLED_COMMAND)
			for n in range(self.width):
				self.writebyte(self.oledbuffer[i*self.width+n],OLED_DATA)
	def oledinvertdisplay(self,val):
		if val == 1:
			self.writebyte(0xA7,OLED_COMMAND)
		else:
			self.writebyte(0xA6,OLED_COMMAND)
	def oledimage(self,image):
		"""set the value of Python Image Library to oled buffer"""
		if image.mode != '1':
			raise ValueError('Image must be in mode 1.')
		imgwidth,imgheight = image.size
		if imgwidth != self.width or imgheight != self.height:
			raise ValueError('Image must be same dimensions as display({0}x{1}).' .format(self.width, self.height))
		pixel = image.load()
		for i in range(self.pagesize):
			for j in range(self.width):
				val = 0
				for k in [0,1,2,3,4,5,6,7]:
                                        val = val << 1
				        val |=0 if pixel[(j,i*8+7-k)] == 0 else 1
				self.oledbuffer[i*self.width+j] = val 
