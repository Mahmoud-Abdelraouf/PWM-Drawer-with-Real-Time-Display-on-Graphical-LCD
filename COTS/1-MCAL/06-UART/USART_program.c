/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 06/02/2023              ***********/
/********** SWC     : USART                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/


/*****************************************INCLUDES***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
/*****************************************IMPLEMENTATIONS********************************************************/
static u32 USART_u32CalcUBRRValue(void)
{
	u32 L_u32UBRRValue = 0;
	if((USART_u32FREQUENCY>=1000000&&USART_u32FREQUENCY<=16000000)&&(USART_u32BAUD_RATE>=2400&&USART_u32BAUD_RATE<=1000000))
	{
		#if 	USART_SPEED_MODE == NORMAL_SPEED
		L_u32UBRRValue = (u32)((USART_u32FREQUENCY/16*USART_u32BAUD_RATE)-1);
		#elif 	USART_SPEED_MODE == DOUBLE_SPEED
		L_u32UBRRValue = (u32)((USART_u32FREQUENCY/8*USART_u32BAUD_RATE)-1);
		#else /*ERROR_STATE*/
		#endif
	}
	else
	{
		/*ERROR_STATE*/
	}
	return L_u32UBRRValue;
}

void USART_voidInit(void)
{
	u16 L_u16BoudRate = USART_u32CalcUBRRValue(); 			
	/* baud rate = 9600 */
	USART_u8_UBRRL_REG = (u8)L_u16BoudRate;
	USART_u8_UBRRH_REG = (u8)(L_u16BoudRate>>8);
	#if 	USART_SPEED_MODE == NORMAL_SPEED
	CLR_BIT(USART_u8_UCSRA_REG,UCSRA_U2X_BIT);
	#elif	USART_SPEED_MODE == DOUBLE_SPEED
	SET_BIT(USART_u8_UCSRA_REG,UCSRA_U2X_BIT);
	#endif
	u8 L_u8UCSRCValue = 0b10000000; // to make sure that the UCSRC is selected the 8th bit should by 1

	/*disable MPCM (Multi-processor Communication Mode)*/
	CLR_BIT(USART_u8_UCSRA_REG,UCSRA_MPCM_BIT);
	/***************Enable Rx,Tx******************/
	SET_BIT(USART_u8_UCSRB_REG,UCSRB_RXEN_BIT);
	SET_BIT(USART_u8_UCSRB_REG,UCSRB_TXEN_BIT);
	/*********************************************/
	/***************select 8 bit data*************/
	CLR_BIT(USART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);
	SET_BIT(L_u8UCSRCValue,UCSRC_UCSZ0_BIT);
	SET_BIT(L_u8UCSRCValue,UCSRC_UCSZ1_BIT);
	/*********************************************/
	/***************select Asynch mode************/
	CLR_BIT(L_u8UCSRCValue,UCSRC_UMSEL_BIT);
	/*********************************************/
	/***************No parity bit*****************/
	CLR_BIT(L_u8UCSRCValue,UCSRC_UPM1_BIT);
	CLR_BIT(L_u8UCSRCValue,UCSRC_UPM0_BIT);
	/*********************************************/
	/***************Enable 2 stop Bits************/
	SET_BIT(L_u8UCSRCValue,UCSRC_USBS_BIT);
	/***************Enable 2 stop Bits************/
	/*update UCSRC REG*/
	USART_u8_UCSRC_REG = L_u8UCSRCValue;
	
}

void USART_voidSendByte(u8 Copy_u8DataByte)
{
	/* wait until the transmit register is empty */
	while(!GET_BIT(USART_u8_UCSRA_REG,UCSRA_UDRE_BIT));
	/*Send the data*/
	USART_u8_UDR_WRITE_REG = Copy_u8DataByte;
}

u8 USART_u8RecieveByte(u8 *Copy_u8RecByte)
{
	u8 L_u8ErrorState = STD_TYPES_NOK;
	if(Copy_u8RecByte != NULL)
	{
		/* wait until the data is recieved */
		while(!GET_BIT(USART_u8_UCSRA_REG,UCSRA_RXC_BIT));
		/* Read the data */
		*Copy_u8RecByte = USART_u8_UDR_READ_REG;
		u8 L_u8ErrorState = STD_TYPES_OK;
	}
	else
	{
		L_u8ErrorState = STD_TYPES_NOK;
	}
	return L_u8ErrorState;
}

