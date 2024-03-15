################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPTIM\ _program.c \
../src/HIR_program.c \
../src/HR2RDAC_program.c \
../src/HTFT_program.c \
../src/MEXTI_program.c \
../src/MGPIO_program.c \
../src/MNVIC_program.c \
../src/MRCC_program.c \
../src/MSPI_program.c \
../src/MSYSTICK_program.c \
../src/OS_prg.c \
../src/TIMER2_program.c \
../src/main.c 

OBJS += \
./src/GPTIM\ _program.o \
./src/HIR_program.o \
./src/HR2RDAC_program.o \
./src/HTFT_program.o \
./src/MEXTI_program.o \
./src/MGPIO_program.o \
./src/MNVIC_program.o \
./src/MRCC_program.o \
./src/MSPI_program.o \
./src/MSYSTICK_program.o \
./src/OS_prg.o \
./src/TIMER2_program.o \
./src/main.o 

C_DEPS += \
./src/GPTIM\ _program.d \
./src/HIR_program.d \
./src/HR2RDAC_program.d \
./src/HTFT_program.d \
./src/MEXTI_program.d \
./src/MGPIO_program.d \
./src/MNVIC_program.d \
./src/MRCC_program.d \
./src/MSPI_program.d \
./src/MSYSTICK_program.d \
./src/OS_prg.d \
./src/TIMER2_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/GPTIM\ _program.o: ../src/GPTIM\ _program.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"src/GPTIM _program.d" -MT"src/GPTIM\ _program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


