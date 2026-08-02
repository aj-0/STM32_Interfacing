################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ether/W5500/w5500.c 

OBJS += \
./Ether/W5500/w5500.o 

C_DEPS += \
./Ether/W5500/w5500.d 


# Each subdirectory must supply rules for building sources it contributes
Ether/W5500/%.o Ether/W5500/%.su Ether/W5500/%.cyclo: ../Ether/W5500/%.c Ether/W5500/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"D:/STM32_Interfacing/Spi_to_Ethernet/Ether" -I"D:/STM32_Interfacing/Spi_to_Ethernet/Ether/W5500" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Ether-2f-W5500

clean-Ether-2f-W5500:
	-$(RM) ./Ether/W5500/w5500.cyclo ./Ether/W5500/w5500.d ./Ether/W5500/w5500.o ./Ether/W5500/w5500.su

.PHONY: clean-Ether-2f-W5500

