/***************************************************************************************
 *	FileName					:	gy521.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 yezhihuo
 *
 *	Abstract Description		:	三轴传感器
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
#include"gy521.h"
#include"i2c.h"
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
 *  @name:void initMPU()
 *	@description : 初始化MPU6050
 *	@param			：none
 *	@return		： none
 *  @notice   ： none
 */
void initMPU()
{
	initI2C();                    //初始化I2C
	writeAdd(PWR_MGMT_1, 0X00);     //唤醒设备
	writeAdd(SMP_DIV, 0X07);        //设置采样率，125HZ
	writeAdd(CONFIG, 0x06);           //低通滤波频率，5HZ
	writeAdd(GYO_CONF, 0x18);        //陀螺仪自检及测量范围，不自检，2000deg/S
	writeAdd(ACC_CONF, 0X01);           //加速计自检、测量范围及高通滤波频率，不自检，2G,5HZ
}

/**
 *  @name:int GetData(uchar REG_Address)
 *	@description : 获得指定数据
 *	@param			：reg_Address 指定地址
 *	@return		： 获得数据
 *  @notice   ： none
 */
int GetData(uchar REG_Address)
{
	char H,L;
	int temp;
	H=readAdd(REG_Address);    //获得高位数据
	L=readAdd(REG_Address+1);     //获得地位数据
	temp = (H<<8)+L;            //获得数据
	return temp / 64;             //转化为十位数
}



	

/**
*  @name  :void judge()
*	@description : 判断晃动符合要求
*	@param	: none
*	@return	:1 确认为震动， 0 不是震动
*  @notice : none
 */
uchar  judge()
{
	int acc[2][3],gyr[2][3];
	uchar i, j, num = 0;
  if( (GetData(ACC_Y_H) == 0 )&& (GetData(ACC_Z_H) == 0) && 	(GetData(GYRO_X_H) == 0) )
	{
       if( 	(GetData(GYRO_Y_H )== 0) && 	(GetData(GYRO_Z_H) == 0) ) 
			 {
               			initMPU();	//判断线路出现问题，重新初始化MPU6050
			 }			
	}	
	acc[0][0] = GetData(ACC_X_H);
	acc[0][1] = GetData(ACC_Y_H);
	acc[0][2] = GetData(ACC_Z_H);
	gyr[0][0] = GetData(GYRO_X_H);
	gyr[0][1] = GetData(GYRO_Y_H);
	gyr[0][2] = GetData(GYRO_Z_H);
	for( j = 0; j < 3; j++ )          //重复测3次查看是否确定为移动
	{
			acc[1][0] = acc[0][0];
			acc[1][1] = acc[0][1];
			acc[1][2] = acc[0][2];
			gyr[1][0] = gyr[0][0];
			gyr[1][1] = gyr[0][1];
			gyr[1][2] = gyr[0][2];			
			acc[0][0] = GetData(ACC_X_H);
			acc[0][1] = GetData(ACC_Y_H);
			acc[0][2] = GetData(ACC_Z_H);
			gyr[0][0] = GetData(GYRO_X_H);
			gyr[0][1] = GetData(GYRO_Y_H);
			gyr[0][2] = GetData(GYRO_Z_H);
			for( i = 0; i < 3; i++ )
			{
				if( acc[0][i] - acc[1][i] > 200 || acc[1][i] - acc[0][i] > 200 )         //比较前后两次角度
				{
					num++;
					break;
				}
			}
  }
			if( num < 3 )
			{
				return 0;                  //判定为不是移动
			}	
			else
			{
				return 1;
			}
}


/**************************************************************
*	Function Define Section
**************************************************************/


  	