/**
  ******************************************************************************
  * File Name          : lcd.c
  * Description        : This file provides code for the configuration
  *                      of the lcd instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "lcd.h"

/* USER CODE BEGIN 0 */
#include "font.h" 
#include "stdio.h"

void delay(uint32_t count)   /* X1ms */
{
  HAL_Delay( count );
}


//**********write register command***********//
void  LCD_WriteCommand(uint8_t c)
{
    uint32_t i;
    LCD_DCX_0;
    LCD_CS_0;
    for(i=0;i<8;i++) {
      if(c &0x80){
        LCD_SDA_1;
      } else 
      LCD_SDA_0;
      LCD_SCK_0;
      LCD_SCK_1;
      c <<=1;
    }
    LCD_CS_1;
}

//***************write  data****************// 
void LCD_WriteData(uint8_t c)
{
    uint32_t i;
    LCD_DCX_1;
    LCD_CS_0;
    for(i=0;i<8;i++) {
      if(c &0x80){
        LCD_SDA_1;
      } else 
      LCD_SDA_0;
      LCD_SCK_0;
      LCD_SCK_1;
      c <<=1;
    }
    LCD_CS_1;
}

//******************************************//
void LCD_Write_Data(uint16_t dat16)
{
  LCD_WriteData(dat16>>8);
  LCD_WriteData(dat16);
}




void  LCD_ST7735S_CPT144_Initial ()
 
{ 
	//------------------------------------ST7735R Reset Sequence-----------------------------------------// 
	LCD_RESET_1; 
	delay(100);                                                              //Delay 100ms 
	LCD_RESET_0; 
	delay(100);                                                              //Delay 10ms 
	LCD_RESET_1; 
	delay(300);                                                              //Delay 300ms
	//--------------------------------End ST7735S Reset Sequence ---------------------------------------//
	LCD_WriteCommand(0x11); //Sleep out
	delay(120); //Delay 120ms
	//------------------------------------ST7735S Frame rate--------------------------------------------//
	LCD_WriteCommand(0xB1); //Frame rate 80Hz
	LCD_WriteData(0x02);
	LCD_WriteData(0x35);
	LCD_WriteData(0x36);
	LCD_WriteCommand(0xB2); //Frame rate 80Hz
	LCD_WriteData(0x02);
	LCD_WriteData(0x35);
	LCD_WriteData(0x36);
	LCD_WriteCommand(0xB3); //Frame rate 80Hz
	LCD_WriteData(0x02);
	LCD_WriteData(0x35);
	LCD_WriteData(0x36);
	LCD_WriteData(0x02);
	LCD_WriteData(0x35);
	LCD_WriteData(0x36);
	//------------------------------------End ST7735S Frame rate-----------------------------------------//
	LCD_WriteCommand(0xB4); //Dot inversion
	LCD_WriteData(0x03);
	//------------------------------------ST7735S Power Sequence-----------------------------------------//
	LCD_WriteCommand(0xC0);
	LCD_WriteData(0xA2);
	LCD_WriteData(0x02);
	LCD_WriteData(0x84);
	LCD_WriteCommand(0xC1);
	LCD_WriteData(0xC5);
	LCD_WriteCommand(0xC2);
	LCD_WriteData(0x0D);
	LCD_WriteData(0x00);
	LCD_WriteCommand(0xC3);
	LCD_WriteData(0x8D);
	LCD_WriteData(0x2A);
	LCD_WriteCommand(0xC4);
	LCD_WriteData(0x8D);
	LCD_WriteData(0xEE);
	//---------------------------------End ST7735S Power Sequence---------------------------------------//
	LCD_WriteCommand(0xC5); //VCOM
	LCD_WriteData(0x0a);
	LCD_WriteCommand(0x36); //MX, MY, RGB mode
	LCD_WriteData(0xC8);
	//------------------------------------ST7735S Gamma Sequence-----------------------------------------//
	LCD_WriteCommand(0XE0);
	LCD_WriteData(0x12);
	LCD_WriteData(0x1C);
	LCD_WriteData(0x10);
	LCD_WriteData(0x18);
	LCD_WriteData(0x33);
	LCD_WriteData(0x2C);
	LCD_WriteData(0x25);
	LCD_WriteData(0x28);
	LCD_WriteData(0x28);
	LCD_WriteData(0x27);
	LCD_WriteData(0x2F);
	LCD_WriteData(0x3C);
	LCD_WriteData(0x00);
	LCD_WriteData(0x03);
	LCD_WriteData(0x03);
	LCD_WriteData(0x10);
	LCD_WriteCommand(0XE1);
	LCD_WriteData(0x12);
	LCD_WriteData(0x1C);
	LCD_WriteData(0x10);
	LCD_WriteData(0x18);
	LCD_WriteData(0x2D);
	LCD_WriteData(0x28);
	LCD_WriteData(0x23);
	LCD_WriteData(0x28);
	LCD_WriteData(0x28);
	LCD_WriteData(0x26);
	LCD_WriteData(0x2F);
	LCD_WriteData(0x3B);
	LCD_WriteData(0x00);
	LCD_WriteData(0x03);
	LCD_WriteData(0x03);
	LCD_WriteData(0x10);
	//------------------------------------End ST7735S Gamma Sequence-----------------------------------------//
	LCD_WriteCommand(0x3A); //65k mode
	LCD_WriteData(0x05);
	LCD_WriteCommand(0x29); //Display on 

	LCD_DISPLAY_COLOR(BLACK);
}


//****************????????????*****************//
void DISP_WINDOWS(void)
{   
    LCD_WriteCommand(0x2A);	    //???????????????
    LCD_WriteData(0x00);
    LCD_WriteData(0x02);
    LCD_WriteData(0x00);
    LCD_WriteData(0x81);

    LCD_WriteCommand(0x2B);	    //???????????????
    LCD_WriteData(0x00);
    LCD_WriteData(0x03);
    LCD_WriteData(0x00);
    LCD_WriteData(0x82);

    LCD_WriteCommand(0x2C);
}


//**************???????????????*******************//
void  LCD_DISPLAY_COLOR(uint32_t color)
{
  uint32_t i,j;
  DISP_WINDOWS();
  for (i=Height;i>0;i--)
  for (j=Width; j>0;j--)
  LCD_Write_Data(color);
}




void LCD_Disp_At_X_Y(uint8_t X, uint8_t Y, uint16_t color)
{
  
//  X = Width-X;
//  Y = Height-Y;

	X += 0x02;
	Y += 0x03;
    
    LCD_WriteCommand(0x2A);	    //???????????????
    LCD_WriteData(0x00);    LCD_WriteData(X);
    LCD_WriteData(0x00);    LCD_WriteData(X+1);

    LCD_WriteCommand(0x2B);	    //???????????????
    LCD_WriteData(0x00);    LCD_WriteData(Y);
    LCD_WriteData(0x00);    LCD_WriteData(Y+1);

    LCD_WriteCommand(0x2C);    LCD_Write_Data(color);
}



//????????????????????????????????????
void LCD_FillScreen( uint8_t GRAM[Height][Y_PAGE] )
{
  uint8_t i,j,k;
  DISP_WINDOWS();
  for(i=0;i<Y_PAGE;i++)
    for (k=0; k<=7;k++)
      for(j=0;j<Height;j++)
        LCD_Write_Data( (GRAM[j][i]&(1<<(k)))?YELLOW:BLACK );
}



//void LCD_FillScreen( uint8_t GRAM[Height][Y_PAGE] )
//{
//  uint8_t i,j,k;
//  DISP_WINDOWS();
//  for(i=1;i<=Y_PAGE;i++)
//    for (k=0; k<=7;k++)
//      for(j=1;j<=Height;j++)
//        LCD_Write_Data( (GRAM[Height-j][Y_PAGE-i]&(1<<(7-k)))?YELLOW:BLACK );
//}


//??????
//x1,y1:????????????
//x2,y2:????????????  
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) 
{
	uint16_t t; 
	uint16_t xerr=0,yerr=0,delta_x,delta_y,distance; 
	uint16_t incx,incy,uRow,uCol; 
	delta_x=x2-x1; //?????????????????? 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //?????????????????? 
	else if(delta_x==0)incx=0;//????????? 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//????????? 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //??????????????????????????? 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//???????????? 
	{  
		LCD_Disp_At_X_Y(uRow,uCol,color);//?????? 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}    

//?????????	  
//(x1,y1),(x2,y2):?????????????????????
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    LCD_DrawLine(x1,y1,x2,y1,color);
    LCD_DrawLine(x1,y1,x1,y2,color);
    LCD_DrawLine(x1,y2,x2,y2,color);
    LCD_DrawLine(x2,y1,x2,y2,color);
}



//??????????????????????????????????????????
//(x,y):?????????
//r    :??????
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
    int a,b;
    int di;
    a=0;b=r;	  
    di=3-(r<<1);             //??????????????????????????????
    while(a<=b)
    {
            LCD_Disp_At_X_Y(x0+a,y0-b,color);             //5
            LCD_Disp_At_X_Y(x0+b,y0-a,color);             //0           
            LCD_Disp_At_X_Y(x0+b,y0+a,color);             //4               
            LCD_Disp_At_X_Y(x0+a,y0+b,color);             //6 
            LCD_Disp_At_X_Y(x0-a,y0+b,color);             //1       
            LCD_Disp_At_X_Y(x0-b,y0+a,color);             
            LCD_Disp_At_X_Y(x0-a,y0-b,color);             //2             
            LCD_Disp_At_X_Y(x0-b,y0-a,color);             //7     	         
            a++;
            //??????Bresenham????????????     
            if(di<0)di +=4*a+6;	  
            else
            {
                    di+=10+4*(a-b);   
                    b--;
            } 						    
    }
} 	


//?????????????????????????????????
//x,y:????????????
//num:??????????????????:" "--->"~"
//size:???????????? 12/16/24
//mode:????????????(1)?????????????????????(0)
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode ,uint16_t POINT_COLOR,uint16_t BACK_COLOR)
{  							  
    uint8_t temp,t1,t;
    uint16_t y0=y;
    uint8_t csize=(size/8+((size%8)?1:0))*(size/2);		//?????????????????????????????????????????????????????????	
    num=num-' ';//????????????????????????ASCII???????????????????????????????????????-' '??????????????????????????????
    for(t=0;t<csize;t++)
    {   
      if(size==12)temp=asc2_1206[num][t]; 	 	//??????1206??????
      else return;								//???????????????
      for(t1=0;t1<8;t1++)
      {			    
        if(temp&0x80)LCD_Disp_At_X_Y(x,y,POINT_COLOR);
        else if(mode==0)LCD_Disp_At_X_Y(x,y,BACK_COLOR);
        temp<<=1;
        y++;
        if(y>=Height)return;		//????????????
        if((y-y0)==size)
        {
                y=y0;
                x++;
                if(x>=Width)return;	//????????????
                break;
        }
      }  	 
    }  	    	   	 	  
}   


//m^n??????
//?????????:m^n??????.
uint32_t LCD_Pow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 



//????????????,?????????0,????????????
//x,y :????????????	 
//len :???????????????
//size:????????????
//color:?????? 
//num:??????(0~4294967295);	 
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode,uint16_t POINT_COLOR,uint16_t BACK_COLOR)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01,POINT_COLOR,BACK_COLOR);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01,POINT_COLOR,BACK_COLOR);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01,POINT_COLOR,BACK_COLOR); 
	}
} 
	
	
	
	
//???????????????
//x,y:????????????
//width,height:????????????  
//size:????????????
//*p:?????????????????????		  
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p,uint16_t POINT_COLOR,uint16_t BACK_COLOR)
{         
    uint8_t x0=x;
    width+=x;
    height+=y;
    while((*p<='~')&&(*p>=' '))//???????????????????????????!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//??????
        LCD_ShowChar(x,y,*p,size,0,POINT_COLOR,BACK_COLOR);
        x+=size/2;
        p++;
    }  
}

	
	
	
//????????????
//x,y:????????????
//width,height:????????????  
//size:???????????? 12 16 24
//double?????????
void LCD_Show_Decimal(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,double num,uint16_t POINT_COLOR,uint16_t BACK_COLOR)
{
	//uint8_t ss[10];
	//sprintf((char *)ss, "%5.1f", num);			//??????????????????
	//LCD_ShowString(x,y,width,height,size,ss,POINT_COLOR,BACK_COLOR);
}







/* USER CODE END 0 */



/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
