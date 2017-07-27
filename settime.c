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
 *	Abstract Description		:    …Ë÷√ ±º‰
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
#include<reg52.h>
#include "clock.h"		//“˝”√»´æ÷±‰¡øtime
#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
#include "GUI.h"
#include "lcd_driver.h"

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
*	Function Define Section
**************************************************************/

/**
*  @name: void setTimeb
*	@description:  µ˜’˚ ±º‰
*	@param		:n =0 ±–ﬁ∏ƒ–° ±£¨=1 ±–ﬁ∏√∑÷÷”£¨=2 ±–ﬁ∏ƒ√Î÷”£¨numŒ™–ﬁ∏ƒ«∞µƒ÷µ£¨
 *	@return		: –ﬁ∏ƒ∫Ûµƒ÷µ
 *  @notice : none
 */
uchar  setTimeB(uchar n, uchar num, uint colo)
{
	char j = 0, m;
	bit tag = 0;
  TFT_ClearScreen(0x0000);		//«Â∆¡£¨œ˚≥˝∆¡ƒª÷Æ«∞œ‘ æƒ⁄»›µƒ”∞œÏ
  if( n == 0 )           //X	–ﬁ∏ƒ–° ±
	{
  	TFT_paintSetSur("HOUR");     
	}
  if( n == 1 )           //X	–ﬁ∏ƒ∑÷÷”
	{
  	TFT_paintSetSur("MINUTE");     
	}	
  if( n == 2 )           //X	–ﬁ∏ƒ√Î÷”
	{
  	TFT_paintSetSur("SECOND");     
	}		
	GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //œ‘ æ–Ë“™…Ë÷√µƒ÷µ1°§
  GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			//◊™ªØ
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
		  //…Ë÷√ ±º‰ 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				m = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				m = 1;
				tag = 1;				
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				m = 2;
				tag = 1;	
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				m = 3;
				tag = 1;	
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				m = 4;
				tag = 1;	
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				m = 5;
				tag = 1;	
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				m = 6;
				tag = 1;	
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				m  = 7;
				tag = 1;	
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				m = 8;
				tag = 1;	
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				m = 9;
				tag = 1;	
			}																															
			else if((x<55)&&(y<24))	 //◊Û…œΩ«
			{
        break;   //ÕÀ≥ˆ—≠ª∑				
			}	
  		if( tag == 1 )      //≈–∂œ «∑Ò–Ë“™∏¸∏ƒ
			{	
				tag = 0;
				j++;
        if( j == 1 )           //µ⁄“ª¥Œ–ﬁ∏ƒ
				{
					num = m;
				}
				if( j== 2)            //µ⁄∂˛¥Œ–ﬁ∏ƒ
				{
					num = num * 10 + m;
				}
				if( j == 3)   // ÷ÿ–¬–ﬁ∏ƒ
				{
					j =1;
					num = m;
				}
				if( n == 0 && num > 23 )
				{
					num = 23;          //–° ±◊Ó¥Û≤ª≥¨π˝23
				}
				else if( num > 59 )
				{
					num = 59;      // ∑÷÷”∫Õ√Î÷”◊Ó¥Û≤ª≥¨π˝53
				}
        GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //œ‘ æ–Ë“™…Ë÷√µƒ÷µ1°§
        GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
        tag = 0;	
				Delay(40);
			}
		}	
	}
	  TFT_ClearScreen(0x0000);		//«Â∆¡£ 
	 return num;
}


/**
*  @name: clockTime setTime(bit tag,clock setTime)
*	@description:  µ˜’˚ ±º‰
*	@param		:setime –Ë“™…Ë÷√µƒ ±º‰
 *	@return		: …Ë÷√∫Ûµƒ ±º‰
 *  @notice : none
 */
clockTime setTimeA(bit tag,clockTime setTime)
{
	uchar num;
  clockTime set;
	set = setTime;
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			//◊™ªØ
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
		  //—°‘Ò…Ë÷√ ±º‰ 
			if( (y > 100)&&( y < 140 ) )
			{
        if( x<60 )	  //–° ±
				{
					num = setTimeB(0, set.hour, 0xf800);
					if( num < 24 )         //≈–∂œ¥À¥Œ–ﬁ∏ƒ «∑Ò”––ß
					{
						set.hour = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}
					TFT_paintSetTime(tag);					
				}					
				else if( x<115 )	  //∑÷÷”
				{
					num = setTimeB(1,set.minute, 0x7e0);			
					if( num < 60 )         //≈–∂œ¥À¥Œ–ﬁ∏ƒ «∑Ò”––ß
					{
						set.minute = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}					
					TFT_paintSetTime(tag);							
				}								
				else	  //√Î÷”
				{
					num = setTimeB(2, set.second, 0xffe0);
					if( num < 60 )         //≈–∂œ¥À¥Œ–ﬁ∏ƒ «∑Ò”––ß
					{
						set.second = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}					
					TFT_paintSetTime(tag);					
				}
			}
	
			
      //∞¥ ˝◊÷…œ∑Ωº”“ª			
      else if( y < 90  && y > 55	 )
			{
				if( x < 30 )	  //–° ± ÆŒª
				{
					if( set.hour > 13 && set.hour < 20 )
					{
						set.hour %= 10;
					}
					else if( set.hour > 19 )
					{
						set.hour = set.hour % 10;
					}
					else
					{
						set.hour += 10;
					}
					 GUI_WriteASCII2Ch(9, 100, set.hour / 10 + '0', 0xF800, 0x0000);	
				}
				else if( x<60 )	  //–° ±∏ˆŒª
				{
          if( set.hour == 23 )
					{
						set.hour = 20;
					}
					else
					{
						set.hour++;
					}
          GUI_WriteASCII2Ch(30, 100, set.hour % 10 + '0', 0xF800, 0x0000);					
				}			
				else if( x<85 )	  //∑÷÷” ÆŒª
				{
            if( set.minute > 49 )
						{
							set.minute %= 10;
						}
						else
						{
							set.minute += 10;
						}
          	GUI_WriteASCII2Ch(69, 100, set.minute / 10 + '0', 0x07e0, 0x0000);				
				}		
				else if( x<115 )	  //∑÷÷”∏ˆŒª
				{
					if( set.minute % 10 == 9 )    //µ±∑÷÷”∏ˆŒª ˝≤ª≥¨π˝9
					{
						set.minute -= set.minute % 10;
					}
					else
					{
						set.minute += 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<147 )	  //√Î÷” ÆŒª
				{
            if( set.second > 49 )
						{
							set.second %= 10;
						}
						else
						{
							set.second += 10;
						}
					GUI_WriteASCII2Ch(129, 100, set.second / 10 + '0', 0xffe0, 0x0000);	
				}				
				else	  //√Î÷”∏ˆŒª
				{
					if( set.second % 10 == 9 )    //µ±∑÷÷”∏ˆŒª ˝≤ª≥¨π˝9
					{
						set.second -= set.second % 10;
					}
					else
					{
						set.second += 1;
					}
					GUI_WriteASCII2Ch(150, 100, set.second % 10 + '0', 0xffe0, 0x0000);
				}	
			}

         // ∞¥ ˝◊÷œ¬∑Ωºı“ª
      else if( y < 185 && y > 	155 )
			{
				if( x < 30 )	  //–° ± ÆŒª
				{
					if( set.hour < 4)
					{						
						 set.hour = set.hour + 2 * 10;
					}
					else if( set.hour < 10 )
					{
						set.hour = set.hour + 10;
					}
					else
					{
						set.hour -= 10;
					}
					 GUI_WriteASCII2Ch(9, 100, set.hour / 10 + '0', 0xF800, 0x0000);
			 }
				else if( x<60 )	  //–° ±∏ˆŒª
				{

					if( set.hour  == 20 )    //µ±–° ± ÆŒª ˝Œ™∂˛ ±£¨∏ˆŒª ˝≤ªƒ‹≥¨π˝»˝
					{
						set.hour = 23;
					}
					else if( set.hour % 10 == 0 )       //–° ±∏ˆŒª ˝¥”–¬¥”0ø™ º
					{
                set.hour = (set.hour / 10) * 10 + 9 ;
					}
					else
					{
						set.hour -= 1 ;		
					}	
          GUI_WriteASCII2Ch(30, 100, set.hour % 10 + '0', 0xF800, 0x0000);					
				}			
				else if( x<85 )	  //∑÷÷” ÆŒª
				{
					if( set.minute < 10 )
					{
						set.minute = set.minute % 10 + 5 * 10;
					}
          else
					{
             set.minute -= 10;
					}						
          	GUI_WriteASCII2Ch(70, 100, set.minute / 10 + '0', 0x07e0, 0x0000);				
				}		
				else if( x<120 )	  //∑÷÷”∏ˆŒª
				{

					if( set.minute % 10 == 0 )    //µ±∑÷÷”∏ˆŒª ˝≤ª≥¨π˝9
					{
						set.minute = (set.minute / 10) * 10 +  9;
					}
					else
					{
						set.minute -= 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<156 )	  //√Î÷” ÆŒª
				{
					if( set.second < 10 )
					{
						set.second = set.second % 10 + 5 * 10;
					}
          else
					{
             set.second -= 10;
					}			
					GUI_WriteASCII2Ch(130, 100, set.second / 10 + '0', 0xffe0, 0x0000);	
				}				
				else	  //√Î÷”∏ˆŒª
				{
					if( set.second % 10 == 0 )    //µ±∑÷÷”∏ˆŒª ˝≤ª≥¨π˝9
					{
						set.second = (set.second / 10) * 10 +  9;
					}
					else
					{
						set.second -= 1;
					}
					GUI_WriteASCII2Ch(150, 100, set.second % 10 + '0', 0xffe0, 0x0000);
				}				
			}	
			else if((x<55)&&(y<24))	 //◊Û…œΩ«
			{
        break;   //ÕÀ≥ˆ—≠ª∑				
			}
			else if((x>115)&&(y<24)&& (tag == 0))	 //◊Û…œΩ«
			{
				clockTag = 1;      //ø™∆Ùƒ÷÷”
        break;   //ÕÀ≥ˆ—≠ª∑				
			}
			Delay(20);
		}	
	}		
     TFT_ClearScreen(0x0000);		//«Â∆¡£¨œ˚≥˝∆¡ƒª÷Æ«∞œ‘ æƒ⁄»›µƒ”∞œÏ	
   return set;			
}	 

