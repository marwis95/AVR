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
Test_AVR.lss \

FLASH_IMAGE += \
Test_AVR.hex \

EEPROM_IMAGE += \
Test_AVR.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Test_AVR.elf secondary-outputs

# Tool invocations
Test_AVR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Test_AVR.map -mmcu=atmega32 -o "Test_AVR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Test_AVR.lss: Test_AVR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Test_AVR.elf  >"Test_AVR.lss"
	@echo 'Finished building: $@'
	@echo ' '

Test_AVR.hex: Test_AVR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Test_AVR.elf  "Test_AVR.hex"
	@echo 'Finished building: $@'
	@echo ' '

Test_AVR.eep: Test_AVR.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Test_AVR.elf  "Test_AVR.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Test_AVR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Test_AVR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Test_AVR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
