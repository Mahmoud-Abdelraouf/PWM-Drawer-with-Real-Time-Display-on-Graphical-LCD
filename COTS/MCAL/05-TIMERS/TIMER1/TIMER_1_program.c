/**********************************************************/
/********** Name    : Ahmed Bakr & Ahmed Samir  ***********/
/********** Date    : 9/9/2023	              	***********/
/********** SWC     : TIMER1                  	***********/
/********** Version : 1.0                     	***********/
/**********************************************************/
#ifndef __TIMER_1_PROGRAM_H__
#define __TIMER_1_PROGRAM_H__

#include "TIMER_1_interface.h"

/**<_Helper Functions*/
static void Timer1_setPrescaler(const Timer1_t *_timer);
static void Timer1_edgeSelect(const Timer1_t *_timer);
static void Timer1_setEdge(u8 edge);

/**
 * @brief initializes timer1 module in input capture mode
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_init(const Timer1_t *_timer)
{
	Std_ReturnType ret = E_OK;

	if (NULL == _timer)
	{
		ret = E_NOT_OK;
	}
	else
	{
		DIO_voidInit();
		TIMER1_CLEAR_INPUT_CAPTURE_FLAG();						// Clear Input Capture Flag
		Timer1_setPrescaler(_timer); 							// Set Timer1 CLK Prescalar 
		switch (_timer->timer_mode)
		{
		case INPUT_CAPTURE_MODE:
			/* code */
			DIO_SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_INPUT); 	// Set D6 (ICP1) as input
			TIMER1_DISABLE_WGM_OCR(); 								// Disable WGM & OCR
			Timer1_edgeSelect(_timer);								// Select edge
			break;

		case OUTPUT_CAPTURE_MODE:
			/* code */
			break;

		case PWM_MODE:
			/* code */
			break;	
		
		case COUNTER_MODE:
			/* code */
			break;	
		
		default:
			break;
		}
	}

	return ret;
}

/**
 * @brief deinitializes timer1 module
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_deinit(const Timer1_t *_timer)
{
	Std_ReturnType ret = E_OK;

	if (NULL == _timer)
	{
		ret = E_NOT_OK;
	}
	else
	{
	}

	return ret;
}

/**
 * @brief
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  value to be written to Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_write(const Timer1_t *_timer, u16 _value)
{
	Std_ReturnType ret = E_OK;

	if (NULL == _timer)
	{
		ret = E_NOT_OK;
	}
	else
	{
	}

	return ret;
}

/**
 * @brief
 *
 * @param _timer1 		pointer to timer1 module configurations @ref Timer1_t
 * @param _value  		pointer to value to be read from Timer1 register
 * @param _freq	  		pointer to value calculated for the frequency of the input signal
 * @param _duty_cycle   pointer to value calculated for the duty cycle of the input signal
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_read(const Timer1_t *_timer, u16 *_value, u32 *_freq, u8 *_duty_cycle)
{
	Std_ReturnType ret = E_OK;
	u16 firstCapture = 0;
	u16 secondCapture = 0;
	u16 thirdCapture = 0;
	u16 high_count = 0;	
	u16 signal_period = 0;

	if ((NULL == _timer) || (NULL == _value) || (NULL == _freq) || (NULL == _duty_cycle))
	{
		ret = E_NOT_OK;
	}
	else
	{
		*_value = (u16)((TIMER1_U8_TCNT1H_REG << 8) + TIMER1_U8_TCNT1L_REG);

		TIMER1_U8_TCNT1H_REG = 0;
		TIMER1_U8_TCNT1L_REG = 0;
		TIMER1_CLEAR_INPUT_CAPTURE_FLAG();	// Clear the flag

		Timer1_setEdge(RISING_EDGE);		// Set capture edge as Rising Edge
		while(TIMER1_U16_TIFR_REG & 0x05); 	// Wait for flag
		firstCapture = TIMER1_U16_ICR1_REG; // Take the first capture
		TIMER1_CLEAR_INPUT_CAPTURE_FLAG();	// Clear the flag

		Timer1_setEdge(FALLING_EDGE);		// Set capture edge as Falling Edge
		while(TIMER1_U16_TIFR_REG & 0x05); 	// Wait for flag
		secondCapture = TIMER1_U16_ICR1_REG;// Take the second capture
		TIMER1_CLEAR_INPUT_CAPTURE_FLAG();	// Clear the flag

		Timer1_setEdge(RISING_EDGE);		// Set capture edge as Rising Edge
		while(TIMER1_U16_TIFR_REG & 0x05); 	// Wait for flag
		thirdCapture = TIMER1_U16_ICR1_REG;	// Take the third capture
		TIMER1_CLEAR_INPUT_CAPTURE_FLAG();	// Clear the flag

		if ((firstCapture < secondCapture) && (secondCapture < thirdCapture))
		{
			high_count = secondCapture - firstCapture;
			signal_period = thirdCapture - firstCapture;

			*_freq = (u16)(F_CPU / (signal_period * _timer->prescalar));
			*_duty_cycle = (u16)(((float)high_count / (float)signal_period) * 100.0);
		}
		else 
		{
			ret = E_NOT_OK;
		}
	}

	return ret;
}

static void Timer1_setPrescaler(const Timer1_t *_timer){
	switch (_timer->prescalar)
	{
	
	case PRESCALAR_DIV_BY_1:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 1);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case PRESCALAR_DIV_BY_8:
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;
	
	case PRESCALAR_DIV_BY_64:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case PRESCALAR_DIV_BY_256:
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 0);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 1);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case PRESCALAR_DIV_BY_1024:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 1);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case EXTERNAL_CLK_SRC_FALLING:
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case EXTERNAL_CLK_SRC_RISING:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	default:
		break;
	}
}

static void Timer1_edgeSelect(const Timer1_t *_timer)
{
	switch (_timer->edge)
	{
	case RISING_EDGE:
		/* code */
		SET_BIT(TIMER1_U8_TCCR1B_REG, 6);
		break;

	case FALLING_EDGE:
		/* code */
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 6);
		break;
	
	default:
		break;
	}
}

static void Timer1_setEdge(u8 edge)
{
	switch (edge)
	{
	case RISING_EDGE:
		/* code */
		SET_BIT(TIMER1_U8_TCCR1B_REG, 6);
		break;

	case FALLING_EDGE:
		/* code */
		CLR_BIT(TIMER1_U8_TCCR1B_REG, 6);
		break;
	
	default:
		break;
	}
}

#endif /**< __TIMER_1_PROGRAM_H__*/
