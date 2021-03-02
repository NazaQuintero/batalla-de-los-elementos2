################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/tablero/Tablero.cpp 

OBJS += \
./src/tablero/Tablero.o 

CPP_DEPS += \
./src/tablero/Tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/tablero/%.o: ../src/tablero/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


