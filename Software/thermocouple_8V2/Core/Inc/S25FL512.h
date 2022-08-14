/**
  ******************************************************************************
  * File Name          : S25FL512.h
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __S25FL512_H
#define __S25FL512_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdlib.h"
/* USER CODE BEGIN Includes */
#include "spi.h"
/* USER CODE END Includes */


#define W25Q80 	0XEF13
#define W25Q16 	0XEF14
#define W25Q32 	0XEF15
#define W25Q64 	0XEF16
#define W25Q128	0XEF17
#define W25Q256 0XEF18


#define S25FL512	0X0119

//指令表
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 

#define W25X_ReadStatusReg1		0x05 
//#define W25X_ReadStatusReg2		0x35
//#define W25X_ReadStatusReg3		0x15 //S25FL512 not support

#define W25X_WriteStatusReg1    0x01 
//#define W25X_WriteStatusReg2    0x31 //S25FL512 not support
//#define W25X_WriteStatusReg3    0x11 //S25FL512 not support

#define W25X_ReadData			0x03 //S25FL512 24bit address
#define W25X_FastReadData		0x0B //S25FL512 24bit address
//#define W25X_FastReadDual		0x3B //S25FL512 not support
#define W25X_PageProgram		0x02 //S25FL512 24bit address
//#define W25X_BlockErase			0xD8 //S25FL512 sector erase, used 24bit address
#define W25X_SectorErase		0xD8
//#define W25X_SectorErase		0x20 //S25FL512 not support
#define W25X_ChipErase			0xC7 
//#define W25X_PowerDown			0xB9 //S25FL512 not support
//#define W25X_ReleasePowerDown	0xAB //S25FL512 not support
#define W25X_DeviceID			0xAB 
#define W25X_ManufactDeviceID	0x90 
#define W25X_JedecDeviceID		0x9F 

#define S25FL_BankRegRead		0x16
#define S25FL_BankRegWrite		0x17
//#define W25X_Enable4ByteAddr    0xB7 //S25FL512 not support
//#define W25X_Exit4ByteAddr      0xE9 //S25FL512 not support

#define S25FLx_CS_IO_0()   (SPI2_CS_FLASH_GPIO_Port->BSRR = (uint32_t)SPI2_CS_FLASH_Pin << 16u )
#define S25FLx_CS_IO_1()    (SPI2_CS_FLASH_GPIO_Port->BSRR = SPI2_CS_FLASH_Pin)
   
extern uint16_t S25FLXX_TYPE;					//定义S25FLXX芯片型号


uint16_t S25FLXX_Init(void);
uint16_t  S25FLXX_ReadID(void);  	    		//读取FLASH ID
uint16_t S25FLXX_Set_4byteADDR(void);

uint8_t	 S25FLXX_ReadSR(uint8_t regno);        		//读取状态寄存器
void S25FLXX_Write_SR(uint8_t regno,uint8_t sr);
void S25FLXX_Wait_Busy(void);           	//等待空闲


void S25FLXX_Write_Enable(void);  		//写使能
void S25FLXX_Write_Disable(void);		//写保护


void S25FLXX_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead);   //读取flash
void S25FLXX_Write_NoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);


void S25FLXX_Erase_Chip(void);    	  	//整片擦除
void S25FLXX_Erase_Sector(uint32_t Dst_Addr);	//扇区擦除

//void S25FLXX_PowerDown(void);        	//进入掉电模式
//void S25FLXX_WAKEUP(void);				//唤醒


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ S25FL512_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
