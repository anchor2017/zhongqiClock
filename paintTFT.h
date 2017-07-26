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
*	@description: �ڴ������ϻ�ͼ
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void TFT_paintSetSur(uchar *s);		//���ý������ʾ

/**
*  @name:void TFT_paintTimeSet(clockTime settime);
*	@description: ��������ʱ�����ʾ
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void TFT_paintTimeSet(clockTime settime);

/**
*  @name:void TFT_paintTimeSet();
*	@description: �������ʱ����ʾ
 *	@param		: ʱ����
 *	@return		: none
 *  @notice : none
 *  @use : �õ�ʱ������λ������ʾ�ڴ��������м�
 */
void TFT_paintMainClock();


#endif