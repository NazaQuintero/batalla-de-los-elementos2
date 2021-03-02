################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/casillero/Camino.cpp \
../src/casillero/Casillero.cpp \
../src/casillero/FabricaDeCasillero.cpp \
../src/casillero/Lago.cpp \
../src/casillero/Montana.cpp \
../src/casillero/Precipicio.cpp \
../src/casillero/Vacio.cpp \
../src/casillero/Volcan.cpp 

OBJS += \
./src/casillero/Camino.o \
./src/casillero/Casillero.o \
./src/casillero/FabricaDeCasillero.o \
./src/casillero/Lago.o \
./src/casillero/Montana.o \
./src/casillero/Precipicio.o \
./src/casillero/Vacio.o \
./src/casillero/Volcan.o 

CPP_DEPS += \
./src/casillero/Camino.d \
./src/casillero/Casillero.d \
./src/casillero/FabricaDeCasillero.d \
./src/casillero/Lago.d \
./src/casillero/Montana.d \
./src/casillero/Precipicio.d \
./src/casillero/Vacio.d \
./src/casillero/Volcan.d 


# Each subdirectory must supply rules for building sources it contributes
src/casillero/%.o: ../src/casillero/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


