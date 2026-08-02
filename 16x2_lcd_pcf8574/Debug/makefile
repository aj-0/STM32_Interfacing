################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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


<<<<<<< HEAD
BUILD_ARTIFACT_NAME := i2c
=======
BUILD_ARTIFACT_NAME := 16x2_lcd_pcf8574
>>>>>>> 472618e (Git: Add Remote)
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
<<<<<<< HEAD
i2c.elf \

MAP_FILES += \
i2c.map \
=======
16x2_lcd_pcf8574.elf \

MAP_FILES += \
16x2_lcd_pcf8574.map \
>>>>>>> 472618e (Git: Add Remote)

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
<<<<<<< HEAD
i2c.list \
=======
16x2_lcd_pcf8574.list \
>>>>>>> 472618e (Git: Add Remote)


# All Target
all: main-build

# Main-build Target
<<<<<<< HEAD
main-build: i2c.elf secondary-outputs

# Tool invocations
i2c.elf i2c.map: $(OBJS) $(USER_OBJS) C:\Users\AJay\STM32CubeIDE\workspace_1.19.0\stM\i2c\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "i2c.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\AJay\STM32CubeIDE\workspace_1.19.0\stM\i2c\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="i2c.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
=======
main-build: 16x2_lcd_pcf8574.elf secondary-outputs

# Tool invocations
16x2_lcd_pcf8574.elf 16x2_lcd_pcf8574.map: $(OBJS) $(USER_OBJS) D:\STM32_Interfacing\16x2_lcd_pcf8574\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "16x2_lcd_pcf8574.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STM32_Interfacing\16x2_lcd_pcf8574\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="16x2_lcd_pcf8574.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
>>>>>>> 472618e (Git: Add Remote)
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

<<<<<<< HEAD
i2c.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "i2c.list"
=======
16x2_lcd_pcf8574.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "16x2_lcd_pcf8574.list"
>>>>>>> 472618e (Git: Add Remote)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
<<<<<<< HEAD
	-$(RM) default.size.stdout i2c.elf i2c.list i2c.map
=======
	-$(RM) 16x2_lcd_pcf8574.elf 16x2_lcd_pcf8574.list 16x2_lcd_pcf8574.map default.size.stdout
>>>>>>> 472618e (Git: Add Remote)
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
