/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: cmd.c
 * Created Date: Monday, March 30th 2020, 7:23:01 pm
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

#include "cmd.h"

static p_cmd_func cmd_table[] = {
    pass_command,
    fail_command,
    ram_load_command,
    ram_jump_command,
};
int read_command(char * buffer, int size){
    uint32_t timeout = 0;
    int index = 0;
    // wait for command 
    uint32_t rxdata;
    while((timeout < CMD_TIMEOUT_CNT) && (index < size)){
        rxdata = UART->RXFIFO;
        if(rxdata & 0x80000000){
            // no data received
            timeout++;
        } else {
            buffer[index++] = (char)(rxdata);
        }
    }
    return size;
}
int validate_command(cmd_t* cmd){
    // currently no checksum check
    if( cmd->header[0] != 'C' 
        || cmd->header[1] != 'M' 
        || cmd->header[2] != 'D' 
        || cmd->tail[0] != 'D' 
        || cmd->tail[1] != 'M' 
        || cmd->tail[2] != 'C'){
            return -1;
    } else {
        return 0;
    }
}

int pass_command(cmd_t* cmd){
    return 0;
}
int fail_command(cmd_t* cmd){
    return 1;
}
int ram_load_command(cmd_t* cmd){
    uint8_t* des = (uint8_t*)cmd->addr;
    for(int i=0; i < BUFFER_LEN; i++){
        des[i] = cmd->data[i];
    }
    return 0;
}
uint32_t g_pc;
int ram_jump_command(cmd_t* cmd){
    g_pc = *(uint32_t*)cmd->data;
    asm("j g_pc");
    return 0;
}
int run_command(cmd_t* cmd){
    if(cmd->id < ARRAY_SIZE(cmd_table)){
        return cmd_table[cmd->id](cmd);
    } 
    return 1;
}