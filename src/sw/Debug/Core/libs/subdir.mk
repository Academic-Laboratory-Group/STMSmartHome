################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/libs/DEV_Config.c \
../Core/libs/LCD_Driver.c \
../Core/libs/LCD_GUI.c \
../Core/libs/LCD_Touch.c \
../Core/libs/Sensor_Driver.c \
../Core/libs/font12.c \
../Core/libs/font16.c \
../Core/libs/font20.c \
../Core/libs/font24.c \
../Core/libs/font8.c \
../Core/libs/gpio.c \
../Core/libs/spi.c \
../Core/libs/stm32f4xx_hal_msp.c \
../Core/libs/stm32f4xx_it.c \
../Core/libs/syscalls.c \
../Core/libs/sysmem.c \
../Core/libs/system_stm32f4xx.c \
../Core/libs/tim.c \
../Core/libs/usart.c 

C_DEPS += \
./Core/libs/DEV_Config.d \
./Core/libs/LCD_Driver.d \
./Core/libs/LCD_GUI.d \
./Core/libs/LCD_Touch.d \
./Core/libs/Sensor_Driver.d \
./Core/libs/font12.d \
./Core/libs/font16.d \
./Core/libs/font20.d \
./Core/libs/font24.d \
./Core/libs/font8.d \
./Core/libs/gpio.d \
./Core/libs/spi.d \
./Core/libs/stm32f4xx_hal_msp.d \
./Core/libs/stm32f4xx_it.d \
./Core/libs/syscalls.d \
./Core/libs/sysmem.d \
./Core/libs/system_stm32f4xx.d \
./Core/libs/tim.d \
./Core/libs/usart.d 

OBJS += \
./Core/libs/DEV_Config.o \
./Core/libs/LCD_Driver.o \
./Core/libs/LCD_GUI.o \
./Core/libs/LCD_Touch.o \
./Core/libs/Sensor_Driver.o \
./Core/libs/font12.o \
./Core/libs/font16.o \
./Core/libs/font20.o \
./Core/libs/font24.o \
./Core/libs/font8.o \
./Core/libs/gpio.o \
./Core/libs/spi.o \
./Core/libs/stm32f4xx_hal_msp.o \
./Core/libs/stm32f4xx_it.o \
./Core/libs/syscalls.o \
./Core/libs/sysmem.o \
./Core/libs/system_stm32f4xx.o \
./Core/libs/tim.o \
./Core/libs/usart.o 


# Each subdirectory must supply rules for building sources it contributes
Core/libs/DEV_Config.o: ../Core/libs/DEV_Config.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/DEV_Config.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/LCD_Driver.o: ../Core/libs/LCD_Driver.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/LCD_Driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/LCD_GUI.o: ../Core/libs/LCD_GUI.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/LCD_GUI.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/LCD_Touch.o: ../Core/libs/LCD_Touch.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/LCD_Touch.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/Sensor_Driver.o: ../Core/libs/Sensor_Driver.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/Sensor_Driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/font12.o: ../Core/libs/font12.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/font12.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/font16.o: ../Core/libs/font16.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/font16.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/font20.o: ../Core/libs/font20.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/font20.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/font24.o: ../Core/libs/font24.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/font24.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/font8.o: ../Core/libs/font8.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/font8.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/gpio.o: ../Core/libs/gpio.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/spi.o: ../Core/libs/spi.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/stm32f4xx_hal_msp.o: ../Core/libs/stm32f4xx_hal_msp.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/stm32f4xx_it.o: ../Core/libs/stm32f4xx_it.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/syscalls.o: ../Core/libs/syscalls.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/sysmem.o: ../Core/libs/sysmem.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/system_stm32f4xx.o: ../Core/libs/system_stm32f4xx.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/tim.o: ../Core/libs/tim.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/libs/usart.o: ../Core/libs/usart.c Core/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/src -I../Core/libs -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/libs/usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

