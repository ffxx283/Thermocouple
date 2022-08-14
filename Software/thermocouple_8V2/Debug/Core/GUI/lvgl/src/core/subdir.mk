################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/core/lv_disp.c \
../Core/GUI/lvgl/src/core/lv_event.c \
../Core/GUI/lvgl/src/core/lv_group.c \
../Core/GUI/lvgl/src/core/lv_indev.c \
../Core/GUI/lvgl/src/core/lv_indev_scroll.c \
../Core/GUI/lvgl/src/core/lv_obj.c \
../Core/GUI/lvgl/src/core/lv_obj_class.c \
../Core/GUI/lvgl/src/core/lv_obj_draw.c \
../Core/GUI/lvgl/src/core/lv_obj_pos.c \
../Core/GUI/lvgl/src/core/lv_obj_scroll.c \
../Core/GUI/lvgl/src/core/lv_obj_style.c \
../Core/GUI/lvgl/src/core/lv_obj_style_gen.c \
../Core/GUI/lvgl/src/core/lv_obj_tree.c \
../Core/GUI/lvgl/src/core/lv_refr.c \
../Core/GUI/lvgl/src/core/lv_theme.c 

OBJS += \
./Core/GUI/lvgl/src/core/lv_disp.o \
./Core/GUI/lvgl/src/core/lv_event.o \
./Core/GUI/lvgl/src/core/lv_group.o \
./Core/GUI/lvgl/src/core/lv_indev.o \
./Core/GUI/lvgl/src/core/lv_indev_scroll.o \
./Core/GUI/lvgl/src/core/lv_obj.o \
./Core/GUI/lvgl/src/core/lv_obj_class.o \
./Core/GUI/lvgl/src/core/lv_obj_draw.o \
./Core/GUI/lvgl/src/core/lv_obj_pos.o \
./Core/GUI/lvgl/src/core/lv_obj_scroll.o \
./Core/GUI/lvgl/src/core/lv_obj_style.o \
./Core/GUI/lvgl/src/core/lv_obj_style_gen.o \
./Core/GUI/lvgl/src/core/lv_obj_tree.o \
./Core/GUI/lvgl/src/core/lv_refr.o \
./Core/GUI/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Core/GUI/lvgl/src/core/lv_disp.d \
./Core/GUI/lvgl/src/core/lv_event.d \
./Core/GUI/lvgl/src/core/lv_group.d \
./Core/GUI/lvgl/src/core/lv_indev.d \
./Core/GUI/lvgl/src/core/lv_indev_scroll.d \
./Core/GUI/lvgl/src/core/lv_obj.d \
./Core/GUI/lvgl/src/core/lv_obj_class.d \
./Core/GUI/lvgl/src/core/lv_obj_draw.d \
./Core/GUI/lvgl/src/core/lv_obj_pos.d \
./Core/GUI/lvgl/src/core/lv_obj_scroll.d \
./Core/GUI/lvgl/src/core/lv_obj_style.d \
./Core/GUI/lvgl/src/core/lv_obj_style_gen.d \
./Core/GUI/lvgl/src/core/lv_obj_tree.d \
./Core/GUI/lvgl/src/core/lv_refr.d \
./Core/GUI/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/core/%.o Core/GUI/lvgl/src/core/%.su: ../Core/GUI/lvgl/src/core/%.c Core/GUI/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-core

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Core/GUI/lvgl/src/core/lv_disp.d ./Core/GUI/lvgl/src/core/lv_disp.o ./Core/GUI/lvgl/src/core/lv_disp.su ./Core/GUI/lvgl/src/core/lv_event.d ./Core/GUI/lvgl/src/core/lv_event.o ./Core/GUI/lvgl/src/core/lv_event.su ./Core/GUI/lvgl/src/core/lv_group.d ./Core/GUI/lvgl/src/core/lv_group.o ./Core/GUI/lvgl/src/core/lv_group.su ./Core/GUI/lvgl/src/core/lv_indev.d ./Core/GUI/lvgl/src/core/lv_indev.o ./Core/GUI/lvgl/src/core/lv_indev.su ./Core/GUI/lvgl/src/core/lv_indev_scroll.d ./Core/GUI/lvgl/src/core/lv_indev_scroll.o ./Core/GUI/lvgl/src/core/lv_indev_scroll.su ./Core/GUI/lvgl/src/core/lv_obj.d ./Core/GUI/lvgl/src/core/lv_obj.o ./Core/GUI/lvgl/src/core/lv_obj.su ./Core/GUI/lvgl/src/core/lv_obj_class.d ./Core/GUI/lvgl/src/core/lv_obj_class.o ./Core/GUI/lvgl/src/core/lv_obj_class.su ./Core/GUI/lvgl/src/core/lv_obj_draw.d ./Core/GUI/lvgl/src/core/lv_obj_draw.o ./Core/GUI/lvgl/src/core/lv_obj_draw.su ./Core/GUI/lvgl/src/core/lv_obj_pos.d ./Core/GUI/lvgl/src/core/lv_obj_pos.o ./Core/GUI/lvgl/src/core/lv_obj_pos.su ./Core/GUI/lvgl/src/core/lv_obj_scroll.d ./Core/GUI/lvgl/src/core/lv_obj_scroll.o ./Core/GUI/lvgl/src/core/lv_obj_scroll.su ./Core/GUI/lvgl/src/core/lv_obj_style.d ./Core/GUI/lvgl/src/core/lv_obj_style.o ./Core/GUI/lvgl/src/core/lv_obj_style.su ./Core/GUI/lvgl/src/core/lv_obj_style_gen.d ./Core/GUI/lvgl/src/core/lv_obj_style_gen.o ./Core/GUI/lvgl/src/core/lv_obj_style_gen.su ./Core/GUI/lvgl/src/core/lv_obj_tree.d ./Core/GUI/lvgl/src/core/lv_obj_tree.o ./Core/GUI/lvgl/src/core/lv_obj_tree.su ./Core/GUI/lvgl/src/core/lv_refr.d ./Core/GUI/lvgl/src/core/lv_refr.o ./Core/GUI/lvgl/src/core/lv_refr.su ./Core/GUI/lvgl/src/core/lv_theme.d ./Core/GUI/lvgl/src/core/lv_theme.o ./Core/GUI/lvgl/src/core/lv_theme.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-core

