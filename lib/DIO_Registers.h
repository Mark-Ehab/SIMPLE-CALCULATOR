/*
 * DIO_Registers.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Mark
 */

#ifndef LIB_DIO_REGISTERS_H_
#define LIB_DIO_REGISTERS_H_

#include"stdtypes.h"

//Port_A DIO registers
#define DDRA_REG *((volatile u8*)0x3A)
#define PORTA_REG *((volatile u8*)0x3B)
#define PINA_REG *((volatile u8*)0x39)
//Port_B DIO registers
#define DDRB_REG *((volatile u8*)0x37)
#define PORTB_REG *((volatile u8*)0x38)
#define PINB_REG *((volatile u8*)0x36)
//Port_C DIO registers
#define DDRC_REG *((volatile u8*)0x34)
#define PORTC_REG *((volatile u8*)0x35)
#define PINC_REG *((volatile u8*)0x33)
//Port_D DIO registers
#define DDRD_REG *((volatile u8*)0x31)
#define PORTD_REG *((volatile u8*)0x32)
#define PIND_REG *((volatile u8*)0x30)


#endif /* LIB_DIO_REGISTERS_H_ */
