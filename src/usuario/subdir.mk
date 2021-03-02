################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/usuario/Usuario.cpp 

OBJS += \
./src/usuario/Usuario.o 

CPP_DEPS += \
./src/usuario/Usuario.d 


# Each subdirectory must supply rules for building sources it contributes
src/usuario/%.o: ../src/usuario/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


