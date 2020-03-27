MKDIR=mkdir -p
BUILD_PATH = build
RTL_SRC += ./rtl/chip.v
RTL_SRC += ./rtl/gpio.v
RTL_SRC += ./rtl/picorv32.v
RTL_SRC += ./rtl/sram_byte_en_model.v
RTL_SRC += ./testbench/testbench.v
RTL_SRC += ./testbench/uart_vip.v
FIRMWARE ?= ./code/build/firmware.hex

# ---- ROM SIM ----
all: $(BUILD_PATH)/testbench.vvp $(FIRMWARE)
	vvp -N $< +firmware=rom.hex

$(BUILD_PATH)/testbench.vvp: $(RTL_SRC)
	@echo "Build verilog files"
	$(MKDIR) $(BUILD_PATH)
	iverilog -s testbench -o $@ $^ 

$(FIRMWARE):
	cd ./code && make

clean:
	rm -rf testbench.vvp testbench.vcd $(BUILD_PATH)
	cd code && make clean

.PHONY: clean
