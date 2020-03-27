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
/** Peripheral GPIO base address */
#define GPIO_BASE                             (0x00100000u)
/** Peripheral GPIO base pointer */
#define GPIO                                 ((GPIO_Type *)GPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                      { GPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                       { GPIO }

#endif /* __CPU_H_ */
