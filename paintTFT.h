/***************************************************************************************
 *	FileName					:	paintTFT.h
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
#ifndef __PAINTTFT_H
#define __PAINTTFT_H

/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include <reg52.h>
#include"clock.h"
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


/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name:void paintTFT();
*	@description: 在触摸屏上画图
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void TFT_paintSetSur(uchar *s);		//设置界面的显示
/**
*  @name:void TFT_paintSetTimeA(bit tag)
*	@description: 设置时间界面1
 *	@param		:tag = 1时设置时间。=0时设置闹钟
 *	@return		: none
 *  @notice : none
 *  @use : 在触摸屏显示调整时间的基本框架（设置界面）
 */
 void TFT_paintSetTime(bit tag);
/**
*  @name:void TFT_paintTimeSet(clockTime settime);
*	@description: 重新设置时间的显示
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void TFT_paintTimeSet(clockTime settime);

/**
/**
*  @name:void TFT_paintTimeSet();
*	@description: 主界面的时间显示
 *	@param		: bit tag 是否需要全屏刷新显示，1为刷新显示
 *	@return		: none
 *  @notice : none
 *  @use : 得到时分秒六位，并显示在触摸屏的中间
 */
void TFT_paintMainClock(bit tag);


#endif
