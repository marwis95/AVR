//ob³uga kbuttonów i lcd
//lcd PD
//buttons PA

/*
 * main.c
 *
 *  Created on: 21-05-2013
 *      Author: Marwis95
 */
#include <avr/io.h>
#include "hd44780.h"
#include <util/delay.h>
#include <stdio.h>
int main(void)
{
    DDRA  = 0x00;
    PORTA = 0xff;

LCD_Initalize();
LCD_Home();  //cofam txt na pocz¹tek
LCD_Clear();
LCD_GoTo(0,0);
LCD_WriteText("Start");


while(1){
if(!(PINA & 0x00)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Zwolniony");
		}

if(!(PINA & 0x01)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 0");
		}

if(!(PINA & 0x02)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 1");
		}

if(!(PINA & 0x04)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 2");
		}

if(!(PINA & 0x08)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 3");
		}


if(!(PINA & 0x10)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 4");
		}

if(!(PINA & 0x20)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 5");
		}

if(!(PINA & 0x40)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 6");
		}

if(!(PINA & 0x80)){
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Button 7");
		}


_delay_ms(250);
}


	return 0;
}

