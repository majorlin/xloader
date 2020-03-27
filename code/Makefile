# 
# Copyright (c) 2020 NXP
# ******************************************************************************
# File: Makefile
# Created Date: Tuesday, February 25th 2020, 4:56:45 pm
# Author: Major Lin
# -----
# Last Modified: 
# Modified By: 
# -----
# 
# -----
# HISTORY:
# Date      	By           	Comments
# ----------	-------------	----------------------------------------------------------
# ******************************************************************************
# 

TOOLCHAIN ?= riscv32-unknown-elf
AS = $(TOOLCHAIN)-as
LD = $(TOOLCHAIN)-ld
CC = $(TOOLCHAIN)-gcc
OC = $(TOOLCHAIN)-objcopy
OD = $(TOOLCHAIN)-objdump
OS = $(TOOLCHAIN)-size
GDB = $(TOOLCHAIN)-gdb
MKDIR=mkdir -p
BUILD_PATH = build

INCLUDE += -I./inc
INCLUDE += -I./cpu
C_SRC += $(wildcard ./src/*.c)
C_SRC += $(wildcard ./cpu/*.c)
A_SRC += ./cpu/start.S

OBJS = $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(A_SRC))))
OBJS += $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(C_SRC))))

CFLAGS += -march=rv32im -W -Bstatic  -ffunction-sections -fmessage-length=0 -O1 -g -nostdlib
CFLAGS += -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables
LDFLAGS += $(CFLAGS)
# LDFLAGS += -specs=nano.specs
LDFLAGS +=  -T ./cpu/cpu.ld 
LDLIBS = -lstdc++
TARGET ?= $(BUILD_PATH)/firmware

# ---- ROM SIM ----
all: ${TARGET}.hex

$(TARGET).elf: $(OBJS) 
	@echo	
	@echo Linking: $@
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(OD) -h -S $(TARGET).elf > $(TARGET).lst

$(TARGET).bin: $(TARGET).elf 
	$(OC) -O binary $(TARGET).elf $(TARGET).bin

size: $(TARGET).elf
	@echo
	@echo == Object size ==
	@$(OS) --format=berkeley $<
	$(OC) -O binary $< $(TARGET).bin

$(BUILD_PATH)/%.o: %.c
	@echo
	@echo Compiling: $<
	@$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(DEFS) $(INCLUDE) -I. $< -o $@

$(BUILD_PATH)/%.o: %.S
	@echo
	@echo Assembling: $<
	@$(MKDIR) -p $(dir $@)
	$(CC) -x assembler-with-cpp -c $(CFLAGS) $< -o $@	

$(TARGET).hex: $(TARGET).bin size
	python3 ./scripts/bin2hex.py $(TARGET).bin > $(TARGET).hex	

clean:
	rm -rf $(BUILD_PATH)

.PHONY: clean
