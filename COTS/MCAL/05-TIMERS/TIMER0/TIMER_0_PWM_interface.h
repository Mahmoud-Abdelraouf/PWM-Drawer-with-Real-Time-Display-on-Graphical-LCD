/******************************************************************/
/********** Name    : Fathy Abdlhady & Yousef Shawky    ***********/
/********** Date    : 10/10/2022                        ***********/
/********** SWC     : TIMER0 PWM                        ***********/
/********** Version : 1.0                               ***********/
/******************************************************************/
#ifndef __TIMER_0_PWM_interface_H_
#define __TIMER_0_PWM_interface_H_


/*********************** Includes ******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_0_PWM_private.h"
#include "TIMER_0_PWM_config.h"
#include "DIO_interface.h"


/***********************MACROS For TIMERS0 Modes****************************/
#define TIMER0_U8_FAST_PWM_MODE					0
#define TIMER0_U8_PWM_PHASE_CORRECT_MODE		1

/*********************MACROS For TIMERS0 Prescaler**************************/
#define TIMER0_U8_NO_CLOCK_SOURCE				0
#define TIMER0_U8_N0_PRESCALER					1
#define TIMER0_U8_PRESCALER_DIV_BY_8			2
#define TIMER0_U8_PRESCALER_DIV_BY_64			3
#define TIMER0_U8_PRESCALER_DIV_BY_256		    4
#define TIMER0_U8_PRESCALER_DIV_BY_1024		    5


/*********************MACROS For TIMERS0 HW Action MODE*********************/
#define TIMER0_U8_HW_NON_INV_MODE	            0
#define TIMER0_U8_HW_INV_MODE				    1




/*********************Public Functions Prototypes***************************/

Std_ReturnType TIMER_0_PWM_Mode_init(u8 copy_u8PWM_Mode,u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler,u8 copy_u8DutyCycle);


Std_ReturnType TIMER_0_PWM_Select_DutyCycle(u8 copy_u8DutyCycle);


Std_ReturnType TIMER_0_PWM_Mode_Stop(void);


#endif
