/***************************************************************************************
 *	FileName					:	calTimeDisplay.h
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
#ifndef __CALTIMEDISPLAY_H
#define __CALTIMEDISPLAY_H

/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include <reg52.h>

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
extern uchar anotherSur;
//extern uchar set, back;	   //main.c/calTimeDisplay.c���е���

//����main.c�и�ֵ/calTimeDisplay.c�е���
extern uchar TimeArray[];	//�м�ת��ֵ
extern uchar i;	
extern long x, y;	
extern uchar set, back;  //���ñ�־λ�����ر�־λ������1�������У���ȫ�ֱ�����calTimeDisplay.h������
extern uchar setFlag, clockFlag;	//��ֹ������һ�����水��ȴ��������һ���������ݵĴ���
extern uchar oriTime;			 //�޸�ʱ�����ʱԭ����ʱ��

/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: displayPageSetting
*	@description: ��ʾ���ý���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting();

/**
*  @name:void displayTemp(int temp)	 
*	@description: ��ʾ�¶�
 *	@param		:temp = �¶� x 10
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp);


#endif