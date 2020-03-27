/*
 * Copyright (c) 2020 NXP
 * ******************************************************************************
 * File: cpu.h
 * Created Date: Tuesday, February 18th 2020, 1:22:07 pm
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

#endif /* __CPU_H_ */
