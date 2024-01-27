################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EXTI_program.c \
../src/FMI_program.c \
../src/GPIO_program.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/STK_program.c \
../src/main.c 

C_DEPS += \
./src/EXTI_program.d \
./src/FMI_program.d \
./src/GPIO_program.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/STK_program.d \
./src/main.d 

OBJS += \
./src/EXTI_program.o \
./src/FMI_program.o \
./src/GPIO_program.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/STK_program.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


