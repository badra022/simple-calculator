 /******************************************************************************
 *
 * Module: Lcd , keypad
 *
 * File Name: Application.c
 *
 * Description: simple calculator with + , - , * ,/ operations
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
#include"keypad.h"
#include "lcd.h"
int main(void)
{
	/*initialization code*/
	KEYPAD_init();
	LCD_init();
	uint32 input1 =0;
	uint32 input2 =0;
	uint8 op;
	while(TRUE)
	{
		/*application code*/
		KEYPAD_getPressed();
		LCD_displayCharacter(current_key);
		if(current_key == '+' || current_key == '-' || current_key == 'x' || current_key == '/')
		{
			op = current_key;
			while(TRUE)
			{
				KEYPAD_getPressed();
				LCD_displayCharacter(current_key);
				if(current_key == '=')break;
				input2 = (current_key-48) + input2*10;
			}
			switch(op)
			{
			case '+' :
				LCD_displayInt(input1 + input2);
				break;
			case '-' :
				LCD_displayInt(input1 - input2);
				break;
			case 'x' :
				LCD_displayInt(input1 * input2);
				break;
			case '/' :
				if(input2 == 0){
					LCD_sendCommand(CLEAR_SCREEN );
					LCD_displayString("Error!");
				}
				else
				{
				LCD_displayInt((int)input1 / input2);
				LCD_displayString(".");
				int reminder = (int)(((float)(input1 % input2)/input2)*100);
				LCD_displayInt(reminder);
				}
				break;
			}
			while(KEYPAD_getPressed() != 'c');
			LCD_sendCommand(CLEAR_SCREEN );
			input1 =0;
			input2 =0;
		}
		else if(current_key != 'c')
		{
			input1 = (current_key-48) + input1*10;
		}
	}
}
