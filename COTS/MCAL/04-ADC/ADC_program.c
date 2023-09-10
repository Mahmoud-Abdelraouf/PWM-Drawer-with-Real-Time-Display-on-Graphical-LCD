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
    // Configure ADC Control Register A (ADCSRA)
    
    // Step 1: Enable the ADC (ADEN bit)
    SET_BIT(ADC_ADCSRA_R, ADEN);

    // Step 2: Disable Auto-Triggering (ADATE bit)
    CLR_BIT(ADC_ADCSRA_R, ADATE);

    // Step 3: Set ADC Prescaler to 128 for CLK/128 (ADPS2, ADPS1, ADPS0 bits)
    SET_BIT(ADC_ADCSRA_R, ADPS2);
    SET_BIT(ADC_ADCSRA_R, ADPS1);
    SET_BIT(ADC_ADCSRA_R, ADPS0);

    // Configure ADC Multiplexer Register (ADMUX)

    // Step 4: Select Vref = AVCC with external capacitor at AREF pin (REFS1:REFS0 bits)
    SET_BIT(ADC_ADMUX_R, REFS0);
    
    // Step 5: Right Adjust Result (ADLAR bit)
    CLR_BIT(ADC_ADMUX_R, ADLAR);
}

Std_ReturnType ADC_GetDigitalValue(u8 Copy_ChannelNo, u16 *Copy_DigitalValue)
{
    Std_ReturnType Local_FunctionStatus = E_OK;

    if ((Copy_ChannelNo < 32) && (NULL != Copy_DigitalValue))
    {
        /* Clear MUX bits 4 to 0 */
        ADC_ADMUX_R &= 0xE0;

        /* Select the channel */
        ADC_ADMUX_R |= Copy_ChannelNo;

        /* Start conversion */
        SET_BIT(ADC_ADCSRA_R, 6);

        /* Wait for the conversion to complete */
        while (!GET_BIT(ADC_ADCSRA_R, 4));

        /* Clear the conversion complete flag */
        CLR_BIT(ADC_ADCSRA_R, 4);

        /* Read the digital value */
        *Copy_DigitalValue = ADC_DATA_R;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

