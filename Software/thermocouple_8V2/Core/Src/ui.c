// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_MainScreen;
lv_obj_t * ui_PowerBar1;
lv_obj_t * ui_TemperatureButton;
lv_obj_t * ui_Temperature_Label;
lv_obj_t * ui_FileButton;
lv_obj_t * ui_FILE_Label;
lv_obj_t * ui_SystemButton;
lv_obj_t * ui_SYSTEM_Label;
lv_obj_t * ui_SDCardOkbox1;
lv_obj_t * ui_TemperatureScreen;
lv_obj_t * ui_SDCardOkbox2;
lv_obj_t * ui_PowerBar2;
lv_obj_t * ui_table;
lv_obj_t * ui_FileScreen;
lv_obj_t * ui_FLASH_capacity;
lv_obj_t * ui_Send_Data_to_UART;
lv_obj_t * ui_Send_Data_to_UART_Label;
lv_obj_t * ui_FLASH_Bar;
lv_obj_t * ui_SD_Label;
lv_obj_t * ui_SD_Bar;
lv_obj_t * ui_SD_capacity;
lv_obj_t * ui_FLASH_Label;
lv_obj_t * ui_SystemScreen;
lv_obj_t * ui_ShutdownButton;
lv_obj_t * ui_Shut_down_Label;
lv_obj_t* ui_SRLabel;
lv_obj_t* ui_SR_Roller;

lv_group_t* Key_group;

//extern lv_indev_t* lv_win32_keypad_device_object;
extern lv_indev_t * indev_keypad;

void ui_group_change_to_main(void);
void ui_group_change_to_temperature(void);
void ui_group_change_to_file(void);
void ui_group_change_to_system(void);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_TemperatureButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    //printf("ui_event_TemperatureButton event:%d\r\n", event);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_TemperatureScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_temperature();
    }
}
static void ui_event_FileButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_FileScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_file();
    }
}
static void ui_event_SystemButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SystemScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_system();        
    }
}

static void ui_event_Send_Data_to_UART(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CANCEL) {
        _ui_screen_change(ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_main();
    }
}

static void ui_event_ShutdownButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CANCEL) {
        _ui_screen_change(ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_main();
    }
}

static void ui_event_SR_Roller(lv_event_t* e)
{
    uint16_t roller_selected = 0;
    lv_event_code_t event = lv_event_get_code(e);
    //printf("ui_event_SR_Roller:%d\r\n", event);
    if (event == LV_EVENT_CANCEL) {
        _ui_screen_change(ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_main();
    }
    else if (event == LV_EVENT_CLICKED){
        roller_selected = lv_roller_get_selected(ui_SR_Roller);
        //printf("roller_selected:%d\r\n", roller_selected);
        roller_selected++;
        if (roller_selected >= 4)
        {
            roller_selected = 0;
        }
        lv_roller_set_selected(ui_SR_Roller, roller_selected, LV_ANIM_OFF);
        TIM1_Start_Working(roller_selected+1);
    }
}


static void draw_part_event_cb(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t* dsc = lv_event_get_draw_part_dsc(e);
    /*If the cells are drawn...*/
    if (dsc->part == LV_PART_ITEMS) {
        uint32_t row = dsc->id / lv_table_get_col_cnt(obj);

        dsc->label_dsc->color = lv_color_hex(0x010101);
        dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;

        /*Make the texts in the first cell center aligned*/
        if (row == 0) {
            dsc->rect_dsc->bg_color = lv_color_hex(0xC1E71D);
        }
        /*MAke every 2nd row grayish*/
        if ((row != 0 && row % 2) == 0) {
            dsc->rect_dsc->bg_color = lv_color_hex(0xbcc3c2);
        }
    }
}


static void ui_event_table(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);
    /*If the cells are drawn...*/
    //printf("event:%d\r\n", event);
    if (event == LV_EVENT_CANCEL) {
        //printf("LV_EVENT_CANCEL\r\n");
        _ui_screen_change(ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0);
        ui_group_change_to_main();
    }
    else if (event == LV_EVENT_CLICKED) {
        //printf("LV_EVENT_CLICKED,%d\r\n", lv_obj_get_scroll_bottom(ui_table));
        if( 0 < lv_obj_get_scroll_bottom(ui_table))
            lv_obj_scroll_by(ui_table, 0, -45, LV_ANIM_ON);
        else
            lv_obj_scroll_by(ui_table, 0, 45, LV_ANIM_ON);
    }
}


///////////////////// SCREENS ////////////////////
void ui_MainScreen_screen_init(void)
{

    // ui_MainScreen

    ui_MainScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_MainScreen, lv_color_hex(0x090909), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MainScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PowerBar1

    ui_PowerBar1 = lv_bar_create(ui_MainScreen);
    lv_bar_set_range(ui_PowerBar1, 0, 100);
    lv_bar_set_value(ui_PowerBar1, 86, LV_ANIM_OFF);

    lv_obj_set_width(ui_PowerBar1, 25);
    lv_obj_set_height(ui_PowerBar1, 10);

    lv_obj_set_x(ui_PowerBar1, 101);
    lv_obj_set_y(ui_PowerBar1, 2);

    lv_obj_set_style_bg_color(ui_PowerBar1, lv_color_hex(0xDBE3DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PowerBar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PowerBar1, lv_color_hex(0xF0F0F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PowerBar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PowerBar1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_PowerBar1, lv_color_hex(0x2CE04A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PowerBar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PowerBar1, lv_color_hex(0xEEEEEE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PowerBar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PowerBar1, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_TemperatureButton

    ui_TemperatureButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_TemperatureButton, 80);
    lv_obj_set_height(ui_TemperatureButton, 20);

    lv_obj_set_x(ui_TemperatureButton, 24);
    lv_obj_set_y(ui_TemperatureButton, 20);

    lv_obj_add_flag(ui_TemperatureButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_TemperatureButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_TemperatureButton, ui_event_TemperatureButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_TemperatureButton, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TemperatureButton, lv_color_hex(0x33BF7A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TemperatureButton, lv_color_hex(0xC1E71D), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_TemperatureButton, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_Temperature_Label

    ui_Temperature_Label = lv_label_create(ui_TemperatureButton);

    lv_obj_set_width(ui_Temperature_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Temperature_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Temperature_Label, 0);
    lv_obj_set_y(ui_Temperature_Label, 0);

    lv_obj_set_align(ui_Temperature_Label, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Temperature_Label, "Temperature");

    lv_obj_clear_flag(ui_Temperature_Label,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_Temperature_Label, lv_color_hex(0x111210), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Temperature_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Temperature_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FileButton

    ui_FileButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_FileButton, 80);
    lv_obj_set_height(ui_FileButton, 20);

    lv_obj_set_x(ui_FileButton, 24);
    lv_obj_set_y(ui_FileButton, 55);

    lv_obj_add_flag(ui_FileButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_FileButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_FileButton, ui_event_FileButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_FileButton, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileButton, lv_color_hex(0x33BF7A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FileButton, lv_color_hex(0xC1E71D), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_FileButton, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_FILE_Label

    ui_FILE_Label = lv_label_create(ui_FileButton);

    lv_obj_set_width(ui_FILE_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FILE_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FILE_Label, 0);
    lv_obj_set_y(ui_FILE_Label, 0);

    lv_obj_set_align(ui_FILE_Label, LV_ALIGN_CENTER);

    lv_label_set_text(ui_FILE_Label, "FILE");

    lv_obj_clear_flag(ui_FILE_Label, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_FILE_Label, lv_color_hex(0x111210), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FILE_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FILE_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SystemButton

    ui_SystemButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_SystemButton, 80);
    lv_obj_set_height(ui_SystemButton, 20);

    lv_obj_set_x(ui_SystemButton, 24);
    lv_obj_set_y(ui_SystemButton, 90);

    lv_obj_add_flag(ui_SystemButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SystemButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SystemButton, ui_event_SystemButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_SystemButton, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemButton, lv_color_hex(0x33BF7A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SystemButton, lv_color_hex(0xC1E71D), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_SystemButton, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_SYSTEM_Label

    ui_SYSTEM_Label = lv_label_create(ui_SystemButton);

    lv_obj_set_width(ui_SYSTEM_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SYSTEM_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SYSTEM_Label, 0);
    lv_obj_set_y(ui_SYSTEM_Label, 0);

    lv_obj_set_align(ui_SYSTEM_Label, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SYSTEM_Label, "SYSTEM");

    lv_obj_clear_flag(ui_SYSTEM_Label, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_SYSTEM_Label, lv_color_hex(0x111210), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SYSTEM_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SYSTEM_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SDCardOkbox1

    ui_SDCardOkbox1 = lv_checkbox_create(ui_MainScreen);
    lv_checkbox_set_text(ui_SDCardOkbox1, " SD");

    lv_obj_set_width(ui_SDCardOkbox1, 40);
    lv_obj_set_height(ui_SDCardOkbox1, 10);

    lv_obj_set_x(ui_SDCardOkbox1, 1);
    lv_obj_set_y(ui_SDCardOkbox1, 1);

    lv_obj_add_flag(ui_SDCardOkbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_font(ui_SDCardOkbox1, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_SDCardOkbox1, lv_color_hex(0x54DB1C), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_SDCardOkbox1, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(ui_SDCardOkbox1, lv_color_hex(0x555655), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SDCardOkbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SDCardOkbox1, lv_color_hex(0x53D41E), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SDCardOkbox1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

}
void ui_TemperatureScreen_screen_init(void)
{

    // ui_TemperatureScreen

    ui_TemperatureScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_TemperatureScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_TemperatureScreen, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SDCardOkbox2

    ui_SDCardOkbox2 = lv_checkbox_create(ui_TemperatureScreen);
    lv_checkbox_set_text(ui_SDCardOkbox2, " SD");

    lv_obj_set_width(ui_SDCardOkbox2, 40);
    lv_obj_set_height(ui_SDCardOkbox2, 10);

    lv_obj_set_x(ui_SDCardOkbox2, 1);
    lv_obj_set_y(ui_SDCardOkbox2, 1);

    lv_obj_add_flag(ui_SDCardOkbox2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_set_style_text_font(ui_SDCardOkbox2, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_SDCardOkbox2, lv_color_hex(0x54DB1C), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_SDCardOkbox2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(ui_SDCardOkbox2, lv_color_hex(0x555655), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SDCardOkbox2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SDCardOkbox2, lv_color_hex(0x53D41E), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SDCardOkbox2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // ui_PowerBar2

    ui_PowerBar2 = lv_bar_create(ui_TemperatureScreen);
    lv_bar_set_range(ui_PowerBar2, 0, 100);
    lv_bar_set_value(ui_PowerBar2, 86, LV_ANIM_OFF);

    lv_obj_set_width(ui_PowerBar2, 25);
    lv_obj_set_height(ui_PowerBar2, 10);

    lv_obj_set_x(ui_PowerBar2, 101);
    lv_obj_set_y(ui_PowerBar2, 2);

    lv_obj_set_style_bg_color(ui_PowerBar2, lv_color_hex(0xDBE3DD), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PowerBar2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PowerBar2, lv_color_hex(0xF0F0F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PowerBar2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PowerBar2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_PowerBar2, lv_color_hex(0x2CE04A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PowerBar2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PowerBar2, lv_color_hex(0xEEEEEE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PowerBar2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PowerBar2, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);


    // ui_Table

    ui_table = lv_table_create(ui_TemperatureScreen);

    /*Fill the first column*/
    lv_table_set_cell_value(ui_table, 0, 0, "Channel");
    lv_table_set_cell_value(ui_table, 0, 1, "Temp");
    uint32_t i;
    for (i = 1; i < 13; i++) {
        lv_table_set_cell_value_fmt(ui_table, i, 0, "CH %"LV_PRIu32, i);
        lv_table_set_cell_value_fmt(ui_table, i, 1, "%"LV_PRIu32, i);
    }

    /*Set a smaller height to the ui_table. It'll make it scrollable*/
    lv_obj_set_size(ui_table, LV_SIZE_CONTENT, 100);
    lv_table_set_col_width(ui_table, 0, 55);
    lv_table_set_col_width(ui_table, 1, 55);
    lv_obj_set_x(ui_table, 10);
    lv_obj_set_y(ui_table, 20);

    lv_obj_set_style_text_font(ui_table, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_table, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_table, ui_event_table, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_table, draw_part_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);


//    // ui_Panel1
//
//    ui_Panel1 = lv_obj_create(ui_TemperatureScreen);
//
//    lv_obj_set_width(ui_Panel1, 100);
//    lv_obj_set_height(ui_Panel1, 100);
//
//    lv_obj_set_x(ui_Panel1, 14);
//    lv_obj_set_y(ui_Panel1, 20);
//
//    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);
//
//    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x2A6A44), LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_FileScreen_screen_init(void)
{

    // ui_FileScreen

    ui_FileScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_FileScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_FileScreen, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FileScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FLASH_capacity

    ui_FLASH_capacity = lv_label_create(ui_FileScreen);

    lv_obj_set_width(ui_FLASH_capacity, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FLASH_capacity, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FLASH_capacity, 19);
    lv_obj_set_y(ui_FLASH_capacity, 40);

    lv_label_set_text(ui_FLASH_capacity, "2MB/64MB : 20%");

    lv_obj_set_style_text_font(ui_FLASH_capacity, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Send_Data_to_UART

    ui_Send_Data_to_UART = lv_btn_create(ui_FileScreen);

    lv_obj_set_width(ui_Send_Data_to_UART, 88);
    lv_obj_set_height(ui_Send_Data_to_UART, 19);

    lv_obj_set_x(ui_Send_Data_to_UART, 20);
    lv_obj_set_y(ui_Send_Data_to_UART, 55);

    lv_obj_add_flag(ui_Send_Data_to_UART, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Send_Data_to_UART, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Send_Data_to_UART, ui_event_Send_Data_to_UART, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_Send_Data_to_UART, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Send_Data_to_UART, lv_color_hex(0x33BF7A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Send_Data_to_UART, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Send_Data_to_UART, lv_color_hex(0xC1E71D), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_Send_Data_to_UART, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_Send_Data_to_UART_Label

    ui_Send_Data_to_UART_Label = lv_label_create(ui_Send_Data_to_UART);

    lv_obj_set_width(ui_Send_Data_to_UART_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Send_Data_to_UART_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Send_Data_to_UART_Label, 0);
    lv_obj_set_y(ui_Send_Data_to_UART_Label, 0);

    lv_obj_set_align(ui_Send_Data_to_UART_Label, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Send_Data_to_UART_Label, "Send to UART");

    lv_obj_clear_flag(ui_Send_Data_to_UART_Label,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_Send_Data_to_UART_Label, lv_color_hex(0x111210), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Send_Data_to_UART_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Send_Data_to_UART_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FLASH_Bar

    ui_FLASH_Bar = lv_bar_create(ui_FileScreen);
    lv_bar_set_range(ui_FLASH_Bar, 0, 100);
    lv_bar_set_value(ui_FLASH_Bar, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_FLASH_Bar, 100);
    lv_obj_set_height(ui_FLASH_Bar, 10);

    lv_obj_set_x(ui_FLASH_Bar, 14);
    lv_obj_set_y(ui_FLASH_Bar, 25);

    lv_obj_set_style_bg_color(ui_FLASH_Bar, lv_color_hex(0x161515), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FLASH_Bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_FLASH_Bar, lv_color_hex(0xFEFEFE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_FLASH_Bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_FLASH_Bar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_FLASH_Bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_FLASH_Bar, lv_color_hex(0x1E7432), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FLASH_Bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_FLASH_Bar, lv_color_hex(0xFCFCFC), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_FLASH_Bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_FLASH_Bar, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_FLASH_Bar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_SD_Label

    ui_SD_Label = lv_label_create(ui_FileScreen);

    lv_obj_set_width(ui_SD_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SD_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SD_Label, 5);
    lv_obj_set_y(ui_SD_Label, 82);

    lv_label_set_text(ui_SD_Label, "SD :");

    lv_obj_set_style_text_color(ui_SD_Label, lv_color_hex(0xD6EC1F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SD_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SD_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SD_Bar

    ui_SD_Bar = lv_bar_create(ui_FileScreen);
    lv_bar_set_range(ui_SD_Bar, 0, 100);
    lv_bar_set_value(ui_SD_Bar, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_SD_Bar, 100);
    lv_obj_set_height(ui_SD_Bar, 10);

    lv_obj_set_x(ui_SD_Bar, 14);
    lv_obj_set_y(ui_SD_Bar, 96);

    lv_obj_set_style_bg_color(ui_SD_Bar, lv_color_hex(0x161515), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SD_Bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_SD_Bar, lv_color_hex(0xFEFEFE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_SD_Bar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_SD_Bar, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SD_Bar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SD_Bar, lv_color_hex(0x1E7432), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SD_Bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_SD_Bar, lv_color_hex(0xFCFCFC), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_SD_Bar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_SD_Bar, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SD_Bar, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_SD_capacity

    ui_SD_capacity = lv_label_create(ui_FileScreen);

    lv_obj_set_width(ui_SD_capacity, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SD_capacity, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SD_capacity, 19);
    lv_obj_set_y(ui_SD_capacity, 111);

    lv_label_set_text(ui_SD_capacity, "2MB/64MB : 20%");

    lv_obj_set_style_text_font(ui_SD_capacity, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_FLASH_Label

    ui_FLASH_Label = lv_label_create(ui_FileScreen);

    lv_obj_set_width(ui_FLASH_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FLASH_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FLASH_Label, 5);
    lv_obj_set_y(ui_FLASH_Label, 10);

    lv_label_set_text(ui_FLASH_Label, "FLASH :");

    lv_obj_set_style_text_color(ui_FLASH_Label, lv_color_hex(0xD6EC1F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_FLASH_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_FLASH_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_SystemScreen_screen_init(void)
{

    // ui_SystemScreen

    ui_SystemScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_SystemScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_SystemScreen, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SystemScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ShutdownButton

    ui_ShutdownButton = lv_btn_create(ui_SystemScreen);

    lv_obj_set_width(ui_ShutdownButton, 88);
    lv_obj_set_height(ui_ShutdownButton, 19);

    lv_obj_set_x(ui_ShutdownButton, 20);
    lv_obj_set_y(ui_ShutdownButton, 65);

    lv_obj_add_flag(ui_ShutdownButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ShutdownButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ShutdownButton, ui_event_ShutdownButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_ShutdownButton, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ShutdownButton, lv_color_hex(0x33BF7A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ShutdownButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ShutdownButton, lv_color_hex(0xC1E71D), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_ShutdownButton, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    // ui_Shut_down_Label

    ui_Shut_down_Label = lv_label_create(ui_ShutdownButton);

    lv_obj_set_width(ui_Shut_down_Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Shut_down_Label, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Shut_down_Label, 0);
    lv_obj_set_y(ui_Shut_down_Label, 0);

    lv_obj_set_align(ui_Shut_down_Label, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Shut_down_Label, "Shut down");

    lv_obj_clear_flag(ui_Shut_down_Label,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_Shut_down_Label, lv_color_hex(0x111210), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Shut_down_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Shut_down_Label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);


    // ui_SRLabel

    ui_SRLabel = lv_label_create(ui_SystemScreen);

    lv_obj_set_width(ui_SRLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SRLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SRLabel, 7);
    lv_obj_set_y(ui_SRLabel, 11);

    lv_label_set_text(ui_SRLabel, "Sample Rate :");

    lv_obj_set_style_text_color(ui_SRLabel, lv_color_hex(0xD6EC1F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SRLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SRLabel, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SR_Roller

    ui_SR_Roller = lv_roller_create(ui_SystemScreen);
    lv_roller_set_options(ui_SR_Roller, "1s\n2s\n5s\n10s", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_width(ui_SR_Roller, 50);
    lv_obj_set_height(ui_SR_Roller, 20);

    lv_obj_set_x(ui_SR_Roller, 37);
    lv_obj_set_y(ui_SR_Roller, 31);

    lv_obj_add_event_cb(ui_SR_Roller, ui_event_SR_Roller, LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_color(ui_SR_Roller, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SR_Roller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SR_Roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SR_Roller, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SR_Roller, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SR_Roller, lv_color_hex(0x95A095), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SR_Roller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_SR_Roller, lv_color_hex(0x000000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SR_Roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SR_Roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SR_Roller, &lv_font_montserrat_10, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SR_Roller, lv_color_hex(0x4D9748), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SR_Roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SR_Roller, lv_color_hex(0xADD232), LV_PART_SELECTED | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_opa(ui_SR_Roller, 255, LV_PART_SELECTED | LV_STATE_FOCUSED);


}

void ui_group_main_screen_init(void)
{
    Key_group = lv_group_create();
    lv_indev_set_group(indev_keypad, Key_group);

    lv_group_add_obj(Key_group, ui_TemperatureButton);
    lv_group_add_obj(Key_group, ui_FileButton);
    lv_group_add_obj(Key_group, ui_SystemButton);

    lv_group_set_editing(Key_group, false);
}


void ui_group_change_to_main(void)
{
    lv_group_remove_all_objs(Key_group);
    lv_group_add_obj(Key_group, ui_TemperatureButton);
    lv_group_add_obj(Key_group, ui_FileButton);
    lv_group_add_obj(Key_group, ui_SystemButton);
    lv_group_set_editing(Key_group, false);
}

void ui_group_change_to_temperature(void)
{
    lv_group_remove_all_objs(Key_group);
    lv_group_add_obj(Key_group, ui_table);
    lv_group_set_editing(Key_group, false);
}

void ui_group_change_to_file(void)
{
    lv_group_remove_all_objs(Key_group);
    lv_group_add_obj(Key_group, ui_Send_Data_to_UART);
    lv_group_set_editing(Key_group, false);
}

void ui_group_change_to_system(void)
{
    lv_group_remove_all_objs(Key_group);
    lv_group_add_obj(Key_group, ui_SR_Roller);
    lv_group_add_obj(Key_group, ui_ShutdownButton);
    lv_group_set_editing(Key_group, false);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    ui_TemperatureScreen_screen_init();
    ui_FileScreen_screen_init();
    ui_SystemScreen_screen_init();
    lv_disp_load_scr(ui_MainScreen);

    ui_group_main_screen_init();

}


void ui_table_data_change(void)
{
    uint32_t i;
    static uint8_t temp = 1;
	temp += 1;
	for (i = 1; i < 13; i++) {
		lv_table_set_cell_value_fmt(ui_table, i, 1, "%3d", temp + i);
	}
}

