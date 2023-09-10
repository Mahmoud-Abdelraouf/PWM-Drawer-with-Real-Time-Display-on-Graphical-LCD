/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 21/09/2022              *************************/
/************** SWC     : GIE                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(void)
{
	SET_BIT(GIE_SREG_R, GIE_SREG_B);
}

void GIE_voidDisable(void)
{
	CLR_BIT(GIE_SREG_R, GIE_SREG_B);
}
