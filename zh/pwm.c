/***************************************************************************************
 *	FileName					:	pwm.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 yezhihuo
 *
 *	Abstract Description		:	1602???
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
#include"pwm.h"

/**************************************************************
*	Macro Define Section
**************************************************************/
sbit PWM = P2^1;
#define PWM_MODE  10       //设置占空比模式

uchar pwmCount, pwmPeriod;          //占空比计数器，占空比标数
uint num;
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
*  @name:void pwmInit();
*	@description: 初始化pwm，开启震动
 *	@param		:none
 *	@return		: none
 *  @notice : 使用定时器1
 */
void pwmInit()
{
	EA = 1;
	TMOD = 0x20; // 开定时器1模式2
	TL1 = 0x6c; // 
	TH1 = 0x6c;
	ET1 = 1;
	TR1 = 1;
	pwmCount = 0;
	pwmPeriod = PWM_MODE;
	if( num % 100 == 0 )
	{
		pwmPeriod++;
		if( pwmPeriod == 100 )
		{
			pwmPeriod = 0;
		}
	}
}

/**
*  @name:void pwmInit();
*	@description: 初始化pwm，开启震动
 *	@param		:none
 *	@return		: none
 *  @notice : 使用定时器1
 */
void pwm() interrupt 3
{
	pwmCount++;
	num++;
	if( num > 60000 )
	{
		num = 0;
	}
	if( pwmCount == 100 )         //从新计数
	{
		pwmCount = 0;
	}
	if( pwmCount < pwmPeriod )    //控制输出
	{
		PWM = 1;
	}
	else
	{
		PWM = 0;
	}
}

void main()
{
		pwmInit();	
	while(1)
	{
    	if( num % 1000 == 0 )
	{
		pwmPeriod += 5;
		if( pwmPeriod > 100 )
		{
			pwmPeriod = 10;
		}
	}      
	}		
	;
}
