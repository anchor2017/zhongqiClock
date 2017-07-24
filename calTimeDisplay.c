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
*  @name:vvoid  displayPageTime()
*	@description: 显示主界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void  displayPageTime()
{
		if(anotherSur==1)		//判断是否要清屏
		{
			TFT_ClearScreen(0x0000);		//清屏
			anotherSur=0;		//如果不是设置界面返回则不需要清屏
		}
		
		/*触摸屏上主时钟界面的显示*/
		//
		while(TOUCH_XPT_ReadXY() != 1)
		{
			TFT_paintMainClock();
		}

		back=0;		   //不再进入时钟界面但是屏幕并不清除
		clockFlag=1;	//如果在时钟界面则时钟界面的触屏有效
		setFlag=0;	   //如果在时钟界面则设置界面的触屏无效
		i=0;		//每次重新进入设置页面都从小时开始调整	
}


/**
*  @name:void displayPageSet()
*	@description: 显示设置界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSet()
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
				back=1;
				set = 0;
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
			 TFT_paintTimeSet();           //显示设置的值
			if(i==6)	//如果时分秒都赋值完毕则可以重新赋值
			{
				i=0;
			}				
			}			
		}	
	}
}
	


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
      displayPageTime();     //显示主界面
	}
	/*进入设置界面*/
	if(set==1)		
	{	
     displayPageSet();  //显示设置界面
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
				back = 0;
			}
		}

		/*屏上功能部分检测反应（设置页面）一旦进入设置页面就停止走时，进入主时钟界面开始走时*/	 //不需要清屏
		if(setFlag==1)
		{
			setTime();      //设置时间
		}				
	} //触摸检测
}