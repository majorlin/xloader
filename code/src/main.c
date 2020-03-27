/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: main.c
 * Created Date: Tuesday, February 25th 2020, 4:55:24 pm
 * Author: Major Lin
 * -----
 * Last Modified: Wed Feb 26 2020
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
    UART->DIV = 3;
    UART->TXCTRL |= UART_TXEN;
    for(int i = 0; i < 100; i++){
    while (UART->TXFIFO & 0x80000000);
      UART->TXFIFO = 'L';
    }
    return 0;
}
