/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 15/11/2022              ***********/
/********** SWC     : TIMER1                  ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef __TIMER_1_INTERFACE_H__
#define __TIMER_1_INTERFACE_H__

/************************  Sec: Includes ******************************/
/*lIB*/
#include "ERROR_STATE.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "TIMER_1_interface.h"
#include "TIMER_1_private.h"
#include "TIMER_1_config.h"

/************************  Sec: MACROS ******************************/
/**<_prescaler*/
#define PRESCALAR_DIV_BY_1      0
#define PRESCALAR_DIV_BY_8      1
#define PRESCALAR_DIV_BY_64     2   
#define PRESCALAR_DIV_BY_256    3
#define PRESCALAR_DIV_BY_1024   4


/************************  Sec: MACRO like Function ******************************/

/************************  Sec: User Defined Data Types ******************************/
typedef struct 
{
    u8 prescalar    :3;
    u8 timer_mode   :2;
    u8 
} Timer1_t;


/************************  Sec: Software Interfaces ******************************/

/**
 * @brief initializes timer1 module
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_init(const Timer1_t *_timer);

/**
 * @brief deinitializes timer1 module
 *
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Timer1_deinit(const Timer1_t *_timer);

/**
 * @brief 
 * 
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  value to be written to Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action 
 */
Std_ReturnType Timer1_write(const Timer1_t *_timer, u16 _value);

/**
 * @brief 
 * 
 * @param _timer1 pointer to timer1 module configurations @ref Timer1_t
 * @param _value  pointer to value to be read from Timer1 register
 * @return Std_ReturnType
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action 
 */
Std_ReturnType Timer1_read(const Timer1_t *_timer, u16 *_value);


#endif /**< __TIMER_1_INTERFACE_H__*/