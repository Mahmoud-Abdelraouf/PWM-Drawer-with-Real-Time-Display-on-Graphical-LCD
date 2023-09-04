/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 18/09/2022              ***********/
/********** SWC     : DIO                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/*lib layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
void DIO_voidInit(void)
{
/****************************************************************************************************************************************************/
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION,
						   DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);
						   
	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION,
						   DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);
						   
	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION,
						   DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);
						   
	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION,
						   DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);
/****************************************************************************************************************************************************/	   
	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,
						   DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);
						   
	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,
						   DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);
						   
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,
						   DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);
						   
	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,
						   DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);
}


/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPinDirection(u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinDirection)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if((copy_u8portId <= DIO_u8_PORTD) && (copy_u8pinId<=DIO_u8_PIN7) && ((copy_u8pinDirection==DIO_u8_OUTPUT) || (copy_u8pinDirection==DIO_u8_INPUT)))
	{
		switch (copy_u8portId)
		{
			case DIO_u8_PORTA:
				switch (copy_u8pinDirection)
				{
					case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,copy_u8pinId);break;
					case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRA_REG,copy_u8pinId);break;
				}
			break;
			case DIO_u8_PORTB:
				switch (copy_u8pinDirection)
				{
					case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REG,copy_u8pinId);break;
					case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRB_REG,copy_u8pinId);break;
				}
			break;
			case DIO_u8_PORTC:
				switch (copy_u8pinDirection)
				{
					case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REG,copy_u8pinId);break;
					case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRC_REG,copy_u8pinId);break;
				}
			break;
			case DIO_u8_PORTD:
				switch (copy_u8pinDirection)
				{
					case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REG,copy_u8pinId);break;
					case DIO_u8_INPUT :CLR_BIT(DIO_u8_DDRD_REG,copy_u8pinId);break;
				}
			break;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
	
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPinValue(u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(copy_u8pinId<=DIO_u8_PIN7)
	{
		switch (copy_u8portId)
		{
			case DIO_u8_PORTA:
				switch(copy_u8pinValue)
				{	
					case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG,copy_u8pinId);break;
					case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTA_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_u8_PORTB:
				switch(copy_u8pinValue)
				{
					case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG,copy_u8pinId);break;
					case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTB_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_u8_PORTC:
				switch(copy_u8pinValue)
				{
					case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG,copy_u8pinId);break;
					case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTC_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			case DIO_u8_PORTD:
				switch(copy_u8pinValue)
				{
					case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG,copy_u8pinId);break;
					case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTD_REG,copy_u8pinId);break;
					default: L_enumFunctionState = RET_NOK;
				}
			break;
			default:
			L_enumFunctionState = RET_NOK;
			break;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tGetPinValue(u8 copy_u8portId, u8 copy_u8pinId,u8 *copy_u8returnedPinValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if((copy_u8pinId<=DIO_u8_PIN7) && (NULL!=copy_u8returnedPinValue))
	{
		switch (copy_u8portId)
		{
			case DIO_u8_PORTA:*copy_u8returnedPinValue = GET_BIT(DIO_u8_PINA_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTB:*copy_u8returnedPinValue = GET_BIT(DIO_u8_PINB_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTC:*copy_u8returnedPinValue = GET_BIT(DIO_u8_PINC_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_u8_HIGH;
			}
			break;
			case DIO_u8_PORTD:*copy_u8returnedPinValue = GET_BIT(DIO_u8_PIND_REG,copy_u8pinId);
			if(*copy_u8returnedPinValue==0)
			{
				*copy_u8returnedPinValue = DIO_u8_LOW;
			}
			else
			{
				*copy_u8returnedPinValue = DIO_u8_HIGH;
			}
			break;
			default:
			L_enumFunctionState = RET_NOK;
			break;
		}
	}
	else
	{
		L_enumFunctionState  =RET_NOK;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPortDirection(u8 copy_u8portId, u8 copy_u8portDirection)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(copy_u8portDirection==DIO_u8_OUTPUT||copy_u8portDirection==DIO_u8_INPUT)
	{
		switch(copy_u8portId)
		{
			case DIO_u8_PORTA:
				switch(copy_u8portDirection)
				{
					case DIO_u8_OUTPUT:DIO_u8_DDRA_REG = 0XFF;break;
					case DIO_u8_INPUT :DIO_u8_DDRA_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_u8_PORTB:
				switch(copy_u8portDirection)
				{
					case DIO_u8_OUTPUT:DIO_u8_DDRB_REG = 0XFF;break;
					case DIO_u8_INPUT :DIO_u8_DDRB_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_u8_PORTC:
				switch(copy_u8portDirection)
				{
					case DIO_u8_OUTPUT:DIO_u8_DDRC_REG = 0XFF;break;
					case DIO_u8_INPUT :DIO_u8_DDRC_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
			break;
			case DIO_u8_PORTD:
				switch(copy_u8portDirection)
				{
					case DIO_u8_OUTPUT:DIO_u8_DDRD_REG = 0XFF;break;
					case DIO_u8_INPUT :DIO_u8_DDRD_REG = 0X00;break;
					default: L_enumFunctionState = RET_NOK;break;
				}
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
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tSetPortValue(u8 copy_u8portId, u8 copy_u8portValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	switch(copy_u8portId)
	{
		case DIO_u8_PORTA: DIO_u8_PORTA_REG = copy_u8portValue;break;
		case DIO_u8_PORTB: DIO_u8_PORTB_REG = copy_u8portValue;break;
		case DIO_u8_PORTC: DIO_u8_PORTC_REG = copy_u8portValue;break;
		case DIO_u8_PORTD: DIO_u8_PORTD_REG = copy_u8portValue;break;
		default: L_enumFunctionState = RET_NOK;break;
	}
	return L_enumFunctionState;
}
/****************************************************************/
/****************************************************************/
/****************************************************************/
/****************************************************************/
Error_State_t DIO_Error_State_tGetPortValue(u8 copy_u8portId, u8 *copy_u8returnedportValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(NULL!=copy_u8returnedportValue)
	{
		switch(copy_u8portId)
		{
			case DIO_u8_PORTA: *copy_u8returnedportValue = DIO_u8_PINA_REG;break;
			case DIO_u8_PORTB: *copy_u8returnedportValue = DIO_u8_PINB_REG;break;
			case DIO_u8_PORTC: *copy_u8returnedportValue = DIO_u8_PINC_REG;break;
			case DIO_u8_PORTD: *copy_u8returnedportValue = DIO_u8_PIND_REG;break;
			default: L_enumFunctionState = RET_NOK;
		}
	}
	else
	{
		L_enumFunctionState = RET_NULL_PTR;
	}
	
	
	return L_enumFunctionState;
}
