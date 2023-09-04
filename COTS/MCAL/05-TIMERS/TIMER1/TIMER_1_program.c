/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 15/11/2022              ***********/
/********** SWC     : TIMER1                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef __TIMER_1_PROGRAM_H__
#define __TIMER_1_PROGRAM_H__

#include "TIMER_1_interface.h"

static void Timer1_setPrescaler(Timer1_t *_timer);

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
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  pointer to value to be read from Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_read(const Timer1_t *_timer, u16 *_value)
{
	Std_ReturnType ret = E_OK;

	if ((NULL == _timer) || (NULL == _value))
	{
		ret = E_NOT_OK;
	}
	else
	{
	}

	return ret;
}

static void Timer1_setPrescaler(Timer1_t *_timer){
	switch (_timer->prescalar)
	{
	
	case PRESCALAR_DIV_BY_1:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		break;

	case PRESCALAR_DIV_BY_8:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		break;
	
	case PRESCALAR_DIV_BY_64:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 1);
		break;

	case PRESCALAR_DIV_BY_256:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case PRESCALAR_DIV_BY_1024:
		SET_BIT(TIMER1_U8_TCCR1B_REG, 0);
		SET_BIT(TIMER1_U8_TCCR1B_REG, 2);
		break;

	case EXTERNAL_CLK_SRC_FALLING:
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

#endif /**< __TIMER_1_PROGRAM_H__*/