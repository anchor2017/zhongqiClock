#ifndef __TOUCH_H
#define __TOUCH_H

//---包含头文件---//
#include<reg52.h>
#include<intrins.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---定义数据类型---//
//12位的电压值
typedef struct 
{
	uint x;
	uint y;
} XPT_XY;

extern XPT_XY xpt_xy;

//---定义芯片命令字节---//
#define XPT_CMD_X	0xD0    //读取X轴的命令
#define XPT_CMD_Y	0x90	//读取Y轴的命令

//---定义使用的IO口---//
sbit TOUCH_DOUT = P2^0;	  //输出
sbit TOUCH_CLK  = P2^1;	  //时钟
sbit TOUCH_DIN  = P2^2;	  //输入
sbit TOUCH_CS   = P2^3;	  //片选
sbit TOUCH_PEN  = P2^4;	  //检测触摸屏响应信号

//---声明全局函数---//
void TOUCH_SPI_Start(void);	  //起始
void TOUCH_SPI_Write(uchar dat); //写
uint TOUCH_SPI_Read(void);	 //读

uint TOUCH_XPT_ReadData(uchar cmd);	 //读电压数据
//读x,y值，不是存储在返回值里，返回值存储的是0，1
//x,y的值存储在全局变量里面，数据类型为uint型
uchar TOUCH_XPT_ReadXY(void);		 



#endif
