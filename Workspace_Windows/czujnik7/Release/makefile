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
czujnik7.lss \

FLASH_IMAGE += \
czujnik7.hex \

EEPROM_IMAGE += \
czujnik7.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: czujnik7.elf secondary-outputs

# Tool invocations
czujnik7.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,czujnik7.map -mmcu=atmega16 -o "czujnik7.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

czujnik7.lss: czujnik7.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S czujnik7.elf  >"czujnik7.lss"
	@echo 'Finished building: $@'
	@echo ' '

czujnik7.hex: czujnik7.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex czujnik7.elf  "czujnik7.hex"
	@echo 'Finished building: $@'
	@echo ' '

czujnik7.eep: czujnik7.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex czujnik7.elf  "czujnik7.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: czujnik7.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 czujnik7.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) czujnik7.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
