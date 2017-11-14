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
hd.lss \

FLASH_IMAGE += \
hd.hex \

EEPROM_IMAGE += \
hd.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: hd.elf secondary-outputs

# Tool invocations
hd.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,hd.map -mmcu=atmega16 -o "hd.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

hd.lss: hd.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S hd.elf  >"hd.lss"
	@echo 'Finished building: $@'
	@echo ' '

hd.hex: hd.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex hd.elf  "hd.hex"
	@echo 'Finished building: $@'
	@echo ' '

hd.eep: hd.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex hd.elf  "hd.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: hd.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 hd.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) hd.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
