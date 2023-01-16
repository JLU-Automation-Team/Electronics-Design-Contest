#(28, 70, 36, 92, 3, 82),   #阳光

import sensor, image, time,math
from pyb import UART
import json
import struct

red_threshold   = (34, 68, 55, 95, 20, 60)
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

K=8200#the value should be measured
R=11000

while(True):
    clock.tick() # Track elapsed milliseconds between snapshots().
    img = sensor.snapshot() # Take a picture and return the image.

    blobs = img.find_blobs([red_threshold])
    if len(blobs) == 1:
        # Draw a rect around the blob.
        b = blobs[0]
        img.draw_rectangle(b[0:4]) # rect
        img.draw_cross(b[5], b[6]) # cx, cy
        Lm = (b[2]+b[3])/2
        length = K/Lm
        cx=b[5]
        Intermediate_Variable = (cx-160)*(cx-160)              #中间变量
        Distance_From_Center = math.sqrt(Intermediate_Variable)                 #开根号计算到中点的距离
        Angle = int(Distance_From_Center*R)
        x=int(Angle/10000)
        y=int((Angle-10000*x)/100)
        print(Angle)
        data = bytearray([0x2C,0x26,x,y,0x5B])
        uart.write(data)    #打印XY轴的偏移坐标






import sensor, image, time,math
from pyb import UART
import json
import struct

red_threshold   = [(8, 47, 25, 86, 10, 51),(28, 70, 36, 92, 3, 82) ]  #室内光/室外光
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

K=8200#the value should be measured
R=11000



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
    blobs = img.find_blobs(red_threshold,pixels_threshold=100, area_threshold=100)
    if blobs:
       max_blob = find_max(blobs)      #寻找同色块里最大的一个         
       img.draw_rectangle(max_blob.rect())
       img.draw_cross(max_blob.cx(),max_blob.cy())   
            
