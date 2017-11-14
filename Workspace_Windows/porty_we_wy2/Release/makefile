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
porty_we_wy2.lss \

FLASH_IMAGE += \
porty_we_wy2.hex \

EEPROM_IMAGE += \
porty_we_wy2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: porty_we_wy2.elf secondary-outputs

# Tool invocations
porty_we_wy2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,porty_we_wy2.map -mmcu=atmega16 -o "porty_we_wy2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

porty_we_wy2.lss: porty_we_wy2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S porty_we_wy2.elf  >"porty_we_wy2.lss"
	@echo 'Finished building: $@'
	@echo ' '

porty_we_wy2.hex: porty_we_wy2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex porty_we_wy2.elf  "porty_we_wy2.hex"
	@echo 'Finished building: $@'
	@echo ' '

porty_we_wy2.eep: porty_we_wy2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex porty_we_wy2.elf  "porty_we_wy2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: porty_we_wy2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 porty_we_wy2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) porty_we_wy2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
