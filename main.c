#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;
//
uchar anotherSur=1;		//����������Ϊ1����һ����Ҫ����(֮��ֻ��ʱ������Ͳ���Ҫ�ٴ�����)����calTimeDisplay.h������Ϊȫ�ֱ���
long x=0, y=0;
uchar set=0, back=1;  //���ñ�־λ�����ر�־λ������1�������У���ȫ�ֱ�����calTimeDisplay.h������
uchar setFlag=0, clockFlag=0;	//��ֹ������һ�����水��ȴ��������һ���������ݵĴ���
uchar oriTime=0;			 //�޸�ʱ�����ʱԭ����ʱ��

void main()
{
	//uchar h1, h0, m1, m0, s1, s0;	 //��������

	initTimer();		 //��ʼ����ʱ��0��ʱ�ӣ�
	TFT_Init();				//��ʼ����������ʾ

	while(1)
	{

	/*
		h1=time.hour/10;	//�õ���ʱ����ʱ��
		h0=time.hour%10;
		m1=time.minute/10;
		m0=time.minute%10;
		s1=time.second/10;
		s0=time.second%10;
	*/
		CalTimeDisplay();		//���������ʾ�����ý������ʾ
	}

}

