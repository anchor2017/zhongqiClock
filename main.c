#include <reg52.h>
#include "gui.h"
#include "touch.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

//uchar h1, h0, m1, m0, s1, s0;
//uchar set;		//进入设置界面
//uchar back;	   //返回时钟界面

void main()
{
	uchar h1[1]={0};
	uchar h0[1]={0};
	uchar m1[1]={0};
	uchar m0[1]={0};
	uchar s1[1]={0};
	uchar s0[1]={0};	//存放时分秒
	uchar hour1=0, hour0=0, min1=0, min0=0, sec1=0, sec0=0;
	uchar Time[]={0, 0, 0, 0, 0, 0};
	
	uchar i=0;		//i与Time数组有关
	uint x=0, y=0;	//存放x,y坐标
	uchar set=0, back=0;  //设置时间，返回主时钟
	
	h1[0]=hour1+'0';
	//h0[0]=hour0+'0';
	//m1[0]=min1+'0';
	//m0[0]=min0+'0';
	s1[0]=sec1+'0';
	s0[0]=sec0+'0';


	 /*时钟原界面*/
	 TFT_Init();				//初始化
	 Delay(5);
	 TFT_ClearScreen(0x0000);	 //清屏

	//GUI_WriteASCII2(20, 100, h1, 0xF800, 0x0000);

	//GUI_WriteASCII(20, 100, "3", 0xF800, 0x0000);	 //h1			 	
	//GUI_WriteASCII(36, 170, h0, 0xF800, 0x0000);	 //h0				 	
	//GUI_WriteASCII(46, 170, m1, 0xF800, 0x0000);	 //m1			 	
	//GUI_WriteASCII(62, 170, m0, 0xF800, 0x0000);	 //m0				 	
	GUI_WriteASCII(72, 170, s1, 0xF800, 0x0000);	 //s1			 	
	//GUI_WriteASCII(88, 170, s0, 0xF800, 0x0000);	 //s0			 	
	GUI_WriteASCII(127, 0, "SET", 0x001F, 0x0000);		 //设置按钮

	 while(1)
	 {
		
		/*时钟界面*/
		if(back==1)
		{
			TFT_ClearScreen(0x0000);
			GUI_ShowPicture(0, 0, 150, 150);
			GUI_WriteASCII(20, 94, h1, 0xF800, 0x0000);	 //h1			 	
			GUI_WriteASCII(36, 94, h0, 0xF800, 0x0000);	 //h0
						 	
			GUI_WriteASCII(46, 94, m1, 0xF800, 0x0000);	 //m1			 	
			GUI_WriteASCII(62, 94, m0, 0xF800, 0x0000);	 //m0
						 	
			GUI_WriteASCII(72, 94, s1, 0xF800, 0x0000);	 //s1			 	
			GUI_WriteASCII(88, 94, s0, 0xF800, 0x0000);	 //s0			 	
			GUI_WriteASCII(127, 0, "SET", 0x001F, 0x0000);		 //设置按
		}

		/*设置界面*/
		if(set==1)		
		{
			TFT_ClearScreen(0x0000);
			GUI_WriteASCII(47, 24, "CLOCK", 0xFFE0, 0x0000);	  //x, y	
		  	//横线
			GUI_Line(20, 50, 155, 50, 0xF800);  //x, y, x, y
			GUI_Line(20, 90, 155, 90, 0xF800);  //x, y, x, y
			GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
			GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
			GUI_Line(20, 210, 155, 210, 0xF800);  //x, y, x, y	
			//竖线
		   	GUI_Line(65, 90, 65, 210, 0xF800);  //x, y, x, y
			GUI_Line(110, 50, 110, 210, 0xF800);  //x, y, x, y	
			//数字	x, y		
		   	GUI_WriteASCII(31, 94, "1", 0xF800, 0x0000);	 //1
			GUI_WriteASCII(81, 94, "2", 0xF800, 0x0000);	 //2
			GUI_WriteASCII(127, 94, "3", 0xF800, 0x0000);	 //3
			GUI_WriteASCII(31, 134, "4", 0xF800, 0x0000);	 //4
			GUI_WriteASCII(81, 134, "5", 0xF800, 0x0000);	 //5
			GUI_WriteASCII(127, 134, "6", 0xF800, 0x0000);	 //6
			GUI_WriteASCII(31, 174, "7", 0xF800, 0x0000);	 //7
			GUI_WriteASCII(81, 174, "8", 0xF800, 0x0000);	 //8
			GUI_WriteASCII(127, 174, "9", 0xF800, 0x0000);	 //9
		    GUI_WriteASCII(127, 58, "0", 0xF800, 0x0000);	 //0	
			GUI_WriteASCII(111, 0, "BACK", 0x001F, 0x0000);	 
			set = 0;
		}

		if(TOUCH_XPT_ReadXY()==1)
		{
			/*转化*/
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
			
			/*屏上数字*/
			if((x>115)&&(y<24))
			{
				back=1;
			}
			if((x>115)&&(y<45)&&(y>85))	  //0
			{
				Time[i]=0;
				i++;
			}
			if((x<60)&&(y<95)&&(y>135))	  //1
			{
				Time[i]=1;
				i++;
			}
			if((x>70)&&(x<105)&&(y<95)&&(y>135)) //2
			{
				Time[i]=2;
				i++;
			}
			if((x>115)&&(y<95)&&(y>135))  //3
			{
				Time[i]=3;
				i++;
			}
			if((x<60)&&(y<145)&&(y>165))	  //4
			{
				Time[i]=4;
				i++;
			}
			if((x>70)&&(x<105)&&(y<145)&&(y>165)) //5
			{
				Time[i]=5;
				i++;
			}
			if((x>115)&&(y<145)&&(y>165)) //6
			{
				Time[i]=6;
				i++;
			}
			if((x<60)&&(y<175)&(y>205))	  //7
			{
				Time[i]=7;
				i++;
			}
			if((x>70)&&(x<105)&&(y<175)&&(y>205)) //8
			{
				Time[i]=8;
				i++;
			}
			if((x>115)&&(y<175)&&(y>205)) //9
			{
				Time[i]=9;
				i++;
			}
			h1[0]=Time[0];
			h0[0]=Time[1];
			m1[0]=Time[2];
			m0[0]=Time[3];
			s1[0]=Time[4];
			s0[0]=Time[5];
		}
	 }
}