/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 25/10/2022              ***********/
/********** SWC     : ADC                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

/*MCAL*/
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
	/*
	* 1- Select Vref = AVCC
	* 2- Rigth Adjust
	* 3- Disable AutoTrigger
	* 4- Select CLK/128
	* 5- Enable ADC
	*/
	
	/*1- Select Vref = AVCC*/
	CLR_BIT(ADC_U8_ADMUX_REG,7);
	SET_BIT(ADC_U8_ADMUX_REG,6);
	/*2- Rigth Adjust*/
	CLR_BIT(ADC_U8_ADMUX_REG,5);
	/*3- Disable AutoTrigger*/
	CLR_BIT(ADC_U8_ADCSRA_REG,5);
	/*4- Select CLK/128*/
	CLR_BIT(ADC_U8_ADCSRA_REG,0);
	SET_BIT(ADC_U8_ADCSRA_REG,1);
	SET_BIT(ADC_U8_ADCSRA_REG,2);
	/*5- Enable ADC*/
	SET_BIT(ADC_U8_ADCSRA_REG,7);

	
	
}

Error_State_t ADC_Get_DigitalValue(u8 copy_u8ChanneNo,u16 *copy_Pu16DigitalValue)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if( (copy_u8ChanneNo) < 32 && (NULL != copy_Pu16DigitalValue) )
	{
		/*Clear MUX 4...0*/
		ADC_ADMUX_REG &= 0XE0;
		/*Select the channel*/
		ADC_U8_ADMUX_REG |= copy_Pu16DigitalValue;
		/*Statr Conversion*/
		SET_BIT(ADC_U8_ADCSRA_REG,6);
		/*wait flag = 1*/
		while(!GET_BIT(ADC_U8_ADCSRA_REG,4));
		//while(GET_BIT(ADC_U8_ADCSRA_REG,4) == 0);
		/*Claer flag*/
		CLR_BIT(ADC_U8_ADCSRA_REG,4);
		/*Read the Didital Value*/
		*copy_Pu16DigitalValue = ADC_U16_ADC_DATA_REG;
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}

	 
	
	
	return L_enumFunctionState;
}

