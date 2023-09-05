 #ifndef __TIMER2_PRIVATE_H_
 #define __TIMER2_PRIVATE_H_

#define TIMER2_TCCR2_R			*((volatile u8 *)0X45)
#define TIMER2_TCNT2_R			*((volatile u8 *)0X44)
#define TIMER2_OCR2_R			*((volatile u8 *)0X43)
#define TIMER2_ASSR_R			*((volatile u8 *)0X42)
/**
 * @brief macros for interrupt
 * TIMSK : for enable
 * TIMFR : for flags
 * bit 6 and 7 for each register are for timer2
 */
#define TIMER2_TIMSK_R			*((volatile u8 *)0X59)
#define TIMER2_TIFR_R			*((volatile u8 *)0X58)





#endif /**< __TIMER2_PRIVATE_H_ */