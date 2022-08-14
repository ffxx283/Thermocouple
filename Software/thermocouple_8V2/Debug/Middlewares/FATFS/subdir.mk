################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/FATFS/diskio.c \
../Middlewares/FATFS/ff.c \
../Middlewares/FATFS/ffsystem.c \
../Middlewares/FATFS/ffunicode.c 

OBJS += \
./Middlewares/FATFS/diskio.o \
./Middlewares/FATFS/ff.o \
./Middlewares/FATFS/ffsystem.o \
./Middlewares/FATFS/ffunicode.o 

C_DEPS += \
./Middlewares/FATFS/diskio.d \
./Middlewares/FATFS/ff.d \
./Middlewares/FATFS/ffsystem.d \
./Middlewares/FATFS/ffunicode.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FATFS/%.o Middlewares/FATFS/%.su: ../Middlewares/FATFS/%.c Middlewares/FATFS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/hal" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Core/GUI/lvgl/src/core" -I"H:/03_thermocouple_V2/03_Code/thermocouple_8V2/Middlewares/FATFS" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-FATFS

clean-Middlewares-2f-FATFS:
	-$(RM) ./Middlewares/FATFS/diskio.d ./Middlewares/FATFS/diskio.o ./Middlewares/FATFS/diskio.su ./Middlewares/FATFS/ff.d ./Middlewares/FATFS/ff.o ./Middlewares/FATFS/ff.su ./Middlewares/FATFS/ffsystem.d ./Middlewares/FATFS/ffsystem.o ./Middlewares/FATFS/ffsystem.su ./Middlewares/FATFS/ffunicode.d ./Middlewares/FATFS/ffunicode.o ./Middlewares/FATFS/ffunicode.su

.PHONY: clean-Middlewares-2f-FATFS
