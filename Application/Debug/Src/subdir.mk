################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HFSR_Program.c \
../Src/HLDR_Program.c \
../Src/HMotor_Program.c \
../Src/MADC_Program.c \
../Src/MEXTI_Program.c \
../Src/MGPIO_Program.c \
../Src/MNVIC_Program.c \
../Src/MRCC_Program.c \
../Src/MSPI_Program.c \
../Src/MTIMER_Program.c \
../Src/MUART_Program.c \
../Src/UDS_Services..c \
../Src/UDS_Services_Config.c \
../Src/Ultrasonic_Program.c \
../Src/main.c \
../Src/syscalls.c 

OBJS += \
./Src/HFSR_Program.o \
./Src/HLDR_Program.o \
./Src/HMotor_Program.o \
./Src/MADC_Program.o \
./Src/MEXTI_Program.o \
./Src/MGPIO_Program.o \
./Src/MNVIC_Program.o \
./Src/MRCC_Program.o \
./Src/MSPI_Program.o \
./Src/MTIMER_Program.o \
./Src/MUART_Program.o \
./Src/UDS_Services..o \
./Src/UDS_Services_Config.o \
./Src/Ultrasonic_Program.o \
./Src/main.o \
./Src/syscalls.o 

C_DEPS += \
./Src/HFSR_Program.d \
./Src/HLDR_Program.d \
./Src/HMotor_Program.d \
./Src/MADC_Program.d \
./Src/MEXTI_Program.d \
./Src/MGPIO_Program.d \
./Src/MNVIC_Program.d \
./Src/MRCC_Program.d \
./Src/MSPI_Program.d \
./Src/MTIMER_Program.d \
./Src/MUART_Program.d \
./Src/UDS_Services..d \
./Src/UDS_Services_Config.d \
./Src/Ultrasonic_Program.d \
./Src/main.d \
./Src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"F:/CUBE_RTOS/RTOS_Wokspace/Application_Test/ThirdParty/FreeRTOS" -I"F:/CUBE_RTOS/RTOS_Wokspace/Application_Test/ThirdParty/FreeRTOS/include" -I"F:/CUBE_RTOS/RTOS_Wokspace/Application_Test/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/HFSR_Program.cyclo ./Src/HFSR_Program.d ./Src/HFSR_Program.o ./Src/HFSR_Program.su ./Src/HLDR_Program.cyclo ./Src/HLDR_Program.d ./Src/HLDR_Program.o ./Src/HLDR_Program.su ./Src/HMotor_Program.cyclo ./Src/HMotor_Program.d ./Src/HMotor_Program.o ./Src/HMotor_Program.su ./Src/MADC_Program.cyclo ./Src/MADC_Program.d ./Src/MADC_Program.o ./Src/MADC_Program.su ./Src/MEXTI_Program.cyclo ./Src/MEXTI_Program.d ./Src/MEXTI_Program.o ./Src/MEXTI_Program.su ./Src/MGPIO_Program.cyclo ./Src/MGPIO_Program.d ./Src/MGPIO_Program.o ./Src/MGPIO_Program.su ./Src/MNVIC_Program.cyclo ./Src/MNVIC_Program.d ./Src/MNVIC_Program.o ./Src/MNVIC_Program.su ./Src/MRCC_Program.cyclo ./Src/MRCC_Program.d ./Src/MRCC_Program.o ./Src/MRCC_Program.su ./Src/MSPI_Program.cyclo ./Src/MSPI_Program.d ./Src/MSPI_Program.o ./Src/MSPI_Program.su ./Src/MTIMER_Program.cyclo ./Src/MTIMER_Program.d ./Src/MTIMER_Program.o ./Src/MTIMER_Program.su ./Src/MUART_Program.cyclo ./Src/MUART_Program.d ./Src/MUART_Program.o ./Src/MUART_Program.su ./Src/UDS_Services..cyclo ./Src/UDS_Services..d ./Src/UDS_Services..o ./Src/UDS_Services..su ./Src/UDS_Services_Config.cyclo ./Src/UDS_Services_Config.d ./Src/UDS_Services_Config.o ./Src/UDS_Services_Config.su ./Src/Ultrasonic_Program.cyclo ./Src/Ultrasonic_Program.d ./Src/Ultrasonic_Program.o ./Src/Ultrasonic_Program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su

.PHONY: clean-Src

