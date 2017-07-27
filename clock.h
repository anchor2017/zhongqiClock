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

#define PWM_MODE  70      //设置占空比模式
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
extern clockTime time, timeclock;          //记录时间
extern uchar clockTag;
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

/**
*  @name: clockTime setTime(bit tag,clock setTime)
*	@description:  调整时间
*	@param		:setime 需要设置的时间
 *	@return		: 设置后的时间
 *  @notice : none
 */
clockTime setTimeA(bit tag,clockTime setTime);

#endif