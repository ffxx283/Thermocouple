################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.c \
../Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.c 

OBJS += \
./Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.o \
./Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.o 

C_DEPS += \
./Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.d \
./Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/extra/libs/qrcode/%.o Core/GUI/lvgl/src/extra/libs/qrcode/%.su: ../Core/GUI/lvgl/src/extra/libs/qrcode/%.c Core/GUI/lvgl/src/extra/libs/qrcode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode:
	-$(RM) ./Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.d ./Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.o ./Core/GUI/lvgl/src/extra/libs/qrcode/lv_qrcode.su ./Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.d ./Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.o ./Core/GUI/lvgl/src/extra/libs/qrcode/qrcodegen.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode

