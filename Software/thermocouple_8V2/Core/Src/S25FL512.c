/**
  ******************************************************************************
  * File Name          : S25FL512.c
  * Description        : This file provides code for the configuration
  *                      of the S25FL512 instances.
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
#include "S25FL512.h"

/* USER CODE BEGIN 0 */


uint16_t S25FLXX_TYPE=S25FL512;


//SPI2 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
uint8_t SPI2_ReadWriteByte(uint8_t TxData)
{
  uint8_t Rxdata;
  HAL_SPI_TransmitReceive(&hspi2,&TxData,&Rxdata,1, 1000);       
  return Rxdata;          		    //返回收到的数据
}


/**
  * @brief  Initializes the S25FLxFV interface.
  * @retval None
  */
uint16_t S25FLXX_Init(void)
{ 
	uint16_t Temp = 0;

	S25FLx_CS_IO_1();
	Temp = S25FLXX_ReadID();
	S25FLXX_Set_4byteADDR();
	return Temp;
}


//读取S25FLXX的状态寄存器，S25FLXX一共有3个状态寄存器
//状态寄存器1：
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:默认0,状态寄存器保护位,配合WP使用
//TB,BP2,BP1,BP0:FLASH区域写保护设置
//WEL:写使能锁定
//BUSY:忙标记位(1,忙;0,空闲)
//默认:0x00
//状态寄存器2：
//BIT7  6   5   4   3   2   1   0
//SUS   CMP LB3 LB2 LB1 (R) QE  SRP1
//状态寄存器3：
//BIT7      6    5    4   3   2   1   0
//HOLD/RST  DRV1 DRV0 (R) (R) WPS ADP ADS
//regno:状态寄存器号，范:1~3
//返回值:状态寄存器值
uint8_t S25FLXX_ReadSR(uint8_t regno)
{  
	uint8_t byte=0,command=0; 
  switch(regno)
  {
    case 1:
        command=W25X_ReadStatusReg1;    //读状态寄存器1指令
        break;
//    case 2:
//        command=W25X_ReadStatusReg2;    //读状态寄存器2指令
//        break;
//    case 3:
//        command=W25X_ReadStatusReg3;    //读状态寄存器3指令
//        break;
    default:
        command=W25X_ReadStatusReg1;    
        break;
  }    
	S25FLx_CS_IO_0();                            //使能器件
	SPI2_ReadWriteByte(command);
	byte=SPI2_ReadWriteByte(0Xff);          //读取一个字节  
	S25FLx_CS_IO_1();                         //取消片选
	return byte;   
} 

//写S25FLXX状态寄存器
void S25FLXX_Write_SR(uint8_t regno,uint8_t sr)
{   
  uint8_t command=0;
  switch(regno)
  {
      case 1:
          command=W25X_WriteStatusReg1;    //写状态寄存器1指令
          break;
//      case 2:
//          command=W25X_WriteStatusReg2;    //写状态寄存器2指令
//          break;
//      case 3:
//          command=W25X_WriteStatusReg3;    //写状态寄存器3指令
//          break;
      default:
          command=W25X_WriteStatusReg1;    
          break;
  }   
	S25FLx_CS_IO_0();                             //使能器件
	SPI2_ReadWriteByte(command);            //发送写取状态寄存器命令    
	SPI2_ReadWriteByte(sr);                 //写入一个字节  
	S25FLx_CS_IO_1();                             //取消片选
}   


//S25FLXX写使能
//将WEL置位   
void S25FLXX_Write_Enable(void)
{
	S25FLx_CS_IO_0();                             //使能器件
  SPI2_ReadWriteByte(W25X_WriteEnable);   //发送写使能  
	S25FLx_CS_IO_1();                             //取消片选
} 
//S25FLXX写禁止
//将WEL清零  
void S25FLXX_Write_Disable(void)
{  
	S25FLx_CS_IO_0();                             //使能器件
  SPI2_ReadWriteByte(W25X_WriteDisable);  //发送写禁止指令    
	S25FLx_CS_IO_1();                             //取消片选
} 

//读取芯片ID
//返回值如下:				   
//0X0119,表示芯片型号为S25FL512
uint16_t S25FLXX_ReadID(void)
{
	uint16_t Temp = 0;	  
	S25FLx_CS_IO_0();
	SPI2_ReadWriteByte(0x90);//发送读取ID命令	    
	SPI2_ReadWriteByte(0x00); 	    
	SPI2_ReadWriteByte(0x00); 	    
	SPI2_ReadWriteByte(0x00); 	 			   
	Temp|=SPI2_ReadWriteByte(0xFF)<<8;  
	Temp|=SPI2_ReadWriteByte(0xFF);	 
	S25FLx_CS_IO_1();
	return Temp;
}


//设置芯片的地址为32bit位宽
//返回值如下:读取到的寄存器的值
uint16_t S25FLXX_Set_4byteADDR(void)
{
	uint8_t Temp = 0;

	S25FLx_CS_IO_0();
	SPI2_ReadWriteByte(S25FL_BankRegRead);  //发送写取状态寄存器命令
	Temp = SPI2_ReadWriteByte(0xFF);        //写入一个字节
	S25FLx_CS_IO_1();

	HAL_Delay(1);
	S25FLx_CS_IO_0();
	Temp |= 0x80;
	SPI2_ReadWriteByte(S25FL_BankRegWrite);  	//发送写取状态寄存器命令
	SPI2_ReadWriteByte(Temp);  					//发送写取状态寄存器命令
	S25FLx_CS_IO_1();

	HAL_Delay(1);
	S25FLx_CS_IO_0();
	SPI2_ReadWriteByte(S25FL_BankRegRead);  //发送写取状态寄存器命令
	Temp = SPI2_ReadWriteByte(0xFF);        //写入一个字节
	S25FLx_CS_IO_1();

	return Temp;
}


//读取SPI FLASH  
//在指定地址开始读取指定长度的数据
//pBuffer:数据存储区
//ReadAddr:开始读取的地址(24bit)
//NumByteToRead:要读取的字节数(最大65535)
void S25FLXX_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead)
{ 
 	uint16_t i;   										    
	S25FLx_CS_IO_0();                             //使能器件
  SPI2_ReadWriteByte(W25X_ReadData);      //发送读取命令  
  if(S25FLXX_TYPE==S25FL512)                //如果是S25FL512的话地址为4字节的，要发送最高8位
  {
    SPI2_ReadWriteByte((uint8_t)((ReadAddr)>>24));    
  }
  SPI2_ReadWriteByte((uint8_t)((ReadAddr)>>16));   //发送24bit地址    
  SPI2_ReadWriteByte((uint8_t)((ReadAddr)>>8));   
  SPI2_ReadWriteByte((uint8_t)ReadAddr);   
  for(i=0;i<NumByteToRead;i++)
  { 
    pBuffer[i]=SPI2_ReadWriteByte(0XFF);    //循环读数  
  }
	S25FLx_CS_IO_1();
}  


//SPI在一页(0~65535)内写入少于256个字节的数据
//在指定地址开始写入最大256字节的数据
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大256),该数不应该超过该页的剩余字节数!!!	 
void S25FLXX_Write_Page(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)
{
 	uint16_t i;  
  S25FLXX_Write_Enable();                  //SET WEL
  S25FLx_CS_IO_0();                             //使能器件
  SPI2_ReadWriteByte(W25X_PageProgram);   //发送写页命令   
  if(S25FLXX_TYPE==S25FL512)                //如果是S25FL512的话地址为4字节的，要发送最高8位
  {
      SPI2_ReadWriteByte((uint8_t)((WriteAddr)>>24)); 
  }
  SPI2_ReadWriteByte((uint8_t)((WriteAddr)>>16)); //发送24bit地址    
  SPI2_ReadWriteByte((uint8_t)((WriteAddr)>>8));   
  SPI2_ReadWriteByte((uint8_t)WriteAddr);   
  for(i=0;i<NumByteToWrite;i++)
    SPI2_ReadWriteByte(pBuffer[i]);//循环写数  
	S25FLx_CS_IO_1();                             //取消片选
	S25FLXX_Wait_Busy();					   //等待写入结束
} 


//无检验写SPI FLASH 
//必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
//具有自动换页功能 
//在指定地址开始写入指定长度的数据,但是要确保地址不越界!
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大65535)
//CHECK OK
void S25FLXX_Write_NoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)
{ 			 		 
	uint16_t pageremain;	   
	pageremain=256-WriteAddr%256; //单页剩余的字节数		 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//不大于256个字节
	while(1)
	{	   
		S25FLXX_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//写入结束了
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			  //减去已经写入了的字节数
			if(NumByteToWrite>256)pageremain=256; //一次可以写入256个字节
			else pageremain=NumByteToWrite; 	  //不够256个字节了
		}
	}
} 




//擦除整个芯片		  
//等待时间超长...
void S25FLXX_Erase_Chip(void)
{                                   
	S25FLXX_Write_Enable();                  //SET WEL
	S25FLXX_Wait_Busy();
	S25FLx_CS_IO_0();                             //使能器件
	SPI2_ReadWriteByte(W25X_ChipErase);        //发送片擦除命令
	S25FLx_CS_IO_1();                             //取消片选
	S25FLXX_Wait_Busy();   				   //等待芯片擦除结束
}   




//擦除一个扇区
//Dst_Addr:扇区地址 根据实际容量设置
//擦除一个扇区的最少时间:150ms
void S25FLXX_Erase_Sector(uint32_t Dst_Addr)
{  
	//监视falsh擦除情况,测试用   
 	//printf("fe:%x\r\n",Dst_Addr);	  
 	//Dst_Addr*=4096;
  S25FLXX_Write_Enable();                  //SET WEL
  S25FLXX_Wait_Busy();
  S25FLx_CS_IO_0();                             //使能器件
  SPI2_ReadWriteByte(W25X_SectorErase);   //发送扇区擦除指令 
  if(S25FLXX_TYPE==S25FL512)                //如果是S25FL512的话地址为4字节的，要发送最高8位
  {
      SPI2_ReadWriteByte((uint8_t)((Dst_Addr)>>24)); 
  }
  SPI2_ReadWriteByte((uint8_t)((Dst_Addr)>>16));  //发送24bit地址    
  SPI2_ReadWriteByte((uint8_t)((Dst_Addr)>>8));   
  SPI2_ReadWriteByte((uint8_t)Dst_Addr);  
  S25FLx_CS_IO_1();                             //取消片选
  S25FLXX_Wait_Busy();   				    //等待擦除完成
}  
//等待空闲
void S25FLXX_Wait_Busy(void)
{   
	while((S25FLXX_ReadSR(1)&0x01)==0x01);   // 等待BUSY位清空
}  


////进入掉电模式
//void S25FLXX_PowerDown(void)
//{
//  S25FLx_CS_IO_0();                             //使能器件
//  SPI2_ReadWriteByte(W25X_PowerDown);     //发送掉电命令
//	S25FLx_CS_IO_1();                             //取消片选
//}
////唤醒
//void S25FLXX_WAKEUP(void)
//{
//  S25FLx_CS_IO_0();                                 //使能器件
//  SPI2_ReadWriteByte(W25X_ReleasePowerDown);  //  send W25X_PowerDown command 0xAB
//	S25FLx_CS_IO_1();                                 //取消片选
//}





/* USER CODE END 0 */



/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
