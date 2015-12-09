################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../l293d/l293d.cpp 

OBJS += \
./l293d/l293d.o 

CPP_DEPS += \
./l293d/l293d.d 


# Each subdirectory must supply rules for building sources it contributes
l293d/%.o: ../l293d/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -I"/home/vmware/workspace/PathFinder/headers" -I/usr/local/include -include/usr/local/include/wiringPi.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


