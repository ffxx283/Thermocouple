################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/misc/lv_anim.c \
../Core/GUI/lvgl/src/misc/lv_anim_timeline.c \
../Core/GUI/lvgl/src/misc/lv_area.c \
../Core/GUI/lvgl/src/misc/lv_async.c \
../Core/GUI/lvgl/src/misc/lv_bidi.c \
../Core/GUI/lvgl/src/misc/lv_color.c \
../Core/GUI/lvgl/src/misc/lv_fs.c \
../Core/GUI/lvgl/src/misc/lv_gc.c \
../Core/GUI/lvgl/src/misc/lv_ll.c \
../Core/GUI/lvgl/src/misc/lv_log.c \
../Core/GUI/lvgl/src/misc/lv_lru.c \
../Core/GUI/lvgl/src/misc/lv_math.c \
../Core/GUI/lvgl/src/misc/lv_mem.c \
../Core/GUI/lvgl/src/misc/lv_printf.c \
../Core/GUI/lvgl/src/misc/lv_style.c \
../Core/GUI/lvgl/src/misc/lv_style_gen.c \
../Core/GUI/lvgl/src/misc/lv_templ.c \
../Core/GUI/lvgl/src/misc/lv_timer.c \
../Core/GUI/lvgl/src/misc/lv_tlsf.c \
../Core/GUI/lvgl/src/misc/lv_txt.c \
../Core/GUI/lvgl/src/misc/lv_txt_ap.c \
../Core/GUI/lvgl/src/misc/lv_utils.c 

OBJS += \
./Core/GUI/lvgl/src/misc/lv_anim.o \
./Core/GUI/lvgl/src/misc/lv_anim_timeline.o \
./Core/GUI/lvgl/src/misc/lv_area.o \
./Core/GUI/lvgl/src/misc/lv_async.o \
./Core/GUI/lvgl/src/misc/lv_bidi.o \
./Core/GUI/lvgl/src/misc/lv_color.o \
./Core/GUI/lvgl/src/misc/lv_fs.o \
./Core/GUI/lvgl/src/misc/lv_gc.o \
./Core/GUI/lvgl/src/misc/lv_ll.o \
./Core/GUI/lvgl/src/misc/lv_log.o \
./Core/GUI/lvgl/src/misc/lv_lru.o \
./Core/GUI/lvgl/src/misc/lv_math.o \
./Core/GUI/lvgl/src/misc/lv_mem.o \
./Core/GUI/lvgl/src/misc/lv_printf.o \
./Core/GUI/lvgl/src/misc/lv_style.o \
./Core/GUI/lvgl/src/misc/lv_style_gen.o \
./Core/GUI/lvgl/src/misc/lv_templ.o \
./Core/GUI/lvgl/src/misc/lv_timer.o \
./Core/GUI/lvgl/src/misc/lv_tlsf.o \
./Core/GUI/lvgl/src/misc/lv_txt.o \
./Core/GUI/lvgl/src/misc/lv_txt_ap.o \
./Core/GUI/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Core/GUI/lvgl/src/misc/lv_anim.d \
./Core/GUI/lvgl/src/misc/lv_anim_timeline.d \
./Core/GUI/lvgl/src/misc/lv_area.d \
./Core/GUI/lvgl/src/misc/lv_async.d \
./Core/GUI/lvgl/src/misc/lv_bidi.d \
./Core/GUI/lvgl/src/misc/lv_color.d \
./Core/GUI/lvgl/src/misc/lv_fs.d \
./Core/GUI/lvgl/src/misc/lv_gc.d \
./Core/GUI/lvgl/src/misc/lv_ll.d \
./Core/GUI/lvgl/src/misc/lv_log.d \
./Core/GUI/lvgl/src/misc/lv_lru.d \
./Core/GUI/lvgl/src/misc/lv_math.d \
./Core/GUI/lvgl/src/misc/lv_mem.d \
./Core/GUI/lvgl/src/misc/lv_printf.d \
./Core/GUI/lvgl/src/misc/lv_style.d \
./Core/GUI/lvgl/src/misc/lv_style_gen.d \
./Core/GUI/lvgl/src/misc/lv_templ.d \
./Core/GUI/lvgl/src/misc/lv_timer.d \
./Core/GUI/lvgl/src/misc/lv_tlsf.d \
./Core/GUI/lvgl/src/misc/lv_txt.d \
./Core/GUI/lvgl/src/misc/lv_txt_ap.d \
./Core/GUI/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/misc/%.o Core/GUI/lvgl/src/misc/%.su: ../Core/GUI/lvgl/src/misc/%.c Core/GUI/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-misc

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Core/GUI/lvgl/src/misc/lv_anim.d ./Core/GUI/lvgl/src/misc/lv_anim.o ./Core/GUI/lvgl/src/misc/lv_anim.su ./Core/GUI/lvgl/src/misc/lv_anim_timeline.d ./Core/GUI/lvgl/src/misc/lv_anim_timeline.o ./Core/GUI/lvgl/src/misc/lv_anim_timeline.su ./Core/GUI/lvgl/src/misc/lv_area.d ./Core/GUI/lvgl/src/misc/lv_area.o ./Core/GUI/lvgl/src/misc/lv_area.su ./Core/GUI/lvgl/src/misc/lv_async.d ./Core/GUI/lvgl/src/misc/lv_async.o ./Core/GUI/lvgl/src/misc/lv_async.su ./Core/GUI/lvgl/src/misc/lv_bidi.d ./Core/GUI/lvgl/src/misc/lv_bidi.o ./Core/GUI/lvgl/src/misc/lv_bidi.su ./Core/GUI/lvgl/src/misc/lv_color.d ./Core/GUI/lvgl/src/misc/lv_color.o ./Core/GUI/lvgl/src/misc/lv_color.su ./Core/GUI/lvgl/src/misc/lv_fs.d ./Core/GUI/lvgl/src/misc/lv_fs.o ./Core/GUI/lvgl/src/misc/lv_fs.su ./Core/GUI/lvgl/src/misc/lv_gc.d ./Core/GUI/lvgl/src/misc/lv_gc.o ./Core/GUI/lvgl/src/misc/lv_gc.su ./Core/GUI/lvgl/src/misc/lv_ll.d ./Core/GUI/lvgl/src/misc/lv_ll.o ./Core/GUI/lvgl/src/misc/lv_ll.su ./Core/GUI/lvgl/src/misc/lv_log.d ./Core/GUI/lvgl/src/misc/lv_log.o ./Core/GUI/lvgl/src/misc/lv_log.su ./Core/GUI/lvgl/src/misc/lv_lru.d ./Core/GUI/lvgl/src/misc/lv_lru.o ./Core/GUI/lvgl/src/misc/lv_lru.su ./Core/GUI/lvgl/src/misc/lv_math.d ./Core/GUI/lvgl/src/misc/lv_math.o ./Core/GUI/lvgl/src/misc/lv_math.su ./Core/GUI/lvgl/src/misc/lv_mem.d ./Core/GUI/lvgl/src/misc/lv_mem.o ./Core/GUI/lvgl/src/misc/lv_mem.su ./Core/GUI/lvgl/src/misc/lv_printf.d ./Core/GUI/lvgl/src/misc/lv_printf.o ./Core/GUI/lvgl/src/misc/lv_printf.su ./Core/GUI/lvgl/src/misc/lv_style.d ./Core/GUI/lvgl/src/misc/lv_style.o ./Core/GUI/lvgl/src/misc/lv_style.su ./Core/GUI/lvgl/src/misc/lv_style_gen.d ./Core/GUI/lvgl/src/misc/lv_style_gen.o ./Core/GUI/lvgl/src/misc/lv_style_gen.su ./Core/GUI/lvgl/src/misc/lv_templ.d ./Core/GUI/lvgl/src/misc/lv_templ.o ./Core/GUI/lvgl/src/misc/lv_templ.su ./Core/GUI/lvgl/src/misc/lv_timer.d ./Core/GUI/lvgl/src/misc/lv_timer.o ./Core/GUI/lvgl/src/misc/lv_timer.su ./Core/GUI/lvgl/src/misc/lv_tlsf.d ./Core/GUI/lvgl/src/misc/lv_tlsf.o ./Core/GUI/lvgl/src/misc/lv_tlsf.su ./Core/GUI/lvgl/src/misc/lv_txt.d ./Core/GUI/lvgl/src/misc/lv_txt.o ./Core/GUI/lvgl/src/misc/lv_txt.su ./Core/GUI/lvgl/src/misc/lv_txt_ap.d ./Core/GUI/lvgl/src/misc/lv_txt_ap.o ./Core/GUI/lvgl/src/misc/lv_txt_ap.su ./Core/GUI/lvgl/src/misc/lv_utils.d ./Core/GUI/lvgl/src/misc/lv_utils.o ./Core/GUI/lvgl/src/misc/lv_utils.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-misc

