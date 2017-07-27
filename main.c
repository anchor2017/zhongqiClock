#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"
#include "AD.H"
#include "paintTFT.h"
#include "gy521.h"
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;
long x=0, y=0;	


void main()
{
	bit backTag = 1;           //从其他界面返回主界面标志
	uchar cou = 50;
  P3 = 0x00;
  initMPU();
	TFT_Init();				//初始化触摸屏显示
  TFT_ClearScreen(0x0000);		//清屏，消除屏幕之前显示内容的影响
	initTimer();		 //初始化定时器0（时钟�	
	tempchange();   //初始化温度   
	while(1)
	{
	   if( clockTag == 2 )       //闹钟响起
		 {
			 displayPageClock();
		 }
    TFT_paintMainClock(backTag);           // 显示时间
		 backTag = 0;
		 if( cou == 50 )
		 {
			 cou = 0;
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
					   backTag = 1;
				}
			}
			cou++;
	}

}

		