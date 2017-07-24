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

uchar anotherSur=1;		//����������Ϊ1����һ����Ҫ����(֮��ֻ��ʱ������Ͳ���Ҫ�ٴ�����)����calTimeDisplay.h������Ϊȫ�ֱ���	
long x=0, y=0;	
uchar set=0, back=1;  //���ñ�־λ�����ر�־λ������1�������У���ȫ�ֱ�����calTimeDisplay.h������
uchar setFlag=0, clockFlag=0;	//��ֹ������һ�����水��ȴ��������һ���������ݵĴ���
uchar oriTime=0;			 //�޸�ʱ�����ʱԭ����ʱ��

void main()
{
	initTimer();		 //��ʼ����ʱ��0��ʱ�ӣ�
	TFT_Init();				//��ʼ����������ʾ

	while(1)
	{
		CalTimeDisplay();		//���������ʾ�����ý������ʾ
	}
}

		