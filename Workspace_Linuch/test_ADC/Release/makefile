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
test_ADC.lss \

FLASH_IMAGE += \
test_ADC.hex \

EEPROM_IMAGE += \
test_ADC.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: test_ADC.elf secondary-outputs

# Tool invocations
test_ADC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,test_ADC.map -mmcu=atmega8 -o"test_ADC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

test_ADC.lss: test_ADC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S test_ADC.elf  >"test_ADC.lss"
	@echo 'Finished building: $@'
	@echo ' '

test_ADC.hex: test_ADC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex test_ADC.elf  "test_ADC.hex"
	@echo 'Finished building: $@'
	@echo ' '

test_ADC.eep: test_ADC.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex test_ADC.elf  "test_ADC.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: test_ADC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 test_ADC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) test_ADC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
