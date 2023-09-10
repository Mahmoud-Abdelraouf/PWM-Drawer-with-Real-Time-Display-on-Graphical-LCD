/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 25/10/2022              ***********/
/********** SWC     : ADC                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**< MCAL */
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_Init(void)
{
	/*
	* 1- Select Vref = AVCC
	* 2- Right Adjust
	* 3- Disable AutoTrigger
	* 4- Select CLK/128
	* 5- Enable ADC
	*/
	
	/*1- Select Vref = AVCC*/
	CLR_BIT(ADC_ADMUX_R, 7);
	SET_BIT(ADC_ADMUX_R, 6);
	/*2- Right Adjust*/
	CLR_BIT(ADC_ADMUX_R, 5);
	/*3- Disable AutoTrigger*/
	CLR_BIT(ADC_ADCSRA_R, 5);
	/*4- Select CLK/128*/
	CLR_BIT(ADC_ADCSRA_R, 0);
	SET_BIT(ADC_ADCSRA_R, 1);
	SET_BIT(ADC_ADCSRA_R, 2);
	/*5- Enable ADC*/
	SET_BIT(ADC_ADCSRA_R, 7);

	
}

Std_ReturnType ADC_GetDigitalValue(u8 Copy_ChannelNo, u16 *Copy_DigitalValue)
{
	Std_ReturnType Local_FunctionStatus = E_OK;

	if( (Copy_ChannelNo) < 32 && (NULL != Copy_DigitalValue) )
	{
		/*Clear MUX 4...0*/
		ADC_ADMUX_R &= 0XE0;
		/*Select the channel*/
		ADC_ADMUX_R |= *Copy_DigitalValue;
		/*Start Conversion*/
		SET_BIT(ADC_ADCSRA_R, 6);
		/*wait flag = 1*/
		while(!GET_BIT(ADC_ADCSRA_R, 4));
		//while(GET_BIT(ADC_U8_ADCSRA_REG,4) == 0);
		/*Clear flag*/
		CLR_BIT(ADC_ADCSRA_R, 4);
		/*Read the Digital Value*/
		*Copy_DigitalValue = ADC_ADC_DATA_R;
	}
	else
	{
		Local_FunctionStatus = E_NOT_OK;
	}

	 
	
	
	return Local_FunctionStatus;
}

