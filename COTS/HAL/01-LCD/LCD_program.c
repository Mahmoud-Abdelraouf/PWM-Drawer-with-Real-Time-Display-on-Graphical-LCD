/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 23/09/2022              ***********/
/********** SWC     : LCD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
/*LIB*/
#include <util/delay.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "BIT_MATH.h"
/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
#if LCD_U8_MODE == LCD_U8_8_BIT
	_delay_ms(1000);
	LCD_voidSendCmnd(LCD_U8_SET_8_BIT_MODE_CMND);
	LCD_voidSendCmnd(LCD_U8_DISPLAY_ON_CMND);
	LCD_voidSendCmnd(LCD_U8_CLEAR_CMND);
	LCD_voidSendCmnd(LCD_U8_ENTRY_MODE_SET_CMND);
#elif LCD_U8_MODE == LCD_U8_4_BIT
_delay_ms(1000);
	LCD_voidSendCmnd(LCD_U8_SET_4_BIT_MODE_CMND1);
	LCD_voidSendCmnd(LCD_U8_SET_4_BIT_MODE_CMND2);
	LCD_voidSendCmnd(LCD_U8_SET_4_BIT_MODE_CMND3);
	LCD_voidSendCmnd(LCD_U8_DISPLAY_ON_CMND);
	LCD_voidSendCmnd(LCD_U8_CLEAR_CMND);
	LCD_voidSendCmnd(LCD_U8_ENTRY_MODE_SET_CMND);
#endif
}




void LCD_voidSendCmnd(u8 copy_u8cmnd)
{
	/*RS = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_RS_PIN,DIO_U8_LOW);
#if LCD_U8_MODE == LCD_U8_8_BIT
/******************************* Code to send a command as 8 bit mode *******************************/
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D0_PIN,copy_u8cmnd >> 0 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D1_PIN,copy_u8cmnd >> 1 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D2_PIN,copy_u8cmnd >> 2 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D3_PIN,copy_u8cmnd >> 3 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8cmnd >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8cmnd >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8cmnd >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8cmnd >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
#elif LCD_U8_MODE == LCD_U8_4_BIT
/******************************* Code to send a command as 4 bit mode *******************************/
	/************************write command higher order 4 bits************************/
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8cmnd >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8cmnd >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8cmnd >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8cmnd >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
	/************************write command lower order 4 bits************************/
	copy_u8cmnd = copy_u8cmnd << 4; // shift the low 4 bits to to 4 high bits to cab be read in D7 D6 D5 D4
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8cmnd >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8cmnd >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8cmnd >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8cmnd >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
#endif
}


void LCD_voidSendChar(u8 copy_u8char)
{
	/*RS = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_RS_PIN,DIO_U8_HIGH);
#if LCD_U8_MODE == LCD_U8_8_BIT
/******************************* Code to send a command as 8 bit mode *******************************/
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D0_PIN,copy_u8char >> 0 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D1_PIN,copy_u8char >> 1 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D2_PIN,copy_u8char >> 2 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D3_PIN,copy_u8char >> 3 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8char >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8char >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8char >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8char >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
#elif LCD_U8_MODE == LCD_U8_4_BIT
/******************************* Code to send a command as 4 bit mode *******************************/
	/************************write command higher order 4 bits************************/
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8char >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8char >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8char >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8char >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
	/************************write command lower order 4 bits************************/
	copy_u8char = copy_u8char << 4; // shift the low 4 bits to to 4 high bits to cab be read in D7 D6 D5 D4
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D4_PIN,copy_u8char >> 4 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D5_PIN,copy_u8char >> 5 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D6_PIN,copy_u8char >> 6 & 0x01);
	DIO_Error_State_tSetPinValue(LCD_U8_DATA_PORT,LCD_U8_D7_PIN,copy_u8char >> 7 & 0x01);
	/*E = 1*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_HIGH);
	/*puls delay*/
	_delay_ms(5);
	/*E = 0*/
	DIO_Error_State_tSetPinValue(LCD_U8_CONTROL_PORT,LCD_U8_E_PIN,DIO_U8_LOW);
#endif
}



void LCD_voidWriteString(u8 *copy_Pu8string)
{
	for(u8 L_u8iter = 0;copy_Pu8string[L_u8iter]!='\0';L_u8iter++)
	{
		LCD_voidSendChar(copy_Pu8string[L_u8iter]);
	}
}

Error_State_t LCD_Error_State_tGoToXY(u8 copy_u8lineNum,u8 copy_u8location)
{
	Error_State_t L_enumFunctionState = RET_OK;
	if(copy_u8location<=39)
	{
		switch(copy_u8lineNum)
		{
			case LCD_U8_LINE1 : LCD_voidSendCmnd(0x80+copy_u8location);break;
			case LCD_U8_LINE2 : LCD_voidSendCmnd(0xC0+copy_u8location);break;
			default : L_enumFunctionState = RET_NOK;
		}
	}
	else
	{
		L_enumFunctionState = RET_NOK;
	}
	return L_enumFunctionState;
}
