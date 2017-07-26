#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

#include<REG52.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

#define TFT_YMAX  220		    //显示的行、列数
#define TFT_XMAX  176

//#define TFT_DATAPORTH P1
//#define TFT_DATAPORTL P0

#define TFT_DATAPORT P0

sbit	TFT_CS  = P2^7;
sbit	TFT_RST = P3^3;
sbit	TFT_RS  = P2^6;
sbit	TFT_WR  = P2^5;
sbit	TFT_RD  = P3^2;


#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x001F
#define RED            0xF800
#define MAGENTA        0xF81F
#define GREEN          0x07E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0		 //定义颜色的宏

void Delay(unsigned int dly);	  //延时
void TFT_WriteCmd(unsigned int cmd); //写命令
void TFT_WriteData(unsigned int dat);  //写数据
void TFT_Init(void);			//初始化
//设置窗口，x轴起始位置，y轴起始位置，x轴终止位置，y轴终止位置
void TFT_SetWindow(unsigned int xStart,unsigned int yStart,unsigned int xEnd,unsigned int yEnd);  
void TFT_ClearScreen(unsigned int color);	//清屏
void TFT_WriteColor(color);		   //涂颜色
#endif
