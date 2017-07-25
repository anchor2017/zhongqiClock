#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"
#include "AD.H"
#include "paintTFT.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;

uchar anotherSur=1;		//可以先设置为1，第一次需要清屏(之后只是时间计数就不需要再次清屏)，在calTimeDisplay.h中声明为全局变量	
long x=0, y=0;	
uchar set=0, back=1;  //设置标志位，返回标志位（先置1才能运行），全局变量在calTimeDisplay.h中声明
uchar setFlag=0, clockFlag=0;	//防止出现在一个界面按键却触发另外一个界面内容的错误
uchar oriTime=0;			 //修改时间错误时原来的时间

void main()
{
	//uchar h1, h0, m1, m0, s1, s0;	 //变量定�
	clockTime lasttime;
  P2 = 0x00;
	TFT_Init();				//初始化触摸屏显示
  TFT_ClearScreen(0x0000);		//清屏，消除屏幕之前显示内容的影响
	initTimer();		 //初始化定时器0（时钟�	
	tempchange();   //初始化温度
	lasttime = time;         
	while(1)
	{
	//	if( lasrtime != time )       //当
		{
			lasttime = time;
      TFT_paintMainClock();           // 显示时间
			tempchange();   
			displayTemp(getTemp());           // 显示温度			
		}
	    if(TOUCH_XPT_ReadXY() == 1)	
			{
				x=xpt_xy.x;
				x=(x-304)*175/3422;
				y=xpt_xy.y;
				y=(y-256)*219/3440;			
				if(x>174)
				{
					x=174;
				}
				if(y>218)
				{
					y=218;
				}		
				if( (x>115)&&(y<24) )	
				{					
    				 displayPageSetting();    //进入设置界面
					   TFT_ClearScreen(0x0000);		//清屏	
				}
			}
	}

}

		