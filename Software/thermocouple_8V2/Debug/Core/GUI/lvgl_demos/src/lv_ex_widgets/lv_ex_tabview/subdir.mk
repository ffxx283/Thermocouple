################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.c 

OBJS += \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.o 

C_DEPS += \
./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/%.o Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/%.su: ../Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/%.c Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_tabview

clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_tabview:
	-$(RM) ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.d ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.o ./Core/GUI/lvgl_demos/src/lv_ex_widgets/lv_ex_tabview/lv_ex_tabview_1.su

.PHONY: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-lv_ex_widgets-2f-lv_ex_tabview

