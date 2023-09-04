/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 26/09/2022              ***********/
/********** SWC     : KPD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_U8_ROWS_PORT            DIO_U8_PORTB
#define KPD_U8_COLS_PORT            DIO_U8_PORTD



#define KPD_U8_R1_PIN				DIO_U8_PIN4
#define KPD_U8_R2_PIN				DIO_U8_PIN5
#define KPD_U8_R3_PIN				DIO_U8_PIN6
#define KPD_U8_R4_PIN				DIO_U8_PIN7




#define KPD_U8_C1_PIN				DIO_U8_PIN2
#define KPD_U8_C2_PIN				DIO_U8_PIN3
#define KPD_U8_C3_PIN				DIO_U8_PIN4
#define KPD_U8_C4_PIN				DIO_U8_PIN5
	
	
	
#define KPD_KEYS               		{						\
										{'1','2','3','+'},  \
										{'4','5','6','-'},  \
										{'7','8','9','*'},  \
										{'0','=','/','%'}	\
									}

#endif
