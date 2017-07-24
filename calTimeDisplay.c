/***************************************************************************************
 *	FileName					:	calTimeDisplay.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:  ��ʾ����
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

#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
#include "GUI.h"
#include "lcd_driver.h"
#include "clock.h"		//����ȫ�ֱ���time
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


/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/


/**
*  @name:void displayPageSet()
*	@description: ��ʾ����ʱ�����
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetTime()
{
		/*���������ֵĻ�����ͼ*/		
		TFT_paintSetSur("TIME");
		/*��ʱ��д�����ý�����ƫ��*/	 
		TFT_paintTimeSet(time);					 
		clockFlag=0;	   //��������ý�����ʱ�ӽ���Ĵ�����Ч
		setFlag=1;	   //��������ý��������ý���Ĵ�����Ч
		anotherSur=1;	//�����ý��淵����ʱ�ӽ�����Ҫ����	
    setTime();        //����ʱ��
}

/**
*  @name:void displayPageSetClock()
*	@description: ��ʾ�������ӽ���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetClock()
{
		/*���������ֵĻ�����ͼ*/		
		TFT_paintSetSur("CLOCK");
		/*��ʱ��д�����ý�����ƫ��*/	 
		TFT_paintTimeSet(timeclock);					 
		clockFlag=0;	   //��������ý�����ʱ�ӽ���Ĵ�����Ч
		setFlag=1;	   //��������ý��������ý���Ĵ�����Ч
		anotherSur=1;	//�����ý��淵����ʱ�ӽ�����Ҫ����	
	  setClockTime();
}



/**
*  @name: displayPageSetting
*	@description: ��ʾ���ý���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting()
{
	TFT_ClearScreen(0x0000);		//����	
	GUI_WriteASCII(0,0, "BACK", 0x001F, 0x0000);
	GUI_WriteASCII(50,24, "SET", 0xFFE0, 0x0000);
	GUI_WriteASCII(50, 94, "TIME", 0x7ff, 0x0000);	
	GUI_WriteASCII(50, 134, "CLOCK", 0x7fff, 0x0000);	
	GUI_Line(20, 50, 155, 50, 0xF800);     //������
	GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
	GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			/*ת��*/
			x=xpt_xy.x;
			x=(x-304)*175/3422;
			y=xpt_xy.y;
			y=(y-256)*219/3440;			
			if(x>174)
			{
				x=174;
			}
			if(y>218)
			{
					y=218;
			}
			if( y < 135 && y > 95)       //ѡ������ʱ��
			{
				displayPageSetTime();
			}
			else if( y > 135 && y < 165)   // ѡ����������
			{
				displayPageSetClock();
			}
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
				back=1;
				set = 0;
			TFT_ClearScreen(0x0000);		//����
        break;   //�˳�ѭ��				
			}
		}
	}		
}

	