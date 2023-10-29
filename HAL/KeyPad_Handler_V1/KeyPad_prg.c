/*
 * Keypad_prg.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Mark
 */
#include"../../MCAL/DIO_V1/DIO_int.h"
#include"util/delay.h"
#include"../../lib/stdtypes.h"
#include "KeyPad_cfg.h"
#include"KeyPad_int.h"

u8 KEYPAD_u8KeypadMap[KEYPAD_ROWS][KEYPAD_COLS]={
												 {1  , 2 ,  3  , '+'},
												 {4  , 5 ,  6  , '-'},
												 {7  , 8 ,  9  , '*'},
												 {'c', 0 , '=' , '/'}
												};

void KEYPAD_vidInit()
{
	/*Set rows as input*/
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_ROW_1,INPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_ROW_2,INPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_ROW_3,INPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_ROW_4,INPUT);
	/*Set columns as output*/
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_COLUMN_1,OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_COLUMN_2,OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_COLUMN_3,OUTPUT);
	DIO_u8setPinDir(KEYPAD_PORT,KEYPAD_COLUMN_4,OUTPUT);

	/*Enable pull-up resistors for keypad rows*/
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_ROW_1,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_ROW_2,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_ROW_3,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_ROW_4,HIGH);
	/*Set initial values for keypad columns*/
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_COLUMN_1,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_COLUMN_2,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_COLUMN_3,HIGH);
	DIO_u8setPinVal(KEYPAD_PORT,KEYPAD_COLUMN_4,HIGH);


}
u8 KEYPAD_u8GetPressed()
{
	u8 Local_u8KeyPressed = NO_KEY_PRESSED ;
	u8 Local_u8CurrentColumn;
	u8 Local_u8CurrentRow;
	u8 Local_u8CurrentRowStatus;

	for(Local_u8CurrentColumn=KEYPAD_COLUMN_START ; Local_u8CurrentColumn<=KEYPAD_COLUMN_END ; Local_u8CurrentColumn++)
	{
		/* Activate the current column*/
		DIO_u8setPinVal(KEYPAD_PORT,Local_u8CurrentColumn,LOW);
		for(Local_u8CurrentRow=KEYPAD_ROW_START ; Local_u8CurrentRow<=KEYPAD_ROW_END ; Local_u8CurrentRow++)
		{
			DIO_u8getPinVal(KEYPAD_PORT,Local_u8CurrentRow,&Local_u8CurrentRowStatus);
			if(Local_u8CurrentRowStatus == LOW)
			{
				/* Using 1D array*/
				//Local_u8KeyPressed = (((Local_u8CurrentRow-KEYPAD_ROW_START)*KEYPAD_COLS) + (Local_u8CurrentColumn-KEYPAD_COLUMN_START));
				/* Using 2D array*/
				Local_u8KeyPressed = KEYPAD_u8KeypadMap[Local_u8CurrentRow-KEYPAD_ROW_START][Local_u8CurrentColumn-KEYPAD_COLUMN_START];
				_delay_ms(5);
				while(Local_u8CurrentRowStatus == LOW)
				{
					DIO_u8getPinVal(KEYPAD_PORT,Local_u8CurrentRow,&Local_u8CurrentRowStatus);
				}
				_delay_ms(5);
			}
		}
		DIO_u8setPinVal(KEYPAD_PORT,Local_u8CurrentColumn,HIGH);
	}
	return Local_u8KeyPressed;
}
//u8 KEPAD_u8IsPressed(u8 copy_u8ID)
//{
//
//}
//const u8*KEYPAD_u8cpGetAll()
//{
//
//}
