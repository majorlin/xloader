/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: w25q_flash_drv.c
 * Created Date: Saturday, March 28th 2020, 1:27:35 pm
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

#include "w25q_flash_drv.h"
void spi_wait_idle(){
    while(QSPI->IP);
}
void spi_flash_cs_low(){
    // CS select when xfer start
    QSPI->CSMODE = 2;
}
void spi_write_byte(uint8_t byte){
    // only output data
    QSPI->FMT |= QSPI_FMT_DIR_MASK;
    while (QSPI->TXDATA & 0x80000000)
        ;
    QSPI->TXDATA = byte;
}
uint8_t spi_write_read(uint8_t byte){
    spi_wait_idle();
    // write with read
    QSPI->FMT &= ~(QSPI_FMT_DIR_MASK);
    while (QSPI->TXDATA & 0x80000000)
        ;
    QSPI->TXDATA = byte;
    uint32_t rxdata;
    do {
        rxdata = QSPI->RXDATA;
    } while(rxdata & 0x80000000);
    return rxdata;
}
void spi_flash_cs_high(){
    spi_wait_idle();
    // CS select HW control
    QSPI->CSMODE = 0;
}
static void flash_wait_idle(void) {
    uint8_t temp = 0;
    spi_flash_cs_low();
    spi_write_byte(0x05);
    do {
        temp = spi_write_read(0x00);
    }
    while(temp&0x01==1);
    spi_flash_cs_high();
}
uint16_t flash_read_id(){
    spi_flash_cs_low();
    spi_write_byte(0x90);
    spi_write_byte(0x00);
    spi_write_byte(0x00);
    spi_write_byte(0x00);
    char mid = spi_write_read(0x00);
    char did = spi_write_read(0x00);
    spi_flash_cs_high();
    return (mid << 8 | did);
}
void flash_write_enable(){
    spi_flash_cs_low();
    spi_write_byte(0x06);
    spi_flash_cs_high();
    flash_wait_idle();
}
void flash_sector_erase(uint32_t addr) {
    uint8_t Addr[3] = {0};
    Addr[0] = (addr&0x00FF0000) >> 16;
    Addr[1] = (addr&0x0000FF00) >> 8;
    Addr[2] = (addr&0x000000FF) >> 0;
    flash_wait_idle();
    flash_write_enable();
    spi_flash_cs_low();
    spi_write_byte(0x20);
    spi_write_byte(Addr[0]);
    spi_write_byte(Addr[1]);
    spi_write_byte(Addr[2]);
    spi_flash_cs_high();

    flash_wait_idle();
    flash_write_enable();
}
void flash_read_data(uint32_t addr,uint8_t *datasto,int num) {
    uint8_t Addr[3] = {0};
    Addr[0] = (addr&0x00FF0000) >> 16;
    Addr[1] = (addr&0x0000FF00) >> 8;
    Addr[2] = (addr&0x000000FF) >> 0;
    spi_flash_cs_low();
    spi_write_byte(0x03);
    spi_write_byte(Addr[0]);
    spi_write_byte(Addr[1]);
    spi_write_byte(Addr[2]);

    for(int i = 0;i < num; i++)
    {
        datasto[i] = spi_write_read(0x00);
    }
    spi_flash_cs_high();
    flash_wait_idle();
}
void flash_write_data(uint32_t addr,uint8_t *datasend,int num) {
    uint8_t Addr[3] = {0};
    flash_write_enable();
    Addr[0] = (addr&0x00FF0000) >> 16;
    Addr[1] = (addr&0x0000FF00) >> 8;
    Addr[2] = (addr&0x000000FF) >> 0;
    spi_flash_cs_low();
    spi_write_byte(0x02);
    spi_write_byte(Addr[0]);
    spi_write_byte(Addr[1]);
    spi_write_byte(Addr[2]);
    for(int i = 0;i < num; i++){
        spi_write_byte(datasend[i]);
    }
    spi_flash_cs_high();
    flash_wait_idle();
}

