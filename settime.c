/***************************************************************************************
 *	FileName					:	settime.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:    设置时间
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
#include "GUI.h"
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
*  @name: void setTime
*	@description:  调整时间
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setTime()
{
	uchar num, tag = 0;
  ET0=0;		//关闭定时器，停止走时
			/*屏上数字部分检测（设置页面）*/	 //不需要清屏					
  i = 0;
	while(1) 
   {
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
		  //设置时间 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				num = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				num = 1;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				num = 2;
				tag = 1;
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				num = 3;
				tag = 1;
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				num = 4;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				num = 5;
				tag = 1;
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				num = 6;
				tag = 1;
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				num  = 7;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				num = 8;
				tag = 1;
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				num = 9;
				tag = 1;
			}																															
			else if((x<55)&&(y<24))	 //左上角
			{
				ET0=1;
        break;   //退出循环				
			}
			if( tag == 1 )       //判断按键是否有效
			{
				tag = 0;
       switch(i)
				{
					case 0:
             if( num < 3 )
						 {
                time.hour = time.hour % 10 + num * 10;
							 i++;
						 }							 
					    break;
					case 1: 
             if( num < 4 || time.hour < 20) 
						 {
                time.hour =time.hour - time.hour % 10 + num;
							 i++; 
						 }						  
					    break;
				case 2: 
             if( num < 6 )
						 {
                time.minute = time.minute % 10 + num * 10;
							 i++;
						 }	
					    break;
				case 3:
 					   time.minute =time.minute - time.minute % 10 + num;
			     	i++;
					    break;
				case 4: 
             if( num < 6 )
						 {
                time.second = time.second % 10 + num * 10;
							 i++;
						 }					 
					    break;
					case 5: 
					    time.second =time.second - time.second % 10 + num;
			      	i++;
					    break;
				}
			 TFT_paintTimeSet(time);           //显示设置的值
			if(i==6)	//如果时分秒都赋值完毕则可以重新赋值
			{
				i=0;
			}				
			}			
		}	
	}
}


/**
*  @name: void setClockTime
*	@description:  调整闹钟时间
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setClockTime()
{
	uchar num, tag = 0;
			/*屏上数字部分检测（设置页面）*/	 //不需要清屏					
  i = 0;
	clockTag = 1;               //闹钟开关
	while(1) 
   {
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
		  //设置时间 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				num = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				num = 1;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				num = 2;
				tag = 1;
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				num = 3;
				tag = 1;
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				num = 4;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				num = 5;
				tag = 1;
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				num = 6;
				tag = 1;
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				num  = 7;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				num = 8;
				tag = 1;
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				num = 9;
				tag = 1;
			}																															
			else if((x<55)&&(y<24))	 //左上角
			{
				ET0=1;
        break;   //退出循环				
			}
			if( tag == 1 )       //判断按键是否有效
			{
				tag = 0;
       switch(i)
				{
					case 0:
             if( num < 3 )
						 {
                timeclock.hour = timeclock.hour % 10 + num * 10;
							 i++;
						 }							 
					    break;
					case 1: 
             if( num < 4 || time.hour < 20) 
						 {
                timeclock.hour =timeclock.hour - timeclock.hour % 10 + num;
							 i++; 
						 }						  
					    break;
				case 2: 
             if( num < 6 )
						 {
                timeclock.minute = timeclock.minute % 10 + num * 10;
							 i++;
						 }	
					    break;
				case 3:
 					   timeclock.minute =timeclock.minute - timeclock.minute % 10 + num;
			     	i++;
					    break;
				case 4: 
             if( num < 6 )
						 {
                timeclock.second = timeclock.second % 10 + num * 10;
							 i++;
						 }					 
					    break;
					case 5: 
					    timeclock.second =timeclock.second - timeclock.second % 10 + num;
			      	i++;
					    break;
				}
			 TFT_paintTimeSet(timeclock);           //显示设置的值
			if(i==6)	//如果时分秒都赋值完毕则可以重新赋值
			{
				i=0;
			}				
			}			
		}	
	}
}
