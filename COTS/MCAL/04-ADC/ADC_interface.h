/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 25/10/2022              ***********/
/********** SWC     : ADC                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*Single Ended*/
#define ADC_U8_CHANNEL_0			0
#define ADC_U8_CHANNEL_1			1
#define ADC_U8_CHANNEL_2			2
#define ADC_U8_CHANNEL_3			3
#define ADC_U8_CHANNEL_4			4
#define ADC_U8_CHANNEL_5			5
#define ADC_U8_CHANNEL_6			6
#define ADC_U8_CHANNEL_7			7
/*Differential Ended*/
#define ADC_U8_CHANNEL_8			8
#define ADC_U8_CHANNEL_9			9
#define ADC_U8_CHANNEL_10			10
#define ADC_U8_CHANNEL_11			11
#define ADC_U8_CHANNEL_12			12
#define ADC_U8_CHANNEL_13			13
#define ADC_U8_CHANNEL_14			14
#define ADC_U8_CHANNEL_15			15
#define ADC_U8_CHANNEL_16			16
#define ADC_U8_CHANNEL_17			17
#define ADC_U8_CHANNEL_18			18
#define ADC_U8_CHANNEL_19			19
#define ADC_U8_CHANNEL_20			20
#define ADC_U8_CHANNEL_21			21
#define ADC_U8_CHANNEL_22			22
#define ADC_U8_CHANNEL_23			23
#define ADC_U8_CHANNEL_24			24
#define ADC_U8_CHANNEL_25			25
#define ADC_U8_CHANNEL_26			26
#define ADC_U8_CHANNEL_27			27
#define ADC_U8_CHANNEL_28			28
#define ADC_U8_CHANNEL_29			29
#define ADC_U8_CHANNEL_30			30
#define ADC_U8_CHANNEL_31			31


void ADC_voidInit(void);

Error_State_t ADC_Get_DigitalValue(u8 copy_u8ChanneNo,u16 *copy_Pu16DigitalValue);


#endif