/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 25/10/2022              ***********/
/********** SWC     : ADC                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*Define for ADC Registers*/
#define ADC_U8_ADMUX_REG				*((volatile u8 *)0X27)
#define ADC_U8_ADCSRA_REG				*((volatile u8 *)0X26)
#define ADC_U8_ADCH_REG					*((volatile u8 *)0X25)
#define ADC_U8_ADCL_REG					*((volatile u8 *)0X24)

#define ADC_U16_ADC_DATA_REG			*((volatile u16 *)0X24) //For ADCH && ADCL 


#define ADC_U8_SFIOR_REG				*((volatile u8 *)0X50)




#endif