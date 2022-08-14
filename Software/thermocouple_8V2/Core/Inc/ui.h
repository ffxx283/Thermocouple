// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "tim.h"



extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_PowerBar1;
extern lv_obj_t * ui_TemperatureButton;
extern lv_obj_t * ui_Temperature_Label;
extern lv_obj_t * ui_FileButton;
extern lv_obj_t * ui_FILE_Label;
extern lv_obj_t * ui_SystemButton;
extern lv_obj_t * ui_SYSTEM_Label;
extern lv_obj_t * ui_SDCardOkbox1;
extern lv_obj_t * ui_TemperatureScreen;
extern lv_obj_t * ui_SDCardOkbox2;
extern lv_obj_t * ui_PowerBar2;
extern lv_obj_t * ui_table;
extern lv_obj_t * ui_FileScreen;
extern lv_obj_t * ui_FLASH_capacity;
extern lv_obj_t * ui_Send_Data_to_UART;
extern lv_obj_t * ui_Send_Data_to_UART_Label;
extern lv_obj_t * ui_FLASH_Bar;
extern lv_obj_t * ui_SD_Label;
extern lv_obj_t * ui_SD_Bar;
extern lv_obj_t * ui_SD_capacity;
extern lv_obj_t * ui_FLASH_Label;
extern lv_obj_t * ui_SystemScreen;
extern lv_obj_t * ui_ShutdownButton;
extern lv_obj_t * ui_Shut_down_Label;
extern lv_obj_t * ui_SRDropdown;
extern lv_obj_t * ui_SRLabel;



void ui_init(void);
void ui_table_data_change(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
