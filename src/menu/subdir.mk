################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/menu/Menu.cpp 

OBJS += \
./src/menu/Menu.o 

CPP_DEPS += \
./src/menu/Menu.d 


# Each subdirectory must supply rules for building sources it contributes
src/menu/%.o: ../src/menu/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


