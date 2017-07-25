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

uchar anotherSur=1;		//����������Ϊ1����һ����Ҫ����(֮��ֻ��ʱ������Ͳ���Ҫ�ٴ�����)����calTimeDisplay.h������Ϊȫ�ֱ���	
long x=0, y=0;	
uchar set=0, back=1;  //���ñ�־λ�����ر�־λ������1�������У���ȫ�ֱ�����calTimeDisplay.h������
uchar setFlag=0, clockFlag=0;	//��ֹ������һ�����水��ȴ��������һ���������ݵĴ���
uchar oriTime=0;			 //�޸�ʱ�����ʱԭ����ʱ��

void main()
{
	//uchar h1, h0, m1, m0, s1, s0;	 //�������
	clockTime lasttime;
  P2 = 0x00;
	TFT_Init();				//��ʼ����������ʾ
  TFT_ClearScreen(0x0000);		//������������Ļ֮ǰ��ʾ���ݵ�Ӱ��
	initTimer();		 //��ʼ����ʱ��0��ʱ�ӣ	
	tempchange();   //��ʼ���¶�
	lasttime = time;         
	while(1)
	{
	//	if( lasrtime != time )       //��
		{
			lasttime = time;
      TFT_paintMainClock();           // ��ʾʱ��
			tempchange();   
			displayTemp(getTemp());           // ��ʾ�¶�			
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
    				 displayPageSetting();    //�������ý���
					   TFT_ClearScreen(0x0000);		//����	
				}
			}
	}

}

		