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
Obs³uga_przycisków.lss \

FLASH_IMAGE += \
Obs³uga_przycisków.hex \

EEPROM_IMAGE += \
Obs³uga_przycisków.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Obs³uga_przycisków.elf secondary-outputs

# Tool invocations
Obs³uga_przycisków.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Obs³uga_przycisków.map -mmcu=atmega16 -o "Obs³uga_przycisków.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Obs³uga_przycisków.lss: Obs³uga_przycisków.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Obs³uga_przycisków.elf  >"Obs³uga_przycisków.lss"
	@echo 'Finished building: $@'
	@echo ' '

Obs³uga_przycisków.hex: Obs³uga_przycisków.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Obs³uga_przycisków.elf  "Obs³uga_przycisków.hex"
	@echo 'Finished building: $@'
	@echo ' '

Obs³uga_przycisków.eep: Obs³uga_przycisków.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Obs³uga_przycisków.elf  "Obs³uga_przycisków.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Obs³uga_przycisków.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Obs³uga_przycisków.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Obs³uga_przycisków.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
