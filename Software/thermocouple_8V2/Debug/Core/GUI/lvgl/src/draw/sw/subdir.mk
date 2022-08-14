################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.c 

OBJS += \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.o 

C_DEPS += \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/draw/sw/%.o Core/GUI/lvgl/src/draw/sw/%.su: ../Core/GUI/lvgl/src/draw/sw/%.c Core/GUI/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_blend.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_dither.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_img.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_line.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.d ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.o ./Core/GUI/lvgl/src/draw/sw/lv_draw_sw_rect.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sw

