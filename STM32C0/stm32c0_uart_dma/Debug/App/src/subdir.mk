################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/src/adc.c \
../App/src/button.c \
../App/src/led.c \
../App/src/pwm.c \
../App/src/uart.c \
../App/src/utils.c 

OBJS += \
./App/src/adc.o \
./App/src/button.o \
./App/src/led.o \
./App/src/pwm.o \
./App/src/uart.o \
./App/src/utils.o 

C_DEPS += \
./App/src/adc.d \
./App/src/button.d \
./App/src/led.d \
./App/src/pwm.d \
./App/src/uart.d \
./App/src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
App/src/%.o App/src/%.su: ../App/src/%.c App/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C031xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -I"C:/STJ Projects Files/STM32 CubeIDE Files/STM32C031-DK Board Lecture/STM32C0/stm32c0_uart_dma/App/include" -I"C:/STJ Projects Files/STM32 CubeIDE Files/STM32C031-DK Board Lecture/STM32C0/stm32c0_uart_dma/App" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-src

clean-App-2f-src:
	-$(RM) ./App/src/adc.d ./App/src/adc.o ./App/src/adc.su ./App/src/button.d ./App/src/button.o ./App/src/button.su ./App/src/led.d ./App/src/led.o ./App/src/led.su ./App/src/pwm.d ./App/src/pwm.o ./App/src/pwm.su ./App/src/uart.d ./App/src/uart.o ./App/src/uart.su ./App/src/utils.d ./App/src/utils.o ./App/src/utils.su

.PHONY: clean-App-2f-src

