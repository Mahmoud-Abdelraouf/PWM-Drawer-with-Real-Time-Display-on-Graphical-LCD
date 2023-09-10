/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 30/09/2022              *************************/
/************** SWC     : EXTI                    *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __EXTI_PRIVATE_H_
#define __EXTI_PRIVATE_H_

/**
 * @brief External Interrupt (EXTI) Registers
 *
 * These macros represent the memory-mapped addresses of the EXTI control registers.
 */
#define EXTI_MCUCR_R            (*((volatile u8 *)0X55)) /**< MCU Control Register for External Interrupts */
#define EXTI_MCUCSR_R           (*((volatile u8 *)0X54)) /**< MCU Control and Status Register for External Interrupts */
#define EXTI_GICR_R             (*((volatile u8 *)0X5B)) /**< General Interrupt Control Register */
#define EXTI_GIFR_R             (*((volatile u8 *)0X5A)) /**< General Interrupt Flag Register */

/**
 * @addtogroup EXTI_MCUCR_Bits External Interrupt (EXTI) MCU Control Register Bits
 * @{
 */

/**
 * @brief Bit 0 in MCU Control Register (MCUCR) - ISC00: Interrupt Sense Control Bit 0
 */
#define ISC00_BIT               0

/**
 * @brief Bit 1 in MCU Control Register (MCUCR) - ISC01: Interrupt Sense Control Bit 1
 */
#define ISC01_BIT               1

/**
 * @brief Bit 2 in MCU Control Register (MCUCR) - ISC10: Interrupt Sense Control Bit 2
 */
#define ISC10_BIT               2

/**
 * @brief Bit 3 in MCU Control Register (MCUCR) - ISC11: Interrupt Sense Control Bit 3
 */
#define ISC11_BIT               3

/** @} EXTI_MCUCR_Bits */

/**
 * @addtogroup EXTI_GICR_Bits External Interrupt (EXTI) General Interrupt Control Register Bits
 * @{
 */

/**
 * @brief Bit 6 in General Interrupt Control Register (GICR) - INT0: External Interrupt Request 0 Enable
 */
#define INT0_BIT                6

/**
 * @brief Bit 7 in General Interrupt Control Register (GICR) - INT1: External Interrupt Request 1 Enable
 */
#define INT1_BIT                7

/**
 * @brief Bit 5 in General Interrupt Control Register (GICR) - INT2: External Interrupt Request 2 Enable
 */
#define INT2_BIT                5

/** @} EXTI_GICR_Bits */

/**
 * @addtogroup EXTI_MCUCSR_Bits External Interrupt (EXTI) MCU Control and Status Register Bits
 * @{
 */

/**
 * @brief Bit 6 in MCU Control and Status Register (MCUCSR) - ISC2: Interrupt Sense Control Bit 2
 */
#define ISC2_BIT                6

/** @} EXTI_MCUCSR_Bits */



#endif /**< __EXTI_PRIVATE_H_ */