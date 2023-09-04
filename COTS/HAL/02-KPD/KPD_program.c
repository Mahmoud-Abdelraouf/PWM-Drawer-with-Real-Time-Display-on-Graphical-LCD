/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 26/09/2022              ***********/
/********** SWC     : KPD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

/*LIB*/
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#include "util/delay.h"
/*MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


const u8 KPD_Au8Keys[4][4] = KPD_KEYS;


const u8 KPD_Au8rowsPins[4] = {KPD_U8_R1_PIN,KPD_U8_R2_PIN,KPD_U8_R3_PIN,KPD_U8_R4_PIN};
const u8 KPD_Au8colsPins[4] = {KPD_U8_C1_PIN,KPD_U8_C2_PIN,KPD_U8_C3_PIN,KPD_U8_C4_PIN};


Error_State_t KPD_u8GetKeyState(u8 *copy_u8returnedKey)
{
	Error_State_t L_enumFunctionState = RET_OK;
	u8 L_u8rowsCounter = 0,L_u8colsCounter = 0,L_u8pinValue = 0,L_u8flag = 0;
	if(NULL!=copy_u8returnedKey)
	{	
		*copy_u8returnedKey = KPD_U8_KEY_NOT_PRESSED;
		/*note the rows pins are the output pins and the column */
		/*Active Each Row => For loop on pins of the rows*/
		for(L_u8rowsCounter = 0;L_u8rowsCounter<4;L_u8rowsCounter++)
		{
			DIO_Error_State_tSetPinValue(KPD_U8_ROWS_PORT,KPD_Au8rowsPins[L_u8rowsCounter],DIO_U8_LOW);
			/*check which input pin has zero*/
			for(L_u8colsCounter = 0;L_u8colsCounter<4;L_u8colsCounter++)
			{
				DIO_Error_State_tGetPinValue(KPD_U8_COLS_PORT,KPD_Au8colsPins[L_u8colsCounter],&L_u8pinValue);
				if(L_u8pinValue == DIO_U8_LOW)
				{
					/*Debouncing*/
					_delay_ms(20);
					DIO_Error_State_tGetPinValue(KPD_U8_COLS_PORT,KPD_Au8colsPins[L_u8colsCounter],&L_u8pinValue);
					/*check if the pin is still equal low*/
					while(L_u8pinValue == DIO_U8_LOW)
					{
						DIO_Error_State_tGetPinValue(KPD_U8_COLS_PORT,KPD_Au8colsPins[L_u8colsCounter],&L_u8pinValue);
					}
					*copy_u8returnedKey = KPD_Au8Keys[L_u8rowsCounter][L_u8colsCounter];
					L_u8flag = 1;
					break;
				}
			}
			/*Deactivate Rows*/
			DIO_Error_State_tSetPinValue(KPD_U8_ROWS_PORT,KPD_Au8rowsPins[L_u8rowsCounter],DIO_U8_HIGH);
			if(L_u8flag == 1)
			{
				break;
			}
		}
	}
	else
	{
		L_enumFunctionState =RET_NOK;
	}
	return L_enumFunctionState;
}
