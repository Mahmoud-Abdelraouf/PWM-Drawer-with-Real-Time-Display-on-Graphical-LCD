/******************************************************************/
/********** Name    : Fathy Abdlhady & Yousef Shawky    ***********/
/********** Date    : 10/10/2022                        ***********/
/********** SWC     : TIMER0 PWM                        ***********/
/********** Version : 1.0                               ***********/
/******************************************************************/
#ifndef __TIMER_0_PWM_private_H_
#define __TIMER_0_PWM_private_H_




/***********************MACROS For TIMERS0 Registers************************/
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

#define TIMER0_U8_TIFR_REG				*((volatile u8 *)0X58)
#define TIMER0_U8_TOV0_BIT						0
#define TIMER0_U8_OCF0_BIT						1


#define TIMER0_U8_OC0_BIT						3


#define TIMER0_U8_TIMSK_REG				*((volatile u8 *)0X59)
#define TIMER0_U8_TOIE0_BIT						0
#define TIMER0_U8_OCIE0_BIT						1



/*********************Static Functions Prototypes***************************/

static Std_ReturnType TIMER_0_Select_Prescaler_value(u8 copy_u8Prescaler);

static Std_ReturnType TIMER_0_HW_ActionMode(u8 copy_u8HW_ActionMode);


#endif
