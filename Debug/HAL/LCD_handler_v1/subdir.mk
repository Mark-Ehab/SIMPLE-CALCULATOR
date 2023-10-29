################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_handler_v1/LCD_Functions.c \
../HAL/LCD_handler_v1/LCD_prg.c 

OBJS += \
./HAL/LCD_handler_v1/LCD_Functions.o \
./HAL/LCD_handler_v1/LCD_prg.o 

C_DEPS += \
./HAL/LCD_handler_v1/LCD_Functions.d \
./HAL/LCD_handler_v1/LCD_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_handler_v1/%.o: ../HAL/LCD_handler_v1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


