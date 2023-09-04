/**************************************************************************/
/************** Author   : Mahmoud Abdelraouf Mahmoud   *******************/
/************** Date	 : 4 Sep 2023                   *******************/
/************** Version  : 0.1                          *******************/
/************** Module   : BIT_MATH.h                   *******************/
/**************************************************************************/
#ifndef __BIT_MATH_H_
#define __BIT_MATH_H_

#define SET_BIT(REG, BIT_NUMBER) 	REG |= (1<< BIT_NUMBER)
#define CLR_BIT(REG, BIT_NUMBER) 	REG &= ~(1<< BIT_NUMBER)
#define TOG_BIT(REG, BIT_NUMBER) 	REG ^= (1<< BIT_NUMBER)
#define GET_BIT(REG, BIT_NUMBER) 	((REG & (1<< BIT_NUMBER)) >> BIT_NUMBER)



#endif /**< __BIT_MATH_H_ */

