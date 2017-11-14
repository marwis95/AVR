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
//#include <string.h>
int main(void)
{
	LCD_Initalize();
	LCD_Home();  //cofam txt na pocz¹tek
	//LCD_GoTo(0,0); //ustalam pozycje
	//LCD_WriteText("aaa"); //napis

	LCD_Clear();





	LCD_GoTo(0,0);
	LCD_WriteText("ABCDEFGHIJKLMNOP");




	LCD_GoTo(0,1);
	LCD_WriteText("RSTUWYZ0123456789");


 	for(;;);


	return 0;
}

