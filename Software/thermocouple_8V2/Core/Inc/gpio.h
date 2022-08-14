/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

#define KEY_OK       	HAL_GPIO_ReadPin( KEY_OK_GPIO_Port , KEY_OK_Pin )
#define KEY_CANCEL   	HAL_GPIO_ReadPin( KEY_CANCEL_GPIO_Port , KEY_CANCEL_Pin )
#define KEY_UP   		HAL_GPIO_ReadPin( KEY_UP_GPIO_Port , KEY_UP_Pin )
#define KEY_DOWN   		HAL_GPIO_ReadPin( KEY_DOWN_GPIO_Port , KEY_DOWN_Pin )



/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
uint8_t Get_Key_Value( uint8_t mode );
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

