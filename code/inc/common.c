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

void print(const char *s) {
    while (*s) {
        uart_write(*s++);
    }
}

static void printf_x(uint32_t hex) {
    char towrite;
    char digit;
    print("0x");
    int j;
    for (int i = sizeof(uint32_t) * 2; i > 0; i--) {
        j = i - 1;
        digit = ((hex & (0xF << (j * 4))) >> (j * 4));
        towrite = digit < 0xA ? ('0' + digit) : ('A' + (digit - 0xA));
        uart_write(towrite);
    }
}
static void printf_c(int c) {
    uart_write(c);
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
        uart_write(*(p++));
}
int puts(const char *p) {
    while (*p){
        uart_write(*(p++));
    }
    return 1;
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
                if (format[i] == 'x') {
                    printf_x(va_arg(ap,int));
                    break;
                }
            }
        } else
            printf_c(format[i]);

    va_end(ap);
}
void *memcpy(void *aa, const void *bb, long n)
{
	// printf("**MEMCPY**\n");
	char *a = aa;
	const char *b = bb;
	while (n--) *(a++) = *(b++);
	return aa;
}

char *strcpy(char* dst, const char* src)
{
	char *r = dst;

	while ((((uint32_t)dst | (uint32_t)src) & 3) != 0)
	{
		char c = *(src++);
		*(dst++) = c;
		if (!c) return r;
	}

	while (1)
	{
		uint32_t v = *(uint32_t*)src;

		if (__builtin_expect((((v) - 0x01010101UL) & ~(v) & 0x80808080UL), 0))
		{
			dst[0] = v & 0xff;
			if ((v & 0xff) == 0)
				return r;
			v = v >> 8;

			dst[1] = v & 0xff;
			if ((v & 0xff) == 0)
				return r;
			v = v >> 8;

			dst[2] = v & 0xff;
			if ((v & 0xff) == 0)
				return r;
			v = v >> 8;

			dst[3] = v & 0xff;
			return r;
		}

		*(uint32_t*)dst = v;
		src += 4;
		dst += 4;
	}
}

int strcmp(const char *s1, const char *s2)
{
	while ((((uint32_t)s1 | (uint32_t)s2) & 3) != 0)
	{
		char c1 = *(s1++);
		char c2 = *(s2++);

		if (c1 != c2)
			return c1 < c2 ? -1 : +1;
		else if (!c1)
			return 0;
	}

	while (1)
	{
		uint32_t v1 = *(uint32_t*)s1;
		uint32_t v2 = *(uint32_t*)s2;

		if (__builtin_expect(v1 != v2, 0))
		{
			char c1, c2;

			c1 = v1 & 0xff, c2 = v2 & 0xff;
			if (c1 != c2) return c1 < c2 ? -1 : +1;
			if (!c1) return 0;
			v1 = v1 >> 8, v2 = v2 >> 8;

			c1 = v1 & 0xff, c2 = v2 & 0xff;
			if (c1 != c2) return c1 < c2 ? -1 : +1;
			if (!c1) return 0;
			v1 = v1 >> 8, v2 = v2 >> 8;

			c1 = v1 & 0xff, c2 = v2 & 0xff;
			if (c1 != c2) return c1 < c2 ? -1 : +1;
			if (!c1) return 0;
			v1 = v1 >> 8, v2 = v2 >> 8;

			c1 = v1 & 0xff, c2 = v2 & 0xff;
			if (c1 != c2) return c1 < c2 ? -1 : +1;
			return 0;
		}

		if (__builtin_expect((((v1) - 0x01010101UL) & ~(v1) & 0x80808080UL), 0))
			return 0;

		s1 += 4;
		s2 += 4;
	}
}
void * memset (void *s, int c, unsigned n)
{
    /* Not optimized, but very portable */
    unsigned char *sp = (unsigned char *)s;

    if ((s != NULL) && (n > 0))
    {
        while (n--)
        {
            *sp++ = (unsigned char)c;
        }
    }
    return s;
}
