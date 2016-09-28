################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../A2.cpp \
../Person.cpp \
../PersonHashMap.cpp \
../PersonLinkedList.cpp 

OBJS += \
./A2.o \
./Person.o \
./PersonHashMap.o \
./PersonLinkedList.o 

CPP_DEPS += \
./A2.d \
./Person.d \
./PersonHashMap.d \
./PersonLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


