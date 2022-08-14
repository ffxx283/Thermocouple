/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "sd.h"

/* Definitions of physical drive number for each drive */
#define SD_CARD	 	0  			//SD��,���Ϊ0

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	return  RES_OK;     //��ʼ���ɹ�
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  uint8_t res=0;	    
	switch(pdrv)
	{
		case SD_CARD:		//SD��
			res = SD_Initialize();//SD_Initialize() 
		 	if(res)//STM32 SPI��bug,��sd������ʧ�ܵ�ʱ�������ִ����������,���ܵ���SPI��д�쳣
			{			
				SD_SPI_ReadWriteByte(0xff);//�ṩ�����8��ʱ��
			}
  		break;
		default:
			res=1; 
	}		 
	if(res)return  STA_NOINIT;
	else return 0; //��ʼ���ɹ� 
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
  uint8_t res=0; 
  if (!count)return RES_PARERR;//count���ܵ���0�����򷵻ز�������		 	 
	switch(pdrv)
	{
		case SD_CARD://SD��			
      res=SD_ReadDisk(buff,sector,count);	 
		 	if(res)//STM32 SPI��bug,��sd������ʧ�ܵ�ʱ�������ִ����������,���ܵ���SPI��д�쳣
			{
				//SD_SPI_SpeedLow();
				SD_SPI_ReadWriteByte(0xff);//�ṩ�����8��ʱ��
				//SD_SPI_SpeedHigh();
			}
			break;
		default:
			res=1; 
	}
   //������ֵ����SPI_SD_driver.c�ķ���ֵת��ff.c�ķ���ֵ
    if(res==0x00)return RES_OK;	 
    else return RES_ERROR;	  
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
  uint8_t res=0;  
    if (!count)return RES_PARERR;//count���ܵ���0�����򷵻ز�������		 	 
	switch(pdrv)
	{
		case SD_CARD://SD��
      res=SD_WriteDisk((uint8_t*)buff,sector,count);
			break;
		default:
			res=1; 
	}
    //������ֵ����SPI_SD_driver.c�ķ���ֵת��ff.c�ķ���ֵ
    if(res == 0x00)return RES_OK;	 
    else return RES_ERROR;	
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  DRESULT res;						  			     
	if(pdrv==SD_CARD)//SD��
  {
    switch(cmd)
    {
      case CTRL_SYNC:
      SD_CS_IO_0();
          if(SD_WaitReady()==0)res = RES_OK; 
          else res = RES_ERROR;	  
      SD_CS_IO_1();
          break;	 
      case GET_SECTOR_SIZE:
          *(WORD*)buff = 512;
          res = RES_OK;
          break;	 
      case GET_BLOCK_SIZE:
          *(WORD*)buff = 8;
          res = RES_OK;
          break;	 
      case GET_SECTOR_COUNT:
          *(DWORD*)buff = SD_GetSectorCount();
          res = RES_OK;
          break;
      default:
          res = RES_PARERR;
          break;
    }
  }else
    res=RES_ERROR;//�����Ĳ�֧��
  return res;
}

