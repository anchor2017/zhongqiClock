/***************************************************************************************
 *	FileName					:	calTimeDisplay.h
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
#ifndef __CALTIMEDISPLAY_H
#define __CALTIMEDISPLAY_H

/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include <reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


//以下main.c中赋值/calTimeDisplay.c中调用
extern uchar TimeArray[];	//中间转化值
extern uchar i;	
extern long x, y;	
extern uchar pwmCount, pwmPeriod ;          //占空比计数器，占空比标数

/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: displayPageSetting
*	@description: 显示设置界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting();

/**
*  @name:void displayTemp(int temp,bit tag)	 
*	@description: 显示温度
 *	@param		:temp = 温度 x 10, tag=1重新显示所有内容
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp ,bit tag)	 ;
/**
*  @name: displayPageSetting
*	@description: 显示闹钟响起时的界面
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageClock();

#endif