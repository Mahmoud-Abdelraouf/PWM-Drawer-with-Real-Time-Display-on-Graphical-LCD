/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 26/09/2022              *************************/
/************** SWC     : ADC                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __ADC_PRIVATE_H_
#define __ADC_PRIVATE_H_

/**< Define for ADC Registers */
#define ADC_ADMUX_R 				(*((volatile u8 *)0X27))
#define ADC_ADCSRA_R    		    (*((volatile u8 *)0X26))
#define ADC_ADCH_R				    (*((volatile u8 *)0X25))
#define ADC_ADCL_R				    (*((volatile u8 *)0X24))

#define ADC_ADC_DATA_R  			(*((volatile u16 *)0X24)) //For ADCH && ADCL 


#define ADC_SFIOR_R 				(*((volatile u8 *)0X50))




#endif /**< __ADC_PRIVATE_H_ */
