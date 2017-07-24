#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"
#include "calTimeDisplay.h"
#include "paintTFT.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;

uchar anotherSur=1;		//¿ÉÒÔÏÈÉèÖÃÎª1£¬µÚÒ»´ÎÐèÒªÇåÆÁ(Ö®ºóÖ»ÊÇÊ±¼ä¼ÆÊý¾Í²»ÐèÒªÔÙ´ÎÇåÆÁ)£¬ÔÚcalTimeDisplay.hÖÐÉùÃ÷ÎªÈ«¾Ö±äÁ¿	
long x=0, y=0;	
uchar set=0, back=1;  //ÉèÖÃ±êÖ¾Î»£¬·µ»Ø±êÖ¾Î»£¨ÏÈÖÃ1²ÅÄÜÔËÐÐ£©£¬È«¾Ö±äÁ¿ÔÚcalTimeDisplay.hÖÐÉùÃ÷
uchar setFlag=0, clockFlag=0;	//·ÀÖ¹³öÏÖÔÚÒ»¸ö½çÃæ°´¼üÈ´´¥·¢ÁíÍâÒ»¸ö½çÃæÄÚÈÝµÄ´íÎó
uchar oriTime=0;			 //ÐÞ¸ÄÊ±¼ä´íÎóÊ±Ô­À´µÄÊ±¼ä

void main()
{
	//uchar h1, h0, m1, m0, s1, s0;	 //±äÁ¿¶¨Òå
 P2 = 0x00;
	TFT_Init();				//³õÊ¼»¯´¥ÃþÆÁÏÔÊ¾
  TFT_ClearScreen(0x0000);		//ÇåÆÁ£¬Ïû³ýÆÁÄ»Ö®Ç°ÏÔÊ¾ÄÚÈÝµÄÓ°Ïì
	initTimer();		 //³õÊ¼»¯¶¨Ê±Æ÷0£¨Ê±ÖÓ£	
	while(1)
	{
 
      TFT_paintMainClock();
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
    				 displayPageSetting();    //½øÈëÉèÖÃ½çÃæ
					   TFT_ClearScreen(0x0000);		//ÇåÆÁ	
				}
			}
	}

}

		