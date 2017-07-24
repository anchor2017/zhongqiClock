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
}clockTime;              //��¼ʱ��


/**************************************************************
*	Global Variable Declare Section
**************************************************************/
#ifndef GLOBAL_TIME_             //�����ظ�����
#define GLOBAL_TIME_
extern clockTime time, timeclock;          //��¼ʱ��
extern uchar clockTag;
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
*	@description: �жϷ������⹦�ܼĴ������ã���ʱ��0��ʼ����
 *	@param		:none
 *	@return		: none
 *  @notice : 12MHZ
 */
void initTimer();

/**
*  @name: void setTime
*	@description:  ����ʱ��
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setTime();
/**
*  @name: void setClockTime
*	@description:  ��������ʱ��
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setClockTime();
#endif