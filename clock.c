      /***************************************************************************************
 *	FileName					:	clock.c
 *	CopyRight					:
 *	ModuleName				:
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	2017.7.22
 *	Author/Corportation			:	yezhihuo
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
#include"clock.h"
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
uchar sb = 0;                     //每增加20次记录1s
uchar clockTag = 0;                //0为关闭，1为开启，2为正在向
clockTime time, timeclock;

sbit PWM = P3^5;                           //震动信号输出
uchar pwmCount, pwmPeriod ;          //占空比计数器，占空比标数
uint num;
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
void initTimer()
{
	TMOD=0x01;		  //模式1
	TH0 = (65536 - 45874) / 256;
	TL0 = (65536 - 45874) % 256;   //0.05s
	ET0=1;		 //开定时器
	TR0=1;		 //开定时器中断
	EA=1;		 //开总中断
}

/**
*  @name: void timeFun() 
*	@description: 时钟计时
 *	@param		:none
 *	@return		: none
 *  @notice : 使用定时器0，程序运行期间始终运行
 */
void timeFun() interrupt 1
{
	TH0 = (65536 - 45870) / 256;
	TL0 = (65536 - 45870) % 256;   //0.05s
	if(sb >= 20 )             //20次为1s
	{
		sb = 0;
		if( time.second < 59 )				 //60秒
		{
			time.second++;
		}
		else
		{
			time.second = 0;                    
			if( time.minute <59 )			//60分钟
			{
				time.minute++;
			}
			else
			{
				time.minute = 0;
				if( time.hour <23 )           ///1小时
				{
		    	                                                                                                                                                                                                                                                                                                                                                                                                                                                        		time.hour++;
				}
				else
				{
					time.hour = 0;
				}
			}
		}			
			if( clockTag == 1 )           //判断闹钟
			{
				 if(time.hour == timeclock.hour && time.minute == timeclock.minute && time.second == timeclock.second)
				 {  
					 clockTag = 2;     
				 }
			 }		
	}
	else
	{
	 sb++;
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
	TH1 = 0XCC;
	TL1 = 0XCC;
	pwmCount++;
	num++;	
	if( num > 60000 )
	{	 
  num = 0;
	}
	if( num % 1000 == 0 )         //从新计数
	{
		pwmPeriod += 10;
	}
	if( pwmCount == 100 )
	{
		pwmCount = 0;
	}
	if( pwmPeriod > 100 )
	{
		pwmPeriod = PWM_MODE;
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

