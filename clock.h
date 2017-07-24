/***************************************************************************************
 *	File Name				:		clock.h
 *	CopyRight				:
 *	ModuleName				:	
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Data				:	
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for  lcd1602
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/ 

#ifndef __CLOCK_H
#define __CLOCK_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uint
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char 
#endif


/**************************************************************
*	Struct Define Section
**************************************************************/
typedef struct clockTime
{
	uchar hour;
	uchar minute;
	uchar second;
}clockTime;              //记录时间


/**************************************************************
*	Global Variable Declare Section
**************************************************************/
#ifndef GLOBAL_TIME_             //避免重复定义
#define GLOBAL_TIME_
extern clockTime time;          //记录时间
#endif
/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void timeFun() 
*	@description: 中断服务特殊功能寄存器配置（定时器0初始化）
 *	@param		:none
 *	@return		: none
 *  @notice : 12MHZ
 */
void initTimer();


#endif