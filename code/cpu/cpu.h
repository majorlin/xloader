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
  __IO  uint32_t OUT_MUX[0x100];                      /**< OUTPUT MUX SEL Register, offset: 0x0 */
  __IO  uint32_t IN_MUX[0x100];                      /**< OUTPUT MUX SEL Register, offset: 0x0 */
} PAD_Type;
/* PAD - Peripheral instance base addresses */

#define PAD_OUT_MUX_LPUART1_TX                 (32+0)
#define PAD_OUT_MUX_LPUART2_TX                 (32+4)
#define PAD_OUT_MUX_LPSPI1_SDI                 (32+16)
#define PAD_OUT_MUX_LPSPI1_SDO                 (32+17)
#define PAD_OUT_MUX_LPSPI1_SCK                 (32+18)
#define PAD_OUT_MUX_LPSPI1_PCS0                (32+19)
#define PAD_OUT_MUX_LPSPI1_PCS1                (32+20)
#define PAD_OUT_MUX_LPSPI1_PCS2                (32+21)
#define PAD_OUT_MUX_LPSPI1_PCS3                (32+22)
#define PAD_OUT_MUX_LPSPI2_SDI                 (32+23)
#define PAD_OUT_MUX_LPSPI2_SDO                 (32+24)
#define PAD_OUT_MUX_LPSPI2_SCK                 (32+25)
#define PAD_OUT_MUX_LPSPI2_PCS0                (32+26)
#define PAD_OUT_MUX_LPSPI2_PCS1                (32+27)
#define PAD_OUT_MUX_LPSPI2_PCS2                (32+28)
#define PAD_OUT_MUX_LPSPI2_PCS3                (32+29)
#define PAD_OUT_MUX_PWM1_OUT                   (32+30)
#define PAD_OUT_MUX_PWM2_OUT                   (32+31)
#define PAD_OUT_MUX_PWM3_OUT                   (32+32)
#define PAD_OUT_MUX_PWM4_OUT                   (32+33)


#define PAD_IN_MUX_LPUART1_TX                  (32+0)
#define PAD_IN_MUX_LPUART1_RX                  (32+1)
#define PAD_IN_MUX_LPUART1_CTS_B               (32+2)
#define PAD_IN_MUX_LPUART1_RTS_B               (32+3)
#define PAD_IN_MUX_LPUART2_TX                  (32+4)
#define PAD_IN_MUX_LPUART2_RX                  (32+5)
#define PAD_IN_MUX_LPUART2_CTS_B               (32+6)
#define PAD_IN_MUX_LPUART2_RTS_B               (32+7)
#define PAD_IN_MUX_LPTMR1_IN0                  (32+8)
#define PAD_IN_MUX_LPTMR1_IN1                  (32+9)
#define PAD_IN_MUX_LPTMR1_IN2                  (32+10)
#define PAD_IN_MUX_LPTMR1_IN3                  (32+11)
#define PAD_IN_MUX_LPTMR2_IN0                  (32+12)
#define PAD_IN_MUX_LPTMR2_IN1                  (32+13)
#define PAD_IN_MUX_LPTMR2_IN2                  (32+14)
#define PAD_IN_MUX_LPTMR2_IN3                  (32+15)
#define PAD_IN_MUX_LPSPI1_SDI                  (32+16)
#define PAD_IN_MUX_LPSPI1_SDO                  (32+17)
#define PAD_IN_MUX_LPSPI1_SCK                  (32+18)
#define PAD_IN_MUX_LPSPI1_PCS0                 (32+19)
#define PAD_IN_MUX_LPSPI1_PCS1                 (32+20)
#define PAD_IN_MUX_LPSPI1_PCS2                 (32+21)
#define PAD_IN_MUX_LPSPI1_PCS3                 (32+22)
#define PAD_IN_MUX_LPSPI2_SDI                  (32+23)
#define PAD_IN_MUX_LPSPI2_SDO                  (32+24)
#define PAD_IN_MUX_LPSPI2_SCK                  (32+25)
#define PAD_IN_MUX_LPSPI2_PCS0                 (32+26)
#define PAD_IN_MUX_LPSPI2_PCS1                 (32+27)
#define PAD_IN_MUX_LPSPI2_PCS2                 (32+28)
#define PAD_IN_MUX_LPSPI2_PCS3                 (32+29)
#define PAD_IN_MUX_PWM1_IN                     (32+30)
#define PAD_IN_MUX_PWM2_IN                     (32+31)
#define PAD_IN_MUX_PWM3_IN                     (32+32)
#define PAD_IN_MUX_PWM4_IN                     (32+33)
/** Peripheral PAD base address */
#define PAD_BASE                             (0x02000000u)
/** Peripheral PAD base pointer */
#define PAD                                 ((PAD_Type *)PAD_BASE)
/** Array initializer of PAD peripheral base addresses */
#define PAD_BASE_ADDRS                        { PAD_BASE }
/** Array initializer of PAD peripheral base pointers */
#define PAD_BASE_PTRS                         { PAD }

typedef struct {
  __IO  uint32_t PDOR;                      /**< Data output Register, offset: 0x0 */
  __IO  uint32_t PSOR;                      /**< Set output Register, offset: 0x4 */
  __IO  uint32_t PCOR;                      /**< Clear output Register, offset: 0x8 */
  __IO  uint32_t PTOR;                      /**< Toggle output Register, offset: 0xc */
  __IO  uint32_t PDIR;                      /**< Data input Register, offset: 0x10 */
  __IO  uint32_t PDDR;                      /**< Direction Register, offset: 0x14 */
} GPIO_Type;
/** Peripheral GPIO base address */
#define GPIO_BASE                             (0x09000000u)
/** Peripheral GPIO base pointer */
#define GPIO                                 ((GPIO_Type *)GPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                        { GPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                         { GPIO }

typedef struct {
  __IO  uint32_t MOD;                      /**< Data output Register, offset: 0x0 */
  __IO  uint32_t CMP;                      /**< Set output Register, offset: 0x4 */
  __IO  uint32_t POS;                      /**< Clear output Register, offset: 0x8 */
  __IO  uint32_t NEG;                      /**< Toggle output Register, offset: 0xc */
} PWM_Type;
/** Peripheral PWM base address */
#define PWM1_BASE                             (0x0A000000u)
/** Peripheral PWM base pointer */
#define PWM1                                 ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM base address */
#define PWM2_BASE                             (0x0A000010u)
/** Peripheral PWM base pointer */
#define PWM2                                 ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM base address */
#define PWM3_BASE                             (0x0A000020u)
/** Peripheral PWM base pointer */
#define PWM3                                 ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM base address */
#define PWM4_BASE                             (0x0A000030u)
/** Peripheral PWM base pointer */
#define PWM4                                 ((PWM_Type *)PWM4_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                        { PWM1_BASE, PWM2_BASE, PWM3_BASE, PWM4_BASE}
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                         { PWM1, PWM2, PWM3, PWM4}
/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/** LPUART - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
  __IO uint32_t PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
  __IO uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< LPUART Status Register, offset: 0x14 */
  __IO uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x18 */
  __IO uint32_t DATA;                              /**< LPUART Data Register, offset: 0x1C */
  __IO uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
  __IO uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
  __IO uint32_t FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
  __IO uint32_t WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type;

/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Masks LPUART Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */
#define LPUART_VERID_FEATURE_MASK                (0xFFFFU)
#define LPUART_VERID_FEATURE_SHIFT               (0U)
/*! FEATURE - Feature Identification Number
 *  0b0000000000000001..Standard feature set.
 *  0b0000000000000011..Standard feature set with MODEM/IrDA support.
 */
#define LPUART_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_FEATURE_SHIFT)) & LPUART_VERID_FEATURE_MASK)
#define LPUART_VERID_MINOR_MASK                  (0xFF0000U)
#define LPUART_VERID_MINOR_SHIFT                 (16U)
/*! MINOR - Minor Version Number
 */
#define LPUART_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_MINOR_SHIFT)) & LPUART_VERID_MINOR_MASK)
#define LPUART_VERID_MAJOR_MASK                  (0xFF000000U)
#define LPUART_VERID_MAJOR_SHIFT                 (24U)
/*! MAJOR - Major Version Number
 */
#define LPUART_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_MAJOR_SHIFT)) & LPUART_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */
#define LPUART_PARAM_TXFIFO_MASK                 (0xFFU)
#define LPUART_PARAM_TXFIFO_SHIFT                (0U)
/*! TXFIFO - Transmit FIFO Size
 */
#define LPUART_PARAM_TXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_PARAM_TXFIFO_SHIFT)) & LPUART_PARAM_TXFIFO_MASK)
#define LPUART_PARAM_RXFIFO_MASK                 (0xFF00U)
#define LPUART_PARAM_RXFIFO_SHIFT                (8U)
/*! RXFIFO - Receive FIFO Size
 */
#define LPUART_PARAM_RXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_PARAM_RXFIFO_SHIFT)) & LPUART_PARAM_RXFIFO_MASK)
/*! @} */

/*! @name GLOBAL - LPUART Global Register */
/*! @{ */
#define LPUART_GLOBAL_RST_MASK                   (0x2U)
#define LPUART_GLOBAL_RST_SHIFT                  (1U)
/*! RST - Software Reset
 *  0b0..Module is not reset.
 *  0b1..Module is reset.
 */
#define LPUART_GLOBAL_RST(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_GLOBAL_RST_SHIFT)) & LPUART_GLOBAL_RST_MASK)
/*! @} */

/*! @name PINCFG - LPUART Pin Configuration Register */
/*! @{ */
#define LPUART_PINCFG_TRGSEL_MASK                (0x3U)
#define LPUART_PINCFG_TRGSEL_SHIFT               (0U)
/*! TRGSEL - Trigger Select
 *  0b00..Input trigger is disabled.
 *  0b01..Input trigger is used instead of RXD pin input.
 *  0b10..Input trigger is used instead of CTS_B pin input.
 *  0b11..Input trigger is used to modulate the TXD pin output. The TXD pin output (after TXINV configuration) is ANDed with the input trigger.
 */
#define LPUART_PINCFG_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_PINCFG_TRGSEL_SHIFT)) & LPUART_PINCFG_TRGSEL_MASK)
/*! @} */

/*! @name BAUD - LPUART Baud Rate Register */
/*! @{ */
#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)
#define LPUART_BAUD_SBR_SHIFT                    (0U)
/*! SBR - Baud Rate Modulo Divisor.
 */
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBR_SHIFT)) & LPUART_BAUD_SBR_MASK)
#define LPUART_BAUD_SBNS_MASK                    (0x2000U)
#define LPUART_BAUD_SBNS_SHIFT                   (13U)
/*! SBNS - Stop Bit Number Select
 *  0b0..One stop bit.
 *  0b1..Two stop bits.
 */
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBNS_SHIFT)) & LPUART_BAUD_SBNS_MASK)
#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)
/*! RXEDGIE - RX Input Active Edge Interrupt Enable
 *  0b0..Hardware interrupts from STAT[RXEDGIF] are disabled.
 *  0b1..Hardware interrupt is requested when STAT[RXEDGIF] flag is 1.
 */
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RXEDGIE_SHIFT)) & LPUART_BAUD_RXEDGIE_MASK)
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)
/*! LBKDIE - LIN Break Detect Interrupt Enable
 *  0b0..Hardware interrupts from STAT[LBKDIF] flag are disabled (use polling).
 *  0b1..Hardware interrupt requested when STAT[LBKDIF] flag is 1.
 */
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_LBKDIE_SHIFT)) & LPUART_BAUD_LBKDIE_MASK)
#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)
/*! RESYNCDIS - Resynchronization Disable
 *  0b0..Resynchronization during received data word is supported
 *  0b1..Resynchronization during received data word is disabled
 */
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RESYNCDIS_SHIFT)) & LPUART_BAUD_RESYNCDIS_MASK)
#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)
/*! BOTHEDGE - Both Edge Sampling
 *  0b0..Receiver samples input data using the rising edge of the baud rate clock.
 *  0b1..Receiver samples input data using the rising and falling edge of the baud rate clock.
 */
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_BOTHEDGE_SHIFT)) & LPUART_BAUD_BOTHEDGE_MASK)
#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)
/*! MATCFG - Match Configuration
 *  0b00..Address Match Wakeup
 *  0b01..Idle Match Wakeup
 *  0b10..Match On and Match Off
 *  0b11..Enables RWU on Data Match and Match On/Off for transmitter CTS input
 */
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MATCFG_SHIFT)) & LPUART_BAUD_MATCFG_MASK)
#define LPUART_BAUD_RIDMAE_MASK                  (0x100000U)
#define LPUART_BAUD_RIDMAE_SHIFT                 (20U)
/*! RIDMAE - Receiver Idle DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define LPUART_BAUD_RIDMAE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RIDMAE_SHIFT)) & LPUART_BAUD_RIDMAE_MASK)
#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)
/*! RDMAE - Receiver Full DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RDMAE_SHIFT)) & LPUART_BAUD_RDMAE_MASK)
#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)
/*! TDMAE - Transmitter DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_TDMAE_SHIFT)) & LPUART_BAUD_TDMAE_MASK)
#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)
#define LPUART_BAUD_OSR_SHIFT                    (24U)
/*! OSR - Oversampling Ratio
 *  0b00000..Writing 0 to this field will result in an oversampling ratio of 16
 *  0b00001..Reserved
 *  0b00010..Reserved
 *  0b00011..Oversampling ratio of 4, requires BOTHEDGE to be set.
 *  0b00100..Oversampling ratio of 5, requires BOTHEDGE to be set.
 *  0b00101..Oversampling ratio of 6, requires BOTHEDGE to be set.
 *  0b00110..Oversampling ratio of 7, requires BOTHEDGE to be set.
 *  0b00111..Oversampling ratio of 8.
 *  0b01000..Oversampling ratio of 9.
 *  0b01001..Oversampling ratio of 10.
 *  0b01010..Oversampling ratio of 11.
 *  0b01011..Oversampling ratio of 12.
 *  0b01100..Oversampling ratio of 13.
 *  0b01101..Oversampling ratio of 14.
 *  0b01110..Oversampling ratio of 15.
 *  0b01111..Oversampling ratio of 16.
 *  0b10000..Oversampling ratio of 17.
 *  0b10001..Oversampling ratio of 18.
 *  0b10010..Oversampling ratio of 19.
 *  0b10011..Oversampling ratio of 20.
 *  0b10100..Oversampling ratio of 21.
 *  0b10101..Oversampling ratio of 22.
 *  0b10110..Oversampling ratio of 23.
 *  0b10111..Oversampling ratio of 24.
 *  0b11000..Oversampling ratio of 25.
 *  0b11001..Oversampling ratio of 26.
 *  0b11010..Oversampling ratio of 27.
 *  0b11011..Oversampling ratio of 28.
 *  0b11100..Oversampling ratio of 29.
 *  0b11101..Oversampling ratio of 30.
 *  0b11110..Oversampling ratio of 31.
 *  0b11111..Oversampling ratio of 32.
 */
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_OSR_SHIFT)) & LPUART_BAUD_OSR_MASK)
#define LPUART_BAUD_M10_MASK                     (0x20000000U)
#define LPUART_BAUD_M10_SHIFT                    (29U)
/*! M10 - 10-bit Mode select
 *  0b0..Receiver and transmitter use 7-bit to 9-bit data characters.
 *  0b1..Receiver and transmitter use 10-bit data characters.
 */
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_M10_SHIFT)) & LPUART_BAUD_M10_MASK)
#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)
/*! MAEN2 - Match Address Mode Enable 2
 *  0b0..Normal operation.
 *  0b1..Enables automatic address matching or data matching mode for MATCH[MA2].
 */
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN2_SHIFT)) & LPUART_BAUD_MAEN2_MASK)
#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)
/*! MAEN1 - Match Address Mode Enable 1
 *  0b0..Normal operation.
 *  0b1..Enables automatic address matching or data matching mode for MATCH[MA1].
 */
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN1_SHIFT)) & LPUART_BAUD_MAEN1_MASK)
/*! @} */

/*! @name STAT - LPUART Status Register */
/*! @{ */
#define LPUART_STAT_MA2F_MASK                    (0x4000U)
#define LPUART_STAT_MA2F_SHIFT                   (14U)
/*! MA2F - Match 2 Flag
 *  0b0..Received data is not equal to MA2
 *  0b1..Received data is equal to MA2
 */
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA2F_SHIFT)) & LPUART_STAT_MA2F_MASK)
#define LPUART_STAT_MA1F_MASK                    (0x8000U)
#define LPUART_STAT_MA1F_SHIFT                   (15U)
/*! MA1F - Match 1 Flag
 *  0b0..Received data is not equal to MA1
 *  0b1..Received data is equal to MA1
 */
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA1F_SHIFT)) & LPUART_STAT_MA1F_MASK)
#define LPUART_STAT_PF_MASK                      (0x10000U)
#define LPUART_STAT_PF_SHIFT                     (16U)
/*! PF - Parity Error Flag
 *  0b0..No parity error.
 *  0b1..Parity error.
 */
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_PF_SHIFT)) & LPUART_STAT_PF_MASK)
#define LPUART_STAT_FE_MASK                      (0x20000U)
#define LPUART_STAT_FE_SHIFT                     (17U)
/*! FE - Framing Error Flag
 *  0b0..No framing error detected. This does not guarantee the framing is correct.
 *  0b1..Framing error.
 */
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_FE_SHIFT)) & LPUART_STAT_FE_MASK)
#define LPUART_STAT_NF_MASK                      (0x40000U)
#define LPUART_STAT_NF_SHIFT                     (18U)
/*! NF - Noise Flag
 *  0b0..No noise detected.
 *  0b1..Noise detected in the received character in the DATA register.
 */
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_NF_SHIFT)) & LPUART_STAT_NF_MASK)
#define LPUART_STAT_OR_MASK                      (0x80000U)
#define LPUART_STAT_OR_SHIFT                     (19U)
/*! OR - Receiver Overrun Flag
 *  0b0..No overrun.
 *  0b1..Receive overrun (new LPUART data lost).
 */
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_OR_SHIFT)) & LPUART_STAT_OR_MASK)
#define LPUART_STAT_IDLE_MASK                    (0x100000U)
#define LPUART_STAT_IDLE_SHIFT                   (20U)
/*! IDLE - Idle Line Flag
 *  0b0..No idle line detected.
 *  0b1..Idle line was detected.
 */
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_IDLE_SHIFT)) & LPUART_STAT_IDLE_MASK)
#define LPUART_STAT_RDRF_MASK                    (0x200000U)
#define LPUART_STAT_RDRF_SHIFT                   (21U)
/*! RDRF - Receive Data Register Full Flag
 *  0b0..Receive data buffer empty.
 *  0b1..Receive data buffer full.
 */
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RDRF_SHIFT)) & LPUART_STAT_RDRF_MASK)
#define LPUART_STAT_TC_MASK                      (0x400000U)
#define LPUART_STAT_TC_SHIFT                     (22U)
/*! TC - Transmission Complete Flag
 *  0b0..Transmitter active (sending data, a preamble, or a break).
 *  0b1..Transmitter idle (transmission activity complete).
 */
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TC_SHIFT)) & LPUART_STAT_TC_MASK)
#define LPUART_STAT_TDRE_MASK                    (0x800000U)
#define LPUART_STAT_TDRE_SHIFT                   (23U)
/*! TDRE - Transmit Data Register Empty Flag
 *  0b0..Transmit data buffer full.
 *  0b1..Transmit data buffer empty.
 */
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TDRE_SHIFT)) & LPUART_STAT_TDRE_MASK)
#define LPUART_STAT_RAF_MASK                     (0x1000000U)
#define LPUART_STAT_RAF_SHIFT                    (24U)
/*! RAF - Receiver Active Flag
 *  0b0..LPUART receiver idle waiting for a start bit.
 *  0b1..LPUART receiver active (RXD input not idle).
 */
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RAF_SHIFT)) & LPUART_STAT_RAF_MASK)
#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)
#define LPUART_STAT_LBKDE_SHIFT                  (25U)
/*! LBKDE - LIN Break Detection Enable
 *  0b0..LIN break detect is disabled, normal break character can be detected.
 *  0b1..LIN break detect is enabled. LIN break character is detected at length of 11 bit times (if M = 0) or 12 (if M = 1) or 13 (M10 = 1).
 */
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDE_SHIFT)) & LPUART_STAT_LBKDE_MASK)
#define LPUART_STAT_BRK13_MASK                   (0x4000000U)
#define LPUART_STAT_BRK13_SHIFT                  (26U)
/*! BRK13 - Break Character Generation Length
 *  0b0..Break character is transmitted with length of 9 to 13 bit times.
 *  0b1..Break character is transmitted with length of 12 to 15 bit times.
 */
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_BRK13_SHIFT)) & LPUART_STAT_BRK13_MASK)
#define LPUART_STAT_RWUID_MASK                   (0x8000000U)
#define LPUART_STAT_RWUID_SHIFT                  (27U)
/*! RWUID - Receive Wake Up Idle Detect
 *  0b0..During receive standby state (RWU = 1), the IDLE bit does not get set upon detection of an idle
 *       character. During address match wakeup, the IDLE bit does not set when an address does not match.
 *  0b1..During receive standby state (RWU = 1), the IDLE bit gets set upon detection of an idle character. During
 *       address match wakeup, the IDLE bit does set when an address does not match.
 */
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RWUID_SHIFT)) & LPUART_STAT_RWUID_MASK)
#define LPUART_STAT_RXINV_MASK                   (0x10000000U)
#define LPUART_STAT_RXINV_SHIFT                  (28U)
/*! RXINV - Receive Data Inversion
 *  0b0..Receive data not inverted.
 *  0b1..Receive data inverted.
 */
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXINV_SHIFT)) & LPUART_STAT_RXINV_MASK)
#define LPUART_STAT_MSBF_MASK                    (0x20000000U)
#define LPUART_STAT_MSBF_SHIFT                   (29U)
/*! MSBF - MSB First
 *  0b0..LSB (bit0) is the first bit that is transmitted following the start bit. Further, the first bit received
 *       after the start bit is identified as bit0.
 *  0b1..MSB (bit9, bit8, bit7 or bit6) is the first bit that is transmitted following the start bit depending on
 *       the setting of CTRL[M], CTRL[PE] and BAUD[M10]. Further, the first bit received after the start bit is
 *       identified as bit9, bit8, bit7 or bit6 depending on the setting of CTRL[M] and CTRL[PE].
 */
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MSBF_SHIFT)) & LPUART_STAT_MSBF_MASK)
#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)
/*! RXEDGIF - RXD Pin Active Edge Interrupt Flag
 *  0b0..No active edge on the receive pin has occurred.
 *  0b1..An active edge on the receive pin has occurred.
 */
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXEDGIF_SHIFT)) & LPUART_STAT_RXEDGIF_MASK)
#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)
/*! LBKDIF - LIN Break Detect Interrupt Flag
 *  0b0..No LIN break character has been detected.
 *  0b1..LIN break character has been detected.
 */
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDIF_SHIFT)) & LPUART_STAT_LBKDIF_MASK)
/*! @} */

/*! @name CTRL - LPUART Control Register */
/*! @{ */
#define LPUART_CTRL_PT_MASK                      (0x1U)
#define LPUART_CTRL_PT_SHIFT                     (0U)
/*! PT - Parity Type
 *  0b0..Even parity.
 *  0b1..Odd parity.
 */
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PT_SHIFT)) & LPUART_CTRL_PT_MASK)
#define LPUART_CTRL_PE_MASK                      (0x2U)
#define LPUART_CTRL_PE_SHIFT                     (1U)
/*! PE - Parity Enable
 *  0b0..No hardware parity generation or checking.
 *  0b1..Parity enabled.
 */
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PE_SHIFT)) & LPUART_CTRL_PE_MASK)
#define LPUART_CTRL_ILT_MASK                     (0x4U)
#define LPUART_CTRL_ILT_SHIFT                    (2U)
/*! ILT - Idle Line Type Select
 *  0b0..Idle character bit count starts after start bit.
 *  0b1..Idle character bit count starts after stop bit.
 */
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILT_SHIFT)) & LPUART_CTRL_ILT_MASK)
#define LPUART_CTRL_WAKE_MASK                    (0x8U)
#define LPUART_CTRL_WAKE_SHIFT                   (3U)
/*! WAKE - Receiver Wakeup Method Select
 *  0b0..Configures RWU for idle-line wakeup.
 *  0b1..Configures RWU with address-mark wakeup.
 */
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_WAKE_SHIFT)) & LPUART_CTRL_WAKE_MASK)
#define LPUART_CTRL_M_MASK                       (0x10U)
#define LPUART_CTRL_M_SHIFT                      (4U)
/*! M - 9-Bit or 8-Bit Mode Select
 *  0b0..Receiver and transmitter use 8-bit data characters.
 *  0b1..Receiver and transmitter use 9-bit data characters.
 */
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_M_SHIFT)) & LPUART_CTRL_M_MASK)
#define LPUART_CTRL_RSRC_MASK                    (0x20U)
#define LPUART_CTRL_RSRC_SHIFT                   (5U)
/*! RSRC - Receiver Source Select
 *  0b0..Provided LOOPS is set, RSRC is cleared, selects internal loop back mode and the LPUART does not use the RXD pin.
 *  0b1..Single-wire LPUART mode where the TXD pin is connected to the transmitter output and receiver input.
 */
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RSRC_SHIFT)) & LPUART_CTRL_RSRC_MASK)
#define LPUART_CTRL_DOZEEN_MASK                  (0x40U)
#define LPUART_CTRL_DOZEEN_SHIFT                 (6U)
/*! DOZEEN - Doze Enable
 *  0b0..LPUART is enabled in Doze mode.
 *  0b1..LPUART is disabled in Doze mode.
 */
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_DOZEEN_SHIFT)) & LPUART_CTRL_DOZEEN_MASK)
#define LPUART_CTRL_LOOPS_MASK                   (0x80U)
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)
/*! LOOPS - Loop Mode Select
 *  0b0..Normal operation - RXD and TXD use separate pins.
 *  0b1..Loop mode or single-wire mode where transmitter outputs are internally connected to receiver input (see RSRC bit).
 */
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_LOOPS_SHIFT)) & LPUART_CTRL_LOOPS_MASK)
#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)
/*! IDLECFG - Idle Configuration
 *  0b000..1 idle character
 *  0b001..2 idle characters
 *  0b010..4 idle characters
 *  0b011..8 idle characters
 *  0b100..16 idle characters
 *  0b101..32 idle characters
 *  0b110..64 idle characters
 *  0b111..128 idle characters
 */
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_IDLECFG_SHIFT)) & LPUART_CTRL_IDLECFG_MASK)
#define LPUART_CTRL_M7_MASK                      (0x800U)
#define LPUART_CTRL_M7_SHIFT                     (11U)
/*! M7 - 7-Bit Mode Select
 *  0b0..Receiver and transmitter use 8-bit to 10-bit data characters.
 *  0b1..Receiver and transmitter use 7-bit data characters.
 */
#define LPUART_CTRL_M7(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_M7_SHIFT)) & LPUART_CTRL_M7_MASK)
#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)
/*! MA2IE - Match 2 Interrupt Enable
 *  0b0..MA2F interrupt disabled
 *  0b1..MA2F interrupt enabled
 */
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA2IE_SHIFT)) & LPUART_CTRL_MA2IE_MASK)
#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)
/*! MA1IE - Match 1 Interrupt Enable
 *  0b0..MA1F interrupt disabled
 *  0b1..MA1F interrupt enabled
 */
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA1IE_SHIFT)) & LPUART_CTRL_MA1IE_MASK)
#define LPUART_CTRL_SBK_MASK                     (0x10000U)
#define LPUART_CTRL_SBK_SHIFT                    (16U)
/*! SBK - Send Break
 *  0b0..Normal transmitter operation.
 *  0b1..Queue break character(s) to be sent.
 */
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_SBK_SHIFT)) & LPUART_CTRL_SBK_MASK)
#define LPUART_CTRL_RWU_MASK                     (0x20000U)
#define LPUART_CTRL_RWU_SHIFT                    (17U)
/*! RWU - Receiver Wakeup Control
 *  0b0..Normal receiver operation.
 *  0b1..LPUART receiver in standby waiting for wakeup condition.
 */
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RWU_SHIFT)) & LPUART_CTRL_RWU_MASK)
#define LPUART_CTRL_RE_MASK                      (0x40000U)
#define LPUART_CTRL_RE_SHIFT                     (18U)
/*! RE - Receiver Enable
 *  0b0..Receiver disabled.
 *  0b1..Receiver enabled.
 */
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RE_SHIFT)) & LPUART_CTRL_RE_MASK)
#define LPUART_CTRL_TE_MASK                      (0x80000U)
#define LPUART_CTRL_TE_SHIFT                     (19U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter disabled.
 *  0b1..Transmitter enabled.
 */
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TE_SHIFT)) & LPUART_CTRL_TE_MASK)
#define LPUART_CTRL_ILIE_MASK                    (0x100000U)
#define LPUART_CTRL_ILIE_SHIFT                   (20U)
/*! ILIE - Idle Line Interrupt Enable
 *  0b0..Hardware interrupts from IDLE disabled; use polling.
 *  0b1..Hardware interrupt requested when IDLE flag is 1.
 */
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILIE_SHIFT)) & LPUART_CTRL_ILIE_MASK)
#define LPUART_CTRL_RIE_MASK                     (0x200000U)
#define LPUART_CTRL_RIE_SHIFT                    (21U)
/*! RIE - Receiver Interrupt Enable
 *  0b0..Hardware interrupts from RDRF disabled; use polling.
 *  0b1..Hardware interrupt requested when RDRF flag is 1.
 */
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RIE_SHIFT)) & LPUART_CTRL_RIE_MASK)
#define LPUART_CTRL_TCIE_MASK                    (0x400000U)
#define LPUART_CTRL_TCIE_SHIFT                   (22U)
/*! TCIE - Transmission Complete Interrupt Enable for
 *  0b0..Hardware interrupts from TC disabled; use polling.
 *  0b1..Hardware interrupt requested when TC flag is 1.
 */
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TCIE_SHIFT)) & LPUART_CTRL_TCIE_MASK)
#define LPUART_CTRL_TIE_MASK                     (0x800000U)
#define LPUART_CTRL_TIE_SHIFT                    (23U)
/*! TIE - Transmit Interrupt Enable
 *  0b0..Hardware interrupts from TDRE disabled; use polling.
 *  0b1..Hardware interrupt requested when TDRE flag is 1.
 */
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TIE_SHIFT)) & LPUART_CTRL_TIE_MASK)
#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)
#define LPUART_CTRL_PEIE_SHIFT                   (24U)
/*! PEIE - Parity Error Interrupt Enable
 *  0b0..PF interrupts disabled; use polling).
 *  0b1..Hardware interrupt requested when PF is set.
 */
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PEIE_SHIFT)) & LPUART_CTRL_PEIE_MASK)
#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)
#define LPUART_CTRL_FEIE_SHIFT                   (25U)
/*! FEIE - Framing Error Interrupt Enable
 *  0b0..FE interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when FE is set.
 */
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_FEIE_SHIFT)) & LPUART_CTRL_FEIE_MASK)
#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)
#define LPUART_CTRL_NEIE_SHIFT                   (26U)
/*! NEIE - Noise Error Interrupt Enable
 *  0b0..NF interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when NF is set.
 */
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_NEIE_SHIFT)) & LPUART_CTRL_NEIE_MASK)
#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)
#define LPUART_CTRL_ORIE_SHIFT                   (27U)
/*! ORIE - Overrun Interrupt Enable
 *  0b0..OR interrupts disabled; use polling.
 *  0b1..Hardware interrupt requested when OR is set.
 */
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ORIE_SHIFT)) & LPUART_CTRL_ORIE_MASK)
#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)
#define LPUART_CTRL_TXINV_SHIFT                  (28U)
/*! TXINV - Transmit Data Inversion
 *  0b0..Transmit data not inverted.
 *  0b1..Transmit data inverted.
 */
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXINV_SHIFT)) & LPUART_CTRL_TXINV_MASK)
#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)
/*! TXDIR - TXD Pin Direction in Single-Wire Mode
 *  0b0..TXD pin is an input in single-wire mode.
 *  0b1..TXD pin is an output in single-wire mode.
 */
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXDIR_SHIFT)) & LPUART_CTRL_TXDIR_MASK)
#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)
#define LPUART_CTRL_R9T8_SHIFT                   (30U)
/*! R9T8 - Receive Bit 9 / Transmit Bit 8
 */
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R9T8_SHIFT)) & LPUART_CTRL_R9T8_MASK)
#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)
#define LPUART_CTRL_R8T9_SHIFT                   (31U)
/*! R8T9 - Receive Bit 8 / Transmit Bit 9
 */
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R8T9_SHIFT)) & LPUART_CTRL_R8T9_MASK)
/*! @} */

/*! @name DATA - LPUART Data Register */
/*! @{ */
#define LPUART_DATA_R0T0_MASK                    (0x1U)
#define LPUART_DATA_R0T0_SHIFT                   (0U)
/*! R0T0 - R0T0
 */
#define LPUART_DATA_R0T0(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R0T0_SHIFT)) & LPUART_DATA_R0T0_MASK)
#define LPUART_DATA_R1T1_MASK                    (0x2U)
#define LPUART_DATA_R1T1_SHIFT                   (1U)
/*! R1T1 - R1T1
 */
#define LPUART_DATA_R1T1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R1T1_SHIFT)) & LPUART_DATA_R1T1_MASK)
#define LPUART_DATA_R2T2_MASK                    (0x4U)
#define LPUART_DATA_R2T2_SHIFT                   (2U)
/*! R2T2 - R2T2
 */
#define LPUART_DATA_R2T2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R2T2_SHIFT)) & LPUART_DATA_R2T2_MASK)
#define LPUART_DATA_R3T3_MASK                    (0x8U)
#define LPUART_DATA_R3T3_SHIFT                   (3U)
/*! R3T3 - R3T3
 */
#define LPUART_DATA_R3T3(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R3T3_SHIFT)) & LPUART_DATA_R3T3_MASK)
#define LPUART_DATA_R4T4_MASK                    (0x10U)
#define LPUART_DATA_R4T4_SHIFT                   (4U)
/*! R4T4 - R4T4
 */
#define LPUART_DATA_R4T4(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R4T4_SHIFT)) & LPUART_DATA_R4T4_MASK)
#define LPUART_DATA_R5T5_MASK                    (0x20U)
#define LPUART_DATA_R5T5_SHIFT                   (5U)
/*! R5T5 - R5T5
 */
#define LPUART_DATA_R5T5(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R5T5_SHIFT)) & LPUART_DATA_R5T5_MASK)
#define LPUART_DATA_R6T6_MASK                    (0x40U)
#define LPUART_DATA_R6T6_SHIFT                   (6U)
/*! R6T6 - R6T6
 */
#define LPUART_DATA_R6T6(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R6T6_SHIFT)) & LPUART_DATA_R6T6_MASK)
#define LPUART_DATA_R7T7_MASK                    (0x80U)
#define LPUART_DATA_R7T7_SHIFT                   (7U)
/*! R7T7 - R7T7
 */
#define LPUART_DATA_R7T7(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R7T7_SHIFT)) & LPUART_DATA_R7T7_MASK)
#define LPUART_DATA_R8T8_MASK                    (0x100U)
#define LPUART_DATA_R8T8_SHIFT                   (8U)
/*! R8T8 - R8T8
 */
#define LPUART_DATA_R8T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R8T8_SHIFT)) & LPUART_DATA_R8T8_MASK)
#define LPUART_DATA_R9T9_MASK                    (0x200U)
#define LPUART_DATA_R9T9_SHIFT                   (9U)
/*! R9T9 - R9T9
 */
#define LPUART_DATA_R9T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R9T9_SHIFT)) & LPUART_DATA_R9T9_MASK)
#define LPUART_DATA_IDLINE_MASK                  (0x800U)
#define LPUART_DATA_IDLINE_SHIFT                 (11U)
/*! IDLINE - Idle Line
 *  0b0..Receiver was not idle before receiving this character.
 *  0b1..Receiver was idle before receiving this character.
 */
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_IDLINE_SHIFT)) & LPUART_DATA_IDLINE_MASK)
#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)
/*! RXEMPT - Receive Buffer Empty
 *  0b0..Receive buffer contains valid data.
 *  0b1..Receive buffer is empty, data returned on read is not valid.
 */
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_RXEMPT_SHIFT)) & LPUART_DATA_RXEMPT_MASK)
#define LPUART_DATA_FRETSC_MASK                  (0x2000U)
#define LPUART_DATA_FRETSC_SHIFT                 (13U)
/*! FRETSC - Frame Error / Transmit Special Character
 *  0b0..The dataword was received without a frame error on read, or transmit a normal character on write.
 *  0b1..The dataword was received with a frame error, or transmit an idle or break character on transmit.
 */
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_FRETSC_SHIFT)) & LPUART_DATA_FRETSC_MASK)
#define LPUART_DATA_PARITYE_MASK                 (0x4000U)
#define LPUART_DATA_PARITYE_SHIFT                (14U)
/*! PARITYE - PARITYE
 *  0b0..The dataword was received without a parity error.
 *  0b1..The dataword was received with a parity error.
 */
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_PARITYE_SHIFT)) & LPUART_DATA_PARITYE_MASK)
#define LPUART_DATA_NOISY_MASK                   (0x8000U)
#define LPUART_DATA_NOISY_SHIFT                  (15U)
/*! NOISY - NOISY
 *  0b0..The dataword was received without noise.
 *  0b1..The data was received with noise.
 */
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_NOISY_SHIFT)) & LPUART_DATA_NOISY_MASK)
/*! @} */

/*! @name MATCH - LPUART Match Address Register */
/*! @{ */
#define LPUART_MATCH_MA1_MASK                    (0x3FFU)
#define LPUART_MATCH_MA1_SHIFT                   (0U)
/*! MA1 - Match Address 1
 */
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA1_SHIFT)) & LPUART_MATCH_MA1_MASK)
#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)
#define LPUART_MATCH_MA2_SHIFT                   (16U)
/*! MA2 - Match Address 2
 */
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA2_SHIFT)) & LPUART_MATCH_MA2_MASK)
/*! @} */

/*! @name MODIR - LPUART Modem IrDA Register */
/*! @{ */
#define LPUART_MODIR_TXCTSE_MASK                 (0x1U)
#define LPUART_MODIR_TXCTSE_SHIFT                (0U)
/*! TXCTSE - Transmitter clear-to-send enable
 *  0b0..CTS has no effect on the transmitter.
 *  0b1..Enables clear-to-send operation. The transmitter checks the state of CTS each time it is ready to send a
 *       character. If CTS is asserted, the character is sent. If CTS is deasserted, the signal TXD remains in the
 *       mark state and transmission is delayed until CTS is asserted. Changes in CTS as a character is being sent
 *       do not affect its transmission.
 */
#define LPUART_MODIR_TXCTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSE_SHIFT)) & LPUART_MODIR_TXCTSE_MASK)
#define LPUART_MODIR_TXRTSE_MASK                 (0x2U)
#define LPUART_MODIR_TXRTSE_SHIFT                (1U)
/*! TXRTSE - Transmitter request-to-send enable
 *  0b0..The transmitter has no effect on RTS.
 *  0b1..When a character is placed into an empty transmitter data buffer , RTS asserts one bit time before the
 *       start bit is transmitted. RTS deasserts one bit time after all characters in the transmitter data buffer and
 *       shift register are completely sent, including the last stop bit.
 */
#define LPUART_MODIR_TXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSE_SHIFT)) & LPUART_MODIR_TXRTSE_MASK)
#define LPUART_MODIR_TXRTSPOL_MASK               (0x4U)
#define LPUART_MODIR_TXRTSPOL_SHIFT              (2U)
/*! TXRTSPOL - Transmitter request-to-send polarity
 *  0b0..Transmitter RTS is active low.
 *  0b1..Transmitter RTS is active high.
 */
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSPOL_SHIFT)) & LPUART_MODIR_TXRTSPOL_MASK)
#define LPUART_MODIR_RXRTSE_MASK                 (0x8U)
#define LPUART_MODIR_RXRTSE_SHIFT                (3U)
/*! RXRTSE - Receiver request-to-send enable
 *  0b0..The receiver has no effect on RTS.
 *  0b1..RTS is deasserted if the receiver data register is full or a start bit has been detected that would cause
 *       the receiver data register to become full. RTS is asserted if the receiver data register is not full and
 *       has not detected a start bit that would cause the receiver data register to become full.
 */
#define LPUART_MODIR_RXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_RXRTSE_SHIFT)) & LPUART_MODIR_RXRTSE_MASK)
#define LPUART_MODIR_TXCTSC_MASK                 (0x10U)
#define LPUART_MODIR_TXCTSC_SHIFT                (4U)
/*! TXCTSC - Transmit CTS Configuration
 *  0b0..CTS input is sampled at the start of each character.
 *  0b1..CTS input is sampled when the transmitter is idle.
 */
#define LPUART_MODIR_TXCTSC(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSC_SHIFT)) & LPUART_MODIR_TXCTSC_MASK)
#define LPUART_MODIR_TXCTSSRC_MASK               (0x20U)
#define LPUART_MODIR_TXCTSSRC_SHIFT              (5U)
/*! TXCTSSRC - Transmit CTS Source
 *  0b0..CTS input is the CTS_B pin.
 *  0b1..CTS input is the inverted Receiver Match result.
 */
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSSRC_SHIFT)) & LPUART_MODIR_TXCTSSRC_MASK)
#define LPUART_MODIR_RTSWATER_MASK               (0x300U)
#define LPUART_MODIR_RTSWATER_SHIFT              (8U)
/*! RTSWATER - Receive RTS Configuration
 */
#define LPUART_MODIR_RTSWATER(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_RTSWATER_SHIFT)) & LPUART_MODIR_RTSWATER_MASK)
#define LPUART_MODIR_TNP_MASK                    (0x30000U)
#define LPUART_MODIR_TNP_SHIFT                   (16U)
/*! TNP - Transmitter narrow pulse
 *  0b00..1/OSR.
 *  0b01..2/OSR.
 *  0b10..3/OSR.
 *  0b11..4/OSR.
 */
#define LPUART_MODIR_TNP(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TNP_SHIFT)) & LPUART_MODIR_TNP_MASK)
#define LPUART_MODIR_IREN_MASK                   (0x40000U)
#define LPUART_MODIR_IREN_SHIFT                  (18U)
/*! IREN - Infrared enable
 *  0b0..IR disabled.
 *  0b1..IR enabled.
 */
#define LPUART_MODIR_IREN(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_IREN_SHIFT)) & LPUART_MODIR_IREN_MASK)
/*! @} */

/*! @name FIFO - LPUART FIFO Register */
/*! @{ */
#define LPUART_FIFO_RXFIFOSIZE_MASK              (0x7U)
#define LPUART_FIFO_RXFIFOSIZE_SHIFT             (0U)
/*! RXFIFOSIZE - Receive FIFO Buffer Depth
 *  0b000..Receive FIFO/Buffer depth = 1 dataword.
 *  0b001..Receive FIFO/Buffer depth = 4 datawords.
 *  0b010..Receive FIFO/Buffer depth = 8 datawords.
 *  0b011..Receive FIFO/Buffer depth = 16 datawords.
 *  0b100..Receive FIFO/Buffer depth = 32 datawords.
 *  0b101..Receive FIFO/Buffer depth = 64 datawords.
 *  0b110..Receive FIFO/Buffer depth = 128 datawords.
 *  0b111..Receive FIFO/Buffer depth = 256 datawords.
 */
#define LPUART_FIFO_RXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFIFOSIZE_SHIFT)) & LPUART_FIFO_RXFIFOSIZE_MASK)
#define LPUART_FIFO_RXFE_MASK                    (0x8U)
#define LPUART_FIFO_RXFE_SHIFT                   (3U)
/*! RXFE - Receive FIFO Enable
 *  0b0..Receive FIFO is not enabled. Buffer is depth 1.
 *  0b1..Receive FIFO is enabled. Buffer is depth indicted by RXFIFOSIZE.
 */
#define LPUART_FIFO_RXFE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFE_SHIFT)) & LPUART_FIFO_RXFE_MASK)
#define LPUART_FIFO_TXFIFOSIZE_MASK              (0x70U)
#define LPUART_FIFO_TXFIFOSIZE_SHIFT             (4U)
/*! TXFIFOSIZE - Transmit FIFO Buffer Depth
 *  0b000..Transmit FIFO/Buffer depth = 1 dataword.
 *  0b001..Transmit FIFO/Buffer depth = 4 datawords.
 *  0b010..Transmit FIFO/Buffer depth = 8 datawords.
 *  0b011..Transmit FIFO/Buffer depth = 16 datawords.
 *  0b100..Transmit FIFO/Buffer depth = 32 datawords.
 *  0b101..Transmit FIFO/Buffer depth = 64 datawords.
 *  0b110..Transmit FIFO/Buffer depth = 128 datawords.
 *  0b111..Transmit FIFO/Buffer depth = 256 datawords
 */
#define LPUART_FIFO_TXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFIFOSIZE_SHIFT)) & LPUART_FIFO_TXFIFOSIZE_MASK)
#define LPUART_FIFO_TXFE_MASK                    (0x80U)
#define LPUART_FIFO_TXFE_SHIFT                   (7U)
/*! TXFE - Transmit FIFO Enable
 *  0b0..Transmit FIFO is not enabled. Buffer is depth 1.
 *  0b1..Transmit FIFO is enabled. Buffer is depth indicated by TXFIFOSIZE.
 */
#define LPUART_FIFO_TXFE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFE_SHIFT)) & LPUART_FIFO_TXFE_MASK)
#define LPUART_FIFO_RXUFE_MASK                   (0x100U)
#define LPUART_FIFO_RXUFE_SHIFT                  (8U)
/*! RXUFE - Receive FIFO Underflow Interrupt Enable
 *  0b0..RXUF flag does not generate an interrupt to the host.
 *  0b1..RXUF flag generates an interrupt to the host.
 */
#define LPUART_FIFO_RXUFE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXUFE_SHIFT)) & LPUART_FIFO_RXUFE_MASK)
#define LPUART_FIFO_TXOFE_MASK                   (0x200U)
#define LPUART_FIFO_TXOFE_SHIFT                  (9U)
/*! TXOFE - Transmit FIFO Overflow Interrupt Enable
 *  0b0..TXOF flag does not generate an interrupt to the host.
 *  0b1..TXOF flag generates an interrupt to the host.
 */
#define LPUART_FIFO_TXOFE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXOFE_SHIFT)) & LPUART_FIFO_TXOFE_MASK)
#define LPUART_FIFO_RXIDEN_MASK                  (0x1C00U)
#define LPUART_FIFO_RXIDEN_SHIFT                 (10U)
/*! RXIDEN - Receiver Idle Empty Enable
 *  0b000..Disable RDRF assertion due to partially filled FIFO when receiver is idle.
 *  0b001..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 1 character.
 *  0b010..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 2 characters.
 *  0b011..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 4 characters.
 *  0b100..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 8 characters.
 *  0b101..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 16 characters.
 *  0b110..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 32 characters.
 *  0b111..Enable RDRF assertion due to partially filled FIFO when receiver is idle for 64 characters.
 */
#define LPUART_FIFO_RXIDEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXIDEN_SHIFT)) & LPUART_FIFO_RXIDEN_MASK)
#define LPUART_FIFO_RXFLUSH_MASK                 (0x4000U)
#define LPUART_FIFO_RXFLUSH_SHIFT                (14U)
/*! RXFLUSH - Receive FIFO/Buffer Flush
 *  0b0..No flush operation occurs.
 *  0b1..All data in the receive FIFO/buffer is cleared out.
 */
#define LPUART_FIFO_RXFLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFLUSH_SHIFT)) & LPUART_FIFO_RXFLUSH_MASK)
#define LPUART_FIFO_TXFLUSH_MASK                 (0x8000U)
#define LPUART_FIFO_TXFLUSH_SHIFT                (15U)
/*! TXFLUSH - Transmit FIFO/Buffer Flush
 *  0b0..No flush operation occurs.
 *  0b1..All data in the transmit FIFO/Buffer is cleared out.
 */
#define LPUART_FIFO_TXFLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFLUSH_SHIFT)) & LPUART_FIFO_TXFLUSH_MASK)
#define LPUART_FIFO_RXUF_MASK                    (0x10000U)
#define LPUART_FIFO_RXUF_SHIFT                   (16U)
/*! RXUF - Receiver Buffer Underflow Flag
 *  0b0..No receive buffer underflow has occurred since the last time the flag was cleared.
 *  0b1..At least one receive buffer underflow has occurred since the last time the flag was cleared.
 */
#define LPUART_FIFO_RXUF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXUF_SHIFT)) & LPUART_FIFO_RXUF_MASK)
#define LPUART_FIFO_TXOF_MASK                    (0x20000U)
#define LPUART_FIFO_TXOF_SHIFT                   (17U)
/*! TXOF - Transmitter Buffer Overflow Flag
 *  0b0..No transmit buffer overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one transmit buffer overflow has occurred since the last time the flag was cleared.
 */
#define LPUART_FIFO_TXOF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXOF_SHIFT)) & LPUART_FIFO_TXOF_MASK)
#define LPUART_FIFO_RXEMPT_MASK                  (0x400000U)
#define LPUART_FIFO_RXEMPT_SHIFT                 (22U)
/*! RXEMPT - Receive Buffer/FIFO Empty
 *  0b0..Receive buffer is not empty.
 *  0b1..Receive buffer is empty.
 */
#define LPUART_FIFO_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXEMPT_SHIFT)) & LPUART_FIFO_RXEMPT_MASK)
#define LPUART_FIFO_TXEMPT_MASK                  (0x800000U)
#define LPUART_FIFO_TXEMPT_SHIFT                 (23U)
/*! TXEMPT - Transmit Buffer/FIFO Empty
 *  0b0..Transmit buffer is not empty.
 *  0b1..Transmit buffer is empty.
 */
#define LPUART_FIFO_TXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXEMPT_SHIFT)) & LPUART_FIFO_TXEMPT_MASK)
/*! @} */

/*! @name WATER - LPUART Watermark Register */
/*! @{ */
#define LPUART_WATER_TXWATER_MASK                (0x3U)
#define LPUART_WATER_TXWATER_SHIFT               (0U)
/*! TXWATER - Transmit Watermark
 */
#define LPUART_WATER_TXWATER(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_TXWATER_SHIFT)) & LPUART_WATER_TXWATER_MASK)
#define LPUART_WATER_TXCOUNT_MASK                (0x700U)
#define LPUART_WATER_TXCOUNT_SHIFT               (8U)
/*! TXCOUNT - Transmit Counter
 */
#define LPUART_WATER_TXCOUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_TXCOUNT_SHIFT)) & LPUART_WATER_TXCOUNT_MASK)
#define LPUART_WATER_RXWATER_MASK                (0x30000U)
#define LPUART_WATER_RXWATER_SHIFT               (16U)
/*! RXWATER - Receive Watermark
 */
#define LPUART_WATER_RXWATER(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_RXWATER_SHIFT)) & LPUART_WATER_RXWATER_MASK)
#define LPUART_WATER_RXCOUNT_MASK                (0x7000000U)
#define LPUART_WATER_RXCOUNT_SHIFT               (24U)
/*! RXCOUNT - Receive Counter
 */
#define LPUART_WATER_RXCOUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_RXCOUNT_SHIFT)) & LPUART_WATER_RXCOUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPUART_Register_Masks */


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x03000000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x04000000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART1_BASE, LPUART2_BASE  }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART1, LPUART2 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART1_IRQn, LPUART2_IRQn  }

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Peripheral_Access_Layer LPTMR Peripheral Access Layer
 * @{
 */

/** LPTMR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Low Power Timer Control Status Register, offset: 0x0 */
  __IO uint32_t PSR;                               /**< Low Power Timer Prescale Register, offset: 0x4 */
  __IO uint32_t CMR;                               /**< Low Power Timer Compare Register, offset: 0x8 */
  __IO uint32_t CNR;                               /**< Low Power Timer Counter Register, offset: 0xC */
} LPTMR_Type;

/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/*! @name CSR - Low Power Timer Control Status Register */
/*! @{ */
#define LPTMR_CSR_TEN_MASK                       (0x1U)
#define LPTMR_CSR_TEN_SHIFT                      (0U)
/*! TEN - Timer Enable
 *  0b0..LPTMR is disabled and internal logic is reset.
 *  0b1..LPTMR is enabled.
 */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TEN_SHIFT)) & LPTMR_CSR_TEN_MASK)
#define LPTMR_CSR_TMS_MASK                       (0x2U)
#define LPTMR_CSR_TMS_SHIFT                      (1U)
/*! TMS - Timer Mode Select
 *  0b0..Time Counter mode.
 *  0b1..Pulse Counter mode.
 */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TMS_SHIFT)) & LPTMR_CSR_TMS_MASK)
#define LPTMR_CSR_TFC_MASK                       (0x4U)
#define LPTMR_CSR_TFC_SHIFT                      (2U)
/*! TFC - Timer Free-Running Counter
 *  0b0..CNR is reset whenever TCF is set.
 *  0b1..CNR is reset on overflow.
 */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TFC_SHIFT)) & LPTMR_CSR_TFC_MASK)
#define LPTMR_CSR_TPP_MASK                       (0x8U)
#define LPTMR_CSR_TPP_SHIFT                      (3U)
/*! TPP - Timer Pin Polarity
 *  0b0..Pulse Counter input source is active-high, and the CNR will increment on the rising-edge.
 *  0b1..Pulse Counter input source is active-low, and the CNR will increment on the falling-edge.
 */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TPP_SHIFT)) & LPTMR_CSR_TPP_MASK)
#define LPTMR_CSR_TPS_MASK                       (0x30U)
#define LPTMR_CSR_TPS_SHIFT                      (4U)
/*! TPS - Timer Pin Select
 *  0b00..Pulse counter input 0 is selected.
 *  0b01..Pulse counter input 1 is selected.
 *  0b10..Pulse counter input 2 is selected.
 *  0b11..Pulse counter input 3 is selected.
 */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TPS_SHIFT)) & LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       (0x40U)
#define LPTMR_CSR_TIE_SHIFT                      (6U)
/*! TIE - Timer Interrupt Enable
 *  0b0..Timer interrupt disabled.
 *  0b1..Timer interrupt enabled.
 */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TIE_SHIFT)) & LPTMR_CSR_TIE_MASK)
#define LPTMR_CSR_TCF_MASK                       (0x80U)
#define LPTMR_CSR_TCF_SHIFT                      (7U)
/*! TCF - Timer Compare Flag
 *  0b0..The value of CNR is not equal to CMR and increments.
 *  0b1..The value of CNR is equal to CMR and increments.
 */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TCF_SHIFT)) & LPTMR_CSR_TCF_MASK)
#define LPTMR_CSR_TDRE_MASK                      (0x100U)
#define LPTMR_CSR_TDRE_SHIFT                     (8U)
/*! TDRE - Timer DMA Request Enable
 *  0b0..Timer DMA Request disabled.
 *  0b1..Timer DMA Request enabled.
 */
#define LPTMR_CSR_TDRE(x)                        (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TDRE_SHIFT)) & LPTMR_CSR_TDRE_MASK)
/*! @} */

/*! @name PSR - Low Power Timer Prescale Register */
/*! @{ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)
#define LPTMR_PSR_PCS_SHIFT                      (0U)
/*! PCS - Prescaler Clock Select
 *  0b00..Prescaler/glitch filter clock 0 selected.
 *  0b01..Prescaler/glitch filter clock 1 selected.
 *  0b10..Prescaler/glitch filter clock 2 selected.
 *  0b11..Prescaler/glitch filter clock 3 selected.
 */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PCS_SHIFT)) & LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      (0x4U)
#define LPTMR_PSR_PBYP_SHIFT                     (2U)
/*! PBYP - Prescaler Bypass
 *  0b0..Prescaler/glitch filter is enabled.
 *  0b1..Prescaler/glitch filter is bypassed.
 */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PBYP_SHIFT)) & LPTMR_PSR_PBYP_MASK)
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)
/*! PRESCALE - Prescale Value
 *  0b0000..Prescaler divides the prescaler clock by 2; glitch filter does not support this configuration.
 *  0b0001..Prescaler divides the prescaler clock by 4; glitch filter recognizes change on input pin after 2 rising clock edges.
 *  0b0010..Prescaler divides the prescaler clock by 8; glitch filter recognizes change on input pin after 4 rising clock edges.
 *  0b0011..Prescaler divides the prescaler clock by 16; glitch filter recognizes change on input pin after 8 rising clock edges.
 *  0b0100..Prescaler divides the prescaler clock by 32; glitch filter recognizes change on input pin after 16 rising clock edges.
 *  0b0101..Prescaler divides the prescaler clock by 64; glitch filter recognizes change on input pin after 32 rising clock edges.
 *  0b0110..Prescaler divides the prescaler clock by 128; glitch filter recognizes change on input pin after 64 rising clock edges.
 *  0b0111..Prescaler divides the prescaler clock by 256; glitch filter recognizes change on input pin after 128 rising clock edges.
 *  0b1000..Prescaler divides the prescaler clock by 512; glitch filter recognizes change on input pin after 256 rising clock edges.
 *  0b1001..Prescaler divides the prescaler clock by 1024; glitch filter recognizes change on input pin after 512 rising clock edges.
 *  0b1010..Prescaler divides the prescaler clock by 2048; glitch filter recognizes change on input pin after 1024 rising clock edges.
 *  0b1011..Prescaler divides the prescaler clock by 4096; glitch filter recognizes change on input pin after 2048 rising clock edges.
 *  0b1100..Prescaler divides the prescaler clock by 8192; glitch filter recognizes change on input pin after 4096 rising clock edges.
 *  0b1101..Prescaler divides the prescaler clock by 16,384; glitch filter recognizes change on input pin after 8192 rising clock edges.
 *  0b1110..Prescaler divides the prescaler clock by 32,768; glitch filter recognizes change on input pin after 16,384 rising clock edges.
 *  0b1111..Prescaler divides the prescaler clock by 65,536; glitch filter recognizes change on input pin after 32,768 rising clock edges.
 */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PRESCALE_SHIFT)) & LPTMR_PSR_PRESCALE_MASK)
/*! @} */

/*! @name CMR - Low Power Timer Compare Register */
/*! @{ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFFFFFU)
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x)) << LPTMR_CMR_COMPARE_SHIFT)) & LPTMR_CMR_COMPARE_MASK)
/*! @} */

/*! @name CNR - Low Power Timer Counter Register */
/*! @{ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFFFFFU)
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x)) << LPTMR_CNR_COUNTER_SHIFT)) & LPTMR_CNR_COUNTER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x05000000)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0x06000000)
/** Peripheral LPTMR2 base pointer */
#define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR1_BASE, LPTMR2_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR1, LPTMR2 }

/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */

/** LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x14 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DER;                               /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  __IO uint32_t CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  __IO uint32_t DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       uint8_t RESERVED_3[20];
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x58 */
  __I  uint32_t FSR;                               /**< FIFO Status Register, offset: 0x5C */
  __IO uint32_t TCR;                               /**< Transmit Command Register, offset: 0x60 */
  __O  uint32_t TDR;                               /**< Transmit Data Register, offset: 0x64 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x70 */
  __I  uint32_t RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type;

/* ----------------------------------------------------------------------------
   -- LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Masks LPSPI Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */
#define LPSPI_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPSPI_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Module Identification Number
 *  0b0000000000000100..Standard feature set supporting a 32-bit shift register.
 */
#define LPSPI_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_FEATURE_SHIFT)) & LPSPI_VERID_FEATURE_MASK)
#define LPSPI_VERID_MINOR_MASK                   (0xFF0000U)
#define LPSPI_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number
 */
#define LPSPI_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_MINOR_SHIFT)) & LPSPI_VERID_MINOR_MASK)
#define LPSPI_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPSPI_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number
 */
#define LPSPI_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_MAJOR_SHIFT)) & LPSPI_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */
#define LPSPI_PARAM_TXFIFO_MASK                  (0xFFU)
#define LPSPI_PARAM_TXFIFO_SHIFT                 (0U)
/*! TXFIFO - Transmit FIFO Size
 */
#define LPSPI_PARAM_TXFIFO(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_PARAM_TXFIFO_SHIFT)) & LPSPI_PARAM_TXFIFO_MASK)
#define LPSPI_PARAM_RXFIFO_MASK                  (0xFF00U)
#define LPSPI_PARAM_RXFIFO_SHIFT                 (8U)
/*! RXFIFO - Receive FIFO Size
 */
#define LPSPI_PARAM_RXFIFO(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_PARAM_RXFIFO_SHIFT)) & LPSPI_PARAM_RXFIFO_MASK)
#define LPSPI_PARAM_PCSNUM_MASK                  (0xFF0000U)
#define LPSPI_PARAM_PCSNUM_SHIFT                 (16U)
/*! PCSNUM - PCS Number
 */
#define LPSPI_PARAM_PCSNUM(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_PARAM_PCSNUM_SHIFT)) & LPSPI_PARAM_PCSNUM_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */
#define LPSPI_CR_MEN_MASK                        (0x1U)
#define LPSPI_CR_MEN_SHIFT                       (0U)
/*! MEN - Module Enable
 *  0b0..Module is disabled
 *  0b1..Module is enabled
 */
#define LPSPI_CR_MEN(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_MEN_SHIFT)) & LPSPI_CR_MEN_MASK)
#define LPSPI_CR_RST_MASK                        (0x2U)
#define LPSPI_CR_RST_SHIFT                       (1U)
/*! RST - Software Reset
 *  0b0..Module is not reset
 *  0b1..Module is reset
 */
#define LPSPI_CR_RST(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RST_SHIFT)) & LPSPI_CR_RST_MASK)
#define LPSPI_CR_DOZEN_MASK                      (0x4U)
#define LPSPI_CR_DOZEN_SHIFT                     (2U)
/*! DOZEN - Doze mode enable
 *  0b0..Module is enabled in Doze mode
 *  0b1..Module is disabled in Doze mode
 */
#define LPSPI_CR_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_DOZEN_SHIFT)) & LPSPI_CR_DOZEN_MASK)
#define LPSPI_CR_DBGEN_MASK                      (0x8U)
#define LPSPI_CR_DBGEN_SHIFT                     (3U)
/*! DBGEN - Debug Enable
 *  0b0..Module is disabled in debug mode
 *  0b1..Module is enabled in debug mode
 */
#define LPSPI_CR_DBGEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_DBGEN_SHIFT)) & LPSPI_CR_DBGEN_MASK)
#define LPSPI_CR_RTF_MASK                        (0x100U)
#define LPSPI_CR_RTF_SHIFT                       (8U)
/*! RTF - Reset Transmit FIFO
 *  0b0..No effect
 *  0b1..Transmit FIFO is reset
 */
#define LPSPI_CR_RTF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RTF_SHIFT)) & LPSPI_CR_RTF_MASK)
#define LPSPI_CR_RRF_MASK                        (0x200U)
#define LPSPI_CR_RRF_SHIFT                       (9U)
/*! RRF - Reset Receive FIFO
 *  0b0..No effect
 *  0b1..Receive FIFO is reset
 */
#define LPSPI_CR_RRF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RRF_SHIFT)) & LPSPI_CR_RRF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */
#define LPSPI_SR_TDF_MASK                        (0x1U)
#define LPSPI_SR_TDF_SHIFT                       (0U)
/*! TDF - Transmit Data Flag
 *  0b0..Transmit data not requested
 *  0b1..Transmit data is requested
 */
#define LPSPI_SR_TDF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TDF_SHIFT)) & LPSPI_SR_TDF_MASK)
#define LPSPI_SR_RDF_MASK                        (0x2U)
#define LPSPI_SR_RDF_SHIFT                       (1U)
/*! RDF - Receive Data Flag
 *  0b0..Receive Data is not ready
 *  0b1..Receive data is ready
 */
#define LPSPI_SR_RDF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_RDF_SHIFT)) & LPSPI_SR_RDF_MASK)
#define LPSPI_SR_WCF_MASK                        (0x100U)
#define LPSPI_SR_WCF_SHIFT                       (8U)
/*! WCF - Word Complete Flag
 *  0b0..Transfer of a received word has not yet completed
 *  0b1..Transfer of a received word has completed
 */
#define LPSPI_SR_WCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_WCF_SHIFT)) & LPSPI_SR_WCF_MASK)
#define LPSPI_SR_FCF_MASK                        (0x200U)
#define LPSPI_SR_FCF_SHIFT                       (9U)
/*! FCF - Frame Complete Flag
 *  0b0..Frame transfer has not completed
 *  0b1..Frame transfer has completed
 */
#define LPSPI_SR_FCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_FCF_SHIFT)) & LPSPI_SR_FCF_MASK)
#define LPSPI_SR_TCF_MASK                        (0x400U)
#define LPSPI_SR_TCF_SHIFT                       (10U)
/*! TCF - Transfer Complete Flag
 *  0b0..All transfers have not completed
 *  0b1..All transfers have completed
 */
#define LPSPI_SR_TCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TCF_SHIFT)) & LPSPI_SR_TCF_MASK)
#define LPSPI_SR_TEF_MASK                        (0x800U)
#define LPSPI_SR_TEF_SHIFT                       (11U)
/*! TEF - Transmit Error Flag
 *  0b0..Transmit FIFO underrun has not occurred
 *  0b1..Transmit FIFO underrun has occurred
 */
#define LPSPI_SR_TEF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TEF_SHIFT)) & LPSPI_SR_TEF_MASK)
#define LPSPI_SR_REF_MASK                        (0x1000U)
#define LPSPI_SR_REF_SHIFT                       (12U)
/*! REF - Receive Error Flag
 *  0b0..Receive FIFO has not overflowed
 *  0b1..Receive FIFO has overflowed
 */
#define LPSPI_SR_REF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_REF_SHIFT)) & LPSPI_SR_REF_MASK)
#define LPSPI_SR_DMF_MASK                        (0x2000U)
#define LPSPI_SR_DMF_SHIFT                       (13U)
/*! DMF - Data Match Flag
 *  0b0..Have not received matching data
 *  0b1..Have received matching data
 */
#define LPSPI_SR_DMF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_DMF_SHIFT)) & LPSPI_SR_DMF_MASK)
#define LPSPI_SR_MBF_MASK                        (0x1000000U)
#define LPSPI_SR_MBF_SHIFT                       (24U)
/*! MBF - Module Busy Flag
 *  0b0..LPSPI is idle
 *  0b1..LPSPI is busy
 */
#define LPSPI_SR_MBF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_MBF_SHIFT)) & LPSPI_SR_MBF_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */
#define LPSPI_IER_TDIE_MASK                      (0x1U)
#define LPSPI_IER_TDIE_SHIFT                     (0U)
/*! TDIE - Transmit Data Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TDIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TDIE_SHIFT)) & LPSPI_IER_TDIE_MASK)
#define LPSPI_IER_RDIE_MASK                      (0x2U)
#define LPSPI_IER_RDIE_SHIFT                     (1U)
/*! RDIE - Receive Data Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_RDIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_RDIE_SHIFT)) & LPSPI_IER_RDIE_MASK)
#define LPSPI_IER_WCIE_MASK                      (0x100U)
#define LPSPI_IER_WCIE_SHIFT                     (8U)
/*! WCIE - Word Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_WCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_WCIE_SHIFT)) & LPSPI_IER_WCIE_MASK)
#define LPSPI_IER_FCIE_MASK                      (0x200U)
#define LPSPI_IER_FCIE_SHIFT                     (9U)
/*! FCIE - Frame Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_FCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_FCIE_SHIFT)) & LPSPI_IER_FCIE_MASK)
#define LPSPI_IER_TCIE_MASK                      (0x400U)
#define LPSPI_IER_TCIE_SHIFT                     (10U)
/*! TCIE - Transfer Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TCIE_SHIFT)) & LPSPI_IER_TCIE_MASK)
#define LPSPI_IER_TEIE_MASK                      (0x800U)
#define LPSPI_IER_TEIE_SHIFT                     (11U)
/*! TEIE - Transmit Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TEIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TEIE_SHIFT)) & LPSPI_IER_TEIE_MASK)
#define LPSPI_IER_REIE_MASK                      (0x1000U)
#define LPSPI_IER_REIE_SHIFT                     (12U)
/*! REIE - Receive Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_REIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_REIE_SHIFT)) & LPSPI_IER_REIE_MASK)
#define LPSPI_IER_DMIE_MASK                      (0x2000U)
#define LPSPI_IER_DMIE_SHIFT                     (13U)
/*! DMIE - Data Match Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_DMIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_DMIE_SHIFT)) & LPSPI_IER_DMIE_MASK)
/*! @} */

/*! @name DER - DMA Enable Register */
/*! @{ */
#define LPSPI_DER_TDDE_MASK                      (0x1U)
#define LPSPI_DER_TDDE_SHIFT                     (0U)
/*! TDDE - Transmit Data DMA Enable
 *  0b0..DMA request is disabled
 *  0b1..DMA request is enabled
 */
#define LPSPI_DER_TDDE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_DER_TDDE_SHIFT)) & LPSPI_DER_TDDE_MASK)
#define LPSPI_DER_RDDE_MASK                      (0x2U)
#define LPSPI_DER_RDDE_SHIFT                     (1U)
/*! RDDE - Receive Data DMA Enable
 *  0b0..DMA request is disabled
 *  0b1..DMA request is enabled
 */
#define LPSPI_DER_RDDE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_DER_RDDE_SHIFT)) & LPSPI_DER_RDDE_MASK)
/*! @} */

/*! @name CFGR0 - Configuration Register 0 */
/*! @{ */
#define LPSPI_CFGR0_HREN_MASK                    (0x1U)
#define LPSPI_CFGR0_HREN_SHIFT                   (0U)
/*! HREN - Host Request Enable
 *  0b0..Host request is disabled
 *  0b1..Host request is enabled
 */
#define LPSPI_CFGR0_HREN(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HREN_SHIFT)) & LPSPI_CFGR0_HREN_MASK)
#define LPSPI_CFGR0_HRPOL_MASK                   (0x2U)
#define LPSPI_CFGR0_HRPOL_SHIFT                  (1U)
/*! HRPOL - Host Request Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define LPSPI_CFGR0_HRPOL(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HRPOL_SHIFT)) & LPSPI_CFGR0_HRPOL_MASK)
#define LPSPI_CFGR0_HRSEL_MASK                   (0x4U)
#define LPSPI_CFGR0_HRSEL_SHIFT                  (2U)
/*! HRSEL - Host Request Select
 *  0b0..Host request input is the LPSPI_HREQ pin
 *  0b1..Host request input is the input trigger
 */
#define LPSPI_CFGR0_HRSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HRSEL_SHIFT)) & LPSPI_CFGR0_HRSEL_MASK)
#define LPSPI_CFGR0_CIRFIFO_MASK                 (0x100U)
#define LPSPI_CFGR0_CIRFIFO_SHIFT                (8U)
/*! CIRFIFO - Circular FIFO Enable
 *  0b0..Circular FIFO is disabled
 *  0b1..Circular FIFO is enabled
 */
#define LPSPI_CFGR0_CIRFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_CIRFIFO_SHIFT)) & LPSPI_CFGR0_CIRFIFO_MASK)
#define LPSPI_CFGR0_RDMO_MASK                    (0x200U)
#define LPSPI_CFGR0_RDMO_SHIFT                   (9U)
/*! RDMO - Receive Data Match Only
 *  0b0..Received data is stored in the receive FIFO as in normal operations
 *  0b1..Received data is discarded unless the Data Match Flag (DMF) is set
 */
#define LPSPI_CFGR0_RDMO(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_RDMO_SHIFT)) & LPSPI_CFGR0_RDMO_MASK)
/*! @} */

/*! @name CFGR1 - Configuration Register 1 */
/*! @{ */
#define LPSPI_CFGR1_MASTER_MASK                  (0x1U)
#define LPSPI_CFGR1_MASTER_SHIFT                 (0U)
/*! MASTER - Master Mode
 *  0b0..Slave mode
 *  0b1..Master mode
 */
#define LPSPI_CFGR1_MASTER(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_MASTER_SHIFT)) & LPSPI_CFGR1_MASTER_MASK)
#define LPSPI_CFGR1_SAMPLE_MASK                  (0x2U)
#define LPSPI_CFGR1_SAMPLE_SHIFT                 (1U)
/*! SAMPLE - Sample Point
 *  0b0..Input data is sampled on SCK edge
 *  0b1..Input data is sampled on delayed SCK edge
 */
#define LPSPI_CFGR1_SAMPLE(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_SAMPLE_SHIFT)) & LPSPI_CFGR1_SAMPLE_MASK)
#define LPSPI_CFGR1_AUTOPCS_MASK                 (0x4U)
#define LPSPI_CFGR1_AUTOPCS_SHIFT                (2U)
/*! AUTOPCS - Automatic PCS
 *  0b0..Automatic PCS generation is disabled
 *  0b1..Automatic PCS generation is enabled
 */
#define LPSPI_CFGR1_AUTOPCS(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_AUTOPCS_SHIFT)) & LPSPI_CFGR1_AUTOPCS_MASK)
#define LPSPI_CFGR1_NOSTALL_MASK                 (0x8U)
#define LPSPI_CFGR1_NOSTALL_SHIFT                (3U)
/*! NOSTALL - No Stall
 *  0b0..Transfers will stall when the transmit FIFO is empty or the receive FIFO is full
 *  0b1..Transfers will not stall, allowing transmit FIFO underruns or receive FIFO overruns to occur
 */
#define LPSPI_CFGR1_NOSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_NOSTALL_SHIFT)) & LPSPI_CFGR1_NOSTALL_MASK)
#define LPSPI_CFGR1_PCSPOL_MASK                  (0xF00U)
#define LPSPI_CFGR1_PCSPOL_SHIFT                 (8U)
/*! PCSPOL - Peripheral Chip Select Polarity
 *  0b0000..The Peripheral Chip Select pin PCSx is active low
 *  0b0001..The Peripheral Chip Select pin PCSx is active high
 */
#define LPSPI_CFGR1_PCSPOL(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PCSPOL_SHIFT)) & LPSPI_CFGR1_PCSPOL_MASK)
#define LPSPI_CFGR1_MATCFG_MASK                  (0x70000U)
#define LPSPI_CFGR1_MATCFG_SHIFT                 (16U)
/*! MATCFG - Match Configuration
 *  0b000..Match is disabled
 *  0b001..Reserved
 *  0b010..010b - Match is enabled, if 1st data word equals MATCH0 OR MATCH1, i.e., (1st data word = MATCH0 + MATCH1)
 *  0b011..011b - Match is enabled, if any data word equals MATCH0 OR MATCH1, i.e., (any data word = MATCH0 + MATCH1)
 *  0b100..100b - Match is enabled, if 1st data word equals MATCH0 AND 2nd data word equals MATCH1, i.e., [(1st
 *         data word = MATCH0) * (2nd data word = MATCH1)]
 *  0b101..101b - Match is enabled, if any data word equals MATCH0 AND the next data word equals MATCH1, i.e.,
 *         [(any data word = MATCH0) * (next data word = MATCH1)]
 *  0b110..110b - Match is enabled, if (1st data word AND MATCH1) equals (MATCH0 AND MATCH1), i.e., [(1st data word * MATCH1) = (MATCH0 * MATCH1)]
 *  0b111..111b - Match is enabled, if (any data word AND MATCH1) equals (MATCH0 AND MATCH1), i.e., [(any data word * MATCH1) = (MATCH0 * MATCH1)]
 */
#define LPSPI_CFGR1_MATCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_MATCFG_SHIFT)) & LPSPI_CFGR1_MATCFG_MASK)
#define LPSPI_CFGR1_PINCFG_MASK                  (0x3000000U)
#define LPSPI_CFGR1_PINCFG_SHIFT                 (24U)
/*! PINCFG - Pin Configuration
 *  0b00..SIN is used for input data and SOUT is used for output data
 *  0b01..SIN is used for both input and output data
 *  0b10..SOUT is used for both input and output data
 *  0b11..SOUT is used for input data and SIN is used for output data
 */
#define LPSPI_CFGR1_PINCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PINCFG_SHIFT)) & LPSPI_CFGR1_PINCFG_MASK)
#define LPSPI_CFGR1_OUTCFG_MASK                  (0x4000000U)
#define LPSPI_CFGR1_OUTCFG_SHIFT                 (26U)
/*! OUTCFG - Output Config
 *  0b0..Output data retains last value when chip select is negated
 *  0b1..Output data is tristated when chip select is negated
 */
#define LPSPI_CFGR1_OUTCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_OUTCFG_SHIFT)) & LPSPI_CFGR1_OUTCFG_MASK)
#define LPSPI_CFGR1_PCSCFG_MASK                  (0x8000000U)
#define LPSPI_CFGR1_PCSCFG_SHIFT                 (27U)
/*! PCSCFG - Peripheral Chip Select Configuration
 *  0b0..PCS[3:2] are enabled
 *  0b1..PCS[3:2] are disabled
 */
#define LPSPI_CFGR1_PCSCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PCSCFG_SHIFT)) & LPSPI_CFGR1_PCSCFG_MASK)
/*! @} */

/*! @name DMR0 - Data Match Register 0 */
/*! @{ */
#define LPSPI_DMR0_MATCH0_MASK                   (0xFFFFFFFFU)
#define LPSPI_DMR0_MATCH0_SHIFT                  (0U)
/*! MATCH0 - Match 0 Value
 */
#define LPSPI_DMR0_MATCH0(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_DMR0_MATCH0_SHIFT)) & LPSPI_DMR0_MATCH0_MASK)
/*! @} */

/*! @name DMR1 - Data Match Register 1 */
/*! @{ */
#define LPSPI_DMR1_MATCH1_MASK                   (0xFFFFFFFFU)
#define LPSPI_DMR1_MATCH1_SHIFT                  (0U)
/*! MATCH1 - Match 1 Value
 */
#define LPSPI_DMR1_MATCH1(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_DMR1_MATCH1_SHIFT)) & LPSPI_DMR1_MATCH1_MASK)
/*! @} */

/*! @name CCR - Clock Configuration Register */
/*! @{ */
#define LPSPI_CCR_SCKDIV_MASK                    (0xFFU)
#define LPSPI_CCR_SCKDIV_SHIFT                   (0U)
/*! SCKDIV - SCK Divider
 */
#define LPSPI_CCR_SCKDIV(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_SCKDIV_SHIFT)) & LPSPI_CCR_SCKDIV_MASK)
#define LPSPI_CCR_DBT_MASK                       (0xFF00U)
#define LPSPI_CCR_DBT_SHIFT                      (8U)
/*! DBT - Delay Between Transfers
 */
#define LPSPI_CCR_DBT(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_DBT_SHIFT)) & LPSPI_CCR_DBT_MASK)
#define LPSPI_CCR_PCSSCK_MASK                    (0xFF0000U)
#define LPSPI_CCR_PCSSCK_SHIFT                   (16U)
/*! PCSSCK - PCS-to-SCK Delay
 */
#define LPSPI_CCR_PCSSCK(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_PCSSCK_SHIFT)) & LPSPI_CCR_PCSSCK_MASK)
#define LPSPI_CCR_SCKPCS_MASK                    (0xFF000000U)
#define LPSPI_CCR_SCKPCS_SHIFT                   (24U)
/*! SCKPCS - SCK-to-PCS Delay
 */
#define LPSPI_CCR_SCKPCS(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_SCKPCS_SHIFT)) & LPSPI_CCR_SCKPCS_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */
#define LPSPI_FCR_TXWATER_MASK                   (0xFU)
#define LPSPI_FCR_TXWATER_SHIFT                  (0U)
/*! TXWATER - Transmit FIFO Watermark
 */
#define LPSPI_FCR_TXWATER(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FCR_TXWATER_SHIFT)) & LPSPI_FCR_TXWATER_MASK)
#define LPSPI_FCR_RXWATER_MASK                   (0xF0000U)
#define LPSPI_FCR_RXWATER_SHIFT                  (16U)
/*! RXWATER - Receive FIFO Watermark
 */
#define LPSPI_FCR_RXWATER(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FCR_RXWATER_SHIFT)) & LPSPI_FCR_RXWATER_MASK)
/*! @} */

/*! @name FSR - FIFO Status Register */
/*! @{ */
#define LPSPI_FSR_TXCOUNT_MASK                   (0x1FU)
#define LPSPI_FSR_TXCOUNT_SHIFT                  (0U)
/*! TXCOUNT - Transmit FIFO Count
 */
#define LPSPI_FSR_TXCOUNT(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FSR_TXCOUNT_SHIFT)) & LPSPI_FSR_TXCOUNT_MASK)
#define LPSPI_FSR_RXCOUNT_MASK                   (0x1F0000U)
#define LPSPI_FSR_RXCOUNT_SHIFT                  (16U)
/*! RXCOUNT - Receive FIFO Count
 */
#define LPSPI_FSR_RXCOUNT(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FSR_RXCOUNT_SHIFT)) & LPSPI_FSR_RXCOUNT_MASK)
/*! @} */

/*! @name TCR - Transmit Command Register */
/*! @{ */
#define LPSPI_TCR_FRAMESZ_MASK                   (0xFFFU)
#define LPSPI_TCR_FRAMESZ_SHIFT                  (0U)
/*! FRAMESZ - Frame Size
 */
#define LPSPI_TCR_FRAMESZ(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_FRAMESZ_SHIFT)) & LPSPI_TCR_FRAMESZ_MASK)
#define LPSPI_TCR_WIDTH_MASK                     (0x30000U)
#define LPSPI_TCR_WIDTH_SHIFT                    (16U)
/*! WIDTH - Transfer Width
 *  0b00..1 bit transfer
 *  0b01..2 bit transfer
 *  0b10..4 bit transfer
 *  0b11..Reserved
 */
#define LPSPI_TCR_WIDTH(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_WIDTH_SHIFT)) & LPSPI_TCR_WIDTH_MASK)
#define LPSPI_TCR_TXMSK_MASK                     (0x40000U)
#define LPSPI_TCR_TXMSK_SHIFT                    (18U)
/*! TXMSK - Transmit Data Mask
 *  0b0..Normal transfer
 *  0b1..Mask transmit data
 */
#define LPSPI_TCR_TXMSK(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_TXMSK_SHIFT)) & LPSPI_TCR_TXMSK_MASK)
#define LPSPI_TCR_RXMSK_MASK                     (0x80000U)
#define LPSPI_TCR_RXMSK_SHIFT                    (19U)
/*! RXMSK - Receive Data Mask
 *  0b0..Normal transfer
 *  0b1..Receive data is masked
 */
#define LPSPI_TCR_RXMSK(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_RXMSK_SHIFT)) & LPSPI_TCR_RXMSK_MASK)
#define LPSPI_TCR_CONTC_MASK                     (0x100000U)
#define LPSPI_TCR_CONTC_SHIFT                    (20U)
/*! CONTC - Continuing Command
 *  0b0..Command word for start of new transfer
 *  0b1..Command word for continuing transfer
 */
#define LPSPI_TCR_CONTC(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CONTC_SHIFT)) & LPSPI_TCR_CONTC_MASK)
#define LPSPI_TCR_CONT_MASK                      (0x200000U)
#define LPSPI_TCR_CONT_SHIFT                     (21U)
/*! CONT - Continuous Transfer
 *  0b0..Continuous transfer is disabled
 *  0b1..Continuous transfer is enabled
 */
#define LPSPI_TCR_CONT(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CONT_SHIFT)) & LPSPI_TCR_CONT_MASK)
#define LPSPI_TCR_BYSW_MASK                      (0x400000U)
#define LPSPI_TCR_BYSW_SHIFT                     (22U)
/*! BYSW - Byte Swap
 *  0b0..Byte swap is disabled
 *  0b1..Byte swap is enabled
 */
#define LPSPI_TCR_BYSW(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_BYSW_SHIFT)) & LPSPI_TCR_BYSW_MASK)
#define LPSPI_TCR_LSBF_MASK                      (0x800000U)
#define LPSPI_TCR_LSBF_SHIFT                     (23U)
/*! LSBF - LSB First
 *  0b0..Data is transferred MSB first
 *  0b1..Data is transferred LSB first
 */
#define LPSPI_TCR_LSBF(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_LSBF_SHIFT)) & LPSPI_TCR_LSBF_MASK)
#define LPSPI_TCR_PCS_MASK                       (0x3000000U)
#define LPSPI_TCR_PCS_SHIFT                      (24U)
/*! PCS - Peripheral Chip Select
 *  0b00..Transfer using LPSPI_PCS[0]
 *  0b01..Transfer using LPSPI_PCS[1]
 *  0b10..Transfer using LPSPI_PCS[2]
 *  0b11..Transfer using LPSPI_PCS[3]
 */
#define LPSPI_TCR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_PCS_SHIFT)) & LPSPI_TCR_PCS_MASK)
#define LPSPI_TCR_PRESCALE_MASK                  (0x38000000U)
#define LPSPI_TCR_PRESCALE_SHIFT                 (27U)
/*! PRESCALE - Prescaler Value
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 *  0b110..Divide by 64
 *  0b111..Divide by 128
 */
#define LPSPI_TCR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_PRESCALE_SHIFT)) & LPSPI_TCR_PRESCALE_MASK)
#define LPSPI_TCR_CPHA_MASK                      (0x40000000U)
#define LPSPI_TCR_CPHA_SHIFT                     (30U)
/*! CPHA - Clock Phase
 *  0b0..Data is captured on the leading edge of SCK and changed on the following edge of SCK
 *  0b1..Data is changed on the leading edge of SCK and captured on the following edge of SCK
 */
#define LPSPI_TCR_CPHA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CPHA_SHIFT)) & LPSPI_TCR_CPHA_MASK)
#define LPSPI_TCR_CPOL_MASK                      (0x80000000U)
#define LPSPI_TCR_CPOL_SHIFT                     (31U)
/*! CPOL - Clock Polarity
 *  0b0..The inactive state value of SCK is low
 *  0b1..The inactive state value of SCK is high
 */
#define LPSPI_TCR_CPOL(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CPOL_SHIFT)) & LPSPI_TCR_CPOL_MASK)
/*! @} */

/*! @name TDR - Transmit Data Register */
/*! @{ */
#define LPSPI_TDR_DATA_MASK                      (0xFFFFFFFFU)
#define LPSPI_TDR_DATA_SHIFT                     (0U)
/*! DATA - Transmit Data
 */
#define LPSPI_TDR_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TDR_DATA_SHIFT)) & LPSPI_TDR_DATA_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */
#define LPSPI_RSR_SOF_MASK                       (0x1U)
#define LPSPI_RSR_SOF_SHIFT                      (0U)
/*! SOF - Start Of Frame
 *  0b0..Subsequent data word received after LPSPI_PCS assertion
 *  0b1..First data word received after LPSPI_PCS assertion
 */
#define LPSPI_RSR_SOF(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_RSR_SOF_SHIFT)) & LPSPI_RSR_SOF_MASK)
#define LPSPI_RSR_RXEMPTY_MASK                   (0x2U)
#define LPSPI_RSR_RXEMPTY_SHIFT                  (1U)
/*! RXEMPTY - RX FIFO Empty
 *  0b0..RX FIFO is not empty
 *  0b1..RX FIFO is empty
 */
#define LPSPI_RSR_RXEMPTY(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_RSR_RXEMPTY_SHIFT)) & LPSPI_RSR_RXEMPTY_MASK)
/*! @} */

/*! @name RDR - Receive Data Register */
/*! @{ */
#define LPSPI_RDR_DATA_MASK                      (0xFFFFFFFFU)
#define LPSPI_RDR_DATA_SHIFT                     (0U)
/*! DATA - Receive Data
 */
#define LPSPI_RDR_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_RDR_DATA_SHIFT)) & LPSPI_RDR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPSPI_Register_Masks */


/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x07000000)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x08000000)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI1_BASE, LPSPI2_BASE}
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI1, LPSPI2 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI1_IRQn, LPSPI2_IRQn }

/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */



#endif /* __CPU_H_ */
