/***************************************************************************************
 *	File Name				:		
 *	CopyRight				:
 *	ModuleName				:	
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Data				:	
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for 
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef __AD_H
#define __AD_H


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
#define uint unsigned int
#define uchar unsigned char 
/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/
/**
*  @name: void delay(uint i)
*	@description: 延时函数
 *	@param： i 延时时间	
 *	@return		：none
 *  @notice ：none
 */
 void delayMs(uint i);
	 
 /**
*  @name:uint getTemp()
*	@description: 读取温度
 *	@param	： none 		
*	@return		: 读取到的温度
 *  @notice
 */
uint getTemp();


 /**
*  @name:void tempchang()
*	@description: 开始获取温度并转换
 *	@param			
 *	@return		
 *  @notice
 */
void tempchange();

/**
 *  @name:void writeData(uchar dat)
 *	@description : 写数据
 *	@param			：dat数据
 *	@return		
 *  @notice
 */
void writeData(uchar dat);

 /**
*  @name: void init()
*	@description: 初始化lcd
 *	@param			：none
 *	@return		：none
 *  @notice：none
 */
void init();

/**
*  @name:void writeCom(uchar com)
*	@description: 向lcd写命令
 *	@param		：com 命令	
 *	@return		： none
 *  @notice ： none
 */
void writeCom(uchar com);


 /**
 *  @name： void displayLcd(uchar x, uint num)
 *	@description：指定位置显示数字
 *	@param			：温度
 *	@return		：none
 *  @notice： none
 */
void displayLcd(uchar x, uint num);
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif