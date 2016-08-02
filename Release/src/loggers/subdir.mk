################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/loggers/consoleLogger.cpp \
../src/loggers/fileLogger.cpp 

OBJS += \
./src/loggers/consoleLogger.o \
./src/loggers/fileLogger.o 

CPP_DEPS += \
./src/loggers/consoleLogger.d \
./src/loggers/fileLogger.d 


# Each subdirectory must supply rules for building sources it contributes
src/loggers/%.o: ../src/loggers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


