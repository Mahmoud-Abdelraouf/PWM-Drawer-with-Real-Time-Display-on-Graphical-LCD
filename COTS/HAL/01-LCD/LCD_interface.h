/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 23/09/2022              ***********/
/********** SWC     : LCD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_U8_LINE1				0
#define LCD_U8_LINE2				1

#include "ERROR_STATE.h"
#include "STD_TYPES.h"

void LCD_voidInit(void);

void LCD_voidSendCmnd(u8 copy_u8cmnd);

void LCD_voidSendChar(u8 copy_u8char);

void LCD_voidWriteString(u8 *copy_Pu8string);

Error_State_t LCD_Error_State_tGoToXY(u8 copy_u8lineNum,u8 copy_u8location);




#endif
