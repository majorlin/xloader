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

#include "common.h"

void outchar(const char c){
    while (UART->TXFIFO & 0x80000000);
    UART->TXFIFO = c;
}

void print(const char *s){
    while(*s){
        outchar(*s++);
    } 
}

void print_hex(uint32_t hex)
{
  char towrite;
  char digit;
  print("0x");
  int j;
  for (int i = sizeof(uint32_t) * 2 ; i > 0; i--) {
    j = i - 1;
    digit = ((hex & (0xF << (j*4))) >> (j*4));
    towrite = digit < 0xA ? ('0' + digit) : ('A' +  (digit - 0xA));
    outchar(towrite);
  }
}
