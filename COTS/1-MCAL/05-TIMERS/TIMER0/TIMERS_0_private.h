/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H
			 
#define TIMER0_U8_TIMSK_REG				*((volatile u8 *)0X59)
#define TIMER0_U8_TOIE0_BIT						0
#define TIMER0_U8_OCIE0_BIT						1
			 
#define TIMER0_U8_TIFR_REG				*((volatile u8 *)0X58)
#define TIMER0_U8_TOV0_BIT						0
#define TIMER0_U8_OCF0_BIT						1
			 
#define TIMER0_U8_TCCR0_REG				*((volatile u8 *)0X53)
#define TIMER0_U8_CS00_BIT						0
#define TIMER0_U8_CS01_BIT						1
#define TIMER0_U8_CS02_BIT						2
#define TIMER0_U8_WGM01_BIT						3
#define TIMER0_U8_COM00_BIT						4
#define TIMER0_U8_COM01_BIT						5
#define TIMER0_U8_WGM00_BIT						6
#define TIMER0_U8_FOC0_BIT						7
			 
#define TIMER0_U8_TCNT0_REG				*((volatile u8 *)0X52)
			 
#define TIMER0_U8_OCR0_REG				*((volatile u8 *)0X5C)


/***********************MACROS For TIMERS0 Modes***********************/
#define TIMER0_U8_NORMAL_MODE					0
#define TIMER0_U8_CTC_MODE						1
#define TIMER0_U8_FAST_PWM_MODE					2
#define TIMER0_U8_PWM_PHASE_CORRECT_MODE		3


/*********************MACROS For TIMERS0 Prescaler*********************/
#define TIMER0_U8_NO_CLOCK_SOURCE				0
#define TIMER0_U8_N0_PRESCALER					1
#define TIMER0_U8_8_PRESCALER					2
#define TIMER0_U8_64_PRESCALER					3
#define TIMER0_U8_256_PRESCALER					4
#define TIMER0_U8_1024_PRESCALER				5

/***********************MACROS For Interrupt Mode**********************/
#define TIMER0_U8_TURN_OFF_INTERRUPT			0
#define TIMER0_U8_TURN_ON_INTERRUPT				1

/*****************MACROS For TIMERS0 Interrupt Enable******************/
#define TIMER0_U8_OVF_INTRPT_ENB_PIN			0	//Timer/Counter0 Overflow Interrupt Enable
#define TIMER0_U8_CMP_MTH_INTRPT_ENB_PIN		1	//Timer/Counter0 Output Compare Match Interrupt Enable


#endif
