/*
 * main.c
 *
 *  Created on: 19-12-2013
 *      Author: root
 */

#include <avr/io.h>
#include "hd44780.h"
#include <stdio.h>
#include <util/delay.h>

int main(void){
	LCD_Initalize();
	LCD_Home();
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_WriteText("testttt");
	LCD_GoTo(0,1);
	LCD_WriteText("aaa");


for(;;);
}
