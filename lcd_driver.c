#include "lcd_driver.h"

void Delay(unsigned int dly)
{
    unsigned int i,j;

    for(i=0;i<dly;i++)
    	for(j=0;j<255;j++);
}

void TFT_WriteCmd(unsigned int cmd)
{
	TFT_CS = 0;
	TFT_RD = 1;
	TFT_RS = 0;	
		
	TFT_DATAPORT=cmd;  
	TFT_WR = 0;  
	TFT_WR = 1; 

	TFT_CS = 1; 
}

void TFT_WriteData(unsigned int dat)
{
	TFT_CS = 0;
	TFT_RD = 1;
	TFT_RS = 1;	 
		
	TFT_DATAPORT=dat;  
	TFT_WR = 0;  
	TFT_WR = 1; 

	TFT_CS = 1;
}	 	 
void TFT_Init(void)
{

	TFT_RST = 1;
	Delay(200);
	TFT_RST = 0;
	Delay(800);
	TFT_RST = 1;
	Delay(800);
	
	 TFT_CS = 0;

	TFT_WriteCmd(0x36);
	TFT_WriteData(0xc8);
		

	TFT_WriteCmd(0x3a);
	TFT_WriteData(0x05);

	
	

	TFT_WriteCmd(0xfe);
	TFT_WriteCmd(0xef);

	TFT_WriteCmd(0xe2);
	TFT_WriteData(0x80);

	TFT_WriteCmd(0xa3);
	TFT_WriteData(0x07);

	TFT_WriteCmd(0xa4);
	TFT_WriteData(0x09);

	TFT_WriteCmd(0xff);
	TFT_WriteData(0x12);

	TFT_WriteCmd(0xfd);
	TFT_WriteData(0x04);


	TFT_WriteCmd(0xf5);  //VRP1
	TFT_WriteData(0x00);
	
	TFT_WriteCmd(0xfb);   //VRN0
	TFT_WriteData(0x00);
	
	TFT_WriteCmd(0xf1);
	TFT_WriteData(0x55);     //KP3+KP2
	
	TFT_WriteCmd(0xf8);
	TFT_WriteData(0x22);     //KN3+KN2
	
	TFT_WriteCmd(0xf3);
	TFT_WriteData(0x52);     //RP1+RP0 
	
	TFT_WriteCmd(0xfa);
	TFT_WriteData(0x25);     //RN1+RN0
	
	TFT_WriteCmd(0xf4);   //VRP0  
	TFT_WriteData(0x00);  
	
	TFT_WriteCmd(0xfc);   //VRN1
	TFT_WriteData(0x00);  
	
        TFT_WriteCmd(0x11);
	Delay(120);
        TFT_WriteCmd(0x29);
	Delay(50);
}


void TFT_SetWindow(unsigned int xStart,unsigned int yStart,unsigned int xEnd,unsigned int yEnd)
{
	TFT_WriteCmd(0x2a);   
	TFT_WriteData(xStart>>8);
	TFT_WriteData(xStart&0xff);
	TFT_WriteData(xEnd>>8);
	TFT_WriteData(xEnd&0xff);

	TFT_WriteCmd(0x2b);   
	TFT_WriteData(yStart>>8);
	TFT_WriteData(yStart&0xff);
	TFT_WriteData(yEnd>>8);
	TFT_WriteData(yEnd&0xff);

	TFT_WriteCmd(0x2c);
}


void TFT_WriteColor(color)
{
	TFT_CS = 0;
	TFT_RD = 1;
	TFT_RS = 1;	 
		
	TFT_DATAPORT=color >> 8;  
	TFT_WR = 0;  
	TFT_WR = 1;
	
	TFT_DATAPORT=color;  
	TFT_WR = 0;  
	TFT_WR = 1; 

	TFT_CS = 1;
}

void TFT_ClearScreen(unsigned int color)
{
     unsigned int i,j;

	TFT_SetWindow(0,0,TFT_XMAX-1,TFT_YMAX-1);

//	TFT_CS=0; 
//	TFT_RS=1;
//	TFT_RD=1;

	for(i=0;i<TFT_YMAX;i++)
	{
	    for(j=0;j<TFT_XMAX;j++)
		{    

			 TFT_WriteColor(color);
//			 TFT_DATAPORT=color>>8;
//			 TFT_WR=0;  
//			 TFT_WR=1;  
	
//			 TFT_DATAPORT=color;
//			 TFT_WR=0;  
//			 TFT_WR=1;  
		}
	}

//	TFT_CS=1;
}	 
