/**
  ******************************************************************************
  * File Name          : file.c
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

/* Includes ------------------------------------------------------------------*/
#include "file.h"

/* USER CODE BEGIN 0 */

FATFS     fs;
FATFS     *pfs;

FIL fil;
FIL *pf = &fil;

FRESULT   fr ;

uint32_t   write_count=0;
uint32_t   read_count=0;
char       line[20]; /* Line buffer */
char       write_data[]="hello fatfs!\r\n";

uint8_t   SD_State=0;
uint32_t  sd_size = 0;

uint8_t CH_Temp_Save_En=0;
extern uint8_t SD_Ready;
extern float CH_Temp[8];

//
//void FATFS_TEST (void)
//{
//
//  uint8_t count=0;
//  //MKFS_PARM MKFS;
//  //BYTE work[FF_MAX_SS];
//
//  pfs = &fs;
//
//  for(count=0;count<100;count++)
//    line[count] = count;
//
//  fr = f_mount(pfs, "0:", 1);
//  //if( fr ) return fr;
//
//  if( fr == FR_NO_FILESYSTEM )
//  {
//    /*
//    MKFS.fmt = FM_FAT;
//    MKFS.align = 0;
//    MKFS.au_size = 0;
//    MKFS.n_fat = 0;
//    MKFS.n_root = 0;
//
//    fr = f_mkfs("0:", &MKFS, work, FF_MAX_SS );
//
//    //fr = f_mount(NULL, "1:", 1);
//    //fr = f_mount(pfs, "1:", 1);
//
//    fr = f_open(pf, "0:message.txt", FA_CREATE_NEW|FA_WRITE );
//
//    fr = f_write( pf , write_data , 20 , &write_count );
//    write_count = 0;
//    f_close ( pf );
//
//    */
//	CDC_Transmit_FS((uint8_t*)"Please format SD card",sizeof("Please format SD card"));
//
//  } else if ( fr != FR_OK )
//  {
//    CDC_Transmit_FS((uint8_t*)"SD card Error",sizeof("SD card Error"));
//  }
//
//  fr = f_open(pf, "0:message.txt", FA_READ );
//  if ( fr == FR_NO_FILE )
//  {
//    fr = f_open( pf, "0:message.txt", FA_CREATE_NEW|FA_WRITE|FA_READ );
//
//    fr = f_write( pf , write_data , sizeof(write_data) , &write_count );
//    write_count = 0;
//
//    f_close ( pf );
//    fr = f_open(pf, "0:message.txt", FA_READ );
//
//    CDC_Transmit_FS((uint8_t*)"FR_NO_FILE",sizeof("FR_NO_FILE"));
//
//  }
//
//  fr = f_read( pf , line, sizeof(write_data), &read_count);  /* Read a chunk of data from the source file */
//
//  f_close ( pf );
//
//  fr = f_open(pf, "0:message.txt", FA_WRITE|FA_READ );
//  fr = f_lseek(pf, f_size(pf));
//
//  fr = f_write( pf , write_data , sizeof(write_data) , &write_count );
//
//  f_close ( pf );
//
//  f_unmount("0:");
//
//  CDC_Transmit_FS((uint8_t*)"f_unmount",sizeof("f_unmount"));
//
//}


void FATFS_MOUNT(void)
{
  pfs = &fs;
  fr = f_mount(pfs, "0:", 1);
}


void FATFS_UNMOUNT(void)
{
  f_unmount("0:");
}


void FATFS_Save_Pwr_Val ( uint32_t Save_Data )
{
  fr = f_open(pf, "0:PWR_VAL.txt", FA_WRITE|FA_READ );
  if ( fr == FR_NO_FILE )
  {
    fr = f_open( pf, "0:PWR_VAL.txt", FA_CREATE_NEW|FA_WRITE|FA_READ );
    f_close ( pf );
    fr = f_open(pf, "0:PWR_VAL.txt", FA_WRITE|FA_READ );
  }
  fr = f_lseek(pf, f_size(pf));
  fr = f_printf(pf, "%d \r\n", Save_Data);
  f_close ( pf );
}


void CH_Temp_Save_to_file (void)
{
	CH_Temp_Save_En = ~ CH_Temp_Save_En;
}

//SD_Ready: 1-ok;  0-error;
void Check_SD_Card_Info(void)
{
	uint8_t *cid_data;
	SD_Ready = ~SD_GetCID(cid_data);
	//FATFS_MOUNT();
}


//void FATFS_Save_CH_Temp ( uint32_t Timestamp )
//{
//	char buf[100];
//	fr = f_open(pf, "0:TEMP.txt", FA_WRITE|FA_READ );
//	if ( fr == FR_NO_FILE )
//	{
//		fr = f_open( pf, "0:TEMP.txt", FA_CREATE_NEW|FA_WRITE|FA_READ );
//		fr = f_printf(pf, "Time\tTEMP_CH0\tTEMP_CH1\tTEMP_CH2\tTEMP_CH3\tTEMP_CH4\tTEMP_CH5\tTEMP_CH6\tTEMP_CH7\r\n");
//		f_close ( pf );
//		fr = f_open(pf, "0:TEMP.txt", FA_WRITE|FA_READ );
//	}
//	else if ( !fr )
//	{
//		fr = f_lseek(pf, f_size(pf));
//		sprintf(buf, "%2dh-%2dm-%2ds\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\t%6.3f\r\n\0",\
//				Timestamp/3600,Timestamp%3600/60,Timestamp%60, \
//				CH_Temp[0],CH_Temp[1],CH_Temp[2],CH_Temp[3],\
//				CH_Temp[4],CH_Temp[5],CH_Temp[6],CH_Temp[7]\
//				);
//		fr = f_printf(pf, "%s",buf);
//		f_close ( pf );
//	}
//}
//




/* USER CODE END 0 */

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
