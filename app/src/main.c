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
#include "avts.h"
int main(void){
    uart_init(115200);
    setvbuf(stdin, NULL, _IONBF, 0);
    // uart_init(25000000);
    printf("************ AVTS FPGA SERVER ************\r\n");
    printf("* Build: %s %s\r\n", __DATE__, __TIME__);
    printf("******************************************\r\n");
    QSPI->SCKDIV = 1;
    avts_main();
    while(1){
        printf("Hello world working!\r\n");
    }
    return 0;
} 
