################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.c \
../Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.c \
../Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.c \
../Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.o \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.o \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.o \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.d \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.d \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.d \
./Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl/src/lv_gpu/%.o Core/GUI/lvgl/src/lv_gpu/%.su: ../Core/GUI/lvgl/src/lv_gpu/%.c Core/GUI/lvgl/src/lv_gpu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_gpu

clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_gpu:
	-$(RM) ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.d ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.o ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.su ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.d ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.o ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.su ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.d ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.o ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.su ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.d ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.o ./Core/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.su

.PHONY: clean-Core-2f-GUI-2f-lvgl-2f-src-2f-lv_gpu

