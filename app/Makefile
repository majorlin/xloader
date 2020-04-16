MKDIR=mkdir -p
BUILD_PATH = build

TOOLCHAIN ?= riscv-none-embed
AS = $(TOOLCHAIN)-as
LD = $(TOOLCHAIN)-ld
CC = $(TOOLCHAIN)-gcc
OC = $(TOOLCHAIN)-objcopy
OD = $(TOOLCHAIN)-objdump
OS = $(TOOLCHAIN)-size
GDB = $(TOOLCHAIN)-gdb
MKDIR=mkdir -p
BUILD_PATH = build

DEBUG ?= NODEBUG

INCLUDE += -I./inc
INCLUDE += -I./cpu
C_SRC += $(wildcard ./src/*.c)
C_SRC += $(wildcard ./cpu/*.c)
C_SRC += $(wildcard ./inc/*.c)
A_SRC += ./cpu/start.S

OBJS = $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(A_SRC))))
OBJS += $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(C_SRC))))

DEFS += -D$(DEBUG)

CFLAGS += -march=rv32im -W -Bstatic  -ffunction-sections -fmessage-length=0 -O1 -g
CFLAGS += -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables
CFLAGS += $(DEFS)
LDFLAGS += $(CFLAGS)
LDFLAGS += -specs=nano.specs
LDFLAGS +=  -T ./cpu/cpu.ld 
LDLIBS = -lstdc++
TARGET ?= $(BUILD_PATH)/firmware
FIRMWARE ?= $(TARGET).hex

all: $(TARGET).elf $(FIRMWARE)

clean:
	rm -rf testbench.vvp testbench.vcd $(BUILD_PATH)

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

$(FIRMWARE): $(TARGET).bin size
	python3 ../code/scripts/bin2hex.py $(TARGET).bin > $(TARGET).hex	
	python3 ./xloader.py
.PHONY: clean
