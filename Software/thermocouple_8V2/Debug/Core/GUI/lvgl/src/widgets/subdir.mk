################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/widgets/lv_arc.c \
../Core/GUI/lvgl/src/widgets/lv_bar.c \
../Core/GUI/lvgl/src/widgets/lv_btn.c \
../Core/GUI/lvgl/src/widgets/lv_btnmatrix.c \
../Core/GUI/lvgl/src/widgets/lv_canvas.c \
../Core/GUI/lvgl/src/widgets/lv_checkbox.c \
../Core/GUI/lvgl/src/widgets/lv_dropdown.c \
../Core/GUI/lvgl/src/widgets/lv_img.c \
../Core/GUI/lvgl/src/widgets/lv_label.c \
../Core/GUI/lvgl/src/widgets/lv_line.c \
../Core/GUI/lvgl/src/widgets/lv_objx_templ.c \
../Core/GUI/lvgl/src/widgets/lv_roller.c \
../Core/GUI/lvgl/src/widgets/lv_slider.c \
../Core/GUI/lvgl/src/widgets/lv_switch.c \
../Core/GUI/lvgl/src/widgets/lv_table.c \
../Core/GUI/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./Core/GUI/lvgl/src/widgets/lv_arc.o \
./Core/GUI/lvgl/src/widgets/lv_bar.o \
./Core/GUI/lvgl/src/widgets/lv_btn.o \
./Core/GUI/lvgl/src/widgets/lv_btnmatrix.o \
./Core/GUI/lvgl/src/widgets/lv_canvas.o \
./Core/GUI/lvgl/src/widgets/lv_checkbox.o \
./Core/GUI/lvgl/src/widgets/lv_dropdown.o \
./Core/GUI/lvgl/src/widgets/lv_img.o \
./Core/GUI/lvgl/src/widgets/lv_label.o \
./Core/GUI/lvgl/src/widgets/lv_line.o \
./Core/GUI/lvgl/src/widgets/lv_objx_templ.o \
./Core/GUI/lvgl/src/widgets/lv_roller.o \
./Core/GUI/lvgl/src/widgets/lv_slider.o \
./Core/GUI/lvgl/src/widgets/lv_switch.o \
./Core/GUI/lvgl/src/widgets/lv_table.o \
./Core/GUI/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./Core/GUI/lvgl/src/widgets/lv_arc.d \
./Core/GUI/lvgl/src/widgets/lv_bar.d \
./Core/GUI/lvgl/src/widgets/lv_btn.d \
./Core/GUI/lvgl/src/widgets/lv_btnmatrix.d \
./Core/GUI/lvgl/src/widgets/lv_canvas.d \
./Core/GUI/lvgl/src/widgets/lv_checkbox.d \
./Core/GUI/lvgl/src/widgets/lv_dropdown.d \
./Core/GUI/lvgl/src/widgets/lv_img.d \
./Core/GUI/lvgl/src/widgets/lv_label.d \
./Core/GUI/lvgl/src/widgets/lv_line.d \
./Core/GUI/lvgl/src/widgets/lv_objx_templ.d \
./Core/GUI/lvgl/src/widgets/lv_roller.d \
./Core/GUI/lvgl/src/widgets/lv_slider.d \
./Core/GUI/lvgl/src/widgets/lv_switch.d \
./Core/GUI/lvgl/src/widgets/lv_table.d \
./Core/GUI/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/widgets/%.o Core/GUI/lvgl/src/widgets/%.su: ../Core/GUI/lvgl/src/widgets/%.c Core/GUI/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-widgets

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./Core/GUI/lvgl/src/widgets/lv_arc.d ./Core/GUI/lvgl/src/widgets/lv_arc.o ./Core/GUI/lvgl/src/widgets/lv_arc.su ./Core/GUI/lvgl/src/widgets/lv_bar.d ./Core/GUI/lvgl/src/widgets/lv_bar.o ./Core/GUI/lvgl/src/widgets/lv_bar.su ./Core/GUI/lvgl/src/widgets/lv_btn.d ./Core/GUI/lvgl/src/widgets/lv_btn.o ./Core/GUI/lvgl/src/widgets/lv_btn.su ./Core/GUI/lvgl/src/widgets/lv_btnmatrix.d ./Core/GUI/lvgl/src/widgets/lv_btnmatrix.o ./Core/GUI/lvgl/src/widgets/lv_btnmatrix.su ./Core/GUI/lvgl/src/widgets/lv_canvas.d ./Core/GUI/lvgl/src/widgets/lv_canvas.o ./Core/GUI/lvgl/src/widgets/lv_canvas.su ./Core/GUI/lvgl/src/widgets/lv_checkbox.d ./Core/GUI/lvgl/src/widgets/lv_checkbox.o ./Core/GUI/lvgl/src/widgets/lv_checkbox.su ./Core/GUI/lvgl/src/widgets/lv_dropdown.d ./Core/GUI/lvgl/src/widgets/lv_dropdown.o ./Core/GUI/lvgl/src/widgets/lv_dropdown.su ./Core/GUI/lvgl/src/widgets/lv_img.d ./Core/GUI/lvgl/src/widgets/lv_img.o ./Core/GUI/lvgl/src/widgets/lv_img.su ./Core/GUI/lvgl/src/widgets/lv_label.d ./Core/GUI/lvgl/src/widgets/lv_label.o ./Core/GUI/lvgl/src/widgets/lv_label.su ./Core/GUI/lvgl/src/widgets/lv_line.d ./Core/GUI/lvgl/src/widgets/lv_line.o ./Core/GUI/lvgl/src/widgets/lv_line.su ./Core/GUI/lvgl/src/widgets/lv_objx_templ.d ./Core/GUI/lvgl/src/widgets/lv_objx_templ.o ./Core/GUI/lvgl/src/widgets/lv_objx_templ.su ./Core/GUI/lvgl/src/widgets/lv_roller.d ./Core/GUI/lvgl/src/widgets/lv_roller.o ./Core/GUI/lvgl/src/widgets/lv_roller.su ./Core/GUI/lvgl/src/widgets/lv_slider.d ./Core/GUI/lvgl/src/widgets/lv_slider.o ./Core/GUI/lvgl/src/widgets/lv_slider.su ./Core/GUI/lvgl/src/widgets/lv_switch.d ./Core/GUI/lvgl/src/widgets/lv_switch.o ./Core/GUI/lvgl/src/widgets/lv_switch.su ./Core/GUI/lvgl/src/widgets/lv_table.d ./Core/GUI/lvgl/src/widgets/lv_table.o ./Core/GUI/lvgl/src/widgets/lv_table.su ./Core/GUI/lvgl/src/widgets/lv_textarea.d ./Core/GUI/lvgl/src/widgets/lv_textarea.o ./Core/GUI/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-widgets

