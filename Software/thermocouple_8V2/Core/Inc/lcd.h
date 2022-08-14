/**
  ******************************************************************************
  * File Name          : LCD.h
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __lcd_H
#define __lcd_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */



/* USER CODE BEGIN Private defines */


//#define LCD_CS_1 HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET )
//#define LCD_CS_0 HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET )
//
//#define LCD_SCK_1 HAL_GPIO_WritePin(LCD_SCK_GPIO_Port, LCD_SCK_Pin, GPIO_PIN_SET )
//#define LCD_SCK_0 HAL_GPIO_WritePin(LCD_SCK_GPIO_Port, LCD_SCK_Pin, GPIO_PIN_RESET )
//
//#define LCD_SDA_1 HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_SET )
//#define LCD_SDA_0 HAL_GPIO_WritePin(LCD_SDA_GPIO_Port, LCD_SDA_Pin, GPIO_PIN_RESET )
//
//#define LCD_DCX_1 HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_SET )
//#define LCD_DCX_0 HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_RESET )
//
//#define LCD_RESET_1 HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_SET )
//#define LCD_RESET_0 HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_RESET )



#define LCD_CS_1 (LCD_CS_GPIO_Port->BSRR = LCD_CS_Pin)
#define LCD_CS_0 (LCD_CS_GPIO_Port->BSRR = (uint32_t)LCD_CS_Pin << 16u )

#define LCD_SCK_1 (LCD_SCK_GPIO_Port->BSRR = LCD_SCK_Pin)
#define LCD_SCK_0 (LCD_SCK_GPIO_Port->BSRR = (uint32_t)LCD_SCK_Pin << 16u )

#define LCD_SDA_1 (LCD_SDA_GPIO_Port->BSRR = LCD_SDA_Pin)
#define LCD_SDA_0 (LCD_SDA_GPIO_Port->BSRR = (uint32_t)LCD_SDA_Pin << 16u )

#define LCD_DCX_1 (LCD_DCX_GPIO_Port->BSRR = LCD_DCX_Pin)
#define LCD_DCX_0 (LCD_DCX_GPIO_Port->BSRR = (uint32_t)LCD_DCX_Pin << 16u )

#define LCD_RESET_1 (LCD_RESET_GPIO_Port->BSRR = LCD_RESET_Pin)
#define LCD_RESET_0 (LCD_RESET_GPIO_Port->BSRR = (uint32_t)LCD_RESET_Pin << 16u )

#define Height 128
#define Width  128
#define X_PAGE 	(Height/6)		//支持多少个6x8字宽（一般不需要修改，默认即可）
#define Y_PAGE 	(Width/8)		//支持多少个6x8字高（一般不需要修改，默认即可）
   
#define RED    0xf800
#define GREEN  0x07e0
#define BLUE   0x001f
#define YELLOW 0xffe0
#define WHITE  0xffff
#define BLACK  0x0000
#define PURPLE 0xf81f
   
      
/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */
void LCD_ST7735S_CPT144_Initial ();
void LCD_DISPLAY_COLOR(uint32_t color);
void LCD_Disp_At_X_Y(uint8_t X, uint8_t Y, uint16_t color);


void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode ,uint16_t POINT_COLOR,uint16_t BACK_COLOR);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode ,uint16_t POINT_COLOR,uint16_t BACK_COLOR);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode,uint16_t POINT_COLOR,uint16_t BACK_COLOR);
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p,uint16_t POINT_COLOR,uint16_t BACK_COLOR);
void LCD_Show_Decimal(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,double num,uint16_t POINT_COLOR,uint16_t BACK_COLOR);

void LCD_FillScreen( uint8_t GRAM[Height][Y_PAGE] );



/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ lcd_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
