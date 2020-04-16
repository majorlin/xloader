/*******************************************************************************
 * File:    avts.c
 * Date:    2018-6-28
 * Author:  Major Lin 
 * Email:   linmingjie@foxmail.com 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avts.h"

AVTS_DEVICE DEIVCE_TAB[] = {
    // {"gpio",    GPIO_CMD_TAB,       gpio_init},
    {"",        NULL,               NULL}   /* keep this at bottom */
};

void avts_main(){
    char cmd_buf[MAX_CMD_LEN];
    /* call device init functions */
    AVTS_DEVICE *device_tab = DEIVCE_TAB;
    while(1){
        if (device_tab->cmd_tab == NULL){
            break;
        }
        if (device_tab->init != NULL){
            log_info("Initing device: %s....\r\n", device_tab->device);
            device_tab->init();
        }
        device_tab ++;
    }
    /* get new command from host */
    log_info("Waiting for commands.\r\n");
    int cmd_len = 0;
    while(1){
        fgets(cmd_buf, MAX_CMD_LEN, stdin);
        // fgets(cmd_buf, 10, stdin);
        log_info("Got New command %s.\r\n", cmd_buf);
        /* remove trailing \n */
        cmd_len = strlen(cmd_buf);
        if(cmd_len > 1){
            cmd_buf[cmd_len - 1] = '\0';
            avts_process_cmd(cmd_buf);
        }
    }
}

void avts_process_cmd(char* cmd){
    char *device, *cmd_name, *para;
    /* get device name */
    device = strtok(cmd, " ");
    if (device == NULL){
        return; // blank line
    }
    DEVICE_CMD_TAB *cmd_tab = NULL;
    AVTS_DEVICE *device_tab = DEIVCE_TAB;
    for (;;){
        if (device_tab->cmd_tab == NULL){
            log_error("FAIL: device \"%s\" not supported.\r\n", device);
            return; // No device found
        }
        if(strcmp(device, device_tab->device) == 0){
            cmd_tab = device_tab->cmd_tab;
            break;
        }
        device_tab ++;
    }
    while(device && (cmd_name = strtok(NULL, " ="))){
        para = strtok(NULL, " =");
        avts_run_cmd(cmd_tab, cmd_name, para, device);
    }
}

int avts_run_cmd(DEVICE_CMD_TAB* cmd_tab, char* cmd, char* para, char* device){
    uint8_t result;
    while(1){
        if (cmd_tab->func == NULL){
            log_error("FAIL: command \"%s\"not supported\r\n", cmd);
            return -1;   // command not supported
        }
        if (strcmp(cmd_tab->cmd, cmd) == 0){
            /* command found */
            log_info("Device %s Execute command: %s\r\n", device, cmd);
            result = cmd_tab->func(para);
            log_print("\r\n$$CMD_END%d$$", result);
			printf("   ");
            return 0;
        }
        cmd_tab ++;
    }
}

/*!
 * Convert string to int array
 * [1,2,3,4,5,6,7,8,9,]
 * Note:
 * 1. space is not allowed in string
 * 2. last ',' is necessary
 */
int *string_to_array(char* s, int* len){
    *len = 0;
    int str_len = strlen(s);
    /* find array size */
    for (int i = 0; i < str_len; i ++){
        if (',' == s[i]){
            (*len)++;
            printf("=");
        }
    }
    /* alloc memory */
    int *result = malloc(sizeof(int) * (*len));
    char *data = strtok(s, "[],");
    int i = 0;
    while(data){
        result[i] = atol(data);
        i++;
        data = strtok(NULL, "[],");
    }
    return result;
}

