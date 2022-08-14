################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.c \
../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.c \
../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.c 

OBJS += \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.o \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.o \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.o 

C_DEPS += \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.d \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.d \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/%.o Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/%.su: ../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/%.c Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_img

clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_img:
	-$(RM) ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.d ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.o ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_1.su ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.d ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.o ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_2.su ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.d ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.o ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_img/lv_ex_img_3.su

.PHONY: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_img

