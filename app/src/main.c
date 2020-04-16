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
#define DELAY     (0x10)
int main(void){
    // uart_init(115200);
    uart_init(25000000);
    QSPI->SCKDIV = 1;
    while(1){
        printf("Hello world!\r\n");
    }
    return 0;
} 
