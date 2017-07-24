/***************************************************************************************
 *	FileName					:	calTimeDisplay.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/

#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
#include "lcd_driver.h"
#include "clock.h"		//引用全局变量time

/**************************************************************
*	Macro Define Section
**************************************************************/

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name:void calTimeDisplay();
*	@description: 主时钟显示及时钟调整设置
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void CalTimeDisplay()	 
{		
	/*进入主时钟界面*/
	if(back==1)
	{
		if(anotherSur==1)		//判断是否要清屏
		{
			TFT_ClearScreen(0x0000);		//清屏
			anotherSur=0;		//如果不是设置界面返回则不需要清屏
		}		
		/*触摸屏上主时钟界面的显示*/
		while(TOUCH_XPT_ReadXY() != 1)
		{
			TFT_paintMainClock();
		}
		back=0;		   //不再进入时钟界面但是屏幕并不清除
		clockFlag=1;	//如果在时钟界面则时钟界面的触屏有效
		setFlag=0;	   //如果在时钟界面则设置界面的触屏无效
		i=0;		//每次重新进入设置页面都从小时开始调整
	}
	/*进入设置界面*/
	if(set==1)		
	{	
		/*线条及数字的基本框图*/		
		TFT_paintSetSur();
		/*将时间写在设置界面左偏上*/	 
		TFT_paintTimeSet();
					 
		set = 0;
		clockFlag=0;	   //如果在设置界面则时钟界面的触屏无效
		setFlag=1;	   //如果在设置界面则设置界面的触屏有效
		anotherSur=1;	//从设置界面返回主时钟界面需要清屏
	}

	/*触摸检测*/
	if(TOUCH_XPT_ReadXY() == 1)		
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
		/*屏上功能部分检测反应（时钟页面）*/	 //不需要清屏
		if(clockFlag==1)
		{
			if((x>115)&&(y<24))
			{
				set=1;		  //右上角
			}
		}
		/*屏上功能部分检测反应（设置页面）一旦进入设置页面就停止走时，进入主时钟界面开始走时*/	 //不需要清屏
		if(setFlag==1)
		{
			ET0=0;		//关闭定时器，停止走时
			/*屏上数字部分检测（设置页面）*/	 //不需要清屏						
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				TimeArray[i]=0;
				i++;

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>95)&&(y<135))	  //1
			{
				TimeArray[i]=1;
				i++;

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				TimeArray[i]=2;
				i++;

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>95)&&(y<135))  //3
			{
				oriTime=TimeArray[i];
				TimeArray[i]=3;
				i++;
								
				if(i==1)		 //时间校准限制
				{
					i--;
					TimeArray[i]=oriTime; 
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>145)&&(y<165))	  //4
			{
				oriTime=TimeArray[i];
				TimeArray[i]=4;
				i++;				

				if(i==1)		 //时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;  
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				oriTime=TimeArray[i];
				TimeArray[i]=5;
				i++;				

				if(i==1)		   //时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;  
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>145)&&(y<165)) //6
			{
				oriTime=TimeArray[i];
				TimeArray[i]=6;
				i++;				

				if((i==1) || (i==3) || (i==5))		//时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>175)&(y<205))	  //7
			{
				oriTime=TimeArray[i];
				TimeArray[i]=7;
				i++;

				if((i==1) || (i==3) || (i==5))		//时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				oriTime=TimeArray[i];
				TimeArray[i]=8;
				i++;

				if((i==1) || (i==3) || (i==5))		 //时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>175)&&(y<205)) //9
			{
				oriTime=TimeArray[i];
				TimeArray[i]=9;
				i++;

				if((i==1) || (i==3) || (i==5))	   //时间校准限制
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*重新设定的时间显示*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
						
			if(i==6)	//如果时分秒都赋值完毕则可以重新赋值
			{
				i=0;
			}

			if((x<55)&&(y<24))	 //左上角
			{
				back=1;
				ET0=1;		   
			}
		}				
	} //触摸检测
}