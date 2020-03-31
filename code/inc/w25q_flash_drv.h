/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: w25q_flash_drv.h
 * Created Date: Saturday, March 28th 2020, 1:27:45 pm
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
#ifndef __W25Q_FLASH_DRV_H_
#define __W25Q_FLASH_DRV_H_
#include "common.h"
// porting functions
void spi_wait_idle();
void spi_flash_cs_low();
void spi_write_byte(uint8_t byte);
uint8_t spi_write_read(uint8_t byte);
void spi_flash_cs_high();
// Flash functions
uint16_t flash_read_id();
void flash_write_enable();
void flash_sector_erase(uint32_t addr);
void flash_read_data(uint32_t addr,uint8_t *datasto,int num);
void flash_write_data(uint32_t addr,uint8_t *datasend,int num);
#endif
