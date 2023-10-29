/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Mark
 */

#ifndef DIO_V1_DIO_INT_H_
#define DIO_V1_DIO_INT_H_

#include "../../lib/stdtypes.h"

/*Macros*/
//PIN level
#define PORT_A 			(u8)0
#define PORT_B 			(u8)1
#define PORT_C 			(u8)2
#define PORT_D 			(u8)3
#define PIN_0 			(u8)0
#define PIN_1 			(u8)1
#define PIN_2 			(u8)2
#define PIN_3 			(u8)3
#define PIN_4 			(u8)4
#define PIN_5 			(u8)5
#define PIN_6 			(u8)6
#define PIN_7 			(u8)7
#define INPUT 			(u8)0
#define OUTPUT			(u8)1
#define LOW 			(u8)0
#define HIGH 			(u8)1
//PORT level
#define FULL_INPUT 		0x00
#define FULL_OUTPUT		0xff
#define FULL_LOW 		0x00
#define FULL_HIGH 		0xff
/*Function prototypes*/
//PORT level
u8 DIO_u8setPortDir(u8 Copy_u8port , u8 Copy_u8dir);
u8 DIO_u8setPortVal(u8 Copy_u8port , u8 Copy_u8val);
u8 DIO_u8getPortVal(u8 Copy_u8port , u8* Copy_u8pval);
// PIN level
u8 DIO_u8setPinDir(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8dir);
u8 DIO_u8setPinVal(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8val);
u8 DIO_u8getPinVal(u8 Copy_u8port , u8 Copy_u8pin , u8* Copy_u8pval);

#endif /* DIO_V1_DIO_INT_H_ */
