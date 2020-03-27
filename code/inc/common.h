/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: common.h
 * Created Date: Tuesday, February 18th 2020, 1:36:01 pm
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


#ifndef __COMMON_H_
#define __COMMON_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cpu.h"

typedef void (*p_isr_fun)(void);

void install_interrupt(p_isr_fun func, int irq_num);
void sysinit(void);

#endif /* __COMMON_H_ */