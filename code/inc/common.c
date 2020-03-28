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

void outchar(const char c) {
    while (UART->TXFIFO & 0x80000000)
        ;
    UART->TXFIFO = c;
}

char inchar() {
    uint32_t rxdata;
    do {
        rxdata = UART->RXFIFO;
    } while(rxdata & 0x80000000);
    return rxdata;
}

void print(const char *s) {
    while (*s) {
        outchar(*s++);
    }
}

void print_hex(uint32_t hex) {
    char towrite;
    char digit;
    print("0x");
    int j;
    for (int i = sizeof(uint32_t) * 2; i > 0; i--) {
        j = i - 1;
        digit = ((hex & (0xF << (j * 4))) >> (j * 4));
        towrite = digit < 0xA ? ('0' + digit) : ('A' + (digit - 0xA));
        outchar(towrite);
    }
}
void uart_init(uint32_t baudrate) {
    UART->DIV = BOARD_CLOCK_HZ / baudrate - 1;
    UART->TXCTRL |= UART_TXCTRL_TXEN_MASK;
    UART->RXCTRL |= UART_RXCTRL_RXEN_MASK;
}
static void printf_c(int c) {
    outchar(c);
}
static void printf_d(int val) {
	char buffer[32];
	char *p = buffer;
	if (val < 0) {
		printf_c('-');
		val = -val;
	}
	while (val || p == buffer) {
		*(p++) = '0' + val % 10;
		val = val / 10;
	}
	while (p != buffer)
		printf_c(*(--p));
}
static void printf_s(char *p) {
	while (*p)
		outchar(*(p++));
}
int printf(const char *format, ...) {
	int i;
	va_list ap;

	va_start(ap, format);

	for (i = 0; format[i]; i++)
		if (format[i] == '%') {
			while (format[++i]) {
				if (format[i] == 'c') {
					printf_c(va_arg(ap,int));
					break;
				}
				if (format[i] == 's') {
					printf_s(va_arg(ap,char*));
					break;
				}
				if (format[i] == 'd') {
					printf_d(va_arg(ap,int));
					break;
				}
			}
		} else
			printf_c(format[i]);

	va_end(ap);
}
