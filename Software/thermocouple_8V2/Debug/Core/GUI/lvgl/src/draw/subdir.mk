################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/draw/lv_draw.c \
../Core/GUI/lvgl/src/draw/lv_draw_arc.c \
../Core/GUI/lvgl/src/draw/lv_draw_img.c \
../Core/GUI/lvgl/src/draw/lv_draw_label.c \
../Core/GUI/lvgl/src/draw/lv_draw_line.c \
../Core/GUI/lvgl/src/draw/lv_draw_mask.c \
../Core/GUI/lvgl/src/draw/lv_draw_rect.c \
../Core/GUI/lvgl/src/draw/lv_draw_triangle.c \
../Core/GUI/lvgl/src/draw/lv_img_buf.c \
../Core/GUI/lvgl/src/draw/lv_img_cache.c \
../Core/GUI/lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./Core/GUI/lvgl/src/draw/lv_draw.o \
./Core/GUI/lvgl/src/draw/lv_draw_arc.o \
./Core/GUI/lvgl/src/draw/lv_draw_img.o \
./Core/GUI/lvgl/src/draw/lv_draw_label.o \
./Core/GUI/lvgl/src/draw/lv_draw_line.o \
./Core/GUI/lvgl/src/draw/lv_draw_mask.o \
./Core/GUI/lvgl/src/draw/lv_draw_rect.o \
./Core/GUI/lvgl/src/draw/lv_draw_triangle.o \
./Core/GUI/lvgl/src/draw/lv_img_buf.o \
./Core/GUI/lvgl/src/draw/lv_img_cache.o \
./Core/GUI/lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./Core/GUI/lvgl/src/draw/lv_draw.d \
./Core/GUI/lvgl/src/draw/lv_draw_arc.d \
./Core/GUI/lvgl/src/draw/lv_draw_img.d \
./Core/GUI/lvgl/src/draw/lv_draw_label.d \
./Core/GUI/lvgl/src/draw/lv_draw_line.d \
./Core/GUI/lvgl/src/draw/lv_draw_mask.d \
./Core/GUI/lvgl/src/draw/lv_draw_rect.d \
./Core/GUI/lvgl/src/draw/lv_draw_triangle.d \
./Core/GUI/lvgl/src/draw/lv_img_buf.d \
./Core/GUI/lvgl/src/draw/lv_img_cache.d \
./Core/GUI/lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/draw/%.o Core/GUI/lvgl/src/draw/%.su: ../Core/GUI/lvgl/src/draw/%.c Core/GUI/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Core/GUI/lvgl/src/draw/lv_draw.d ./Core/GUI/lvgl/src/draw/lv_draw.o ./Core/GUI/lvgl/src/draw/lv_draw.su ./Core/GUI/lvgl/src/draw/lv_draw_arc.d ./Core/GUI/lvgl/src/draw/lv_draw_arc.o ./Core/GUI/lvgl/src/draw/lv_draw_arc.su ./Core/GUI/lvgl/src/draw/lv_draw_img.d ./Core/GUI/lvgl/src/draw/lv_draw_img.o ./Core/GUI/lvgl/src/draw/lv_draw_img.su ./Core/GUI/lvgl/src/draw/lv_draw_label.d ./Core/GUI/lvgl/src/draw/lv_draw_label.o ./Core/GUI/lvgl/src/draw/lv_draw_label.su ./Core/GUI/lvgl/src/draw/lv_draw_line.d ./Core/GUI/lvgl/src/draw/lv_draw_line.o ./Core/GUI/lvgl/src/draw/lv_draw_line.su ./Core/GUI/lvgl/src/draw/lv_draw_mask.d ./Core/GUI/lvgl/src/draw/lv_draw_mask.o ./Core/GUI/lvgl/src/draw/lv_draw_mask.su ./Core/GUI/lvgl/src/draw/lv_draw_rect.d ./Core/GUI/lvgl/src/draw/lv_draw_rect.o ./Core/GUI/lvgl/src/draw/lv_draw_rect.su ./Core/GUI/lvgl/src/draw/lv_draw_triangle.d ./Core/GUI/lvgl/src/draw/lv_draw_triangle.o ./Core/GUI/lvgl/src/draw/lv_draw_triangle.su ./Core/GUI/lvgl/src/draw/lv_img_buf.d ./Core/GUI/lvgl/src/draw/lv_img_buf.o ./Core/GUI/lvgl/src/draw/lv_img_buf.su ./Core/GUI/lvgl/src/draw/lv_img_cache.d ./Core/GUI/lvgl/src/draw/lv_img_cache.o ./Core/GUI/lvgl/src/draw/lv_img_cache.su ./Core/GUI/lvgl/src/draw/lv_img_decoder.d ./Core/GUI/lvgl/src/draw/lv_img_decoder.o ./Core/GUI/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw

