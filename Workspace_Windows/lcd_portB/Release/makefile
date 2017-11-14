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
lcd_portB.lss \

FLASH_IMAGE += \
lcd_portB.hex \

EEPROM_IMAGE += \
lcd_portB.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: lcd_portB.elf secondary-outputs

# Tool invocations
lcd_portB.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lcd_portB.map -mmcu=atmega16 -o "lcd_portB.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lcd_portB.lss: lcd_portB.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lcd_portB.elf  >"lcd_portB.lss"
	@echo 'Finished building: $@'
	@echo ' '

lcd_portB.hex: lcd_portB.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex lcd_portB.elf  "lcd_portB.hex"
	@echo 'Finished building: $@'
	@echo ' '

lcd_portB.eep: lcd_portB.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lcd_portB.elf  "lcd_portB.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lcd_portB.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 lcd_portB.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) lcd_portB.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
