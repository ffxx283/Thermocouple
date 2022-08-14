################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.c \
../Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.c 

OBJS += \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.o \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.o 

C_DEPS += \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.d \
./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl_demos/src/lv_ex_style/%.o Core/GUI/lvgl_demos/src/lv_ex_style/%.su: ../Core/GUI/lvgl_demos/src/lv_ex_style/%.c Core/GUI/lvgl_demos/src/lv_ex_style/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_style

clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_style:
	-$(RM) ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_1.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_10.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_11.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_2.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_3.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_4.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_5.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_6.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_7.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_8.su ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.d ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.o ./Core/GUI/lvgl_demos/src/lv_ex_style/lv_ex_style_9.su

.PHONY: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_style

