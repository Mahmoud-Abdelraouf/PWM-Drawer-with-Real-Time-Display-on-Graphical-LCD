/********************************************************/
/********** Name    : Mahmoud a raouf mahmoud ***********/
/********** Date    : 06/02/2023              ***********/
/********** SWC     : USART                    ***********/
/********** Version : 1.0                     ***********/
/********************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


#define NORMAL_SPEED		0
#define DOUBLE_SPEED		1


/********************************************************************************************/
/**********************************USART Register and Bits***********************************/
/* USART I/O Daata Register */
#define USART_u8_UDR_READ_REG				*((volatile u8*)0X2C)
#define USART_u8_UDR_WRITE_REG				*((volatile u8*)0X2C)

/* USART Baud Rate Register-UBRRH */
#define USART_u8_UBRRH_REG				*((volatile u8*)0X40)
/* USART Baud Rate Register-UBRRL */
#define USART_u8_UBRRL_REG				*((volatile u8*)0X29)

/* USART Control and Status Register A*/
#define USART_u8_UCSRA_REG				*((volatile u8*)0X2B)
/* USART Control and Status Register A -> BITS */
#define	UCSRA_MPCM_BIT              	0
#define	UCSRA_U2X_BIT                	1
#define	UCSRA_PE_BIT                 	2
#define	UCSRA_DOR_BIT                	3
#define	UCSRA_FE_BIT                 	4
#define	UCSRA_UDRE_BIT              	5
#define UCSRA_TXC_BIT               	6
#define UCSRA_RXC_BIT					7
/*USART Control and Status Register B*/
#define USART_u8_UCSRB_REG				*((volatile u8*)0X2A)
/*USART Control and Status Register B -> BITS */
#define UCSRB_TXB8_BIT					0
#define UCSRB_RXB8_BIT               	1
#define UCSRB_UCSZ2_BIT              	2
#define UCSRB_TXEN_BIT               	3
#define UCSRB_RXEN_BIT               	4
#define UCSRB_UDRIE_BIT              	5
#define UCSRB_TXCIE_BIT              	6
#define UCSRB_RXCIE_BIT					7
/*USART Control and Status Register C*/
#define USART_u8_UCSRC_REG				*((volatile u8*)0X40)
/*USART Control and Status Register C -> BITS*/
#define UCSRC_UCPOL_BIT					0
#define UCSRC_UCSZ0_BIT					1
#define UCSRC_UCSZ1_BIT					2
#define UCSRC_USBS_BIT					3
#define UCSRC_UPM0_BIT					4
#define UCSRC_UPM1_BIT					5
#define UCSRC_UMSEL_BIT					6
#define UCSRC_URSEL_BIT					7


/********************************************************************************************/



#endif
