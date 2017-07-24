/***************************************************************************************
 *	FileName					:	
 *	CopyRight					:
 *	ModuleName					:	
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	
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
#include"AD.H"

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
sbit ds = P3^7;

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void delayMs(uint i)
*	@description: ÑÓÊ±º¯Êý
 *	@param£º i ÑÓÊ±Ê±¼ä	
 *	@return		£ºnone
 *  @notice £ºnone
 */
 void delayMs(uint i)
 {
	 uchar j;
	 while( i > 0 )
	 {
		 for( j = 0; j < 110; j++ )
		 {
			 ;
		 }
		 i--;
	 }
 }

/**
	*  @name: void dsreset()
	*	@description: DS180B20¸´Î»£¬³õÊ¼»¯º¯Êý
	*	@param:	none
	*	@return:		none
	*  @notice: none
 */
void dsreset()
{
	uint i;
	ds = 0;
	i = 103;
	while ( i > 0 )
	{
		i--;             //ÑÓÊ±
	}
	ds = 1;
	i = 4;
	while( i > 0) 
	{
		i--;
	}
}
 
/**
*  @name: bit tempReadBit()
*	@description: ¶ÁÒ»Î»Êý¾Ý
 *	@param			
 *	@return		£º¶ÁÈ¡µÄÊý¾Ý
 *  @notice
 */
bit tempReadBit()
{
	uint i;
	bit dat;
	ds = 0;
	i++;
	ds = 1;
	i++; i++;
	dat = ds;
	i = 8;
	while( i > 0 )
	{
		i--;
	}
	return dat;
}


	
	/**
*  @name: uchar tempRead()
 *	@description£º¶ÁÒ»¸ö×Ö½ÚÊý¾Ý
 *	@param			
 *	@return		£º¶ÁÈ¡µÄÊý¾Ý
 *  @notice
 */
 uchar tempRead()
{
	uchar i, j, dat;
	dat = 0;
	for( i = 0; i < 8; i++ )
	{
		j = tempReadBit();
		dat = (dat >> 1) | (j << 7);               //½«¶ÁÈ¡µÄÊý¾Ý´æÈëÒ»¸ö×Ö½Ú
	} 
	return dat;
}
	
 
 /**
 *  @name£ºvoid tempWrite(uchar dat)
 *	@description£º Ïòds18b20Ð´Ò»¸ö×Ö½ÚÊý¾Ý
 *	@param			£ºÐèÒªÐ´ÈëµÄÊý¾Ý
 *	@return		
 *  @notice
 */
void tempWrite(uchar dat)
{
	uint i;
	uchar j;
	bit test;
	for( j = 0; j < 8; j++ )
	{
		test = dat & 0x01;
		dat >>= 1;
		if( test == 1 )           //Ð´1
		{
			ds = 0;
			i++; i++;
			ds = 1;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
		}
		else             //Ð´0
		{
			ds = 0;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
			ds = 1;
			i++; i++;
		}
	}
}

 
 /**
*  @name:float getTemp()
*	@description: ¶ÁÈ¡ÎÂ¶È
 *	@param	£º none 		
*	@return		: ¶ÁÈ¡µ½µÄÎÂ¶È * 10
*  @notice   :none
 */
uint getTemp()
{
	uchar a, b;
	float ftemp;
  uint	temp;
	dsreset();
	delayMs(1);
  tempWrite(0xcc);
	tempWrite(0xbe);
	a = tempRead();          //¶ÁµÍ8Î»
	b = tempRead();          //¶Á¸ß8Î» 
	temp = b;
	temp <<= 8;
	temp = temp | a;         //ºÏ²¢ÎªÒ»¸ö×Ö
	ftemp = temp * 0.0625;          //ÎÂ¶ÈÔÚ¼Ä´æÆ÷ÖÐÎª12Î»£¬·Ö±æÂÊÎª0.0625
  temp = ftemp * 10 + 0.5;           //¬+0.05ÎªËÄÉáÎåÈë,*10 ±íÊ¾Ö§È¡Ò»Î»Ð¡Êý
	return temp;
}

 /**
*  @name:void tempchang()
*	@description: ¿ªÊ¼»ñÈ¡ÎÂ¶È²¢×ª»»
*	@param			:none
*	@return		:none
*  @notice : none
 */
void tempchange()
{
	dsreset();
	delayMs(1);
	tempWrite(0xcc);    //Ð´Ìø¹ý¶ÁromÖ¸Áî
	tempWrite(0x44);     //Ð´ÎÂ¶È×ª»»Ö¸Áî
}
