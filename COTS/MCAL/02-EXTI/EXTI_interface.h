/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 30/09/2022              *************************/
/************** SWC     : EXTI                    *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __EXTI_INTERFACE_H_
#define __EXTI_INTERFACE_H_

/**
 * @addtogroup EXTI_Interrupts External Interrupt Types
 * @{
 */

#define EXTI_INT0               0 /**< External Interrupt 0 */
#define EXTI_INT1               1 /**< External Interrupt 1 */
#define EXTI_INT2               2 /**< External Interrupt 2 */

/** @} EXTI_Interrupts */


/**
 * @addtogroup EXTI_TriggerModes External Interrupt Trigger Modes
 * @{
 */

#define EXTI_RAISING_EDGE       0 /**< Trigger on Rising Edge */
#define EXTI_FALLING_EDGE       1 /**< Trigger on Falling Edge */
#define EXTI_ANY_LOGICAL_CHANGE 2 /**< Trigger on Any Logical Change */
#define EXTI_LOW_LEVEL          3 /**< Trigger on Low Level */

/** @} EXTI_TriggerModes */



/**
 * @addtogroup EXTI_Functions
 * @{
 */

/**
 * @brief Enable External Interrupts with specified edge triggers.
 *
 * This function enables external interrupts with specified edge triggers for the
 * specified external interrupt index.
 *
 * @param[in] Copy_EXTIIndex The external interrupt index (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @param[in] Copy_EdgeIndex The edge trigger type (EXTI_RAISING_EDGE, EXTI_FALLING_EDGE,
 *                           EXTI_ANY_LOGICAL_CHANGE, or EXTI_LOW_LEVEL).
 *
 * @return Std_ReturnType
 *   - E_OK     : External interrupt enabled successfully.
 *   - E_NOT_OK : An error occurred (invalid EXTI index or edge trigger type).
 *
 * @note You should call this function to enable external interrupts with the desired edge trigger type.
 */
Std_ReturnType EXTI_Enable(u8 Copy_EXTIIndex, u8 Copy_EdgeIndex);

/**
 * @brief Disable External Interrupts.
 *
 * This function disables external interrupts for the specified external interrupt index.
 *
 * @param[in] Copy_EXTIIndex The external interrupt index (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 *
 * @return Std_ReturnType
 *   - E_OK     : External interrupt disabled successfully.
 *   - E_NOT_OK : An error occurred (invalid EXTI index).
 *
 * @note You should call this function to disable external interrupts for a specific index.
 */
Std_ReturnType EXTI_Disable(u8 Copy_EXTIIndex);

/**
 * @brief Register a Callback Function for External Interrupts.
 *
 * This function allows you to register a callback function to be executed when an external
 * interrupt occurs on the specified external interrupt index.
 *
 * @param[in] Copy_PF        A pointer to the callback function.
 * @param[in] Copy_EXTIIndex The external interrupt index (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 *
 * @return Std_ReturnType
 *   - E_OK     : Callback function registered successfully.
 *   - E_NOT_OK : An error occurred (invalid callback function or EXTI index).
 *
 * @note You should call this function to register a callback function that will be executed
 * when an external interrupt occurs on the specified index.
 */
Std_ReturnType EXTI_EXTICallBack(void (*Copy_PF)(void), u8 Copy_EXTIIndex);

/**
 * @} EXTI_Functions
 */

#endif /**< __EXTI_INTERFACE_H_ */
