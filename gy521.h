/***************************************************************************************
 *	File Name				:		gy521.h
 *	CopyRight				:
 *	ModuleName				:	
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Data				:	
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for  lcd1602
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef __GY521_H
#define __GY521_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uint
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char 
#endif

#define  SMP_DIV   0X19      //陀螺采样率
#define  CONFIG    0X1A       //低通滤波频率
#define  GYO_CONF  0X1B      //陀螺仪自检及测量范围
#define  ACC_CONF  0X1C      //加速计自检、测量范围及高通频率    
#define  ACC_X_H   0X3B      //X轴加速度高位
#define  ACC_X_L   0X3C      //X轴加速度低位
#define  ACC_Y_H   0X3D      //y轴加速度高位
#define  ACC_Y_L   0X3E
#define  ACC_Z_H   0X3F
#define  ACC_Z_L   0X40
#define  TEMP_H    0X41     
#define  TEMP_L    0X42
#define  GYRO_X_H  0X43      //x轴角速度
#define  GYRO_X_L  0X44       //X轴角速度
#define  GYRO_Y_H  0X45       //Y轴角速度
#define  GYRO_Y_L  0X46
#define  GYRO_Z_H  0X47
#define  GYRO_Z_L  0X48
#define  PWR_MGMT_1  0X6B       //电源管理
#define  WHO_AM_I    0X75      //I2C地址
#define  SLAVEADDR   0XD0    //IIC写入时的地址字节数，+1位读取
/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/
/**
 *  @name:int GetData(uchar REG_Address)
 *	@description : 获得指定数据
 *	@param			：reg_Address 指定地址
 *	@return		： 获得数据
 *  @notice   ： none
 */
int GetData(uchar REG_Address);
/**
 *  @name:void initMPU()
 *	@description : 初始化MPU6050
 *	@param			：none
 *	@return		： none
 *  @notice   ： none
 */
void initMPU();

/**
*  @name  :void judge()
*	@description : 判断晃动符合要求
*	@param	: none
*	@return	:none
*  @notice : none
 */
uchar judge();
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif