################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SteeringLock.c \
../src/engine.c \
../src/signals.c \
../src/stages.c \
../src/sysfun.c 

OBJS += \
./src/SteeringLock.o \
./src/engine.o \
./src/signals.o \
./src/stages.o \
./src/sysfun.o 

C_DEPS += \
./src/SteeringLock.d \
./src/engine.d \
./src/signals.d \
./src/stages.d \
./src/sysfun.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -DOPTIMIZE=1 -O0 -g3 -Wall -c -fmessage-length=0 -finline-functions -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


