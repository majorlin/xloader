/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: cmd.h
 * Created Date: Monday, March 30th 2020, 7:24:14 pm
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


#ifndef __CMD_H_
#define __CMD_H_
#include "common.h"

#define BUFFER_LEN           (1024)
#define CMD_TIMEOUT_CNT      (0x10)
typedef struct _cmd_t{
    uint8_t header[3];
    uint8_t id;
    uint32_t addr;
    uint8_t data[BUFFER_LEN];
    uint8_t checksum;
    uint8_t tail[3];
}cmd_t;
typedef int (*p_cmd_func)(cmd_t * cmd);
int read_command(char * buffer, int size);
int validate_command(cmd_t* cmd);
int pass_command(cmd_t* cmd);
int fail_command(cmd_t* cmd);
int ram_load_command(cmd_t* cmd);
int ram_jump_command(cmd_t* cmd);
int run_command(cmd_t* cmd);
#endif /* __CMD_H_ */