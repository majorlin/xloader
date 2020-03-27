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

int main(void){
    GPIO->PDDR = 0xff;
    while(1){
        for(int i=0; i< 0x1000; i++){
            GPIO->PTOR = 0x1;
            for(int j=0; j< 0x1000; j++){
                GPIO->PTOR = 0x2;
                for(int k=0; j< 0x1000; k++){
                    GPIO->PTOR = 0x4;
                    for(int l=0; l< 0x1000; l++){
                        GPIO->PTOR = 0x8;
                    }
                }
            }
        }
    }
    return 0;
}
