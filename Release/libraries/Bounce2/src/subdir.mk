################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src\Bounce2.cpp 

LINK_OBJ += \
.\libraries\Bounce2\src\Bounce2.cpp.o 

CPP_DEPS += \
.\libraries\Bounce2\src\Bounce2.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Bounce2\src\Bounce2.cpp.o: C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src\Bounce2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


