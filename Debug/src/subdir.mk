################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/command.cpp \
../src/main.cpp \
../src/motor_control.cpp 

OBJS += \
./src/command.o \
./src/main.o \
./src/motor_control.o 

CPP_DEPS += \
./src/command.d \
./src/main.d \
./src/motor_control.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"/home/vmware/workspace/PathFinder/headers" -I/usr/local/include -include/usr/local/include/wiringPi.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


