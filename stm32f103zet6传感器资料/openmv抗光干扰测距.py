import sensor, image, time,math
from pyb import UART
import json
import struct

red_threshold   = [(34, 54, 50, 79, 17, 62),(46, 69, 41, 79, 20, 60)]  #室内光/室外光
uart = UART(3, 115200)  #串口3，波特率115200
uart.init(115200, bits=8, parity=None, stop=1)  #8位数据位，无校验位，1位停止位

sensor.reset() # Initialize the camera sensor.
sensor.set_pixformat(sensor.RGB565) # use RGB565.
sensor.set_framesize(sensor.QQVGA) # use QQVGA for speed.
sensor.skip_frames(time=2000) # Let new settings take affect.
sensor.set_auto_whitebal(False) # turn this off.
sensor.set_contrast(0)#对比度
sensor.set_auto_gain(False) # 颜色跟踪必须关闭自动增益
sensor.set_auto_exposure(True,1)   #自动曝光，1微秒
clock = time.clock() # Tracks FPS.

K=820   #系数待改
def find_max(blobs):                    #寻找同色块里最大的一个
    max_size=0
    for blob in blobs:
        if blob.pixels() > max_size:
            max_blob = blob
            max_size = blob.pixels()
    return max_blob
while(True):
    clock.tick() # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot() # Take a picture and return the image.
    blobs = img.find_blobs(red_threshold,pixels_threshold=50, area_threshold=50,merge=True)
    if blobs:
       max_blob = find_max(blobs)      #寻找同色块里最大的一个         
       img.draw_rectangle(max_blob.rect())
       img.draw_cross(max_blob.cx(),max_blob.cy())   
       Lm = (max_blob.w()+max_blob.h())/2
       length = K/Lm
       x=int(length*10000)
       print(length)
       data = bytearray([0x2C,0x26,x,max_blob.cx(),0x5B])
       uart.write(data)    #打印XY轴的偏移坐标