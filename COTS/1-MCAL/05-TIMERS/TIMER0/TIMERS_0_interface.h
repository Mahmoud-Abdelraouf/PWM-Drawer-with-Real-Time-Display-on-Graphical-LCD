/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H


/*Interrupt Vectors for TIPMERS0*/
#define TIMER0_U8_CMP_MTH_INTRPT				11	//Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMER0_U8_OVF_INTRPT					12	//Timer/Counter0 Overflow Interrupt Enable




/******************************Macros for Timer0 Mode***********************************/
#define TIMER0_U8_NORMAL_MODE					0
#define TIMER0_U8_CTC_MODE						1
#define TIMER0_U8_FAST_PWM_MODE					2
#define TIMER0_U8_PWM_PHASE_CORRECT_MODE		3
/***************************************************************************************/

/*Fast PWM Mode Options*/

#define TIMER0_U8_NON_INV_MODE					0
#define TIMER0_U8_INV_MODE						1

/********************************Select Interrupt Mode Operation**********************************/
#define TIMER0_U8_TURN_OFF_INTERRUPT			0
#define TIMER0_U8_TURN_ON_INTERRUPT				1
/***************************************************************************************/

/*********************Macros for Prescaler For Timer0 CLK*******************************/
#define TIMER0_U8_NO_CLOCK_SOURCE				0
#define TIMER0_U8_N0_PRESCALER					1
#define TIMER0_U8_8_PRESCALER					2
#define TIMER0_U8_64_PRESCALER					3
#define TIMER0_U8_256_PRESCALER					4
#define TIMER0_U8_1024_PRESCALER				5
/***************************************************************************************/




Error_State_t TIMERS_Error_State_tTimer0Init(void);

Error_State_t TIMERS_Error_State_tTimer0NormalModeInit(u8 copy_u8InterruptMode,u8 copy_u8PreloadValue,u8 copy_u8Prescaler);

Error_State_t TIMERS_Error_State_tTimer0CTCModeInit(u8 copy_u8InterruptMode,u8 copy_u8CTC_Value,u8 copy_u8Prescaler);

Error_State_t TIMERS_Error_State_tTimer0FastPWMModeInit(u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler,u8 copy_u8OCR0IntValue);

Error_State_t TIMERS_Error_State_tTimer0PhaseCorrectPWMModeInit(u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler);

void TIMERS_voidTimer0SetCompareMatchValue(u8 copy_u8OCR0Value);

Error_State_t TIMERS_Error_State_tSetCallBack(void (*copy_pf)(void),u8 copy_u8TimersINTRPTIndex);

void TIMERS_voidTimerDelay_ms(u16 copy_u16DelayTimeIn_ms);





#endif
