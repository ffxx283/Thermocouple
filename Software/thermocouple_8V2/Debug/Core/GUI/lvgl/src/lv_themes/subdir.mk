################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/lv_themes/lv_theme.c \
../Core/GUI/lvgl/src/lv_themes/lv_theme_empty.c \
../Core/GUI/lvgl/src/lv_themes/lv_theme_material.c \
../Core/GUI/lvgl/src/lv_themes/lv_theme_mono.c \
../Core/GUI/lvgl/src/lv_themes/lv_theme_template.c 

OBJS += \
./Core/GUI/lvgl/src/lv_themes/lv_theme.o \
./Core/GUI/lvgl/src/lv_themes/lv_theme_empty.o \
./Core/GUI/lvgl/src/lv_themes/lv_theme_material.o \
./Core/GUI/lvgl/src/lv_themes/lv_theme_mono.o \
./Core/GUI/lvgl/src/lv_themes/lv_theme_template.o 

C_DEPS += \
./Core/GUI/lvgl/src/lv_themes/lv_theme.d \
./Core/GUI/lvgl/src/lv_themes/lv_theme_empty.d \
./Core/GUI/lvgl/src/lv_themes/lv_theme_material.d \
./Core/GUI/lvgl/src/lv_themes/lv_theme_mono.d \
./Core/GUI/lvgl/src/lv_themes/lv_theme_template.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/lv_themes/%.o Core/GUI/lvgl/src/lv_themes/%.su: ../Core/GUI/lvgl/src/lv_themes/%.c Core/GUI/lvgl/src/lv_themes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_themes

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_themes:
	-$(RM) ./Core/GUI/lvgl/src/lv_themes/lv_theme.d ./Core/GUI/lvgl/src/lv_themes/lv_theme.o ./Core/GUI/lvgl/src/lv_themes/lv_theme.su ./Core/GUI/lvgl/src/lv_themes/lv_theme_empty.d ./Core/GUI/lvgl/src/lv_themes/lv_theme_empty.o ./Core/GUI/lvgl/src/lv_themes/lv_theme_empty.su ./Core/GUI/lvgl/src/lv_themes/lv_theme_material.d ./Core/GUI/lvgl/src/lv_themes/lv_theme_material.o ./Core/GUI/lvgl/src/lv_themes/lv_theme_material.su ./Core/GUI/lvgl/src/lv_themes/lv_theme_mono.d ./Core/GUI/lvgl/src/lv_themes/lv_theme_mono.o ./Core/GUI/lvgl/src/lv_themes/lv_theme_mono.su ./Core/GUI/lvgl/src/lv_themes/lv_theme_template.d ./Core/GUI/lvgl/src/lv_themes/lv_theme_template.o ./Core/GUI/lvgl/src/lv_themes/lv_theme_template.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_themes

