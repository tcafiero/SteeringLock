################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SteeringLock.c \
../src/SteeringLock_wrap.c \
../src/engine.c 

O_SRCS += \
../src/SteeringLock.o \
../src/SteeringLock_wrap.o \
../src/engine.o 

OBJS += \
./src/SteeringLock.o \
./src/SteeringLock_wrap.o \
./src/engine.o 

C_DEPS += \
./src/SteeringLock.d \
./src/SteeringLock_wrap.d \
./src/engine.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -finline-functions -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


