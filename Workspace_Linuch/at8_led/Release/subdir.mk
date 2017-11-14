################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HD44780.c \
../ds18b20.c \
../ds18b20_2.c \
../ds18b20_3.c \
../ds18b20_4.c \
../main.c 

OBJS += \
./HD44780.o \
./ds18b20.o \
./ds18b20_2.o \
./ds18b20_3.o \
./ds18b20_4.o \
./main.o 

C_DEPS += \
./HD44780.d \
./ds18b20.d \
./ds18b20_2.d \
./ds18b20_3.d \
./ds18b20_4.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


