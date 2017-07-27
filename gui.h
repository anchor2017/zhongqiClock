#ifndef _GUI_H_
#define _GUI_H_

//---包含头文件---//
//#include <reg52.H>
#include "lcd_driver.h"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---显示图片---//
//#define PICTURE_SHOW

//---显示32*29的汉字---//
#define CHAR32_SHOW

//---显示19x24的汉字---//
//#define CHAR14_SHOW

//---显示ASCII码对应的字符---//
#define USE_ASCII

//---定义全局变量---//
void GUI_Dot(uint x, uint y, uint color);  //画点

//void GUI_DrowSign(uint x, uint y, uint color);	//画十字
//void GUI_Box(uint sx, uint sy, uchar ex, uint ey, uint color);   //画方框

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color);//画线条
//画汉字， x轴初始位置，y轴初始位置，汉字首地址，字颜色，背景颜色
void GUI_Write32CnChar(uint x, uint y, uchar *cn, uint wordColor, uint backColor);
//画汉字，x轴初始位置，y轴初始位置，汉字首地址，字颜色，背景颜色
	 
//void GUI_Write14CnChar(uint x,uint y,uchar *cn,uint wordColor,uint backColor);
//画图，x轴初始位置，y轴初始位置，宽，高	 
//void GUI_ShowPicture(uint x, uint y, uchar wide, uint high);

//画字符，x轴初始位置，y轴初始位置，字符首地址，字颜色，背景颜色
void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor);

void GUI_WriteASCII2(uint x, uint y, uchar *p, uint wordColor, uint backColor);
void GUI_WriteASCII2Ch(uint x, uint y, uchar c, uint wordColor, uint backColor);
void GUI_WriteASCIICh(uint x, uint y, uchar c, uint wordColor, uint backColor);
void GUI_Writetable(uint x, uint y, uchar *c, uint wordColor, uint backColor);
#endif
