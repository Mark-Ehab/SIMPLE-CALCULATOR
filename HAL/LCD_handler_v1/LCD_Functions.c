/*
 * LCD_Functions.c
 *
 *  Created on: Sep 21, 2021
 *      Author: Mark
 */
#include"LCD_Functions.h"
#include"LCD_int.h"
#include"../../lib/stderrors.h"

/*LCD functions*/

//Set up LCD on 8-bit mode
void LCD_vidfunctionSetEightBitMode()
{
	LCD_vidsendCommand(LCD_FUNCTION_SET_EIGHT_BIT_MODE_CMD);
}
//Set up LCD on 4-bit mode
void LCD_vidfunctionSetFourBitMode()
{
	LCD_vidsendCommand(LCD_FUNCTION_SET_FOUR_BIT_MODE_CMD);
}
//Turn on display and turn off cursor
void LCD_viddisplayOnCursorOff()
{
	LCD_vidsendCommand(LCD_DISPLAY_ON_CURSOR_OFF_CMD);
}
//Turn off display and turn off cursor
void LCD_viddisplayOffCursorOff()
{
	LCD_vidsendCommand(LCD_DISPLAY_OFF_CURSOR_OFF_CMD);
}
//Turn on display and turn on cursor
void LCD_viddisplayOnCursorOn()
{
	LCD_vidsendCommand(LCD_DISPLAY_ON_CURSOR_ON_CMD);
}
//Turn off display and turn on cursor
void LCD_viddisplayOffCursorOn()
{
	LCD_vidsendCommand(LCD_DISPLAY_OFF_CURSOR_ON_CMD);
}
//Blink the cursor
void LCD_vidblinkCursor()
{
	LCD_vidsendCommand(LCD_BLINK_CURSOR_CMD);
}
//Shift left the cursor
void LCD_vidshiftLeftCursor()
{
	LCD_vidsendCommand(LCD_SHIFT_LEFT_CURSOR_CMD);
}
//Shift right the cursor
void LCD_vidshiftRightCursor()
{
	LCD_vidsendCommand(LCD_SHIFT_RIGHT_CURSOR_CMD);
}
//Shift left the entire display
void LCD_vidshiftDisplayLeft()
{
	LCD_vidsendCommand(LCD_SHIFT_LEFT_DISPLAY_CMD);
}
//Shift right the entire display
void LCD_vidshiftDisplayRight()
{
	LCD_vidsendCommand(LCD_SHIFT_RIGHT_DISPLAY_CMD);
}
//Force cursor to he beginning of the first line
void LCD_vidbeginAtFirstLine()
{
	LCD_vidsendCommand(LCD_BEGIN_AT_FIRST_LINE_CMD);
}
//Force cursor to he beginning of the second line
void LCD_vidbeginAtSecondLine()
{
	LCD_vidsendCommand(LCD_BEGIN_AT_SECOND_LINE_CMD);
}
//Clear the entire display
void LCD_vidclearDisplay()
{
	LCD_vidsendCommand(LCD_DISPLAY_CLEAR_CMD);
}
//Set up LCD on the entry mode
void LCD_videntryModeSet()
{
	LCD_vidsendCommand(LCD_ENTRY_MODE_SET_CMD);
}
//Forces the LCD controller to point CGRAM address
void LCD_vidsetCGRamAddress(u32 loc)
{
	if(loc<8)
	{
		LCD_vidsendCommand(64+(loc*8));
	}
}
//Write a string on the LCD display
void LCD_vidwriteString(u8*str)
{
	u32 counter=0;
	/**Writing the string on the LCD display**/
	while(str[counter]!='\0')
	{
		LCD_vidwriteCharacter(str[counter]);
		counter++;
		if(counter==16)
		{
			LCD_vidbeginAtSecondLine();
		}
	}
}
//Write an integer number on the LCD display
void LCD_vidwriteNumber(s32 num)
{
	s32 num_copy=num;
	u8 counter=0;
	if(num==0)
	{
		LCD_vidwriteCharacter('0');
	}
	if(num<0)
	{
		LCD_vidwriteCharacter('-');
		num_copy *=-1;
		num*=-1;
	}
	/**Counting number of digits for the integer**/
	while(num_copy!=0)
	{
		num_copy=num_copy/10;
		counter++;
	}
	/**Separating number digits then organizing them into a char array**/
	u8 num_digits[counter];
	for(s32 digit_no=counter-1 ; digit_no>=0 ; digit_no--)
	{
		num_digits[digit_no]=(num%10)+'0';
		num=num/10;
	}
	/**Writing the number on the LCD display**/
	for(u32 digit_no=0 ; digit_no<counter ; digit_no++)
	{
		LCD_vidwriteCharacter(num_digits[digit_no]);
	}
}
//Put the cursor at a specific location (segment) on the LCD display
u8 LCD_u8goTo(u8 row_no , u8 col_no)
{
	u8 local_u8errStatus = RT_OK ;
	if(col_no>=0 && col_no<=15)
	{
		switch(row_no)
		{
		case 0:
			LCD_vidsendCommand(col_no+128);
			break;
		case 1:
			LCD_vidsendCommand(col_no+192);
			break;
		default:
			local_u8errStatus = RT_NOK;
		}
	}
	else
	{
		local_u8errStatus = RT_NOK;
	}
	return local_u8errStatus ;
}

void LCD_vidwriteArabicCharactersOnCGRam(u8*character,u32 loc)
{
	LCD_vidsetCGRamAddress(loc);
	for(u32 i = 0 ; i < 8 ; i++)
	{
		LCD_vidwriteCharacter(character[i]);
	}
}
