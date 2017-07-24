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
 *	Abstract Description		:  显示界面
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
*  @name:void displayPageSet()
*	@description: 显示设置时间界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetTime()
{
		/*线条及数字的基本框图*/		
		TFT_paintSetSur("TIME");
		/*将时间写在设置界面左偏上*/	 
		TFT_paintTimeSet(time);					 
		clockFlag=0;	   //如果在设置界面则时钟界面的触屏无效
		setFlag=1;	   //如果在设置界面则设置界面的触屏有效
		anotherSur=1;	//从设置界面返回主时钟界面需要清屏	
    setTime();        //设置时间
}

/**
*  @name:void displayPageSetClock()
*	@description: 显示设置闹钟界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetClock()
{
		/*线条及数字的基本框图*/		
		TFT_paintSetSur("CLOCK");
		/*将时间写在设置界面左偏上*/	 
		TFT_paintTimeSet(timeclock);					 
		clockFlag=0;	   //如果在设置界面则时钟界面的触屏无效
		setFlag=1;	   //如果在设置界面则设置界面的触屏有效
		anotherSur=1;	//从设置界面返回主时钟界面需要清屏	
	  setClockTime();
}



/**
*  @name: displayPageSetting
*	@description: 显示设置界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting()
{
	TFT_ClearScreen(0x0000);		//清屏	
	GUI_WriteASCII(0,0, "BACK", 0x001F, 0x0000);
	GUI_WriteASCII(50,24, "SET", 0xFFE0, 0x0000);
	GUI_WriteASCII(50, 94, "TIME", 0x7ff, 0x0000);	
	GUI_WriteASCII(50, 134, "CLOCK", 0x7fff, 0x0000);	
	GUI_Line(20, 50, 155, 50, 0xF800);     //画横线
	GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
	GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
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
			if( y < 135 && y > 95)       //选择设置时间
			{
				displayPageSetTime();
			}
			else if( y > 135 && y < 165)   // 选择设置闹钟
			{
				displayPageSetClock();
			}
			else if((x<55)&&(y<24))	 //左上角
			{
				back=1;
				set = 0;
			TFT_ClearScreen(0x0000);		//清屏
        break;   //退出循环				
			}
		}
	}		
}

	