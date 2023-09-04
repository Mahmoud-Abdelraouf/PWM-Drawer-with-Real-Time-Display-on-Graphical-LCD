/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 15/11/2022              ***********/
/********** SWC     : TIMER1                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMER_1_PRIVATE_H
#define TIMER_1_PRIVATE_H


#define TIMER1_U8_TCCR1A_REG			*((volatile u8 *)0X4F)
#define TIMER1_U8_TCCR1B_REG			*((volatile u8 *)0X4E)

#define TIMER1_U8_TCNT1H_REG			*((volatile u8 *)0X4D)
#define TIMER1_U8_TCNT1L_REG			*((volatile u8 *)0X4C)

#define TIMER1_U16_TCNT1_REG			*((volatile u16 *)0X4C)

#define TIMER1_U8_OCR1AH_REG			*((volatile u8 *)0X4B)
#define TIMER1_U8_OCR1AL_REG			*((volatile u8 *)0X4A)

#define TIMER1_U16_OCRA1_REG			*((volatile u16 *)0X4A)

#define TIMER1_U8_ICR1H_REG				*((volatile u8 *)0X47)
#define TIMER1_U8_ICR1L_REG				*((volatile u8 *)0X46)

#define TIMER1_U16_ICR1_REG				*((volatile u16 *)0X46)


#endif