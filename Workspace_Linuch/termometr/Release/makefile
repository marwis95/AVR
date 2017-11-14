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
termometr.lss \

FLASH_IMAGE += \
termometr.hex \

EEPROM_IMAGE += \
termometr.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: termometr.elf secondary-outputs

# Tool invocations
termometr.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,termometr.map -mmcu=atmega32 -o"termometr.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

termometr.lss: termometr.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S termometr.elf  >"termometr.lss"
	@echo 'Finished building: $@'
	@echo ' '

termometr.hex: termometr.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex termometr.elf  "termometr.hex"
	@echo 'Finished building: $@'
	@echo ' '

termometr.eep: termometr.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex termometr.elf  "termometr.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: termometr.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 termometr.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) termometr.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
