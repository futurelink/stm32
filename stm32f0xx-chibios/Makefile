###################################################
# Project
###################################################

CHIP=STM32F0xx
PROJECT_NAME=stm32-chibios
TARGET_DIR = build
LIB = lib
CHIBIOS = chibios

# Linker script
################
LDSCRIPT = $(CHIBIOS)/ports/GCC/ARMCMx/STM32F0xx/ld/STM32F051x8.ld

# Project file build path (e.g. target/main)
PROJECT_FILE=$(TARGET_DIR)/$(PROJECT_NAME)

# Source files list
SRCS = \
	main.c \
	crt0.c \
	vectors.c

# Standard Peripheral Library build path
LIB_TARGET_DIR = $(TARGET_DIR)/$(LIB)

###################################################
# Toolchain
###################################################

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump
SIZE=arm-none-eabi-size

include chibios/chibios.mk

CFLAGS = -DCORTEX_USE_FPU=FALSE
CFLAGS += -Wall -Wextra -g3 -O2
CFLAGS += -mcpu=cortex-m0 -mthumb -mthumb-interwork -DTHUMB
CFLAGS += -ffunction-sections -fdata-sections -fno-common -fsigned-char  -fomit-frame-pointer -falign-functions=16 -ggdb
CFLAGS += -nostartfiles -Wl,-Map=$(PROJECT_FILE).map,--cref,--script=$(LDSCRIPT),--gc-sections
CFLAGS += $(CHIBIOS_INC)

###################################################
# Release flags:
# -g0 - no debug
# -Os - optimize for size
###################################################
CFLAGS_RELEASE = -g0 -Os

# Include OpenOCD specific vars
include openocd/openocd.mk

###################################################
# Common
###################################################

vpath %.c src chibios/ports/GCC/ARMCMx chibios/ports/GCC/ARMCMx/STM32F0xx
vpath %.a $(LIB_TARGET_DIR)

ROOT = $(shell pwd)

###################################################
# STM32F0Discovery
###################################################

OBJS = $(addprefix $(TARGET_DIR)/, $(SRCS:.c=.o))

###################################################

.PHONY: proj

all: lib$(CHIBIOS_LIB).a $(PROJECT_FILE).elf $(PROJECT_FILE).hex $(PROJECT_FILE).bin $(PROJECT_FILE).siz

lib$(CHIBIOS_LIB).a:
	cd $(CHIBIOS) && $(MAKE) all

$(PROJECT_FILE).elf: $(SRCS)
	@echo 'Building target: $@'
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIB_TARGET_DIR) -l$(CHIBIOS_LIB)
	$(OBJDUMP) -St $(PROJECT_FILE).elf >$(PROJECT_FILE).lst
	$(OBJDUMP) -x --syms $(PROJECT_FILE).elf > $(PROJECT_FILE).dmp
	@echo 'Finished building target: $@'
	@echo ' '

$(PROJECT_FILE).hex: $(PROJECT_FILE).elf
	@echo 'Invoking: Cross ARM GNU Create Hex'
	$(OBJCOPY) -O ihex $(PROJECT_FILE).elf $(PROJECT_FILE).hex
	@echo 'Finished building: $@'
	@echo ' '

$(PROJECT_FILE).bin: $(PROJECT_FILE).elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	$(OBJCOPY) -O binary $(PROJECT_FILE).elf $(PROJECT_FILE).bin
	@echo 'Finished building: $@'
	@echo ' '

$(PROJECT_FILE).siz: $(PROJECT_FILE).elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	$(SIZE) --format=berkeley $(PROJECT_FILE).elf
	@echo 'Finished building: $@'
	@echo ' '

flash: $(PROJECT_FILE).bin
	openocd -f $(OPENOCD_BOARD_DIR)/$(OPENOCD_CFG) -f $(OPENOCD_PROC_FILE) -c "stm_flash `pwd`/$(PROJECT_FILE).bin" -c shutdown

clean:
	rm -f $(PROJECT_FILE).elf
	rm -f $(PROJECT_FILE).hex
	rm -f $(PROJECT_FILE).bin
	rm -f $(PROJECT_FILE).map
	rm -f $(PROJECT_FILE).lst

	cd $(CHIBIOS) && $(MAKE) clean

cleanall:
	rm -rf $(TARGET_DIR)
