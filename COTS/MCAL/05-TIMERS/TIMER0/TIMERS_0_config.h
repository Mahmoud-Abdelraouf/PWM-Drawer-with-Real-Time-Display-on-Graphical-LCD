/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H



/********************************Waveform Generation Mode********************************/
/*options : TIMER0_U8_NORMAL_MODE
          : TIMER0_U8_CTC_MODE
          : TIMER0_U8_FAST_PWM_MODE
          : TIMER0_U8_PWM_PHASE_CORRECT_MODE*/


#define TIMER0_U8_TIMER0_Mode						TIMER0_U8_NORMAL_MODE
/***************************************************************************************/




/****************Select Prescaler For Timer0 CLK => Clock Select************************/
/*options : TIMER0_U8_NO_CLOCK_SOURCE
          : TIMER0_U8_N0_PRESCALER
          : TIMER0_U8_8_PRESCALER
          : TIMER0_U8_64_PRESCALER
          : TIMER0_U8_256_PRESCALER
          : TIMER0_U8_1024_PRESCALER*/


#define TIMER0_U8_TIMER0_PRESCALER					TIMER0_U8_8_PRESCALER
/***************************************************************************************/




/****************************Select Interrupt Mode Operation****************************/
/*options : TIMER0_U8_TURN_OFF_INTERRUPT
          : TIMER0_U8_TURN_ON_INTERRUPT*/

#define TIMER0_U8_TIMER0_TNTERRUPT_MODE_OPTN		TIMER0_U8_TURN_OFF_INTERRUPT
/***************************************************************************************/



/***************************************************************************************/
/* 1. The No of overflow you want to get the required time delay.
 * 2. The preload value to make sure you set the exact time.
 */
#define TIMER0_U8_NORMAL_NO_OF_OVF					19531
#define TIMER0_U8_PRELOAD_INITIAL_VALUE				192
/* 1. The No of overflow you want to get required time delay.
 * 2. The Initial value you want to make the timer start from, this value ranges from 0 to 2^n(max).
 */
#define TIMER0_U8_CTC_NO_OF_OVF						10000
#define TIMER0_U8_SET_CTC_INITIAL_VALUE				100
/***************************************************************************************/


#endif
