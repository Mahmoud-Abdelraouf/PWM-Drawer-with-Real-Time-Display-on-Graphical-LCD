/**<  LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**<  MCAL */
#include "TIMERS_2_interface.h"
#include "TIMERS_2_config.h"
#include "TIMERS_2_private.h"

/**
 * static functions
 */
/**< Helper Function to delay 1ms */
static void delay_1ms(void);
/**< Helper Function to delay 1us */
static void delay_1us(void);
/**< Helper Function to delay 10us */
static void delay_10us(void);
/**< Helper Function to delay 10ms */
static void delay_10ms(void);

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

Std_ReturnType timer2_delay_ms(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    u32 Local_Counter = 0;
    for (Local_Counter = 0; Local_Counter < delay_time; Local_Counter++)
    {
        delay_1ms();
    }
    return Local_FunctionStatus;
}

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

Std_ReturnType timer2_delay_10ms(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    u32 Local_Counter = 0;
    for (Local_Counter = 0; Local_Counter < delay_time; Local_Counter++)
    {
        delay_10ms();
    }
    return Local_FunctionStatus;
}

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

Std_ReturnType timer2_delay_us(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    u32 Local_Counter = 0;
    for (Local_Counter = 0; Local_Counter < delay_time; Local_Counter++)
    {
        delay_1us();
    }
    return Local_FunctionStatus;
}

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

Std_ReturnType timer2_delay_10us(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    u32 Local_Counter = 0;
    for (Local_Counter = 0; Local_Counter < delay_time; Local_Counter++)
    {
        delay_10us();
    }
    return Local_FunctionStatus;
}

static void delay_10ms(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XB2); /* preloaded value -> 178 (0xB2)*/
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1024);
    while ((TIMER2_TIFR_R & 0x40) == 0)
        ;
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}

static void delay_1ms(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XF0); /* preloaded value -> 240 (0xF0)*/
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1024);
    while ((TIMER2_TIFR_R & 0x40) == 0)
        ;
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}

static void delay_1us(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XF0); /* preloaded value -> 240 (0xF0)*/
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1);
    while ((TIMER2_TIFR_R & 0x40) == 0)
        ;
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}

static void delay_10us(void)
{
    TIMER2_PRELOAD_VALUE_SET(0X61); /* preloaded value -> 97 (0x61)*/
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1);
    while ((TIMER2_TIFR_R & 0x40) == 0)
        ;
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}