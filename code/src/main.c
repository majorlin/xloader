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
    QSPI->SCKDIV = 3;
    printf("Build: %s %s\r\n", __DATE__, __TIME__);
    // printf("DEVICE ID: %x\r\n", flash_read_id());
	uint32_t read_back[64] = {0};
    for (int addr = 0; addr < 2*1024; addr=addr + 256){
        flash_read_data(0x81000 + addr, (uint8_t*)read_back, 256);
        for (int i = 0; i < 64; i++){
            if(0 == i % 8) {
                printf("\r\n [%x]: ", i + addr);
            }
            printf("%x ", read_back[i]);
        }
    }
    cmd_t cmd;
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
