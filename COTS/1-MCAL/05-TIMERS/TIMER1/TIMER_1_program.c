/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 15/11/2022              ***********/
/********** SWC     : TIMER1                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMER_1_PROGRAM_H
#define TIMER_1_PROGRAM_H
/*lIB*/
#include "ERROR_STATE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "TIMER_1_interface.h"
#include "TIMER_1_private.h"
#include "TIMER_1_config.h"


void TIMER1_voidTimer1Init(void)
{
	/*set timer1 mode => 14*/ 
	SET_BIT(TIMER1_U8_TCCRA_REG,1);
	CLR_BIT(TIMER1_U8_TCCRA_REG,0);
	SET_BIT(TIMER1_U8_TCCRA_REG,4);
	SET_BIT(TIMER1_U8_TCCRA_REG,3);
	/*Select HW Action on OC1A pin => Non-Inverting mode*/
	SET_BIT(TIMER1_U8_TCCR1A_REG,7);
	CLR_BIT(TIMER1_U8_TCCR1A_REG,6);
	/*set top value in ICR1*/
	TIMER1_u16_ICR1_REG = 19999;
	/*set the angle of servo motor*/
	TIMER1_U16_OCR1A_REG = 999;
	
}

#endif