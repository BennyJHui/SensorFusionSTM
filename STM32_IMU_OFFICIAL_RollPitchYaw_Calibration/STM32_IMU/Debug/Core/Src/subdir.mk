################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AccGyrXSim.c \
../Core/Src/SMI_IMU.c \
../Core/Src/bmi3.c \
../Core/Src/bmi323.c \
../Core/Src/main.c \
../Core/Src/rtGetNaN.c \
../Core/Src/rt_nonfinite.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c 

OBJS += \
./Core/Src/AccGyrXSim.o \
./Core/Src/SMI_IMU.o \
./Core/Src/bmi3.o \
./Core/Src/bmi323.o \
./Core/Src/main.o \
./Core/Src/rtGetNaN.o \
./Core/Src/rt_nonfinite.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o 

C_DEPS += \
./Core/Src/AccGyrXSim.d \
./Core/Src/SMI_IMU.d \
./Core/Src/bmi3.d \
./Core/Src/bmi323.d \
./Core/Src/main.d \
./Core/Src/rtGetNaN.d \
./Core/Src/rt_nonfinite.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H753xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../smi330/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AccGyrXSim.cyclo ./Core/Src/AccGyrXSim.d ./Core/Src/AccGyrXSim.o ./Core/Src/AccGyrXSim.su ./Core/Src/SMI_IMU.cyclo ./Core/Src/SMI_IMU.d ./Core/Src/SMI_IMU.o ./Core/Src/SMI_IMU.su ./Core/Src/bmi3.cyclo ./Core/Src/bmi3.d ./Core/Src/bmi3.o ./Core/Src/bmi3.su ./Core/Src/bmi323.cyclo ./Core/Src/bmi323.d ./Core/Src/bmi323.o ./Core/Src/bmi323.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rtGetNaN.cyclo ./Core/Src/rtGetNaN.d ./Core/Src/rtGetNaN.o ./Core/Src/rtGetNaN.su ./Core/Src/rt_nonfinite.cyclo ./Core/Src/rt_nonfinite.d ./Core/Src/rt_nonfinite.o ./Core/Src/rt_nonfinite.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su

.PHONY: clean-Core-2f-Src

