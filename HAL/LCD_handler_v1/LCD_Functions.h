/*
 * LCD_Functions.h
 *
 *  Created on: Sep 21, 2021
 *      Author: Mark
 */

#ifndef HAL_LCD_HANDLER_V1_LCD_FUNCTIONS_H_
#define HAL_LCD_HANDLER_V1_LCD_FUNCTIONS_H_

#include"../../lib/stdtypes.h"

/*LCD commands macros*/
#define LCD_FUNCTION_SET_EIGHT_BIT_MODE_CMD  		(u8) 0x38
#define LCD_FUNCTION_SET_FOUR_BIT_MODE_CMD  		(u8) 0x28
#define LCD_DISPLAY_ON_CURSOR_OFF_CMD   	    	(u8) 0x0C
#define LCD_DISPLAY_OFF_CURSOR_OFF_CMD    	    	(u8) 0x08
#define LCD_DISPLAY_ON_CURSOR_ON_CMD   	    		(u8) 0x0E
#define LCD_DISPLAY_OFF_CURSOR_ON_CMD    	    	(u8) 0x0A
#define LCD_BLINK_CURSOR_CMD						(u8) 0x0F
#define LCD_SHIFT_LEFT_CURSOR_CMD					(u8) 0x10
#define LCD_SHIFT_RIGHT_CURSOR_CMD					(u8) 0x14
#define LCD_SHIFT_LEFT_DISPLAY_CMD					(u8) 0x18
#define LCD_SHIFT_RIGHT_DISPLAY_CMD					(u8) 0x1C
#define LCD_BEGIN_AT_FIRST_LINE_CMD					(u8) 0x80
#define LCD_BEGIN_AT_SECOND_LINE_CMD				(u8) 0xC0
#define LCD_DISPLAY_CLEAR_CMD 						(u8) 0x01
#define LCD_ENTRY_MODE_SET_CMD						(u8) 0x06
/*LCD functions prototypes*/
void LCD_vidfunctionSetEightBitMode();
void LCD_vidfunctionSetFourBitMode();
void LCD_viddisplayOnCursorOff();
void LCD_viddisplayOffCursorOff();
void LCD_viddisplayOnCursorOn();
void LCD_viddisplayOffCursorOn();
void LCD_vidblinkCursor();
void LCD_vidshiftLeftCursor();
void LCD_vidshiftRightCursor();
void LCD_vidshiftDisplayLeft();
void LCD_vidshiftDisplayRight();
void LCD_vidbeginAtFirstLine();
void LCD_vidbeginAtSecondLine();
void LCD_vidclearDisplay();
void LCD_videntryModeSet();
void LCD_vidwriteString(u8*str);
void LCD_vidwriteNumber(s32 num);
void LCD_vidsetCGRamAddress(u32 loc);
void LCD_vidwriteArabicCharactersOnCGRam(u8*character,u32 loc);
u8 LCD_u8goTo(u8 row_no , u8 col_no);

#endif /* HAL_LCD_HANDLER_V1_LCD_FUNCTIONS_H_ */
