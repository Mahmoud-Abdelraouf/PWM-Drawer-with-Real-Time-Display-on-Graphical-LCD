/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 10/10/2022              ***********/
/********** SWC     : TIMERS                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/*LIB*/
#include "ERROR_STATE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

/*Global pointer to Function of Timer0 OVF*/
static void (*TIMER0_APTimer0_OVF_CTC[2])(void) = {NULL,NULL};

Error_State_t TIMERS_Error_State_tTimer0NormalModeInit(u8 copy_u8InterruptMode,u8 copy_u8PreloadValue,u8 copy_u8Prescaler)
{
	Error_State_t L_enumFunctionState = RET_OK;
	/*select Mode => Normal Mode*/
	CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
	CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
	/*Enable/disable Interrupt => Interrupt at the Overflow*/
	switch(copy_u8InterruptMode)
	{
	case TIMER0_U8_TURN_OFF_INTERRUPT:
		CLR_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_TOIE0_BIT);
		break;                                      
	case TIMER0_U8_TURN_ON_INTERRUPT:               
		SET_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_TOIE0_BIT);
		break;
	default: L_enumFunctionState = RET_NOK;
		break;
	}
	/*set preload value*/
	TIMER0_U8_TCNT0_REG = copy_u8PreloadValue; // this value for freq = 8 MHZ , and to make 1 sec delay, this value we should evaluate for every value we want
	/*select timer prescaler*/
	switch(copy_u8Prescaler)
	{
	case TIMER0_U8_NO_CLOCK_SOURCE:
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                    
	case TIMER0_U8_N0_PRESCALER:                  
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                   
	case TIMER0_U8_8_PRESCALER:                  
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	case TIMER0_U8_64_PRESCALER:
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	case TIMER0_U8_256_PRESCALER:
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	case TIMER0_U8_1024_PRESCALER:
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	default:L_enumFunctionState = RET_NOK;
	break;
	}
	return L_enumFunctionState;
}


Error_State_t TIMERS_Error_State_tTimer0CTCModeInit(u8 copy_u8InterruptMode,u8 copy_u8CTC_Value,u8 copy_u8Prescaler)
{
	Error_State_t L_enumFunctionState = RET_OK;
	
	/*select Mode => CTC mode*/
	CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
	SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
	/*Enable/Disable CTC Interrupt => Interrupt at Compare Match Value*/
	switch(copy_u8InterruptMode)
	{
	case TIMER0_U8_TURN_OFF_INTERRUPT:
		CLR_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_OCIE0_BIT);
		break;
	case TIMER0_U8_TURN_ON_INTERRUPT:
		SET_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_OCIE0_BIT);
		break;
	default: L_enumFunctionState = RET_NOK;
		break;
	}
	/*Set Compare Match Unit Register*/
	TIMER0_U8_OCR0_REG = copy_u8CTC_Value; // this value for freq = 8 MHZ , and
	/*select timer prescaler*/
	switch(copy_u8Prescaler)
	{
	case TIMER0_U8_NO_CLOCK_SOURCE:
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                   
	case TIMER0_U8_N0_PRESCALER:                 
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                   
	case TIMER0_U8_8_PRESCALER:                  
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	case TIMER0_U8_64_PRESCALER:
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                    
	case TIMER0_U8_256_PRESCALER:                 
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                 
	case TIMER0_U8_1024_PRESCALER:             
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	default:L_enumFunctionState = RET_NOK;
		break;
	}
	
	return L_enumFunctionState;
}

Error_State_t TIMERS_Error_State_tTimer0FastPWMModeInit(u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler,u8 copy_u8OCR0IntValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	
	/*select Mode => Fast PWM mode*/
    SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
    SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
	switch(copy_u8HW_ActionMode)
	{
	case TIMER0_U8_NON_INV_MODE:
		 /*select HW Action on OC0 Pin => Non Inverting Mode*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
	break;
	case TIMER0_U8_INV_MODE:
		/*select HW Action on OC0 Pin => Inverting Mode*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
	break;
	}
	
	switch(copy_u8Prescaler)
	{
	case TIMER0_U8_NO_CLOCK_SOURCE:
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_N0_PRESCALER:                   
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_8_PRESCALER:                    
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	case TIMER0_U8_64_PRESCALER:
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_256_PRESCALER:                  
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_1024_PRESCALER:                 
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	default:L_enumFunctionState = RET_NOK;
	break;
	}
	return L_enumFunctionState;
}

Error_State_t TIMERS_Error_State_tTimer0PhaseCorrectPWMModeInit(u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler)
{
	Error_State_t L_enumFunctionState = RET_OK;
	
	/*select Mode => Phase Correct PWM mode*/
    SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
    SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
	switch(copy_u8HW_ActionMode)
	{
	case TIMER0_U8_NON_INV_MODE:
		 /*select HW Action on OC0 Pin => Non Inverting Mode*/
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
	break;
	case TIMER0_U8_INV_MODE:
		/*select HW Action on OC0 Pin => Inverting Mode*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
	break;
	}
	
	switch(copy_u8Prescaler)
	{
	case TIMER0_U8_NO_CLOCK_SOURCE:
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_N0_PRESCALER:                   
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                    
	case TIMER0_U8_8_PRESCALER:                   
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                    
	case TIMER0_U8_64_PRESCALER:                  
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                   
	case TIMER0_U8_256_PRESCALER:                
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;                                     
	case TIMER0_U8_1024_PRESCALER:                 
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
		break;
	default:L_enumFunctionState = RET_NOK;
	break;
	}
	return L_enumFunctionState;
}

/*This function change the vaalue of the OCR0 During the Run Time*/
void TIMERS_voidTimer0SetCompareMatchValue(u8 copy_u8OCR0Value)
{
	TIMER0_U8_OCR0_REG = copy_u8OCR0Value;
}


Error_State_t TIMERS_Error_State_tTimer0Init(void)
{
	Error_State_t L_enumFunctionState = RET_OK;
	switch(TIMER0_U8_TIMER0_Mode)
	{
	case TIMER0_U8_NORMAL_MODE:
		/*select Mode => Normal Mode*/
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
		/*Enable/disable OVF Interrupt*/
		switch(TIMER0_U8_TIMER0_TNTERRUPT_MODE_OPTN)
		{
		case TIMER0_U8_TURN_OFF_INTERRUPT:
			CLR_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_TOIE0_BIT);
			break;
		case TIMER0_U8_TURN_ON_INTERRUPT:
			SET_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_TOIE0_BIT);
			break;
		default: L_enumFunctionState = RET_NOK;
			break;
		}
		/*set preload value*/
		TIMER0_U8_TCNT0_REG = TIMER0_U8_PRELOAD_INITIAL_VALUE; // this value for freq = 8 MHZ , and to make 1 sec delay, this value we should evaluate for every value we want
		/*select timer prescaler*/
		switch(TIMER0_U8_TIMER0_PRESCALER)
		{
		case TIMER0_U8_NO_CLOCK_SOURCE:
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_N0_PRESCALER:                   
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_8_PRESCALER:                    
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_64_PRESCALER:                  
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_256_PRESCALER:                 
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_1024_PRESCALER:                
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		default:L_enumFunctionState = RET_NOK;
			break;
		}
	break;


	case TIMER0_U8_CTC_MODE:
		/*select Mode => CTC mode*/
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
		/*Enable/Disable CTC Interrupt*/
		switch(TIMER0_U8_TIMER0_TNTERRUPT_MODE_OPTN)
		{
		case TIMER0_U8_TURN_OFF_INTERRUPT:
			CLR_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_OCIE0_BIT);
			break;
		case TIMER0_U8_TURN_ON_INTERRUPT:
			SET_BIT(TIMER0_U8_TIMSK_REG,TIMER0_U8_OCIE0_BIT);
			break;
		default: L_enumFunctionState = RET_NOK;
			break;
		}
		/*Set Compare Match Unit Register*/
		TIMER0_U8_OCR0_REG = TIMER0_U8_SET_CTC_INITIAL_VALUE; // this value for freq = 8 MHZ , and to make 1 sec delay, this value we should evaluate for every value we want
		/*select timer prescaler*/
		switch(TIMER0_U8_TIMER0_PRESCALER)
		{
		case TIMER0_U8_NO_CLOCK_SOURCE:
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_N0_PRESCALER:                   
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_8_PRESCALER:                    
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_64_PRESCALER:                   
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_256_PRESCALER:                 
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                   
		case TIMER0_U8_1024_PRESCALER:               
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		default:L_enumFunctionState = RET_NOK;
			break;
		}
	break;


	case TIMER0_U8_FAST_PWM_MODE:
		/*select Mode => Fast PWM mode*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
		/*select HW Action on OC0 Pin => Non Inverting*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
		/*select timer prescaler*/
		switch(TIMER0_U8_TIMER0_PRESCALER)
		{
		case TIMER0_U8_NO_CLOCK_SOURCE:
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		case TIMER0_U8_N0_PRESCALER:
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_8_PRESCALER:                   
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                    
		case TIMER0_U8_64_PRESCALER:                  
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_256_PRESCALER:                  
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_1024_PRESCALER:                 
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		default:L_enumFunctionState = RET_NOK;
			break;
		}
	break;


	case TIMER0_U8_PWM_PHASE_CORRECT_MODE:
		/*select Mode => Phase correct PWM mode*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM00_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_WGM01_BIT);
		/*select HW Action on OC0 Pin => Non Inverting*/
		SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM01_BIT);
		CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_COM00_BIT);
		switch(TIMER0_U8_TIMER0_PRESCALER)
		{
		case TIMER0_U8_NO_CLOCK_SOURCE:
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                   
		case TIMER0_U8_N0_PRESCALER:                 
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		case TIMER0_U8_8_PRESCALER:
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                     
		case TIMER0_U8_64_PRESCALER:                   
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                  
		case TIMER0_U8_256_PRESCALER:               
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;                                 
		case TIMER0_U8_1024_PRESCALER:             
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS00_BIT);
			CLR_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS01_BIT);
			SET_BIT(TIMER0_U8_TCCR0_REG,TIMER0_U8_CS02_BIT);
			break;
		default:L_enumFunctionState = RET_NOK;
			break;
		}
	break;
	default : L_enumFunctionState = RET_NOK;
		break;
	}
	return L_enumFunctionState;
}



void TIMERS_voidTimerDelay_ms(u16 copy_u16DelayTimeIn_ms)
{
	u16 L_u16OverFlowCounter = 0;
	f32 L_u16NoOfOVF = 0;

	L_u16NoOfOVF = copy_u16DelayTimeIn_ms * 3.90625; // copy_u16DelayTimeIn_ms (msec) / (time of OVF) => 2^n * tick time
	
	TIMERS_Error_State_tTimer0NormalModeInit(TIMER0_U8_TURN_OFF_INTERRUPT,192,TIMER0_U8_8_PRESCALER);
	TIMER0_U8_TCNT0_REG = 256 * (1 - (L_u16NoOfOVF - (u32) L_u16NoOfOVF));
	while(L_u16OverFlowCounter < (u32)L_u16NoOfOVF)
	{
		while(GET_BIT(TIMER0_U8_TIFR_REG,TIMER0_U8_TOV0_BIT) == 0);
		SET_BIT(TIMER0_U8_TIFR_REG,TIMER0_U8_TOV0_BIT); // to clear the OVF flag by software
		L_u16OverFlowCounter++;
	}
	L_u16OverFlowCounter = 0;
}


Error_State_t TIMERS_Error_State_tSetCallBack(void (*copy_pf)(void),u8 copy_u8TimersINTRPTIndex)
{
	Error_State_t  L_enumFunctionState = RET_OK;
	if(NULL != copy_pf)
	{
		switch(copy_u8TimersINTRPTIndex)
		{
		case TIMER0_U8_CMP_MTH_INTRPT:
			TIMER0_APTimer0_OVF_CTC[TIMER0_U8_CMP_MTH_INTRPT_ENB_PIN] = copy_pf;
			break;
		case TIMER0_U8_OVF_INTRPT:
			TIMER0_APTimer0_OVF_CTC[TIMER0_U8_OVF_INTRPT_ENB_PIN] = copy_pf;
			break;
		default: L_enumFunctionState = RET_NOK;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}



/*prototype for ISR of TIMER0 CTC*/
void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	static u16 L_u16CounterCTC = 0;
	L_u16CounterCTC++;
	if(L_u16CounterCTC == TIMER0_U8_CTC_NO_OF_OVF)
	{
		/*clear counter*/
		L_u16CounterCTC = 0;
		/*call callback function*/
		if(TIMER0_APTimer0_OVF_CTC[TIMER0_U8_CMP_MTH_INTRPT_ENB_PIN] != NULL)
		{
			TIMER0_APTimer0_OVF_CTC[TIMER0_U8_CMP_MTH_INTRPT_ENB_PIN]();
		}else{}
	}else{}
}

/*prototype for ISR of TIMER0 OVF*/
void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	static u16 L_u16CounterOVF = 0;
	L_u16CounterOVF++;
	if(L_u16CounterOVF == TIMER0_U8_NORMAL_NO_OF_OVF)
	{
		/*update preload value*/
		TIMER0_U8_TCNT0_REG = TIMER0_U8_PRELOAD_INITIAL_VALUE;
		/*clear the OVF counter*/
		L_u16CounterOVF = 0;
		/*call APP function*/
		if(TIMER0_APTimer0_OVF_CTC[TIMER0_U8_OVF_INTRPT_ENB_PIN] != NULL)
		{
			TIMER0_APTimer0_OVF_CTC[TIMER0_U8_OVF_INTRPT_ENB_PIN]();
		}else{}
	}else{}
}


