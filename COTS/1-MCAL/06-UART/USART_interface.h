/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 06/02/2023              ***********/
/********** SWC     : USART                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


/****************************************PROTOTYPES***********************************************************************/


void USART_voidInit(void);
void USART_voidSendByte(u8 Copy_u8DataByte);
u8 USART_u8RecieveByte(u8 *Copy_pu8RecByte);



#endif /* USART_INTERFACE_H */
