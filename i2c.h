/***************************************************************************************
 *	FileName					:	main.c
 *	CopyRight					:
 *	ModuleName				:
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	2017.47.10
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
#ifndef  _CLOCK_H
#define _CLOCK_H

/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>
#include<intrins.h>
/**************************************************************
*	Macro Define Section  
**************************************************************/
#define uint unsigned int
#define uchar unsigned char 
extern uchar  write;



/**************************************************************
*	Struct Define Section
**************************************************************/
typedef struct clock
{
	uchar hour;
	uchar minute;
	uchar second;
}clock;


/**************************************************************
*	Prototype Declare Section  ????
**************************************************************/


/**************************************************************
*	Global Variable Declare Section????
**************************************************************/
extern uchar sb, ld;
extern clock time;
extern uchar code table[16];


/**
 *  @name        :void delay()
 *	@description : 微秒延时函数
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void delay();

/*  @name        : void init()
 *	@description : 总线初始化
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void initI2C();

/*  @name        : uchar readAdd()
 *	@description :
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
uchar readAdd(uchar address);

/*  @name        : void writeAdd(uchar adress, uchar date)
 *	@description : 向从机发送数据
 *	@param		 : address 从机
 *	@return		 : none
 *  @notice      : None
 */
void writeAdd(uchar address, uchar date);

 /*  @name        :void delayms()
 *	@description : ms延时函数
 *	@param		 : uint i 延时ims
 *	@return		 : none
 *  @notice      : None
 */
void delayms(uint i);




#endif