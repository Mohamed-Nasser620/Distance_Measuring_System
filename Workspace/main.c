/*
 * Mini_Project_4.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Mohamed
 */

#include "lcd.h"
#include "ultrasonic.h"
#include "common_macros.h"
#include <avr/io.h>

int main (void)
{
	register uint16 distance = 0;                /* Register variable for storing the measured distance */
	SET_BIT (SREG, 7);                           /* Set I_Bit */
	LCD_init();                                  /* Initialize LCD */
	Ultrasonic_init();      					 /* Initialize ultrasonic sensor */
	/* Print the fixed message on LCD */
	LCD_moveCursor(0,0);
	LCD_displayString("DISTANCE =    CM");

	for(;;)
	{
		distance = Ultrasonic_readDistance();    /* Read the value from ultrasonic sensor */
		/* Print the value of distance on LCD */
		LCD_moveCursor(0,11);
		if (distance < 10)
		{
		LCD_displayInteger((sint32) distance);
		LCD_sendData(' ');
		LCD_sendData(' ');
		}
		else if (distance < 100)
		{
			LCD_displayInteger((sint32) distance);
			LCD_sendData(' ');
		}
		else
		{
			LCD_displayInteger((sint32) distance);
		}
	}
}
