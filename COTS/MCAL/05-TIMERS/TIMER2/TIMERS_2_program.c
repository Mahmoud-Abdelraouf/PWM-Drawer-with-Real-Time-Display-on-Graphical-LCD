/**<  LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**<  MCAL */
#include "TIMERS_2_interface.h"
#include "TIMERS_2_config.h"
#include "TIMERS_2_private.h"
static void delay_1ms(void);
static void delay_1us(void);
static void delay_10us(void);
static void delay_10ms(void);
Std_ReturnType timer2_delay_ms(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus=E_OK;
    u32 Local_Counter=0;
    for(Local_Counter=0;Local_Counter<delay_time;Local_Counter++){
        delay_1ms();
    }
    return Local_FunctionStatus;
}
Std_ReturnType timer2_delay_10ms(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus=E_OK;
    u32 Local_Counter=0;
    for(Local_Counter=0;Local_Counter<delay_time;Local_Counter++){
        delay_10ms();
    }
    return Local_FunctionStatus;
}
Std_ReturnType timer2_delay_us(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus=E_OK;
    u32 Local_Counter=0;
    for(Local_Counter=0;Local_Counter<delay_time;Local_Counter++){
        delay_1us();
    }
    return Local_FunctionStatus;
}
Std_ReturnType timer2_delay_10us(u32 delay_time)
{
    Std_ReturnType Local_FunctionStatus=E_OK;
    u32 Local_Counter=0;
    for(Local_Counter=0;Local_Counter<delay_time;Local_Counter++){
        delay_10us();
    }
    return Local_FunctionStatus;
}
static void delay_10ms(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XB2);
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1024);
    while((TIMER2_TIFR_R&0x40)==0);
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}
static void delay_1ms(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XF0);
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1024);
    while((TIMER2_TIFR_R&0x40)==0);
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}
static void delay_1us(void)
{
    TIMER2_PRELOAD_VALUE_SET(0XF0);
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1);
    while((TIMER2_TIFR_R&0x40)==0);
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}
static void delay_10us(void)
{
    TIMER2_PRELOAD_VALUE_SET(0X61);
    TIMER2_PRESCALER_VALUE_SET(TIMER2_PRESCALER_PRESCALER_DIV_1);
    while((TIMER2_TIFR_R&0x40)==0);
    TIMER2_DSIABLE();
    TIMER2_FLAG_CLEAR();
}