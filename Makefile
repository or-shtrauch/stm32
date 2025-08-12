include log.mk

PROJECT_NAME    := stm_fw
PROJECT_VERSION ?= $(shell cat version)

CROSS_COMPILE ?= arm-none-eabi-
CC            := $(shell which $(CROSS_COMPILE)gcc)
LD            := $(shell which $(CROSS_COMPILE)ld)
AR            := $(shell which $(CROSS_COMPILE)ar)
OBJCOPY       := $(shell which $(CROSS_COMPILE)objcopy)
OBJDUMP       := $(shell which $(CROSS_COMPILE)objdump)

CCACHE   ?= $(strip $(shell which ccache))
ST_FLASH ?= $(strip $(shell which st-flash))

CC_VERSION ?= $(shell $(CC) -dumpversion)

ifeq ($(CC),)
    $(call error,missing ARM compiler $(CROSS_COMPILE)gcc)
endif

ifneq ($(CCACHE),)
    CC := $(CCACHE) $(CC)
endif

ifeq ($(V),1)
	AT =
else
	AT = @
endif

define command
	$(AT)$1
endef

SRC_DIR     ?= src
BUILD_DIR   ?= build
OBJ_DIR     ?= $(BUILD_DIR)/obj
TARGET_NAME ?= $(BUILD_DIR)/$(PROJECT_NAME)_$(PROJECT_VERSION)

FINAL_TARGET := $(PROJECT_NAME).bin

SRC_FILES ?= $(wildcard $(SRC_DIR)/*.c)
LD_SCRIPT ?= linker/stm32.ld

C_SRCS ?= $(filter %.c, $(SRC_FILES))
C_OBJS ?= $(patsubst %.c, $(OBJ_DIR)/%.o, $(C_SRCS))

CFLAGS ?= -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -g -Os -Wall -Wextra -Werror -Wno-unused-parameter
CFLAGS += -MD -MP -std=c99 -fdiagnostics-color

LDFLAGS      ?= -T$(LD_SCRIPT) -nostdlib -Wl,--gc-sections
INCLUDE_DIRS ?= -I./include

FLASH_MEM_ADDR ?= 0x08000000

.DEFAULT_GOAL ?= all

all: print-info $(FINAL_TARGET)
	$(call print,Build successful.)

.PHONY: flash print-info setup_dir

print-info:
	@printf "$(B_CYAN)####################################################################$(RESET)\n"
	$(call print-var,PROJECT_NAME,$(PROJECT_NAME))
	$(call print-var,PROJECT_VERSION,$(PROJECT_VERSION))
	$(call print-var,TARGET,$(TARGET_NAME).bin)
	$(call print-var,CC_VERSION,$(CC_VERSION))
	$(call print-var,CC,$(CC))
	$(call print-var,LD,$(LD))
	$(call print-var,AR,$(AR))
	$(call print-var,OBJCOPY,$(OBJCOPY))
	$(call print-var,OBJDUMP,$(OBJDUMP))
	$(call print-var,INCLUDE_DIRS,$(INCLUDE_DIRS))
	$(call print-var,FLASH_MEM_ADDR,$(FLASH_MEM_ADDR))
	$(call print-var,LDFLAGS,$(LDFLAGS))
	$(call print-var,CFLAGS,$(CFLAGS))
	@printf "$(B_CYAN)####################################################################$(RESET)\n"

flash: $(TARGET_NAME).bin
	ifeq ($(ST_FLASH),)
		$(call error,missing stlink)
	endif

	$(call log,Flashing $(PROJECT_NAME)...)
	$(call command,$(ST_FLASH) --reset write $< $(FLASH_MEM_ADDR))
	$(call log,Flash successful.)

$(FINAL_TARGET): $(TARGET_NAME).bin
	$(call log,Linking firmware binary...)
	$(call command,ln -s $(TARGET_NAME).bin $(FINAL_TARGET))

$(TARGET_NAME).bin: $(TARGET_NAME)
	$(call log,Creating firmware binary...)
	$(call command,$(OBJCOPY) -O binary $< $@)

$(TARGET_NAME): $(C_OBJS)
	$(call log,Compiling and linking...)
	$(call command,$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(LDFLAGS) -o $@ $^)

$(OBJ_DIR)/%.o: %.c setup_dir
	$(call log, Compiling: $<)
	$(call command,$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@)

setup_dir:
	$(call log,Creating build directory...)
	$(call command,mkdir -p $(OBJ_DIR)/src)


.PHONY: clean
clean:
	$(call log,Cleaning build directory...)
	$(call command,rm -rf $(BUILD_DIR))
	$(call command,rm -rf $(FINAL_TARGET))