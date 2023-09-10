/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 26/09/2022              *************************/
/************** SWC     : ADC                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __ADC_PRIVATE_H_
#define __ADC_PRIVATE_H_

/**< Define for ADC Registers */
#define ADC_ADMUX_R 		(*((volatile u8 *)0X27))
#define ADC_ADCSRA_R    	(*((volatile u8 *)0X26))
#define ADC_ADCH_R			(*((volatile u8 *)0X25))
#define ADC_ADCL_R			(*((volatile u8 *)0X24))

#define ADC_DATA_R  		(*((volatile u16 *)0X24)) 


#define ADC_SFIOR_R 		(*((volatile u8 *)0X50))

// Macros for ADC Control Register A (ADCSRA) bits
#define ADEN    7   // ADC Enable bit
#define ADATE   5   // ADC Auto-Trigger Enable bit
#define ADPS2   2   // ADC Prescaler Select bit 2
#define ADPS1   1   // ADC Prescaler Select bit 1
#define ADPS0   0   // ADC Prescaler Select bit 0

// Macros for ADC Multiplexer Register (ADMUX) bits
#define REFS1   7   // Reference Selection bit 1
#define REFS0   6   // Reference Selection bit 0
#define ADLAR   5   // ADC Left Adjust Result bit



#endif /**< __ADC_PRIVATE_H_ */
