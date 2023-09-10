#ifndef __TIMER2_INTERFACE_H_
#define __TIMER2_INTERFACE_H_
/**
 * @addtogroup TIMER2_Macros
 * @{
 */

/**< Macros for prescaler values */
#define TIMER2_PRESCALER_PRESCALER_DIV_1 1
#define TIMER2_PRESCALER_PRESCALER_DIV_8 2
#define TIMER2_PRESCALER_PRESCALER_DIV_32 3
#define TIMER2_PRESCALER_PRESCALER_DIV_64 4
#define TIMER2_PRESCALER_PRESCALER_DIV_128 5
#define TIMER2_PRESCALER_PRESCALER_DIV_256 6
#define TIMER2_PRESCALER_PRESCALER_DIV_1024 7

/**< Macros for Modes */
#define TIMER2_MODE_NORMAL 0
#define TIMER2_MODE_PWM_PHASE_CORRECT 1
#define TIMER2_MODE_CTC 2
#define TIMER2_MODE_PWM_FAST 3

/**< Macros for CTC mode */
#define TIMER2_NORMAL_OC2 0
#define TIMER2_TOGGLE_OC2 1
#define TIMER2_CLEAR_OC2 2
#define TIMER2_SET_OC2 3

/**
 * @} TIMER2_Macros
 */

/**
 * @addtogroup TIMER2_Function_Like_Macros
 * @{
 */

/**< Function like macros for disable Timer2 */
#define TIMER2_DSIABLE() (TIMER2_TCCR2_R = 0)
/**< Function like macros for preload */
#define TIMER2_PRELOAD_VALUE_SET(_CONFIG) (TIMER2_TCNT2_R = _CONFIG)
/**< Function like macros for prescale */
#define TIMER2_PRESCALER_VALUE_SET(_CONFIG) (TIMER2_TCCR2_R |= _CONFIG)
/**< Function like macros for interrupts */
#define TIMER2_INTERRUPT_COMPARE_ENABLE() (SET_BIT(TIMER2_TIMSK_R, 7))
/**< Function like macros for interrupt overflow enable */
#define TIMER2_INTERRUPT_OVERFLOW_ENABLE() (SET_BIT(TIMER2_TIMSK_R, 6))
/**< Function like macros for clear the flag of Timer2 */
#define TIMER2_FLAG_CLEAR() (CLR_BIT(TIMER2_TIFR_R, 6))

/**
 * @} TIMER2_Function_Like_Macros
 */
/**
 * @addtogroup TIMER2_DataTypes
 * @{
 */

/**
 * @} TIMER2_DataTypes
 */

/**
 * @addtogroup TIMER2_Functions
 * @{
 */

/**
 * @brief Delays the program execution for a specified time using Timer/Counter 2 in milliseconds.
 *
 * This function generates a delay by utilizing Timer/Counter 2 in the Atmega32 microcontroller.
 * It configures Timer/Counter 2 in a mode suitable for generating accurate delays in milliseconds.
 *
 * @param delay_time The delay time in milliseconds. The valid range depends on the clock frequency and Timer/Counter 2 settings.
 * @return Std_ReturnType Represents the status of the delay operation.
 *         - E_OK: Delay completed successfully.
 *         - E_NOT_OK: Delay operation failed due to invalid input or other reasons.
 *
 */

Std_ReturnType timer2_delay_ms(u32 delay_time);

/**
 * @brief Delays the program execution for a specified time using Timer/Counter 2 in macroseconds.
 *
 * This function generates a delay by utilizing Timer/Counter 2 in the Atmega32 microcontroller.
 * It configures Timer/Counter 2 in a mode suitable for generating accurate delays in macroseconds.
 *
 * @param delay_time The delay time in macroseconds. The valid range depends on the clock frequency and Timer/Counter 2 settings.
 * @return Std_ReturnType Represents the status of the delay operation.
 *         - E_OK: Delay completed successfully.
 *         - E_NOT_OK: Delay operation failed due to invalid input or other reasons.
 *
 */

Std_ReturnType timer2_delay_us(u32 delay_time);

/**
 * @brief Delays the program execution for a specified time using Timer/Counter 2 in 10 macroseconds.
 *
 * This function generates a delay by utilizing Timer/Counter 2 in the Atmega32 microcontroller.
 * It configures Timer/Counter 2 in a mode suitable for generating accurate delays in macroseconds.
 *
 * @param delay_time The delay time in 10 macroseconds. The valid range depends on the clock frequency and Timer/Counter 2 settings.
 * @return Std_ReturnType Represents the status of the delay operation.
 *         - E_OK: Delay completed successfully.
 *         - E_NOT_OK: Delay operation failed due to invalid input or other reasons.
 *
 */

Std_ReturnType timer2_delay_10us(u32 delay_time);

/**
 * @brief Delays the program execution for a specified time using Timer/Counter 2 in 10 milliseconds.
 *
 * This function generates a delay by utilizing Timer/Counter 2 in the Atmega32 microcontroller.
 * It configures Timer/Counter 2 in a mode suitable for generating accurate delays in macroseconds.
 *
 * @param delay_time The delay time in 10 milliseconds. The valid range depends on the clock frequency and Timer/Counter 2 settings.
 * @return Std_ReturnType Represents the status of the delay operation.
 *         - E_OK: Delay completed successfully.
 *         - E_NOT_OK: Delay operation failed due to invalid input or other reasons.
 *
 */

Std_ReturnType timer2_delay_10ms(u32 delay_time);

/**
 * @} TIMER2_Functions
 */
#endif /**< __TIMER2_INTERFACE_H_ */