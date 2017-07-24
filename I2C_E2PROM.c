#include <reg52.h>

//�ض���
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//I2C��ʼ��
void I2C_init()	
{
	SDA = 1;
	_nop_();
	SCL = 1;
	_nop_();
}

//I2C��ʼ�ź�
void I2C_Start()  
{
	SCL = 1;
	_nop_();
	SDA = 1;
	delay_5us();
	SDA = 0;
	delay_5us();
}

//I2C��ֹ�ź�
void I2C_Stop()
{
	SDA = 0;
	_nop_();
	SCL = 1;
	delay_5us();
	SDA = 1;
	delay_5us();
}

//��������Ӧ��
void Master_ACK(bit i)		
{
	SCL = 0; // ����ʱ����������SDA���������ϵ����ݱ仯
	_nop_(); // �������ȶ�
	if (i)	 //���i = 1 ��ô������������ ��ʾ����Ӧ��
	{
		SDA = 0;
	}
	else	 
	{
		SDA = 1;	 //���ͷ�Ӧ��
	}
	_nop_();//�������ȶ�
	SCL = 1;//����ʱ������ �ôӻ���SDA���϶��� ������Ӧ���ź�
	delay_5us();
	SCL = 0;//����ʱ�����ߣ� ռ�����߼���ͨ��
	_nop_();
	SDA = 1;//�ͷ�SDA�������ߡ�
	_nop_();
}

//���ӻ�Ӧ��
bit Test_ACK()
{
	SCL = 1;
	delay_5us();
	if (SDA)	//�ӻ����ͷ�Ӧ���ź�
	{
		SCL = 0;
		_nop_();
		I2C_Stop();
		return(0);
	}
	else		//�ӻ�Ӧ��
	{
		SCL = 0;
		_nop_();
		return(1);
	}
}

//����һ���ֽ�
void I2C_send_byte(uchar byte)
{
	uchar i;
	for(i = 0 ; i < 8 ; i++) //�������ݸ�E2PROM���ȴ����λ��ʼ��
	{
		SCL = 0;
		_nop_();				
		if (byte & 0x80)  //1000 0000
		{ 
			_nop_();				   
			SDA = 1;	
		}
		else
		{				
			SDA = 0;
			_nop_();
		}
		SCL = 1;
		_nop_();
		byte <<= 1;	// 0101 0100B 
	}
	SCL = 0;
	_nop_();
	_nop_();
	SDA = 1;
}


//I2C ��һ�ֽ�
uchar I2C_read_byte()
{
	uchar dat,i;
	SCL = 0;
	_nop_();
	SDA = 1;   //������������
	_nop_();
	for(i = 0 ; i < 8 ; i++)
	{
		SCL = 1;
		_nop_();
		if (SDA)			    
		{
			 dat |= 0x01; //0000 0001 ��λ��ǰ��λͬdat, ���һλΪ1
		}
		else
		{
			dat &=  0xfe;	//1111 1110	 ��λ�룬ǰ��λͬdat, ���һλΪ0
		}
		_nop_();
		SCL = 0 ;
		_nop_();
		if(i < 7)
		{
			dat = dat << 1;	 //�ߵ�λ�������ӵ�λ���Ƶ���λ
		}
	}
	return(dat);
}

//I2C�����������ݣ�ÿһ��д�����ݶ���Ҫ���ӻ�Ӧ��
//ÿ��ʹ���������ֻ��д��һ�ֽڵ�����
bit I2C_transData(uchar ADDR, DAT)	//�ȷ���E2PROM��ַ���ٷ�������
{								 
	I2C_Start();					//������ʼ�ź�
	I2C_send_byte(AT24C02_ADDR+0); //д��������ַ
	if (!Test_ACK())			   //���ӻ�Ӧ�𣬾����Ƿ������������
	{
		return(0);
	}
	I2C_send_byte(ADDR); 		   //����д���׵�ַ���ɱ�д�߾���
	if (!Test_ACK())			   //���ӻ�Ӧ��
	{
		return(0);
	}
	I2C_send_byte(DAT);			 //����һ�ֽڵ�����	 
	if (!Test_ACK())		   //���ӻ�Ӧ��
	{
		return(0);
	}
	I2C_Stop();				   //I2C��ֹ�ź�
	return(1);	
}

//I2C������������
//������ȡE2PROM���ݣ�ÿ��ֻ�ܴ�E2PROM���ض���ַ��ȡһ�ֽ����ݣ������ظ�����
uchar I2C_receData(uchar ADDR)	 
{
	uchar DAT;
	I2C_Start();					 //��ʼ�ź�
	I2C_send_byte(AT24C02_ADDR+0);	 //����������ַ����������
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_send_byte(ADDR);
	Master_ACK(0);		//����������Ӧ��
	//------------------
	I2C_Start();
	I2C_send_byte(AT24C02_ADDR+1); 	//����������ַ����������
	if (!Test_ACK())
	{
		return(0);
	}

	DAT = I2C_read_byte();	//������ȡ��һ�ֽ�֮��
	Master_ACK(0);		   //����������Ӧ��

	I2C_Stop();
	return(DAT);	
}