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
avr_root.lss \

FLASH_IMAGE += \
avr_root.hex \

EEPROM_IMAGE += \
avr_root.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: avr_root.elf secondary-outputs

# Tool invocations
avr_root.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avr_root.map -mmcu=atmega32 -o"avr_root.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avr_root.lss: avr_root.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avr_root.elf  >"avr_root.lss"
	@echo 'Finished building: $@'
	@echo ' '

avr_root.hex: avr_root.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex avr_root.elf  "avr_root.hex"
	@echo 'Finished building: $@'
	@echo ' '

avr_root.eep: avr_root.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex avr_root.elf  "avr_root.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avr_root.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 avr_root.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) avr_root.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
