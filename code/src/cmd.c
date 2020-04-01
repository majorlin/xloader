/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: cmd.c
 * Created Date: Monday, March 30th 2020, 7:23:01 pm
 * Author: Major Lin
 * -----
 * Last Modified: Mon Mar 30 2020
 * Modified By: Major Lin
 * -----
 * 
 * -----
 * HISTORY:
 * Date      	By           	Comments
 * ----------	-------------	----------------------------------------------------------
 * ******************************************************************************
 */

#include "cmd.h"
#include "w25q_flash_drv.h"

static p_cmd_func cmd_table[] = {
    pass_command,
    fail_command,
    ram_load_command,
    ram_jump_command,
    flash_erase_command,
    flash_program_command,
    fpga_reboot_command,
    uart_baudrate_command,
    spi_baudrate_command
};
int read_command(char * buffer, int size){
    uint32_t timeout = 0;
    int index = 0;
    // wait for command 
    uint32_t rxdata;
    while((timeout < CMD_TIMEOUT_CNT) && (index < size)){
        rxdata = UART->RXFIFO;
        if(rxdata & 0x80000000){
            // no data received
            timeout++;
        } else {
            buffer[index++] = (char)(rxdata);
        }
    }
    return index;
}
int validate_command(cmd_t* cmd){
    // currently no checksum check
    if( cmd->header[0] != 'C' 
        || cmd->header[1] != 'M' 
        || cmd->header[2] != 'D' 
        || cmd->tail[0] != 'D' 
        || cmd->tail[1] != 'M' 
        || cmd->tail[2] != 'C'){
#ifdef DEBUG
            uart_write(cmd->header[0]);
            uart_write(cmd->header[1]);
            uart_write(cmd->header[2]);
            printf("addr=%x", cmd->addr);
            uart_write(cmd->id);
            uart_write(cmd->tail[0]);
            uart_write(cmd->tail[1]);
            uart_write(cmd->tail[2]);
#endif
            return -1;
    } else {
        return 0;
    }
}

int pass_command(cmd_t* cmd){
    return 0;
}
int fail_command(cmd_t* cmd){
    return 1;
}
int ram_load_command(cmd_t* cmd){
    uint8_t* des = (uint8_t*)cmd->addr;
    for(int i=0; i < BUFFER_LEN; i++){
        des[i] = cmd->data[i];
    }
    return 0;
}
uint32_t g_pc;
int ram_jump_command(cmd_t* cmd){
    g_pc = *(uint32_t*)cmd->data;
    asm("j g_pc");
    return 0;
}
int run_command(cmd_t* cmd){
    if(cmd->id < ARRAY_SIZE(cmd_table)){
        return cmd_table[cmd->id](cmd);
    } 
    return 1;
}
int flash_erase_command(cmd_t* cmd){
    flash_sector_erase(cmd->addr);
#ifdef DEBUG
    printf("E%x", cmd->addr);
#endif
}
int flash_program_command(cmd_t* cmd){
    for(int i = 0; i < BUFFER_LEN; i = i+256){
        flash_write_data(cmd->addr + i, cmd->data + i, 256);
#ifdef DEBUG
        printf("P%x", cmd->addr + i);
#endif
    }
    return 0;
}
int fpga_reboot_command(cmd_t* cmd){
    BOOT->SPI_ADDR = cmd->addr;
    BOOT->REBOOT = 1;
    BOOT->REBOOT = 1;
    BOOT->REBOOT = 1;
    BOOT->REBOOT = 1;
    BOOT->REBOOT = 0;
    printf("REBOOT");
    return 0;
}
int uart_baudrate_command(cmd_t* cmd){
    UART->DIV = BOARD_CLOCK_HZ / cmd->addr - 1;
    printf("UD=%d", cmd->addr);
    return 0;
}
int spi_baudrate_command(cmd_t* cmd){
    QSPI->SCKDIV = BOARD_CLOCK_HZ / cmd->addr / 2 - 1;
    printf("SD=%d", cmd->addr);
    return 0;
}
