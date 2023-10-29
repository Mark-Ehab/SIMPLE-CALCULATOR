/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Mark
 */
#include"../HAL/KeyPad_Handler_V1/KeyPad_int.h"
#include"../HAL/LCD_handler_v1/LCD_int.h"
#include"../HAL/LCD_handler_v1/LCD_Functions.h"
#include"util/delay.h"
#include"Calculator_Operations.h"

void main()
{
	/*Initializations*/
	LCD_vidinit();
	KEYPAD_vidInit();
	/*Screen Intro Glitch*/
	LCD_u8goTo(0,5);
	LCD_vidwriteString("MARK'S");
	_delay_ms(30);
	LCD_u8goTo(0,5);
	LCD_vidwriteString("S'KARM");
	_delay_ms(30);
	LCD_u8goTo(0,5);
	LCD_vidwriteString("MARK'S");
	_delay_ms(1000);
	LCD_u8goTo(1,3);
	LCD_vidwriteString("rotaluclaC");
	_delay_ms(30);
	LCD_u8goTo(1,3);
	LCD_vidwriteString("Calculator");
	_delay_ms(1000);
	LCD_vidclearDisplay();
	LCD_viddisplayOnCursorOn();
	LCD_vidblinkCursor();
	/*Variables Declarations*/
	u8 Local_u8Keypressed;
	u8 Local_u8LastKeypressed=0;
	u8 Local_u8ScreenCounter=0;
	s32 Local_s32Num_1=0;
	s32 Local_s32Num_2=0;
	s32 Local_s32Result;
	u8 num_organize[10];
	u8 Local_u8NumLength_1 = 0 ;
	u8 Local_u8NumLength_2 = 0 ;
	u8 Local_u8OperationFlag;
	u32 iteration=1;
	Local_u8Keypressed = NO_KEY_PRESSED;
	while(1)
	{
		/*Entering the first number*/
		while(Local_u8Keypressed!='+' && Local_u8Keypressed!='-' && Local_u8Keypressed!='*' && Local_u8Keypressed!='/' && Local_u8Keypressed!='=')
		{
			Local_u8Keypressed = KEYPAD_u8GetPressed();
			if(Local_u8Keypressed != NO_KEY_PRESSED)
			{
				if(Local_u8Keypressed<=9)
				{
					LCD_vidwriteNumber(Local_u8Keypressed);
					Local_u8ScreenCounter++;
					num_organize[Local_u8NumLength_1]=Local_u8Keypressed;
					Local_u8NumLength_1++;
				}
				else
				{
					switch(Local_u8Keypressed)
					{
					case '+':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8ScreenCounter++;
						Local_u8OperationFlag=0;
						break;
					case '-':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8ScreenCounter++;
						Local_u8OperationFlag=1;
						break;
					case'=':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						break;
					case '*':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8ScreenCounter++;
						Local_u8OperationFlag=2;
						break;
					case '/':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8ScreenCounter++;
						Local_u8OperationFlag=3;
						break;
					case'c':
						Local_u8NumLength_1=0;
						Local_u8ScreenCounter=0;
						LCD_vidclearDisplay();
						break;
					default:
						Local_u8Keypressed=NO_KEY_PRESSED;
					}
				}
			}
		}
		for(u8 Local_u8DigitCounter = 0 ; Local_u8DigitCounter<Local_u8NumLength_1 ;Local_u8DigitCounter++)
		{
			Local_s32Num_1 += num_organize[Local_u8NumLength_1-1-Local_u8DigitCounter]*iteration;
			iteration*=10;
		}
		iteration=1;
		Local_u8NumLength_1=0;
		if(Local_u8Keypressed =='=')
		{
			LCD_vidwriteNumber(Local_s32Num_1);
			Local_u8Keypressed=NO_KEY_PRESSED;
			Local_s32Num_1=0;
		}
		/*Entering the second number*/
		while(Local_u8Keypressed!='=')
		{
			Local_u8Keypressed = KEYPAD_u8GetPressed();
			if(Local_u8Keypressed != NO_KEY_PRESSED)
			{
				if(Local_u8Keypressed<=9)
				{
					LCD_vidwriteNumber(Local_u8Keypressed);
					Local_u8ScreenCounter++;
					num_organize[Local_u8NumLength_2]=Local_u8Keypressed;
					Local_u8NumLength_2++;
				}
				else if(Local_u8Keypressed =='=')
				{
					LCD_vidwriteCharacter(Local_u8Keypressed);
					Local_u8ScreenCounter++;
				}
				else if(Local_u8Keypressed =='c')
				{
					Local_u8NumLength_1=0;
					Local_u8NumLength_2=0;
					Local_s32Num_1=0;
					Local_u8ScreenCounter=0;
					LCD_vidclearDisplay();
					break;
				}
				else
				{
					switch(Local_u8Keypressed)
					{
					case '+':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8LastKeypressed=Local_u8Keypressed;
						break;
					case '-':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8LastKeypressed=Local_u8Keypressed;
						break;
					case '*':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8LastKeypressed=Local_u8Keypressed;
						break;
					case '/':
						LCD_vidwriteCharacter(Local_u8Keypressed);
						Local_u8LastKeypressed=Local_u8Keypressed;
						break;
					default:
						Local_u8Keypressed=NO_KEY_PRESSED;
					}
				}
			}
		}
		if((Local_u8LastKeypressed=='+'||Local_u8LastKeypressed=='-'||Local_u8LastKeypressed=='*'||Local_u8LastKeypressed=='/') && Local_u8Keypressed=='=')
		{
			LCD_u8goTo(1,0);
			LCD_vidwriteString("Syntax Error!");
			Local_u8LastKeypressed=0;
			Local_s32Num_1=0;
			Local_s32Num_2=0;
			Local_u8ScreenCounter=0;
			Local_u8Keypressed=NO_KEY_PRESSED;
		}
		else if (Local_u8Keypressed=='=')
		{
			for(u8 Local_u8DigitCounter = 0 ; Local_u8DigitCounter<Local_u8NumLength_2 ;Local_u8DigitCounter++)
			{
				Local_s32Num_2 += num_organize[Local_u8NumLength_2-1-Local_u8DigitCounter]*iteration;
				iteration*=10;
			}
			iteration=1;
			Local_u8NumLength_2=0;
			switch(Local_u8OperationFlag)
			{
			//Summation
			case 0 :
				Local_s32Result=CALC_u32Sum(Local_s32Num_1,Local_s32Num_2);
				break;
			//Subtraction
			case 1 :
				Local_s32Result=CALC_u32Sub(Local_s32Num_1,Local_s32Num_2);
				break;
			//Multiplication
			case 2 :
				Local_s32Result=CALC_u32Mul(Local_s32Num_1,Local_s32Num_2);
				break;
			//Division
			default :
				Local_s32Result=CALC_u32Div(Local_s32Num_1,Local_s32Num_2);
			}
			if(Local_u8OperationFlag==3 && Local_s32Result==(-1))
			{
				LCD_u8goTo(1,0);
				LCD_vidwriteString("Math Error!");
			}
			else
			{
				u8 counter = 0;
				s32 Local_s32ResultCopy = Local_s32Result;
				if(Local_s32ResultCopy < 0)
				{
					Local_s32ResultCopy*=-1;
					counter++;
				}
				while(Local_s32ResultCopy!=0)
				{
					Local_s32ResultCopy=Local_s32ResultCopy/10;
					counter++;
				}
				if((Local_u8ScreenCounter+counter)<=16)
				{
					LCD_vidwriteNumber(Local_s32Result);
				}
				else
				{
					LCD_u8goTo(1,0);
					LCD_vidwriteString("Out of space");
				}
			}
			Local_u8Keypressed=NO_KEY_PRESSED;
			Local_s32Num_1=0;
			Local_s32Num_2=0;
			Local_u8ScreenCounter=0;
		}
		else
		{
			Local_u8Keypressed=NO_KEY_PRESSED;
		}
	}
}



