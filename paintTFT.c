 /***************************************************************************************
 *	FileName					:	paintTFT.c
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

/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include <reg52.h>
#include "paintTFT.h"
#include "GUI.h"
#include "clock.h"

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
*  @name:void paintTFT();
*	@description: 在触摸屏上画图
 *	@param		:none
 *	@return		: none
 *  @notice : none
 *  @use : 在触摸屏显示调整时间的基本框架（设置界面）
 */
void TFT_paintSetSur(uchar *s)		//设置界面的显示
{
	TFT_ClearScreen(0x0000);
	GUI_WriteASCII(47, 24, s, 0xFFE0, 0x0000);	  //x, y	
  	//横线
	GUI_Line(20, 50, 155, 50, 0xF800);  //x, y, x, y
	GUI_Line(20, 90, 155, 90, 0xF800);  //x, y, x, y
	GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
	GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
	GUI_Line(20, 210, 155, 210, 0xF800);  //x, y, x, y	
	//竖线
   	GUI_Line(65, 90, 65, 210, 0xF800);  //x, y, x, y
	GUI_Line(110, 50, 110, 210, 0xF800);  //x, y, x, y	
	//数字	x, y		
   	GUI_WriteASCII(31, 94, "1", 0xF800, 0x0000);	 //1
	GUI_WriteASCII(81, 94, "2", 0xF800, 0x0000);	 //2
	GUI_WriteASCII(127, 94, "3", 0xF800, 0x0000);	 //3
	GUI_WriteASCII(31, 134, "4", 0xF800, 0x0000);	 //4
	GUI_WriteASCII(81, 134, "5", 0xF800, 0x0000);	 //5
	GUI_WriteASCII(127, 134, "6", 0xF800, 0x0000);	 //6
	GUI_WriteASCII(31, 174, "7", 0xF800, 0x0000);	 //7
	GUI_WriteASCII(81, 174, "8", 0xF800, 0x0000);	 //8
	GUI_WriteASCII(127, 174, "9", 0xF800, 0x0000);	 //9
    GUI_WriteASCII(127, 58, "0", 0xF800, 0x0000);	 //0	
	GUI_WriteASCII(0, 0, "BACK", 0x001F, 0x0000);	  //返回   左上角

}

/**
*  @name:void TFT_paintTimeSet();
*	@description: 主界面的时间显示
 *	@param		: 时分秒
 *	@return		: none
 *  @notice : none
 *  @use : 得到时分秒六位，并显示在触摸屏的中间
 */
void TFT_paintMainClock()
{
	uchar h1[]={0,'\0'}, h0[]={0,'\0'};
	uchar m1[]={0,'\0'}, m0[]={0,'\0'};
	uchar s1[]={0,'\0'}, s0[]={0,'\0'};	//存放时分秒
	
	/*设置界面的显示时间*/
	h1[0]=time.hour/10+'0';
	h0[0]=time.hour%10+'0';
	m1[0]=time.minute/10+'0';
	m0[0]=time.minute%10+'0';
	s1[0]=time.second/10+'0';
	s0[0]=time.second%10+'0';

	/*将时间显示在触摸屏上*/
	GUI_WriteASCII2(10, 100, h1, 0xF800, 0x0000);	 //h1			 	
	GUI_WriteASCII2(30, 100, h0, 0xF800, 0x0000);	 //h0									 	
	GUI_WriteASCII2(50, 94, ":", 0xF800, 0x0000);
	GUI_WriteASCII2(70, 100, m1, 0xF800, 0x0000);	 //m1			 	
	GUI_WriteASCII2(90, 100, m0, 0xF800, 0x0000);	 //m0
	GUI_WriteASCII2(110, 94, ":", 0xF800, 0x0000);									 	
	GUI_WriteASCII2(130, 100, s1, 0xF800, 0x0000);	 //s1			 	
	GUI_WriteASCII2(150, 100, s0, 0xF800, 0x0000);	 //s0						 	
	GUI_WriteASCII(127, 0, "SET", 0x001F, 0x0000);	 //设置   右上角
}

/**
*  @name:void TFT_paintTimeSet(clockTime setime)
*	@description: 重新设置时间的显示
 *	@param		: 时分秒
 *	@return		: none
 *  @notice : none
 *  @use : 得到时分秒六位，并显示在触摸屏的左上角
 */
void TFT_paintTimeSet(clockTime setime)
{
	uchar h1[]={0,'\0'}, h0[]={0,'\0'};
	uchar m1[]={0,'\0'}, m0[]={0,'\0'};
	uchar s1[]={0,'\0'}, s0[]={0,'\0'};	//存放时分秒

	/*得到设置界面的显示时间*/
	h1[0]=setime.hour/10+'0';
	h0[0]=setime.hour%10+'0';
	m1[0]=setime.minute/10+'0';
	m0[0]=setime.minute%10+'0';
	s1[0]=setime.second/10+'0';
	s0[0]=setime.second%10+'0';
	/*将时间写在设置界面左偏上*/
	GUI_WriteASCII(39, 56, ":", 0xF800, 0x0000);
	GUI_WriteASCII(71, 56, ":", 0xF800, 0x0000);
	GUI_WriteASCII(17, 58, h1, 0xF800, 0x0000);	   //宽度12
	GUI_WriteASCII(29, 58, h0, 0xF800, 0x0000);
	GUI_WriteASCII(49, 58, m1, 0xF800, 0x0000);
	GUI_WriteASCII(61, 58, m0, 0xF800, 0x0000);
	GUI_WriteASCII(81, 58, s1, 0xF800, 0x0000);
	GUI_WriteASCII(93, 58, s0, 0xF800, 0x0000);
}