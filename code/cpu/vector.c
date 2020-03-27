/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: vector.c
 * Created Date: Monday, February 24th 2020, 6:58:21 pm
 * Author: Major Lin
 * -----
 * Last Modified: Tue Feb 25 2020
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

static p_isr_fun g_vector_table[32] = {0};

void install_interrupt(p_isr_fun func, int irq_num){
    g_vector_table[irq_num] = func;
}

uint32_t *irq(uint32_t *regs, uint32_t irqs){
    for(int i = 0; i < 32; i++){
        if(irqs & (1 << i)){
            // execute ISR
            g_vector_table[i]();
        }
    }
    return regs;
}
