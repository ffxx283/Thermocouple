################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/draw/sdl/%.o Core/GUI/lvgl/src/draw/sdl/%.su: ../Core/GUI/lvgl/src/draw/sdl/%.c Core/GUI/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Core/GUI/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-draw-2f-sdl

