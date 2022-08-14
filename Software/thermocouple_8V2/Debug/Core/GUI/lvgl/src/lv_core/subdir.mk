################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/lv_core/lv_disp.c \
../Core/GUI/lvgl/src/lv_core/lv_group.c \
../Core/GUI/lvgl/src/lv_core/lv_indev.c \
../Core/GUI/lvgl/src/lv_core/lv_obj.c \
../Core/GUI/lvgl/src/lv_core/lv_refr.c \
../Core/GUI/lvgl/src/lv_core/lv_style.c 

OBJS += \
./Core/GUI/lvgl/src/lv_core/lv_disp.o \
./Core/GUI/lvgl/src/lv_core/lv_group.o \
./Core/GUI/lvgl/src/lv_core/lv_indev.o \
./Core/GUI/lvgl/src/lv_core/lv_obj.o \
./Core/GUI/lvgl/src/lv_core/lv_refr.o \
./Core/GUI/lvgl/src/lv_core/lv_style.o 

C_DEPS += \
./Core/GUI/lvgl/src/lv_core/lv_disp.d \
./Core/GUI/lvgl/src/lv_core/lv_group.d \
./Core/GUI/lvgl/src/lv_core/lv_indev.d \
./Core/GUI/lvgl/src/lv_core/lv_obj.d \
./Core/GUI/lvgl/src/lv_core/lv_refr.d \
./Core/GUI/lvgl/src/lv_core/lv_style.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/lv_core/%.o Core/GUI/lvgl/src/lv_core/%.su: ../Core/GUI/lvgl/src/lv_core/%.c Core/GUI/lvgl/src/lv_core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_core

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_core:
	-$(RM) ./Core/GUI/lvgl/src/lv_core/lv_disp.d ./Core/GUI/lvgl/src/lv_core/lv_disp.o ./Core/GUI/lvgl/src/lv_core/lv_disp.su ./Core/GUI/lvgl/src/lv_core/lv_group.d ./Core/GUI/lvgl/src/lv_core/lv_group.o ./Core/GUI/lvgl/src/lv_core/lv_group.su ./Core/GUI/lvgl/src/lv_core/lv_indev.d ./Core/GUI/lvgl/src/lv_core/lv_indev.o ./Core/GUI/lvgl/src/lv_core/lv_indev.su ./Core/GUI/lvgl/src/lv_core/lv_obj.d ./Core/GUI/lvgl/src/lv_core/lv_obj.o ./Core/GUI/lvgl/src/lv_core/lv_obj.su ./Core/GUI/lvgl/src/lv_core/lv_refr.d ./Core/GUI/lvgl/src/lv_core/lv_refr.o ./Core/GUI/lvgl/src/lv_core/lv_refr.su ./Core/GUI/lvgl/src/lv_core/lv_style.d ./Core/GUI/lvgl/src/lv_core/lv_style.o ./Core/GUI/lvgl/src/lv_core/lv_style.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_core

