#include"gui.h"

//---汉字的字库头文件---//
#include"charcode.h"

//---如果要显示图片就添加这个头文件---//
#ifdef PICTURE_SHOW	   //在GUI.h中可以定义

#include"picture.h"

#endif


/****************************************************************************
*函数名：GUI_Line 
*输  入：xStart：直线的起始X坐标
*      * yStart：直线的其实Y坐标
*      * xEnd：直线的结束X坐标
*      * yEnd：直线的结束Y坐标
*      * color：直线的颜色
*输  出：
*功  能：画一条直线
****************************************************************************/	  

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color)
{
	uint t;  
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;  
	int incx, incy;  
	uint row, col;  
	delta_x = xEnd - xStart;//计算坐标增量  
	delta_y = yEnd - yStart;  
	col = xStart;  
	row = yStart;  
	if (delta_x > 0)
	{
		incx=1;//设置单步方向
	} 	  
	else    
	{  
	    if (delta_x == 0)
		{
			incx = 0;//垂直线 
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
			incy = 0;//水平线  
		} 
	    else 
		{
			incy = -1;
			delta_y = -delta_y;
		}  
	}  
	if (delta_x > delta_y)
	{ 
		distance = delta_x;//选取基本增量坐标轴  
	}
	else
	{
		distance = delta_y; 
	} 	
	for (t=0; t<=distance+1; t++)  
	{                                     //画线输出  
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
*函数名：GUI_WriteASCII 
*输  入：x：字母显示的X坐标
*      * y：字母显示的Y坐标
*      * cn：要显示的字母
*      * wordColor：文字的颜色
*      * backColor：背景颜色
*输  出：
*功  能：写16X24的ASCII字符
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
*函数名：GUI_ShowPicture 
*输  入：x：图片显示起始X坐标
*      * y：图片显示起始Y坐标
*      * wide：图片的宽度
*      * high：图片的高度
*输  出：
*功  能：显示一张图片（取自picture.h中的pic[]数组，换图片直接替换掉pic数组就
*      * 可以了）
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
		TFT_WriteColor(temp);   //逐点显示
		tmp += 2;
	}
	while(tmp < num);	
}

#endif

#endif