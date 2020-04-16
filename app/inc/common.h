/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: common.h
 * Created Date: Tuesday, February 18th 2020, 1:36:01 pm
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


#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "cpu.h"

#define BOARD_CLOCK_HZ      (100000000)
#define ARRAY_SIZE(x)       (sizeof(x) / sizeof(x[0]))

typedef void (*p_isr_fun)(void);

void uart_init(uint32_t baudrate);
void uart_write(const char c);
char uart_read();
int printf(const char *format, ...);

#endif /* __COMMON_H_ */
