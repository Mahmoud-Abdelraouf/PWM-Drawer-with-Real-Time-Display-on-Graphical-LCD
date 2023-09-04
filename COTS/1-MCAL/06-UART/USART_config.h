/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 06/02/2023              ***********/
/********** SWC     : USART                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/*USART_SPEED_TRANSMISSION_OPTIONS: DOUBLE_SPEED,
									NORMAL_SPEED*/
									
#define USART_SPEED_MODE			NORMAL_SPEED

/*USART_FREQUENCY_OPTIONS: write your Oscillator Frequency, note that your range (1000000 ~ 16000000), 
						   see that Atmega32 can work on a maximum frequency of 16MHz.*/
#define USART_u32FREQUENCY			8000000

/*USART_BAUD_RATE_OPTIONS: you have range from (2400 ~ 1000000) for Baud Rate(bps)
						   and some of this range invalid for some frequency
*/
#define USART_u32BAUD_RATE			9600






#endif
