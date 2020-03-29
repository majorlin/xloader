/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: cpu.h
 * Created Date: Tuesday, February 18th 2020, 1:22:07 pm
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

#ifndef __CPU_H_
#define __CPU_H_

#include <stdint.h>

#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */


typedef struct {
  __IO  uint32_t PDOR;                      /**< Data output Register, offset: 0x0 */
  __IO  uint32_t PSOR;                      /**< Set output Register, offset: 0x4 */
  __IO  uint32_t PCOR;                      /**< Clear output Register, offset: 0x8 */
  __IO  uint32_t PTOR;                      /**< Toggle output Register, offset: 0xc */
  __IO  uint32_t PDIR;                      /**< Data input Register, offset: 0x10 */
  __IO  uint32_t PDDR;                      /**< Direction Register, offset: 0x14 */
} GPIO_Type;
#define GPIO_BASE                             (0x00100000u)
#define GPIO                                 ((GPIO_Type *)GPIO_BASE)

typedef struct {
  __IO  uint32_t TXFIFO;                  /**< offset: 0x0 */
  __IO  uint32_t RXFIFO;                  /**< offset: 0x4 */
  __IO  uint32_t TXCTRL;                  /**< offset: 0x8 */
  __IO  uint32_t RXCTRL;                  /**< offset: 0xc */
  __IO  uint32_t IE;                      /**< offset: 0x10 */
  __IO  uint32_t IP;                      /**< offset: 0x14 */
  __IO  uint32_t DIV;                     /**< offset: 0x18 */
} UART_Type;

/* TXCTRL register */
#define UART_TXCTRL_TXEN_MASK             0x1
#define UART_TXCTRL_TXWM(x)               (((x) & 0xffff) << 16)

/* RXCTRL register */
#define UART_RXCTRL_RXEN_MASK             0x1
#define UART_RXCTRL_RXWM(x)               (((x) & 0xffff) << 16)

/* IP register */
#define UART_IP_TXWM_MASK                 0x1
#define UART_IP_RXWM_MASK                 0x2

#define UART_BASE                         (0x00200000u)
#define UART                              ((UART_Type *)UART_BASE)

typedef struct {
  __IO  uint32_t SCKDIV;                  /**< offset: 0x0 */
  __IO  uint32_t SCKMODE;                 /**< offset: 0x4 */
  __IO  uint8_t  reserved_0[8];           /**< offset: 0x8 */
  __IO  uint32_t CSID;                    /**< offset: 0x10 */
  __IO  uint32_t CSDEF;                   /**< offset: 0x14 */
  __IO  uint32_t CSMODE;                  /**< offset: 0x18 */
  __IO  uint8_t  reserved_1[12];          /**< offset: 0x1c - 0x24 */
  __IO  uint32_t DELAY0;                  /**< offset: 0x28 */
  __IO  uint32_t DELAY1;                  /**< offset: 0x2C */
  __IO  uint8_t  reserved_2[16];          /**< offset: 0x30 - 0x3c */
  __IO  uint32_t FMT;                     /**< offset: 0x40 */
  __IO  uint8_t  reserved_3[4];           /**< offset: 0x44 */
  __IO  uint32_t TXDATA;                  /**< offset: 0x48 */
  __IO  uint32_t RXDATA;                  /**< offset: 0x4C */
  __IO  uint32_t TXMARK;                  /**< offset: 0x50 */
  __IO  uint32_t RXMARK;                  /**< offset: 0x54 */
  __IO  uint8_t  reserved_4[8];           /**< offset: 0x58 0x5C */
  __IO  uint32_t FCTRL;                   /**< offset: 0x60 */
  __IO  uint32_t FFMT;                    /**< offset: 0x64 */
  __IO  uint8_t  reserved_5[8];           /**< offset: 0x68 0x6C */
  __IO  uint32_t IE;                      /**< offset: 0x70 */
  __IO  uint32_t IP;                      /**< offset: 0x74 */
} QSPI_Type;
/* FMT register */
#define QSPI_FMT_PROTO_SHIFT              (0x00)
#define QSPI_FMT_PROTO_MASK               (0x03 << QSPI_FMT_PROTO_SHIFT)
#define QSPI_FMT_PROTO(x)                 (((x) << QSPI_FMT_PROTO_SHIFT) & QSPI_FMT_PROTO_MASK)

#define QSPI_FMT_ENDIAN_SHIFT             (2)
#define QSPI_FMT_ENDIAN_MASK              (0x1U << QSPI_FMT_ENDIAN_SHIFT)

#define QSPI_FMT_DIR_SHIFT                (3)
#define QSPI_FMT_DIR_MASK                 (0x1U << QSPI_FMT_DIR_SHIFT)

#define QSPI_FMT_LEN_SHIFT                (16)
#define QSPI_FMT_LEN_MASK                 (0x0F << QSPI_FMT_LEN_SHIFT)
#define QSPI_FMT_LEN(x)                   (((x) << QSPI_FMT_LEN_SHIFT) & QSPI_FMT_LEN_MASK)

#define QSPI_BASE                         (0x00400000u)
#define QSPI                              ((QSPI_Type *)QSPI_BASE)
#endif /* __CPU_H_ */
