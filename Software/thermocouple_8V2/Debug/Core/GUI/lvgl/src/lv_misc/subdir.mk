################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/lv_misc/lv_anim.c \
../Core/GUI/lvgl/src/lv_misc/lv_area.c \
../Core/GUI/lvgl/src/lv_misc/lv_async.c \
../Core/GUI/lvgl/src/lv_misc/lv_bidi.c \
../Core/GUI/lvgl/src/lv_misc/lv_color.c \
../Core/GUI/lvgl/src/lv_misc/lv_debug.c \
../Core/GUI/lvgl/src/lv_misc/lv_fs.c \
../Core/GUI/lvgl/src/lv_misc/lv_gc.c \
../Core/GUI/lvgl/src/lv_misc/lv_ll.c \
../Core/GUI/lvgl/src/lv_misc/lv_log.c \
../Core/GUI/lvgl/src/lv_misc/lv_math.c \
../Core/GUI/lvgl/src/lv_misc/lv_mem.c \
../Core/GUI/lvgl/src/lv_misc/lv_printf.c \
../Core/GUI/lvgl/src/lv_misc/lv_task.c \
../Core/GUI/lvgl/src/lv_misc/lv_templ.c \
../Core/GUI/lvgl/src/lv_misc/lv_txt.c \
../Core/GUI/lvgl/src/lv_misc/lv_txt_ap.c \
../Core/GUI/lvgl/src/lv_misc/lv_utils.c 

OBJS += \
./Core/GUI/lvgl/src/lv_misc/lv_anim.o \
./Core/GUI/lvgl/src/lv_misc/lv_area.o \
./Core/GUI/lvgl/src/lv_misc/lv_async.o \
./Core/GUI/lvgl/src/lv_misc/lv_bidi.o \
./Core/GUI/lvgl/src/lv_misc/lv_color.o \
./Core/GUI/lvgl/src/lv_misc/lv_debug.o \
./Core/GUI/lvgl/src/lv_misc/lv_fs.o \
./Core/GUI/lvgl/src/lv_misc/lv_gc.o \
./Core/GUI/lvgl/src/lv_misc/lv_ll.o \
./Core/GUI/lvgl/src/lv_misc/lv_log.o \
./Core/GUI/lvgl/src/lv_misc/lv_math.o \
./Core/GUI/lvgl/src/lv_misc/lv_mem.o \
./Core/GUI/lvgl/src/lv_misc/lv_printf.o \
./Core/GUI/lvgl/src/lv_misc/lv_task.o \
./Core/GUI/lvgl/src/lv_misc/lv_templ.o \
./Core/GUI/lvgl/src/lv_misc/lv_txt.o \
./Core/GUI/lvgl/src/lv_misc/lv_txt_ap.o \
./Core/GUI/lvgl/src/lv_misc/lv_utils.o 

C_DEPS += \
./Core/GUI/lvgl/src/lv_misc/lv_anim.d \
./Core/GUI/lvgl/src/lv_misc/lv_area.d \
./Core/GUI/lvgl/src/lv_misc/lv_async.d \
./Core/GUI/lvgl/src/lv_misc/lv_bidi.d \
./Core/GUI/lvgl/src/lv_misc/lv_color.d \
./Core/GUI/lvgl/src/lv_misc/lv_debug.d \
./Core/GUI/lvgl/src/lv_misc/lv_fs.d \
./Core/GUI/lvgl/src/lv_misc/lv_gc.d \
./Core/GUI/lvgl/src/lv_misc/lv_ll.d \
./Core/GUI/lvgl/src/lv_misc/lv_log.d \
./Core/GUI/lvgl/src/lv_misc/lv_math.d \
./Core/GUI/lvgl/src/lv_misc/lv_mem.d \
./Core/GUI/lvgl/src/lv_misc/lv_printf.d \
./Core/GUI/lvgl/src/lv_misc/lv_task.d \
./Core/GUI/lvgl/src/lv_misc/lv_templ.d \
./Core/GUI/lvgl/src/lv_misc/lv_txt.d \
./Core/GUI/lvgl/src/lv_misc/lv_txt_ap.d \
./Core/GUI/lvgl/src/lv_misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/lv_misc/%.o Core/GUI/lvgl/src/lv_misc/%.su: ../Core/GUI/lvgl/src/lv_misc/%.c Core/GUI/lvgl/src/lv_misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_misc

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_misc:
	-$(RM) ./Core/GUI/lvgl/src/lv_misc/lv_anim.d ./Core/GUI/lvgl/src/lv_misc/lv_anim.o ./Core/GUI/lvgl/src/lv_misc/lv_anim.su ./Core/GUI/lvgl/src/lv_misc/lv_area.d ./Core/GUI/lvgl/src/lv_misc/lv_area.o ./Core/GUI/lvgl/src/lv_misc/lv_area.su ./Core/GUI/lvgl/src/lv_misc/lv_async.d ./Core/GUI/lvgl/src/lv_misc/lv_async.o ./Core/GUI/lvgl/src/lv_misc/lv_async.su ./Core/GUI/lvgl/src/lv_misc/lv_bidi.d ./Core/GUI/lvgl/src/lv_misc/lv_bidi.o ./Core/GUI/lvgl/src/lv_misc/lv_bidi.su ./Core/GUI/lvgl/src/lv_misc/lv_color.d ./Core/GUI/lvgl/src/lv_misc/lv_color.o ./Core/GUI/lvgl/src/lv_misc/lv_color.su ./Core/GUI/lvgl/src/lv_misc/lv_debug.d ./Core/GUI/lvgl/src/lv_misc/lv_debug.o ./Core/GUI/lvgl/src/lv_misc/lv_debug.su ./Core/GUI/lvgl/src/lv_misc/lv_fs.d ./Core/GUI/lvgl/src/lv_misc/lv_fs.o ./Core/GUI/lvgl/src/lv_misc/lv_fs.su ./Core/GUI/lvgl/src/lv_misc/lv_gc.d ./Core/GUI/lvgl/src/lv_misc/lv_gc.o ./Core/GUI/lvgl/src/lv_misc/lv_gc.su ./Core/GUI/lvgl/src/lv_misc/lv_ll.d ./Core/GUI/lvgl/src/lv_misc/lv_ll.o ./Core/GUI/lvgl/src/lv_misc/lv_ll.su ./Core/GUI/lvgl/src/lv_misc/lv_log.d ./Core/GUI/lvgl/src/lv_misc/lv_log.o ./Core/GUI/lvgl/src/lv_misc/lv_log.su ./Core/GUI/lvgl/src/lv_misc/lv_math.d ./Core/GUI/lvgl/src/lv_misc/lv_math.o ./Core/GUI/lvgl/src/lv_misc/lv_math.su ./Core/GUI/lvgl/src/lv_misc/lv_mem.d ./Core/GUI/lvgl/src/lv_misc/lv_mem.o ./Core/GUI/lvgl/src/lv_misc/lv_mem.su ./Core/GUI/lvgl/src/lv_misc/lv_printf.d ./Core/GUI/lvgl/src/lv_misc/lv_printf.o ./Core/GUI/lvgl/src/lv_misc/lv_printf.su ./Core/GUI/lvgl/src/lv_misc/lv_task.d ./Core/GUI/lvgl/src/lv_misc/lv_task.o ./Core/GUI/lvgl/src/lv_misc/lv_task.su ./Core/GUI/lvgl/src/lv_misc/lv_templ.d ./Core/GUI/lvgl/src/lv_misc/lv_templ.o ./Core/GUI/lvgl/src/lv_misc/lv_templ.su ./Core/GUI/lvgl/src/lv_misc/lv_txt.d ./Core/GUI/lvgl/src/lv_misc/lv_txt.o ./Core/GUI/lvgl/src/lv_misc/lv_txt.su ./Core/GUI/lvgl/src/lv_misc/lv_txt_ap.d ./Core/GUI/lvgl/src/lv_misc/lv_txt_ap.o ./Core/GUI/lvgl/src/lv_misc/lv_txt_ap.su ./Core/GUI/lvgl/src/lv_misc/lv_utils.d ./Core/GUI/lvgl/src/lv_misc/lv_utils.o ./Core/GUI/lvgl/src/lv_misc/lv_utils.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_misc

