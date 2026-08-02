################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ether/socket.c \
../Ether/wizchip_conf.c 

OBJS += \
./Ether/socket.o \
./Ether/wizchip_conf.o 

C_DEPS += \
./Ether/socket.d \
./Ether/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Ether/%.o Ether/%.su Ether/%.cyclo: ../Ether/%.c Ether/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"D:/STM32_Interfacing/Spi_to_Ethernet/Ether" -I"D:/STM32_Interfacing/Spi_to_Ethernet/Ether/W5500" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Ether

clean-Ether:
	-$(RM) ./Ether/socket.cyclo ./Ether/socket.d ./Ether/socket.o ./Ether/socket.su ./Ether/wizchip_conf.cyclo ./Ether/wizchip_conf.d ./Ether/wizchip_conf.o ./Ether/wizchip_conf.su

.PHONY: clean-Ether

