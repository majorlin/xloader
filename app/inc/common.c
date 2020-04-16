/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: common.h
 * Created Date: Tuesday, February 18th 2020, 1:36:01 pm
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

void uart_init(uint32_t baudrate) {
    UART->DIV = BOARD_CLOCK_HZ / baudrate - 1;
    UART->TXCTRL |= UART_TXCTRL_TXEN_MASK;
    UART->RXCTRL |= UART_RXCTRL_RXEN_MASK;
}
void uart_write(const char c) {
    while (UART->TXFIFO & 0x80000000)
        ;
    UART->TXFIFO = c;
}

char uart_read() {
    uint32_t rxdata;
    do {
        rxdata = UART->RXFIFO;
    } while(rxdata & 0x80000000);
    return rxdata;
}
void qspi_init(uint32_t baudrate) {
    QSPI->SCKDIV = BOARD_CLOCK_HZ / baudrate / 2 - 1;
}
void qspi_write(const char c) {
    while (QSPI->TXDATA & 0x80000000)
        ;
    QSPI->TXDATA = c;
}

char qspi_read() {
    uint32_t rxdata;
    do {
        rxdata = QSPI->RXDATA;
    } while(rxdata & 0x80000000);
    return rxdata;
}

