################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
adc.lss \

FLASH_IMAGE += \
adc.hex \

EEPROM_IMAGE += \
adc.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: adc.elf secondary-outputs

# Tool invocations
adc.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,adc.map -Wl,-u,vfprintf -mmcu=atmega32 -o"adc.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

adc.lss: adc.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S adc.elf  >"adc.lss"
	@echo 'Finished building: $@'
	@echo ' '

adc.hex: adc.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex adc.elf  "adc.hex"
	@echo 'Finished building: $@'
	@echo ' '

adc.eep: adc.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex adc.elf  "adc.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: adc.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 adc.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) adc.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
