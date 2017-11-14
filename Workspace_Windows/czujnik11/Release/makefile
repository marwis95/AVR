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
czujnik11.lss \

FLASH_IMAGE += \
czujnik11.hex \

EEPROM_IMAGE += \
czujnik11.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: czujnik11.elf secondary-outputs

# Tool invocations
czujnik11.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,czujnik11.map -mmcu=atmega16 -o "czujnik11.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

czujnik11.lss: czujnik11.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S czujnik11.elf  >"czujnik11.lss"
	@echo 'Finished building: $@'
	@echo ' '

czujnik11.hex: czujnik11.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex czujnik11.elf  "czujnik11.hex"
	@echo 'Finished building: $@'
	@echo ' '

czujnik11.eep: czujnik11.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex czujnik11.elf  "czujnik11.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: czujnik11.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 czujnik11.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) czujnik11.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
