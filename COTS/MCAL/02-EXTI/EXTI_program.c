/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 30/09/2022              *************************/
/************** SWC     : EXTI                    *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/**< Global Pointer to a function */
static void (*EXTI_APFEXTI[3])(void) = {NULL,NULL,NULL};

Std_ReturnType EXTI_Enable(u8 Copy_EXTIIndex, u8 Copy_EdgeIndex)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	switch(Copy_EXTIIndex)
	{
		case EXTI_INT0:
			switch(Copy_EdgeIndex)
			{
				case EXTI_RAISING_EDGE:
					SET_BIT(EXTI_MCUCR_R, ISC00_BIT);
					SET_BIT(EXTI_MCUCR_R, ISC01_BIT);
					SET_BIT(EXTI_GICR_R, INT0_BIT);
					break;
				case EXTI_FALLING_EDGE:
					CLR_BIT(EXTI_MCUCR_R, ISC00_BIT);
					SET_BIT(EXTI_MCUCR_R, ISC01_BIT);
					SET_BIT(EXTI_GICR_R, INT0_BIT);
					break;
				case EXTI_ANY_LOGICAL_CHANGE:
					SET_BIT(EXTI_MCUCR_R, ISC00_BIT);
					CLR_BIT(EXTI_MCUCR_R, ISC01_BIT);
					SET_BIT(EXTI_GICR_R, INT0_BIT);
					break;
				case EXTI_LOW_LEVEL:
					CLR_BIT(EXTI_MCUCR_R, ISC00_BIT);
					CLR_BIT(EXTI_MCUCR_R, ISC01_BIT);
					SET_BIT(EXTI_GICR_R, INT0_BIT);
					break;
				default : Local_FunctionStatus = E_NOT_OK; break;
			}
			break;
		case EXTI_INT1:
			switch(Copy_EdgeIndex)
			{
				case EXTI_RAISING_EDGE:
					SET_BIT(EXTI_MCUCR_R, ISC10_BIT);
					SET_BIT(EXTI_MCUCR_R, ISC11_BIT);
					SET_BIT(EXTI_GICR_R, INT1_BIT);
					break;
				case EXTI_FALLING_EDGE:
					CLR_BIT(EXTI_MCUCR_R, ISC10_BIT);
					SET_BIT(EXTI_MCUCR_R, ISC11_BIT);
					SET_BIT(EXTI_GICR_R, INT1_BIT);
					break;
				case EXTI_ANY_LOGICAL_CHANGE:
					SET_BIT(EXTI_MCUCR_R, ISC10_BIT);
					CLR_BIT(EXTI_MCUCR_R, ISC11_BIT);
					SET_BIT(EXTI_GICR_R, INT1_BIT);
					break;
				case EXTI_LOW_LEVEL:
				CLR_BIT(EXTI_MCUCR_R, ISC10_BIT);
				CLR_BIT(EXTI_MCUCR_R, ISC11_BIT);
				SET_BIT(EXTI_GICR_R, INT1_BIT);
				break;
				default : Local_FunctionStatus = E_NOT_OK; break;
			}
			break;		
		case EXTI_INT2:
			switch(Copy_EdgeIndex)
			{
				case EXTI_RAISING_EDGE:
					SET_BIT(EXTI_MCUCR_R, ISC10_BIT);
					SET_BIT(EXTI_MCUCR_R, ISC11_BIT);
					SET_BIT(EXTI_GICR_R, INT1_BIT);
					break;
				case EXTI_FALLING_EDGE:
					CLR_BIT(EXTI_MCUCSR_R, ISC2_BIT);
					SET_BIT(EXTI_GICR_R, INT2_BIT);
					break;
				default : Local_FunctionStatus = E_NOT_OK; break;
			}
			break;	
		default : Local_FunctionStatus = E_NOT_OK; break;
	}
	return Local_FunctionStatus;
}

Std_ReturnType EXTI_Disable(u8 Copy_EXTIIndex)
{
	Std_ReturnType Local_FunctionStatus = E_OK;
	switch(Copy_EXTIIndex) 
	{
		case EXTI_INT0:
		CLR_BIT(EXTI_GICR_R, INT0_BIT);
		break;
		case EXTI_INT1:
		CLR_BIT(EXTI_GICR_R, INT1_BIT);
		break;
		case EXTI_INT2:
		CLR_BIT(EXTI_GICR_R, INT2_BIT);
		break;
		default : Local_FunctionStatus = E_NOT_OK;
		break;
	} 

	return Local_FunctionStatus;
}


Std_ReturnType EXTI_EXTICallBack(void (*Copy_PF)(void),u8 Copy_EXTIIndex)
{
	Std_ReturnType L_enumFunctionState = E_OK;

	if((Copy_PF != NULL) && (Copy_EXTIIndex < 3))
	{
		EXTI_APFEXTI[Copy_EXTIIndex] = Copy_PF;
	}
	else
	{
		L_enumFunctionState = E_NOT_OK;
	}

	return L_enumFunctionState;
}


/**< prototype for ISR of EXTI0 */
void __vector_1(void)	__attribute__((signal));
void __vector_1(void)
{
	if(EXTI_APFEXTI[EXTI_INT0] != NULL)
	{
		EXTI_APFEXTI[EXTI_INT0]();
	}
}

/**< prototype for ISR of EXTI1 */
void __vector_2(void)	__attribute__((signal));
void __vector_2(void)
{
	if(EXTI_APFEXTI[EXTI_INT1] != NULL)
	{
		EXTI_APFEXTI[EXTI_INT1]();
	}
}

/**< prototype for ISR of EXTI2 */
void __vector_3(void)	__attribute__((signal));
void __vector_3(void)
{
	if(EXTI_APFEXTI[EXTI_INT2] != NULL)
	{
		EXTI_APFEXTI[EXTI_INT2]();
	}
}
