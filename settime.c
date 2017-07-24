/***************************************************************************************
 *	FileName					:	settime.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:    ����ʱ��
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
*  @name: void setTime
*	@description:  ����ʱ��
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setTime()
{
	uchar num, tag = 0;
  ET0=0;		//�رն�ʱ����ֹͣ��ʱ
			/*�������ֲ��ּ�⣨����ҳ�棩*/	 //����Ҫ����					
  i = 0;
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
		  //����ʱ�� 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				num = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				num = 1;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				num = 2;
				tag = 1;
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				num = 3;
				tag = 1;
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				num = 4;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				num = 5;
				tag = 1;
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				num = 6;
				tag = 1;
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				num  = 7;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				num = 8;
				tag = 1;
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				num = 9;
				tag = 1;
			}																															
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
				ET0=1;
        break;   //�˳�ѭ��				
			}
			if( tag == 1 )       //�жϰ����Ƿ���Ч
			{
				tag = 0;
       switch(i)
				{
					case 0:
             if( num < 3 )
						 {
                time.hour = time.hour % 10 + num * 10;
							 i++;
						 }							 
					    break;
					case 1: 
             if( num < 4 || time.hour < 20) 
						 {
                time.hour =time.hour - time.hour % 10 + num;
							 i++; 
						 }						  
					    break;
				case 2: 
             if( num < 6 )
						 {
                time.minute = time.minute % 10 + num * 10;
							 i++;
						 }	
					    break;
				case 3:
 					   time.minute =time.minute - time.minute % 10 + num;
			     	i++;
					    break;
				case 4: 
             if( num < 6 )
						 {
                time.second = time.second % 10 + num * 10;
							 i++;
						 }					 
					    break;
					case 5: 
					    time.second =time.second - time.second % 10 + num;
			      	i++;
					    break;
				}
			 TFT_paintTimeSet(time);           //��ʾ���õ�ֵ
			if(i==6)	//���ʱ���붼��ֵ�����������¸�ֵ
			{
				i=0;
			}				
			}			
		}	
	}
}


/**
*  @name: void setClockTime
*	@description:  ��������ʱ��
*	@param		:none
 *	@return		: none
 *  @notice : none
 */
void setClockTime()
{
	uchar num, tag = 0;
			/*�������ֲ��ּ�⣨����ҳ�棩*/	 //����Ҫ����					
  i = 0;
	clockTag = 1;               //���ӿ���
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
		  //����ʱ�� 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				num = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				num = 1;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				num = 2;
				tag = 1;
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				num = 3;
				tag = 1;
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				num = 4;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				num = 5;
				tag = 1;
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				num = 6;
				tag = 1;
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				num  = 7;
				tag = 1;
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				num = 8;
				tag = 1;
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				num = 9;
				tag = 1;
			}																															
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
				ET0=1;
        break;   //�˳�ѭ��				
			}
			if( tag == 1 )       //�жϰ����Ƿ���Ч
			{
				tag = 0;
       switch(i)
				{
					case 0:
             if( num < 3 )
						 {
                timeclock.hour = timeclock.hour % 10 + num * 10;
							 i++;
						 }							 
					    break;
					case 1: 
             if( num < 4 || time.hour < 20) 
						 {
                timeclock.hour =timeclock.hour - timeclock.hour % 10 + num;
							 i++; 
						 }						  
					    break;
				case 2: 
             if( num < 6 )
						 {
                timeclock.minute = timeclock.minute % 10 + num * 10;
							 i++;
						 }	
					    break;
				case 3:
 					   timeclock.minute =timeclock.minute - timeclock.minute % 10 + num;
			     	i++;
					    break;
				case 4: 
             if( num < 6 )
						 {
                timeclock.second = timeclock.second % 10 + num * 10;
							 i++;
						 }					 
					    break;
					case 5: 
					    timeclock.second =timeclock.second - timeclock.second % 10 + num;
			      	i++;
					    break;
				}
			 TFT_paintTimeSet(timeclock);           //��ʾ���õ�ֵ
			if(i==6)	//���ʱ���붼��ֵ�����������¸�ֵ
			{
				i=0;
			}				
			}			
		}	
	}
}
