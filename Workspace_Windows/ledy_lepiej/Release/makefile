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
lcdfun.lss \

FLASH_IMAGE += \
lcdfun.hex \

EEPROM_IMAGE += \
lcdfun.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: lcdfun.elf secondary-outputs

# Tool invocations
lcdfun.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lcdfun.map -mmcu=atmega16 -o "lcdfun.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lcdfun.lss: lcdfun.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lcdfun.elf  >"lcdfun.lss"
	@echo 'Finished building: $@'
	@echo ' '

lcdfun.hex: lcdfun.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex lcdfun.elf  "lcdfun.hex"
	@echo 'Finished building: $@'
	@echo ' '

lcdfun.eep: lcdfun.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lcdfun.elf  "lcdfun.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lcdfun.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 lcdfun.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) lcdfun.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
