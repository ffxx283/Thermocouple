/**
  ******************************************************************************
  * File Name          : file.h
  * Description        : This file provides code for the configuration
  *                      of the file instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ulfileate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __file_H
#define __file_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "file.h"
#include "ff.h"  
#include "stdio.h"
#include "stdlib.h"
#include "sd.h"
#include "usbd_cdc_if.h"
   
   
/* USER CODE BEGIN Prototypes */




//void FATFS_TEST (void);
void FATFS_MOUNT(void);
void FATFS_UNMOUNT(void);
void FATFS_Save_Pwr_Val ( uint32_t Save_Data );
void CH_Temp_Save_to_file (void);
void Check_SD_Card_Info(void);
//void FATFS_Save_CH_Temp ( uint32_t Timestamp );


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ file_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
