/*
 * bitmath.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Mark
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#include"stdtypes.h"
/*Function-like macros*/
#define CLR_BIT(Copy_u8reg,Copy_u8pin) 		Copy_u8reg &= ~(1<<(Copy_u8pin))
#define SET_BIT(Copy_u8reg,Copy_u8pin) 		Copy_u8reg |= (1<<(Copy_u8pin))
#define TOGGLE_BIT(Copy_u8reg,Copy_u8pin)	Copy_u8reg ^= (1<<(Copy_u8pin))
#define GET_BIT(Copy_u8reg,Copy_u8pin)		((Copy_u8reg&(1<<Copy_u8pin))>>(Copy_u8pin))

#endif /* LIB_BITMATH_H_ */
