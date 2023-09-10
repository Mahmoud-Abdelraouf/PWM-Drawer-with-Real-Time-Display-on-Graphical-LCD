/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 21/09/2022              *************************/
/************** SWC     : GIE                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __GIE_PRIVATE_H_
#define __GIE_PRIVATE_H_

/**
 * @brief Global Interrupt Enable (GIE) Register Address.
 *
 * This macro defines the memory address of the Global Interrupt Enable (GIE) register.
 */
#define GIE_SREG_R        (*((volatile u8 *)0X5F))

/**
 * @brief Global Interrupt Enable (GIE) Bit Position.
 *
 * This macro defines the bit position of the Global Interrupt Enable (GIE) bit
 * within the Status Register (SREG).
 */
#define GIE_SREG_B        7


#endif /**< __GIE_PRIVATE_H_ */