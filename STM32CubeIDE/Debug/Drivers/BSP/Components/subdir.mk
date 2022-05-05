################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/STM32_Projects/B-U585I-IOT02A-FreeFall/Drivers/BSP/Components/ism330dhcx/ism330dhcx.c \
C:/STM32_Projects/B-U585I-IOT02A-FreeFall/Drivers/BSP/Components/ism330dhcx/ism330dhcx_reg.c 

OBJS += \
./Drivers/BSP/Components/ism330dhcx.o \
./Drivers/BSP/Components/ism330dhcx_reg.o 

C_DEPS += \
./Drivers/BSP/Components/ism330dhcx.d \
./Drivers/BSP/Components/ism330dhcx_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ism330dhcx.o: C:/STM32_Projects/B-U585I-IOT02A-FreeFall/Drivers/BSP/Components/ism330dhcx/ism330dhcx.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ism330dhcx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/ism330dhcx_reg.o: C:/STM32_Projects/B-U585I-IOT02A-FreeFall/Drivers/BSP/Components/ism330dhcx/ism330dhcx_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../../Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ism330dhcx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/ism330dhcx.d ./Drivers/BSP/Components/ism330dhcx.o ./Drivers/BSP/Components/ism330dhcx.su ./Drivers/BSP/Components/ism330dhcx_reg.d ./Drivers/BSP/Components/ism330dhcx_reg.o ./Drivers/BSP/Components/ism330dhcx_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

