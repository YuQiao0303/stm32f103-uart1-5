正点原子stm32f103rct mini开发板

寄存器版

全部五个串口的使用和测试

# 使用方法
## 接线

|串口|TX|RX|
|-|-|-|
|1|PA9|PA10|
|2|PA2|PA3|
|3|PB10|PB11|
|4|PC10|PC11| 
|5*|PC12|PD2|

将串口的TX接到ttl转usb模块的RX，RX接到TX，GND接到GND，usb接到电脑

## 测试
打开串口调试助手，向串口发送一个字符，结果如图：
![image.png](https://upload-images.jianshu.io/upload_images/15426916-130fe1b1bf644929.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)