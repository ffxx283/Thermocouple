/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

#include "ADS1262.h"
#include "S25FL512.h"
#include "sd.h"
#include "usbd_cdc_if.h"

#include "file.h"
#include <stdio.h>
#include <stdarg.h>
//#include "lv_examples.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
uint8_t Time_Flag_Is_Get=0;
extern lv_indev_t * indev_keypad;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void System_init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void My_sprintf ( const char * format, ... )
{
  char buffer[32];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer,256,format, args);
  va_end (args);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_USB_DEVICE_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  TIM1_Start_Working(1);

  //init the system
  System_init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	ui_init();

	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		ADS1262_Get_ADC();
		ADC_Get_Voltage();


		//time base,set by customer,can be 1s 2s 5s 10s
		if(Time_Flag_Is_Get)
		{
			Time_Flag_Is_Get = 0;
			ui_table_data_change();
		}

		//LVGL system function
		lv_task_handler();
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void System_init(void)
{
	uint8_t buffer[20]={0};
	uint32_t SD_SectorCount_Num = 0;

	//LCD

	LCD_ST7735S_CPT144_Initial();
	LCD_DrawLine(2, 0, 2, 126, YELLOW);
	LCD_ShowString(5,0,100,12,12,(uint8_t*)"LCD Init OK!",YELLOW,BLACK);
	HAL_Delay(200);

	//ADS1262

	if( 0 == ADS1262_Init() )
		LCD_ShowString(5,13,100,12,12,(uint8_t*)"ADS1262 Init OK!",YELLOW,BLACK);
	else
		LCD_ShowString(5,13,100,12,12,(uint8_t*)"ADS1262 Init FAIL!",YELLOW,BLACK);
	HAL_Delay(200);

	//SPI FLASH init

	if( S25FL512 == S25FLXX_Init() )
		LCD_ShowString(5,26,100,12,12,(uint8_t*)"S25FL512 Init OK!",YELLOW,BLACK);
	else
		LCD_ShowString(5,26,100,12,12,(uint8_t*)"S25FL512 Init FAIL!",YELLOW,BLACK);
	HAL_Delay(200);

	//SPI FLASH Read Test

//	LCD_ShowString(5,39,100,12,12,(uint8_t*)"S25FL512 Erase...",YELLOW,BLACK);
//	S25FLXX_Erase_Chip();
//	S25FLXX_Write_NoCheck((uint8_t*)"Read Test OK!",0,sizeof("Read Test OK!"));
	S25FLXX_Read(buffer,0,sizeof("Read Test OK!"));   //读取flash
	LCD_ShowString(5,39,100,12,12,buffer,YELLOW,BLACK);
	HAL_Delay(200);

	//SD Card

	if( !SD_Initialize() )
	{
		SD_SectorCount_Num = SD_GetSectorCount();
		LCD_ShowString(5,52,100,12,12,(uint8_t*)"SD Card Init OK!",YELLOW,BLACK);
		LCD_ShowString(5,65,100,12,12,(uint8_t*)"Size(MB):",YELLOW,BLACK);
		LCD_ShowNum(54,65, SD_SectorCount_Num>>11 ,6,12,0,YELLOW,BLACK);
	}
	else
		LCD_ShowString(5,52,100,12,12,(uint8_t*)"SD Card Init FAIL!",YELLOW,BLACK);
	HAL_Delay(200);

	//LVGL

	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	LCD_ShowString(5,78,100,12,12,(uint8_t*)"LVGL Init OK!",YELLOW,BLACK);
	LCD_ShowString(5,91,100,12,12,(uint8_t*)"UI loading...",YELLOW,BLACK);

	HAL_Delay(2000);

}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
