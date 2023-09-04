/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 23/09/2022              ***********/
/********** SWC     : LCD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*options:
	For PORTS Choose :
			1-DIO_U8_PORTA
			2-DIO_U8_PORTB
			3-DIO_U8_PORTC
			4-DIO_U8_PORTD
	For PINS Choose :
			1-DIO_U8_PIN0
			2-DIO_U8_PIN1
			3-DIO_U8_PIN2
			4-DIO_U8_PIN3
			5-DIO_U8_PIN4
			6-DIO_U8_PIN5
			7-DIO_U8_PIN6
			8-DIO_U8_PIN7*/
/*************************Control Port*************************/	
#define LCD_U8_CONTROL_PORT				DIO_U8_PORTA
#define LCD_U8_RS_PIN					DIO_U8_PIN1
#define LCD_U8_RW_PIN					DIO_U8_PINX
#define LCD_U8_E_PIN					DIO_U8_PIN2
/*************************Data Port*************************/	
#define LCD_U8_DATA_PORT				DIO_U8_PORTA
#define LCD_U8_D0_PIN					DIO_U8_PIN0
#define LCD_U8_D1_PIN					DIO_U8_PIN1
#define LCD_U8_D2_PIN					DIO_U8_PIN2
#define LCD_U8_D3_PIN					DIO_U8_PIN3
#define LCD_U8_D4_PIN					DIO_U8_PIN3
#define LCD_U8_D5_PIN					DIO_U8_PIN4
#define LCD_U8_D6_PIN					DIO_U8_PIN5
#define LCD_U8_D7_PIN					DIO_U8_PIN6

/*options : 1-LCD_U8_8_BIT
			2-LCD_U8_4_BIT*/
#define LCD_U8_MODE						LCD_U8_4_BIT



#endif


