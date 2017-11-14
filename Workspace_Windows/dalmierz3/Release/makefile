################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include hd44780/subdir.mk
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
dalmierz3.lss \

FLASH_IMAGE += \
dalmierz3.hex \

EEPROM_IMAGE += \
dalmierz3.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: dalmierz3.elf secondary-outputs

# Tool invocations
dalmierz3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,dalmierz3.map -mmcu=atmega16 -o "dalmierz3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

dalmierz3.lss: dalmierz3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S dalmierz3.elf  >"dalmierz3.lss"
	@echo 'Finished building: $@'
	@echo ' '

dalmierz3.hex: dalmierz3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex dalmierz3.elf  "dalmierz3.hex"
	@echo 'Finished building: $@'
	@echo ' '

dalmierz3.eep: dalmierz3.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex dalmierz3.elf  "dalmierz3.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: dalmierz3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 dalmierz3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) dalmierz3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
