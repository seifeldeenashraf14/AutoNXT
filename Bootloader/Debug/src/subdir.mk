################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MFMI_program.c \
../src/MGPIO_program.c \
../src/MRCC_program.c \
../src/MSCB_program.c \
../src/MSTK_program.c \
../src/MUART_program.c \
../src/SHexParser_program.c \
../src/main.c 

C_DEPS += \
./src/MFMI_program.d \
./src/MGPIO_program.d \
./src/MRCC_program.d \
./src/MSCB_program.d \
./src/MSTK_program.d \
./src/MUART_program.d \
./src/SHexParser_program.d \
./src/main.d 

OBJS += \
./src/MFMI_program.o \
./src/MGPIO_program.o \
./src/MRCC_program.o \
./src/MSCB_program.o \
./src/MSTK_program.o \
./src/MUART_program.o \
./src/SHexParser_program.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


