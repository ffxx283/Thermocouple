################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/examples/porting/lv_port_disp.c \
../Core/GUI/lvgl/examples/porting/lv_port_fs.c \
../Core/GUI/lvgl/examples/porting/lv_port_indev.c 

OBJS += \
./Core/GUI/lvgl/examples/porting/lv_port_disp.o \
./Core/GUI/lvgl/examples/porting/lv_port_fs.o \
./Core/GUI/lvgl/examples/porting/lv_port_indev.o 

C_DEPS += \
./Core/GUI/lvgl/examples/porting/lv_port_disp.d \
./Core/GUI/lvgl/examples/porting/lv_port_fs.d \
./Core/GUI/lvgl/examples/porting/lv_port_indev.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/examples/porting/%.o Core/GUI/lvgl/examples/porting/%.su: ../Core/GUI/lvgl/examples/porting/%.c Core/GUI/lvgl/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-examples-2f-porting

clean-Core-2f-GUI-2f-lvgl-2f-examples-2f-porting:
	-$(RM) ./Core/GUI/lvgl/examples/porting/lv_port_disp.d ./Core/GUI/lvgl/examples/porting/lv_port_disp.o ./Core/GUI/lvgl/examples/porting/lv_port_disp.su ./Core/GUI/lvgl/examples/porting/lv_port_fs.d ./Core/GUI/lvgl/examples/porting/lv_port_fs.o ./Core/GUI/lvgl/examples/porting/lv_port_fs.su ./Core/GUI/lvgl/examples/porting/lv_port_indev.d ./Core/GUI/lvgl/examples/porting/lv_port_indev.o ./Core/GUI/lvgl/examples/porting/lv_port_indev.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-examples-2f-porting

