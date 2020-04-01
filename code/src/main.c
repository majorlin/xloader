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
    printf("Xloader build: %s %s\r\n", __DATE__, __TIME__);
    cmd_t cmd;
    if(BOOT->BOOT_PIN == 0){
        cmd.addr = 0x80000;
        fpga_reboot_command(&cmd);
    }
    int cmd_size = sizeof(cmd);
    while(1) {
        if(cmd_size != read_command((char*)(&cmd), cmd_size)){
            printf("TIMEOUT");
            continue;
        }
        if(validate_command(&cmd)){
            printf("FORMATERR");
            continue;
        }
        if(run_command(&cmd)){
            printf("FAIL");
        } else {
            printf("OK");
        }
    }
    return 0;
} 
