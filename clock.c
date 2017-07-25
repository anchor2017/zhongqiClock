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
uchar clockTag, sb;                     //每增加20次记录1s
sbit led = P2^0;
clockTime time, timeclock;
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
			if( clockTag == 1 )
			{
				 if(time.hour == timeclock.hour && time.minute == timeclock.minute)
				 {
					 led = 1;
				 }
			 }
		}			 
	}
	else
	{
	 sb++;
	}
}
