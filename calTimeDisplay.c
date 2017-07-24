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

#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
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
*  @name:void calTimeDisplay();
*	@description: ��ʱ����ʾ��ʱ�ӵ�������
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void CalTimeDisplay()	 
{		
	/*������ʱ�ӽ���*/
	if(back==1)
	{
		if(anotherSur==1)		//�ж��Ƿ�Ҫ����
		{
			TFT_ClearScreen(0x0000);		//����
			anotherSur=0;		//����������ý��淵������Ҫ����
		}		
		/*����������ʱ�ӽ������ʾ*/
		while(TOUCH_XPT_ReadXY() != 1)
		{
			TFT_paintMainClock();
		}
		back=0;		   //���ٽ���ʱ�ӽ��浫����Ļ�������
		clockFlag=1;	//�����ʱ�ӽ�����ʱ�ӽ���Ĵ�����Ч
		setFlag=0;	   //�����ʱ�ӽ��������ý���Ĵ�����Ч
		i=0;		//ÿ�����½�������ҳ�涼��Сʱ��ʼ����
	}
	/*�������ý���*/
	if(set==1)		
	{	
		/*���������ֵĻ�����ͼ*/		
		TFT_paintSetSur();
		/*��ʱ��д�����ý�����ƫ��*/	 
		TFT_paintTimeSet();
					 
		set = 0;
		clockFlag=0;	   //��������ý�����ʱ�ӽ���Ĵ�����Ч
		setFlag=1;	   //��������ý��������ý���Ĵ�����Ч
		anotherSur=1;	//�����ý��淵����ʱ�ӽ�����Ҫ����
	}

	/*�������*/
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
		/*���Ϲ��ܲ��ּ�ⷴӦ��ʱ��ҳ�棩*/	 //����Ҫ����
		if(clockFlag==1)
		{
			if((x>115)&&(y<24))
			{
				set=1;		  //���Ͻ�
			}
		}
		/*���Ϲ��ܲ��ּ�ⷴӦ������ҳ�棩һ����������ҳ���ֹͣ��ʱ��������ʱ�ӽ��濪ʼ��ʱ*/	 //����Ҫ����
		if(setFlag==1)
		{
			ET0=0;		//�رն�ʱ����ֹͣ��ʱ
			/*�������ֲ��ּ�⣨����ҳ�棩*/	 //����Ҫ����						
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				TimeArray[i]=0;
				i++;

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>95)&&(y<135))	  //1
			{
				TimeArray[i]=1;
				i++;

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				TimeArray[i]=2;
				i++;

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>95)&&(y<135))  //3
			{
				oriTime=TimeArray[i];
				TimeArray[i]=3;
				i++;
								
				if(i==1)		 //ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime; 
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>145)&&(y<165))	  //4
			{
				oriTime=TimeArray[i];
				TimeArray[i]=4;
				i++;				

				if(i==1)		 //ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;  
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				oriTime=TimeArray[i];
				TimeArray[i]=5;
				i++;				

				if(i==1)		   //ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;  
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>145)&&(y<165)) //6
			{
				oriTime=TimeArray[i];
				TimeArray[i]=6;
				i++;				

				if((i==1) || (i==3) || (i==5))		//ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];
				TFT_paintTimeSet();
			}
			if((x<60)&&(y>175)&(y<205))	  //7
			{
				oriTime=TimeArray[i];
				TimeArray[i]=7;
				i++;

				if((i==1) || (i==3) || (i==5))		//ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5];	 
				TFT_paintTimeSet();
			}
			if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				oriTime=TimeArray[i];
				TimeArray[i]=8;
				i++;

				if((i==1) || (i==3) || (i==5))		 //ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
			if((x>115)&&(y>175)&&(y<205)) //9
			{
				oriTime=TimeArray[i];
				TimeArray[i]=9;
				i++;

				if((i==1) || (i==3) || (i==5))	   //ʱ��У׼����
				{
					i--;
					TimeArray[i]=oriTime;
				}
				if((TimeArray[0]==2) && (i==2))
				{
					i--;
					TimeArray[i]=oriTime;
				}

				/*�����趨��ʱ����ʾ*/
				time.hour=TimeArray[0]*10+TimeArray[1]; 
				time.minute=TimeArray[2]*10+TimeArray[3];
				time.second=TimeArray[4]*10+TimeArray[5]; 
				TFT_paintTimeSet();
			}
						
			if(i==6)	//���ʱ���붼��ֵ�����������¸�ֵ
			{
				i=0;
			}

			if((x<55)&&(y<24))	 //���Ͻ�
			{
				back=1;
				ET0=1;		   
			}
		}				
	} //�������
}