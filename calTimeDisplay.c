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
#include"AD.H"
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

/**
*  @name:void displayTemp(int temp)	 
*	@description: 显示温度
 *	@param		:temp = 温度 x 10
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp)	 
{
	 uchar code table[] ={
0x38,0x00,0x6C,0x00,0xC6,0x00,0x82,0x00,0xC6,0x00,0x6C,0x00,0x38,0xFE,0x01,0xFE,
0x07,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
0x0E,0x00,0x0E,0x00,0x06,0x00,0x03,0xFE,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,
	 };        //摄氏度		 
	 uchar color,k,j,stemp[][2]= { 0, '\0', 0, '\0', '.', '\0', 0,  '\0'};
	 stemp[0][0] = temp / 100 + '0';     
	 stemp[1][0] = (temp % 100) / 10 + '0';
	 stemp[3][0] = temp % 10 + '0';
   GUI_WriteASCII(60, 170, stemp[0], 0x7fff, 0x0000);	
   GUI_WriteASCII(70, 170, stemp[1], 0x7fff, 0x0000);	 
   GUI_WriteASCII(80, 170, stemp[2], 0x7fff, 0x0000);
   GUI_WriteASCII(90, 170, stemp[3], 0x7fff, 0x0000);	
	 //摄氏度符号
		TFT_SetWindow(105,170,120, 170+23);	   //15，23
		for (k=0; k<48; k++)
		{
			color = table[k];
			for (j=0; j<8; j++) 
			{
				if ((color&0x80) == 0x80)
				{
					TFT_WriteColor(0x7fff);
				} 						
				else
				{
					TFT_WriteColor(0x000);
				} 	
				color <<= 1;
			}
		}	 
 } 