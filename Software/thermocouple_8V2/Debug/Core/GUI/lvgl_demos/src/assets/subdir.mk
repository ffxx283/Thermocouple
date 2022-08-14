################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.c \
../Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.c \
../Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.c \
../Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.c \
../Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.c \
../Core/GUI/lvgl_demos/src/assets/img_hand.c \
../Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.c \
../Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.c \
../Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.c 

OBJS += \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.o \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.o \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.o \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.o \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.o \
./Core/GUI/lvgl_demos/src/assets/img_hand.o \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.o \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.o \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.o 

C_DEPS += \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.d \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.d \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.d \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.d \
./Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.d \
./Core/GUI/lvgl_demos/src/assets/img_hand.d \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.d \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.d \
./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.d 


# Each subdirectory must supply rules for building sources it contributes
Core/GUI/lvgl_demos/src/assets/%.o Core/GUI/lvgl_demos/src/assets/%.su: ../Core/GUI/lvgl_demos/src/assets/%.c Core/GUI/lvgl_demos/src/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl_demos" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/examples/porting" -I"H:/03_thermocouple_V2/03_Code/thermocouple_V2/Core/GUI/lvgl/src/lv_hal" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-assets

clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-assets:
	-$(RM) ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.d ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.o ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_alpha16.su ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.d ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.o ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_argb.su ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.d ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.o ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_chroma_keyed.su ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.d ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.o ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_indexed16.su ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.d ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.o ./Core/GUI/lvgl_demos/src/assets/img_cogwheel_rgb.su ./Core/GUI/lvgl_demos/src/assets/img_hand.d ./Core/GUI/lvgl_demos/src/assets/img_hand.o ./Core/GUI/lvgl_demos/src/assets/img_hand.su ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.d ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.o ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_12_compr_az.su ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.d ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.o ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_16_compr_az.su ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.d ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.o ./Core/GUI/lvgl_demos/src/assets/lv_font_montserrat_28_compr_az.su

.PHONY: clean-Core-2f-GUI-2f-lvgl_demos-2f-src-2f-assets

