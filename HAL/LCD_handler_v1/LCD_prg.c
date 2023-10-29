/*
 * LCD_prg.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Mark
 */
#include "../../MCAL/DIO_V1/DIO_int.h"
#include "../../lib/stdtypes.h"
#include "util/delay.h"
#include "LCD_cfg.h"
#include "LCD_Functions.h"
#include "LCD_int.h"

void LCD_vidinit()
{
	//Setting control and data ports directions as output ports
	DIO_u8setPortDir(LCD_DATA_PORT,FULL_OUTPUT);
	DIO_u8setPortDir(LCD_CTRL_PINS_PORT,0x07);
	_delay_ms(40);
	//Set up LCD on the 8-bit mode
	LCD_vidfunctionSetEightBitMode();
	_delay_ms(1);
	//Display on LCD and turn off cursor
	LCD_viddisplayOnCursorOff();
	_delay_ms(1);
	//Clear LCD
	LCD_vidclearDisplay();
	_delay_ms(3);
	//Setting up LCD on entry mode
	LCD_videntryModeSet();
	_delay_ms(1);

}
void LCD_vidsendCommand(u8 Copy_u8cmd)
{
	//For command
	DIO_u8setPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);
	//For write
	DIO_u8setPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);
	//For setting enable HIGH
	DIO_u8setPinVal(LCD_E_PORT , LCD_E_PIN , HIGH);
	//Send CMD
	DIO_u8setPortVal(LCD_DATA_PORT , Copy_u8cmd);
	//For clearing enable
	DIO_u8setPinVal(LCD_E_PORT , LCD_E_PIN , LOW);
	_delay_ms(2);

}
void LCD_vidwriteCharacter(u8 Copy_u8char)
{
	//For data
	DIO_u8setPinVal(LCD_RS_PORT , LCD_RS_PIN , HIGH);
	//For write
	DIO_u8setPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);
	//For setting enable HIGH
	DIO_u8setPinVal(LCD_E_PORT , LCD_E_PIN , HIGH);
	//Send Char
	DIO_u8setPortVal(LCD_DATA_PORT , Copy_u8char);
	//For clearing enable
	DIO_u8setPinVal(LCD_E_PORT , LCD_E_PIN , LOW);
	_delay_ms(2);
}


