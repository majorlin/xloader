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


#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include "cpu.h"

#define BOARD_CLOCK_HZ      (50000000)

typedef void (*p_isr_fun)(void);

void install_interrupt(p_isr_fun func, int irq_num);
void sysinit(void);
void outchar(const char c);
char inchar();
void uart_init(uint32_t baudrate);
int printf(const char *format, ...);

#endif /* __COMMON_H_ */
