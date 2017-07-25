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
extern uchar anotherSur;
//extern uchar set, back;	   //main.c/calTimeDisplay.c中有调用

//以下main.c中赋值/calTimeDisplay.c中调用
extern uchar TimeArray[];	//中间转化值
extern uchar i;	
extern long x, y;	
extern uchar set, back;  //设置标志位，返回标志位（先置1才能运行），全局变量在calTimeDisplay.h中声明
extern uchar setFlag, clockFlag;	//防止出现在一个界面按键却触发另外一个界面内容的错误
extern uchar oriTime;			 //修改时间错误时原来的时间

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
*  @name:void displayTemp(int temp)	 
*	@description: 显示温度
 *	@param		:temp = 温度 x 10
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp);


#endif