/**
  ******************************************************************************
  * File Name          : ADS1262.h
  * Description        : This ADS1262 provides code for the configuration
  *                      of the ADS1262 instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under UlADS1262ate Liberty license
  * SLA0044, the "License"; You may not use this ADS1262 except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADS1262_H
#define __ADS1262_H
#ifdef __cplusplus
 extern "C" {
#endif
   


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "math.h"

//ADS1262 POWER controll
#define ADS_POWER_CTL_1 (ADS_POWER_CTL_GPIO_Port->BSRR = ADS_POWER_CTL_Pin)
#define ADS_POWER_CTL_0 (ADS_POWER_CTL_GPIO_Port->BSRR = (uint32_t)ADS_POWER_CTL_Pin << 16u )

//CH444G Analog switch controll
#define ADC_SWITCH_EN_1 (ADC_SWITCH_EN_GPIO_Port->BSRR = ADC_SWITCH_EN_Pin)
#define ADC_SWITCH_EN_0 (ADC_SWITCH_EN_GPIO_Port->BSRR = (uint32_t)ADC_SWITCH_EN_Pin << 16u )

#define ADC_SWITCH_IN0_1 (ADC_SWITCH_IN0_GPIO_Port->BSRR = ADC_SWITCH_IN0_Pin)
#define ADC_SWITCH_IN0_0 (ADC_SWITCH_IN0_GPIO_Port->BSRR = (uint32_t)ADC_SWITCH_IN0_Pin << 16u )

#define ADC_SWITCH_IN1_1 (ADC_SWITCH_IN1_GPIO_Port->BSRR = ADC_SWITCH_IN1_Pin)
#define ADC_SWITCH_IN1_0 (ADC_SWITCH_IN1_GPIO_Port->BSRR = (uint32_t)ADC_SWITCH_IN1_Pin << 16u )

//ADS1262 CS
#define SPI1_CS_ADS_1 (SPI1_CS_ADS_GPIO_Port->BSRR = SPI1_CS_ADS_Pin)
#define SPI1_CS_ADS_0 (SPI1_CS_ADS_GPIO_Port->BSRR = (uint32_t)SPI1_CS_ADS_Pin << 16u )
//ADS1262 RESET
#define ADS_RESET_1 (ADS_RESET_GPIO_Port->BSRR = ADS_RESET_Pin)
#define ADS_RESET_0 (ADS_RESET_GPIO_Port->BSRR = (uint32_t)ADS_RESET_Pin << 16u )
//ADS1262 START
#define ADS_START_1 (ADS_START_GPIO_Port->BSRR = ADS_START_Pin)
#define ADS_START_0 (ADS_START_GPIO_Port->BSRR = (uint32_t)ADS_START_Pin << 16u )

#define ADS_DRDY       	HAL_GPIO_ReadPin( ADS_DRDY_GPIO_Port , ADS_DRDY_Pin )


//ADS1262 regsister define
#define ADS1262_ID 0x00
#define ADS1262_POWER 0x01
#define ADS1262_INTERFACE 0x02
#define ADS1262_MODE0 0x03
#define ADS1262_MODE1 0x04
#define ADS1262_MODE2 0x05
#define ADS1262_INPMUX 0x06
#define ADS1262_OFCAL0 0x07
#define ADS1262_OFCAL1 0x08
#define ADS1262_OFCAL2 0x09
#define ADS1262_FSCAL0 0x0A
#define ADS1262_FSCAL1 0x0B
#define ADS1262_FSCAL2 0x0C
#define ADS1262_IDACMUX 0x0D
#define ADS1262_IDACMAG 0x0E
#define ADS1262_REFMUX 0x0F
#define ADS1262_TDACP 0x10
#define ADS1262_TDACN 0x11
#define ADS1262_GPIOCON 0x12
#define ADS1262_GPIODIR 0x13
#define ADS1262_GPIODAT 0x14


#define CMD_WRITE 0x40
#define CMD_READ 0x20


//Spice register
#define ADS1262_ADC1_DATA 0x12


#define ADC_COVEN_TIME 20      //ms
#define ADS1262_INPUT_01 0x01
#define ADS1262_INPUT_23 0x23
#define ADS1262_INPUT_45 0x45
/*---------------------*/


uint8_t ADS1262_Get_ID(void);
void ADS1262_Set_Test_DAC(void);


uint8_t ADS1262_Init(void);
uint32_t ADS1262_Get_ADC(void);
void ADS1262_Set_Channel( uint8_t num );
void CH444G_Set_Channel( uint8_t num );


//float ADS1262_Temperature_sensor_DATA_GET(void);
//float ADC1262_Change_VAL_to_Temperature ( float Temperature  , float ADC_VAL );









/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ ADS1262_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
