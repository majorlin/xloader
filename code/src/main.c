/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: main.c
 * Created Date: Tuesday, February 25th 2020, 4:55:24 pm
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

#include "common.h"
#include "w25q_flash_drv.h"
#include "cmd.h"
#define DELAY     (0x10)
int main(void){
    uart_init(BAUDRATE);
    QSPI->SCKDIV = 1;
    cmd_t* cmd;
    cmd = (cmd_t*)0x6c00;
#ifdef DEBUG
    cmd->addr = 0x1000;
    ram_jump_command(cmd);
#else
    if(BOOT->BOOT_PIN){
        cmd->addr = 0x80000;
        fpga_reboot_command(cmd);
    }
#endif
    GPIO->PDDR = 1;
    int cmd_size = sizeof(cmd_t);
    while(1) {
        if(cmd_size != read_command((char*)(cmd), cmd_size)){
            GPIO->PTOR = 1;
#ifdef DEBUG
            printf("TOUT");
#endif
            continue;
        }
        if(validate_command(cmd)){
            printf("FMTE");
            continue;
        }
        if(run_command(cmd)){
            printf("FAIL");
        } else {
            printf("DONE");
        }
    }
    return 0;
} 
