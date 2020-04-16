/*******************************************************************************
 * File:    avts.h
 * Date:    2018-6-28
 * Author:  Major Lin 
 * Email:   linmingjie@foxmail.com 
*******************************************************************************/

#ifndef __AVTS_H_
#define __AVTS_H_
#define MAX_CMD_LEN     (1024)
#include "common.h"

#define log_info    printf
#define log_error   printf
#define log_print   printf

#define COMMAND_TIMEOUT     (20)

typedef struct {
    char *  cmd;                    /* device name */
    uint8_t (*func)(char* para);    /* process function */
} DEVICE_CMD_TAB;

/* GPIO command table */
extern uint8_t gpio_init();
extern DEVICE_CMD_TAB GPIO_CMD_TAB[];

typedef struct {
    char *  device;                     /* device name */
    DEVICE_CMD_TAB* cmd_tab;            /* process function */
    uint8_t     (*init)(void);              /* init function */
} AVTS_DEVICE;


void avts_main();
void avts_process_cmd(char* cmd);
int avts_run_cmd(DEVICE_CMD_TAB* cmd_tab, char* cmd, char* para, char* device);
/*!
 * Convert string to int array
 * [1,2,3,4,5,6,7,8,9,]
 * Note:
 * 1. space is not allowed in string
 * 2. last ',' is necessary
 */
int *string_to_array(char* s, int* len);

#endif

