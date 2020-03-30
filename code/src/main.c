/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: main.c
 * Created Date: Tuesday, February 25th 2020, 4:55:24 pm
 * Author: Major Lin
 * -----
 * Last Modified: Sat Mar 28 2020
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
#define DELAY     (0x10)
int main(void){
    uart_init(BAUDRATE);
    QSPI->SCKDIV = 3;
    printf("Build: %s %s\r\n", __DATE__, __TIME__);
    printf("DEVICE ID: %x\r\n", flash_read_id());
    uint32_t read_back[64] = {0};
    // flash_sector_erase(0x2000);
    // flash_write_data(0x2100, "LINMINGJIE", 11);
    for(int addr = 0; addr < 1*1024; addr += 256){
        flash_read_data(addr, (uint8_t*)read_back, 256);
        for (int i = 0; i < 64; i++){
            if(0 == i % 8) {
                printf("\r\n [%x]: ", i+addr);
            }
            printf("%x ", read_back[i]);
        }
    }
    while(1){
        uart_write(uart_read());
    }
    return 0;
} 
