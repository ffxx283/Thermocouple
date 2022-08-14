/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define Debug_Version 1
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RESET_Pin GPIO_PIN_13
#define LCD_RESET_GPIO_Port GPIOC
#define PWR_VAL_ADC_Pin GPIO_PIN_0
#define PWR_VAL_ADC_GPIO_Port GPIOA
#define UB_PR_ADC_Pin GPIO_PIN_1
#define UB_PR_ADC_GPIO_Port GPIOA
#define IP5306_5V_ADC_Pin GPIO_PIN_2
#define IP5306_5V_ADC_GPIO_Port GPIOA
#define ADS_DRDY_Pin GPIO_PIN_3
#define ADS_DRDY_GPIO_Port GPIOA
#define SPI1_CS_ADS_Pin GPIO_PIN_4
#define SPI1_CS_ADS_GPIO_Port GPIOA
#define SYS_PWR_KEY_Pin GPIO_PIN_0
#define SYS_PWR_KEY_GPIO_Port GPIOB
#define ADC_SWITCH_EN_Pin GPIO_PIN_1
#define ADC_SWITCH_EN_GPIO_Port GPIOB
#define ADC_SWITCH_IN0_Pin GPIO_PIN_2
#define ADC_SWITCH_IN0_GPIO_Port GPIOB
#define ADC_SWITCH_IN1_Pin GPIO_PIN_10
#define ADC_SWITCH_IN1_GPIO_Port GPIOB
#define ADS_START_Pin GPIO_PIN_11
#define ADS_START_GPIO_Port GPIOB
#define SPI2_CS_SD_Pin GPIO_PIN_12
#define SPI2_CS_SD_GPIO_Port GPIOB
#define SPI2_CS_FLASH_Pin GPIO_PIN_8
#define SPI2_CS_FLASH_GPIO_Port GPIOA
#define ADS_RESET_Pin GPIO_PIN_9
#define ADS_RESET_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_10
#define LCD_CS_GPIO_Port GPIOA
#define KEY_DOWN_Pin GPIO_PIN_15
#define KEY_DOWN_GPIO_Port GPIOA
#define KEY_UP_Pin GPIO_PIN_3
#define KEY_UP_GPIO_Port GPIOB
#define ADS_POWER_CTL_Pin GPIO_PIN_4
#define ADS_POWER_CTL_GPIO_Port GPIOB
#define KEY_OK_Pin GPIO_PIN_5
#define KEY_OK_GPIO_Port GPIOB
#define KEY_CANCEL_Pin GPIO_PIN_6
#define KEY_CANCEL_GPIO_Port GPIOB
#define LCD_SCK_Pin GPIO_PIN_7
#define LCD_SCK_GPIO_Port GPIOB
#define LCD_SDA_Pin GPIO_PIN_8
#define LCD_SDA_GPIO_Port GPIOB
#define LCD_DCX_Pin GPIO_PIN_9
#define LCD_DCX_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
