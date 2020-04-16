MKDIR=mkdir -p
BUILD_PATH = build
RTL_SRC += $(wildcard ./rtl/*.v)
RTL_SRC += $(wildcard ./testbench/*.v)

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

INCLUDE += -I./code//inc
INCLUDE += -I./code/cpu
C_SRC += $(wildcard ./code/src/*.c)
C_SRC += $(wildcard ./code/cpu/*.c)
C_SRC += $(wildcard ./code/inc/*.c)
A_SRC += ./code/cpu/start.S

OBJS = $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(A_SRC))))
OBJS += $(addprefix $(BUILD_PATH)/,$(addsuffix .o,$(basename $(C_SRC))))

DEFS += -D$(DEBUG)

CFLAGS += -march=rv32im -W -Bstatic  -ffunction-sections -fmessage-length=0 -O1 -g -nostdlib
CFLAGS += -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables
CFLAGS += $(DEFS)
LDFLAGS += $(CFLAGS)
# LDFLAGS += -specs=nano.specs
LDFLAGS +=  -T ./code/cpu/cpu.ld 
LDLIBS = -lstdc++
TARGET ?= $(BUILD_PATH)/firmware
FIRMWARE ?= $(TARGET).hex

# ---- ROM SIM ----
all: $(BUILD_PATH)/testbench.vvp $(FIRMWARE)
	vvp -N $< +firmware=rom.hex

$(BUILD_PATH)/testbench.vvp: $(RTL_SRC)
	@echo "Build verilog files"
	$(MKDIR) $(BUILD_PATH)
	iverilog -y $(ISE_SRC)/unisims -y $(ISE_SRC) -y $(ISE_SRC)/simprims -s testbench -o $@ $^ 

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
	python3 ./code/scripts/bin2hex.py $(TARGET).bin > $(TARGET).hex	
	cp $(TARGET).hex .
.PHONY: clean
