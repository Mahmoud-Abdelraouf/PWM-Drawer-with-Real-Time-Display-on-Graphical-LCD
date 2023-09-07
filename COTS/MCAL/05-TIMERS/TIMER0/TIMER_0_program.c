/******************************************************************/
/********** Name    : Fathy Abdlhady & Yousef Shawky    ***********/
/********** Date    : 10/10/2022                        ***********/
/********** SWC     : TIMER0 PWM                        ***********/
/********** Version : 1.0                               ***********/
/******************************************************************/


#include "TIMER_0_PWM_interface.h"





Std_ReturnType TIMER_0_PWM_Mode_init(u8 copy_u8PWM_Mode,u8 copy_u8HW_ActionMode,u8 copy_u8Prescaler,u8 copy_u8DutyCycle)
{
    Std_ReturnType ret = E_OK;

    switch(copy_u8PWM_Mode)
    {
        case TIMER0_U8_FAST_PWM_MODE:
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_WGM01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_WGM00_BIT);
            break;
        case TIMER0_U8_PWM_PHASE_CORRECT_MODE:
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_WGM01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_WGM00_BIT);
            break;
        default:
            ret = E_NOT_OK;
            break;
    }

    ret = DIO_SetPinDirection(DIO_PORTB, TIMER0_U8_OC0_BIT, DIO_OUTPUT);

    ret = TIMER_0_HW_ActionMode(copy_u8HW_ActionMode);

    ret = TIMER_0_Select_Prescaler_value(copy_u8Prescaler);

    ret = TIMER_0_PWM_Select_DutyCycle(copy_u8DutyCycle);

    return ret;

}

Std_ReturnType TIMER_0_PWM_Mode_Stop(void)
{
    Std_ReturnType ret = E_OK;

    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
    CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);

    return ret;
}



Std_ReturnType TIMER_0_PWM_Select_DutyCycle(u8 copy_u8DutyCycle)
{
    Std_ReturnType ret = E_OK;

    TIMER0_U8_OCR0_REG = ( ( (float)copy_u8DutyCycle )/100 ) * 255;

    return ret;
}







static Std_ReturnType TIMER_0_Select_Prescaler_value(u8 copy_u8Prescaler)
{
    Std_ReturnType ret = E_OK;

    switch(copy_u8Prescaler)
    {
        case TIMER0_U8_NO_CLOCK_SOURCE: /**< 000 */
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        case TIMER0_U8_N0_PRESCALER: /**< 001 */
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        case TIMER0_U8_PRESCALER_DIV_BY_8: /**< 010 */
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        case TIMER0_U8_PRESCALER_DIV_BY_64: /**< 011 */
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        case TIMER0_U8_PRESCALER_DIV_BY_256: /**< 100 */
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        case TIMER0_U8_PRESCALER_DIV_BY_1024: /**< 101 */
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS02_BIT);
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_CS00_BIT);
            break;
        default:
            ret = E_NOT_OK;
            break;
    }

    return ret;
}

static Std_ReturnType TIMER_0_HW_ActionMode(u8 copy_u8HW_ActionMode)
{
    Std_ReturnType ret = E_OK;

    switch(copy_u8HW_ActionMode)
    {
        case TIMER0_U8_HW_NON_INV_MODE:
            CLR_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_COM00_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_COM01_BIT);
            break;
        case TIMER0_U8_HW_INV_MODE:
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_COM01_BIT);
            SET_BIT(TIMER0_U8_TCCR0_REG, TIMER0_U8_COM00_BIT);
            break;
        default:
            ret = E_NOT_OK;
            break;
    }

    return ret;
}
