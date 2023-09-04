/**************************************************************************/
/************** Name    : Mahmoud a raouf mahmoud *************************/
/************** Date    : 18/09/2022              *************************/
/************** SWC     : DIO                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
 #ifndef __DIO_INTERFACE_H_
 #define __DIO_INTERFACE_H_


/* Macros for PORTS */
#define DIO_u8_PORTA		0
#define DIO_u8_PORTB		1
#define DIO_u8_PORTC		2
#define DIO_u8_PORTD		3



/* Macros for PINS */
#define DIO_u8_PIN0 		0
#define DIO_u8_PIN1			1
#define DIO_u8_PIN2			2
#define DIO_u8_PIN3			3
#define DIO_u8_PIN4			4
#define DIO_u8_PIN5			5
#define DIO_u8_PIN6			6
#define DIO_u8_PIN7			7



/* Macros for Pin Direction */
#define DIO_u8_OUTPUT		1
#define DIO_u8_INPUT		0



/* Macros for pin value */
#define DIO_u8_HIGH			1
#define DIO_u8_LOW			0

void DIO_voidInit(void);

Std_ReturnType DIO_Error_State_tSetPinDirection  (u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinDirection);

Std_ReturnType DIO_Error_State_tSetPinValue      (u8 copy_u8portId, u8 copy_u8pinId,u8 copy_u8pinValue);

Std_ReturnType DIO_Error_State_tGetPinValue      (u8 copy_u8portId, u8 copy_u8pinId,u8 *copy_u8returnedPinValue);

Std_ReturnType DIO_Error_State_tSetPortDirection (u8 copy_u8portId, u8 copy_u8portDirection);

Std_ReturnType DIO_Error_State_tSetPortValue     (u8 copy_u8portId, u8 copy_u8portValue);

Std_ReturnType DIO_Error_State_tGetPortValue     (u8 copy_u8portId, u8 *copy_u8returnedportValue);


#endif /**< __DIO_INTERFACE_H_ */
