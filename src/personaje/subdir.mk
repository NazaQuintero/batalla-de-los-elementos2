################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/personaje/Agua.cpp \
../src/personaje/Aire.cpp \
../src/personaje/FabricaDePersonaje.cpp \
../src/personaje/Fuego.cpp \
../src/personaje/Personaje.cpp \
../src/personaje/Tierra.cpp 

OBJS += \
./src/personaje/Agua.o \
./src/personaje/Aire.o \
./src/personaje/FabricaDePersonaje.o \
./src/personaje/Fuego.o \
./src/personaje/Personaje.o \
./src/personaje/Tierra.o 

CPP_DEPS += \
./src/personaje/Agua.d \
./src/personaje/Aire.d \
./src/personaje/FabricaDePersonaje.d \
./src/personaje/Fuego.d \
./src/personaje/Personaje.d \
./src/personaje/Tierra.d 


# Each subdirectory must supply rules for building sources it contributes
src/personaje/%.o: ../src/personaje/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


