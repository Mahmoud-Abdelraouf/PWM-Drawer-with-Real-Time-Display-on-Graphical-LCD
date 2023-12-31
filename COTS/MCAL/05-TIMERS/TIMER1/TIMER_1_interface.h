/**********************************************************/
/********** Name    : Ahmed Bakr & Ahmed Samir  ***********/
/********** Date    : 9/9/2023	              	***********/
/********** SWC     : TIMER1                  	***********/
/********** Version : 1.0                     	***********/
/**********************************************************/
#ifndef __TIMER_1_INTERFACE_H__
#define __TIMER_1_INTERFACE_H__

/************************  Sec: Includes ******************************/
/*lIB*/

#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
/*MCAL*/

#include "TIMER_1_private.h"
#include "TIMER_1_config.h"
#include "../../01-DIO/DIO_interface.h"



/************************  Sec: MACROS ******************************/

#ifndef F_CPU
#define F_CPU 16000000 //clock speed is 16MHz
#endif

/**<_prescaler*/
#define PRESCALAR_DIV_BY_1 			1
#define PRESCALAR_DIV_BY_8 			8U
#define PRESCALAR_DIV_BY_64 		64U
#define PRESCALAR_DIV_BY_256 		256U
#define PRESCALAR_DIV_BY_1024 		1024U
#define EXTERNAL_CLK_SRC_FALLING 	6U
#define EXTERNAL_CLK_SRC_RISING 	7U

/**<_modes*/
#define INPUT_CAPTURE_MODE 0
#define OUTPUT_CAPTURE_MODE 1
#define PWM_MODE 2
#define COUNTER_MODE 3

/**<_edge*/
#define RISING_EDGE 0
#define FALLING_EDGE 1

/************************  Sec: MACRO like Function ******************************/
#define TIMER1_DISABLE_WGM_OCR() (TIMER1_U8_TCCR1A_REG = 0) // Disable WGM & OCR

#define TIMER1_CLEAR_INPUT_CAPTURE_FLAG() (CLR_BIT(TIMER1_U16_TIFR_REG, 5)) // Clear ICF1

/************************  Sec: User Defined Data Types ******************************/

typedef struct
{
	u16 prescalar;
	u8 timer_mode : 2;
	u8 edge : 1;
	u8 : 5;
} Timer1_t;

/************************  Sec: Software Interfaces ******************************/

/**
 * @brief initializes timer1 module
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_init(const Timer1_t *_timer);

/**
 * @brief deinitializes timer1 module
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_deinit(const Timer1_t *_timer);

/**
 * @brief
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  value to be written to Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_write(const Timer1_t *_timer, u16 _value);

/**
 * @brief
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  pointer to value to be read from Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_read(const Timer1_t *_timer, u16 *_value, u64 *_freq, u8 *_duty_cycle);

#endif /**<__TIMER_1_INTERFACE_H__*/
