################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_DEVICE/Target/subdir.mk
-include USB_DEVICE/App/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include Middlewares/FATFS/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/GUI/lvgl/src/widgets/subdir.mk
-include Core/GUI/lvgl/src/misc/subdir.mk
-include Core/GUI/lvgl/src/hal/subdir.mk
-include Core/GUI/lvgl/src/font/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/win/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/tileview/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/tabview/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/spinner/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/spinbox/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/span/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/msgbox/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/meter/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/menu/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/list/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/led/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/keyboard/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/chart/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/calendar/subdir.mk
-include Core/GUI/lvgl/src/extra/widgets/animimg/subdir.mk
-include Core/GUI/lvgl/src/extra/themes/mono/subdir.mk
-include Core/GUI/lvgl/src/extra/themes/default/subdir.mk
-include Core/GUI/lvgl/src/extra/themes/basic/subdir.mk
-include Core/GUI/lvgl/src/extra/others/snapshot/subdir.mk
-include Core/GUI/lvgl/src/extra/others/monkey/subdir.mk
-include Core/GUI/lvgl/src/extra/others/gridnav/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/sjpg/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/rlottie/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/qrcode/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/png/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/gif/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/fsdrv/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/freetype/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/ffmpeg/subdir.mk
-include Core/GUI/lvgl/src/extra/libs/bmp/subdir.mk
-include Core/GUI/lvgl/src/extra/layouts/grid/subdir.mk
-include Core/GUI/lvgl/src/extra/layouts/flex/subdir.mk
-include Core/GUI/lvgl/src/extra/subdir.mk
-include Core/GUI/lvgl/src/draw/sw/subdir.mk
-include Core/GUI/lvgl/src/draw/stm32_dma2d/subdir.mk
-include Core/GUI/lvgl/src/draw/sdl/subdir.mk
-include Core/GUI/lvgl/src/draw/nxp_vglite/subdir.mk
-include Core/GUI/lvgl/src/draw/nxp_pxp/subdir.mk
-include Core/GUI/lvgl/src/draw/subdir.mk
-include Core/GUI/lvgl/src/core/subdir.mk
-include Core/GUI/lvgl/examples/porting/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := thermocouple_V2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
thermocouple_V2.elf \

MAP_FILES += \
thermocouple_V2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
thermocouple_V2.list \


# All Target
all: main-build

# Main-build Target
main-build: thermocouple_V2.elf secondary-outputs

# Tool invocations
thermocouple_V2.elf thermocouple_V2.map: $(OBJS) $(USER_OBJS) H:\03_thermocouple_V2\03_Code\thermocouple_8V2\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "thermocouple_V2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"H:\03_thermocouple_V2\03_Code\thermocouple_8V2\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="thermocouple_V2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

thermocouple_V2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "thermocouple_V2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout thermocouple_V2.elf thermocouple_V2.list thermocouple_V2.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
