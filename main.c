#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;
//
uchar anotherSur=1;		//可以先设置为1，第一次需要清屏(之后只是时间计数就不需要再次清屏)，在calTimeDisplay.h中声明为全局变量
long x=0, y=0;
uchar set=0, back=1;  //设置标志位，返回标志位（先置1才能运行），全局变量在calTimeDisplay.h中声明
uchar setFlag=0, clockFlag=0;	//防止出现在一个界面按键却触发另外一个界面内容的错误
uchar oriTime=0;			 //修改时间错误时原来的时间

void main()
{
	//uchar h1, h0, m1, m0, s1, s0;	 //变量定义

	initTimer();		 //初始化定时器0（时钟）
	TFT_Init();				//初始化触摸屏显示

	while(1)
	{

	/*
		h1=time.hour/10;	//得到定时器的时间
		h0=time.hour%10;
		m1=time.minute/10;
		m0=time.minute%10;
		s1=time.second/10;
		s0=time.second%10;
	*/
		CalTimeDisplay();		//主界面的显示及设置界面的显示
	}

}

