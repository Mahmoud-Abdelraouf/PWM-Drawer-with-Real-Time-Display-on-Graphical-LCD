/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 21/09/2022              *************************/
/************** SWC     : GIE                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __GIE_INTERFACE_H_
#define __GIE_INTERFACE_H_

/**
 * @brief Enable Global Interrupts.
 *
 * This function enables global interrupts by setting the Global Interrupt Enable (GIE) bit
 * in the Status Register (SREG). Once enabled, interrupts at lower priority than the
 * current execution will be serviced.
 */
void GIE_voidEnable(void);

/**
 * @brief Disable Global Interrupts.
 *
 * This function disables global interrupts by clearing the Global Interrupt Enable (GIE) bit
 * in the Status Register (SREG). When global interrupts are disabled, no interrupts will
 * be serviced, allowing for critical sections of code.
 */
void GIE_voidDisable(void);


#endif /**< __GIE_INTERFACE_H_ */