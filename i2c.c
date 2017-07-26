/***************************************************************************************
 *	FileName					:	main.c
 *	CopyRight					:
 *	ModuleName				:
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	2017.47.10
 *	Author/Corportation			:	yezhihuo
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
#include"i2c.h"

/**************************************************************
*	Macro Define Section  
**************************************************************/


/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section  ????
**************************************************************/


/**************************************************************
*	Global Variable Declare Section????
**************************************************************/
sbit sda = P3^0;
sbit scl = P3^1;
#define I2CAddr    0xd0    //设备地址
/**************************************************************
*	Function Define Section??????
**************************************************************/


/*  @name :void delay5us(uchar i)
*	@description: 延时 5us
*	@param : uchar i
*	@return		:none
*  @notice : none
 */
void Delay5us()
{
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
}

	

/*  @name        : void start()
 *	@description : 开始信号
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void start()
{
	sda = 1;
	Delay5us();
	scl = 1;
	Delay5us();
	sda = 0;
	Delay5us();
}

/*  @name        : void stop()
 *	@description : 停止信号
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void stop()
{
	sda = 0;
	Delay5us();
	scl = 1;
	Delay5us();
	sda = 1;
	Delay5us();
}

/*  @name        : void respons()
 *	@description : 应答信号
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void respons()
{
	uchar i = 0;
	scl = 1;
	Delay5us();
	while( (sda == 1) && (i < 250) )       //若一段时间内未接受到应答则默认已接收
	{
		i++;
	}
	scl = 0;
	Delay5us();
}

/*  @name        : void init()
 *	@description : 总线初始化
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void initI2C()
{
	sda = 1;
	Delay5us();
	scl = 1;
	Delay5us();
}

/*  @name        : void writeByte(uchar date)
 *	@description : 写一个字节
 *	@param		 : date 要写入的字节
 *	@return		 : none
 *  @notice      : None
 */
void writeByte(uchar date)
{
	uchar i,temp;
	temp = date;
	for( i = 0; i < 8; i++ )
	{
		temp <<= 1;                //temp左移一位，将最高位移入PSW寄存器的CY位
		scl = 0;
		Delay5us();
		sda = CY;        // 将CY位发送出去
		Delay5us();
		scl = 1;
		Delay5us();
	}
	scl = 0;
	Delay5us();
	sda = 1;
	Delay5us();
}

/*  @name        : uchar readByte()
 *	@description : 读取一个字节
 *	@param		 : none
 *	@return		 : 读取的字节
 *  @notice      : None
 */
uchar readByte()
{
	uchar i,k = 0;
	scl = 0;
	Delay5us();
	sda = 1;
	Delay5us();
	for( i = 0; i < 8; i++ )
	{
		scl = 1;
		Delay5us();
		k = (k <<1) | sda;
		scl = 0;
		Delay5us();
	}
	return k;
}

/*  @name        : void writeAdd(uchar adress, uchar date)
 *	@description : 向从机发送数据
 *	@param		 : address 从机
 *	@return		 : none
 *  @notice      : None
 */
void writeAdd(uchar address, uchar date)
{
	start();
	writeByte(I2CAddr);
	respons();
	writeByte(address);
	respons();
	writeByte(date);
	respons();
	stop();
}

/*  @name        : uchar readAdd()
 *	@description :
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
uchar readAdd(uchar address)
{
	uchar date;
	start();
	writeByte(I2CAddr);
	respons();
	writeByte(address);
	respons();
	start();
	writeByte(I2CAddr + 1);
	respons();
	date = readByte();
	stop();
	return date;
}








