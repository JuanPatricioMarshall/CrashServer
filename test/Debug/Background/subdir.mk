################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Background/Background.cpp \
../Background/BackgroundObject.cpp \
../Background/Island.cpp 

OBJS += \
./Background/Background.o \
./Background/BackgroundObject.o \
./Background/Island.o 

CPP_DEPS += \
./Background/Background.d \
./Background/BackgroundObject.d \
./Background/Island.d 


# Each subdirectory must supply rules for building sources it contributes
Background/%.o: ../Background/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -O0 -g3 -Wall -c -fmessage-length=0  -lSDL2 -lSDL2_image -lSDL_ttf  -std=c++11  -lpthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


