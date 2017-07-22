#include"gui.h"

//---���ֵ��ֿ�ͷ�ļ�---//
#include"charcode.h"

//---���Ҫ��ʾͼƬ��������ͷ�ļ�---//
#ifdef PICTURE_SHOW	   //��GUI.h�п��Զ���

#include"picture.h"

#endif


/****************************************************************************
*��������GUI_Line 
*��  �룺xStart��ֱ�ߵ���ʼX����
*      * yStart��ֱ�ߵ���ʵY����
*      * xEnd��ֱ�ߵĽ���X����
*      * yEnd��ֱ�ߵĽ���Y����
*      * color��ֱ�ߵ���ɫ
*��  ����
*��  �ܣ���һ��ֱ��
****************************************************************************/	  

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color)
{
	uint t;  
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;  
	int incx, incy;  
	uint row, col;  
	delta_x = xEnd - xStart;//������������  
	delta_y = yEnd - yStart;  
	col = xStart;  
	row = yStart;  
	if (delta_x > 0)
	{
		incx=1;//���õ�������
	} 	  
	else    
	{  
	    if (delta_x == 0)
		{
			incx = 0;//��ֱ�� 
		} 		 
	    else 
			{
				incx = -1;
				delta_x = -delta_x;
			}  
	}  
	if (delta_y > 0)
	{
		incy = 1;
	}	  
	else  
	{  
	    if (delta_y == 0)
		{
			incy = 0;//ˮƽ��  
		} 
	    else 
		{
			incy = -1;
			delta_y = -delta_y;
		}  
	}  
	if (delta_x > delta_y)
	{ 
		distance = delta_x;//ѡȡ��������������  
	}
	else
	{
		distance = delta_y; 
	} 	
	for (t=0; t<=distance+1; t++)  
	{                                     //�������  
	    GUI_Dot(col, row, color);
	    xerr += delta_x;  
	    yerr += delta_y;  
	  	if(xerr > distance)  
	    {  
	        xerr -= distance;  
	        col += incx;  
	    }  
	    if(yerr > distance)  
	    {  
	        yerr -= distance;  
	        row += incy;  
	    }  
	}  
}	  

/****************************************************************************
*��������GUI_WriteASCII 
*��  �룺x����ĸ��ʾ��X����
*      * y����ĸ��ʾ��Y����
*      * cn��Ҫ��ʾ����ĸ
*      * wordColor�����ֵ���ɫ
*      * backColor��������ɫ
*��  ����
*��  �ܣ�д16X24��ASCII�ַ�
****************************************************************************/	  

#ifdef USE_ASCII

void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor)
{
	uchar j, wordByte,wordNum;
	uint color;
	while(*p != '\0')
	{
		wordNum = *p - 32;
		TFT_SetWindow(x,y,x+15, y+23);
		for (wordByte=0; wordByte<48; wordByte++)
		{
			color = ASCII16x24[wordNum][wordByte];
			for (j=0; j<8; j++) 
			{
				if ((color&0x80) == 0x80)
				{
					TFT_WriteColor(wordColor);
				} 						
				else
				{
					TFT_WriteColor(backColor);
				} 	
				color <<= 1;
			}
		}
		p++;
		x +=16;
	}
}
#endif

/****************************************************************************
*��������GUI_ShowPicture 
*��  �룺x��ͼƬ��ʾ��ʼX����
*      * y��ͼƬ��ʾ��ʼY����
*      * wide��ͼƬ�Ŀ��
*      * high��ͼƬ�ĸ߶�
*��  ����
*��  �ܣ���ʾһ��ͼƬ��ȡ��picture.h�е�pic[]���飬��ͼƬֱ���滻��pic�����
*      * �����ˣ�
****************************************************************************/	  

#ifdef PICTURE_SHOW

void GUI_ShowPicture(uint x, uint y, uchar wide, uint high)
{
	uint temp = 0, tmp = 0, num = 0;
	TFT_SetWindow(x, y, x+wide-1, y+high-1);
	num = wide * high * 2;
	do
	{   
		temp = pic[tmp + 1];
		temp = temp << 8;
		temp = temp | pic[tmp];
		TFT_WriteColor(temp);   //�����ʾ
		tmp += 2;
	}
	while(tmp < num);	
}

#endif

#endif