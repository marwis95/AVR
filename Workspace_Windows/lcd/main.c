/*
 * main.c
 *
 *  Created on: 21-05-2013
 *      Author: Marwis95
 */


#include <avr/io.h>
#include "hd44780.h"
#include <stdio.h>
#include <util/delay.h>

int main(void){
	LCD_Initalize();
	LCD_Home();
	LCD_Clear();
	LCD_WriteText("Napis");

	/*char tab[9];
	tab[0]="N";
	tab[1]="A";
	tab[2]="P";
	tab[3]="I";
	tab[4]="S";
	tab[5]=" ";
	tab[6]=":";
	tab[7]=")";
	tab[8]=0x0;


	LCD_Initalize();
	LCD_Home();
	LCD_Clear();

	int i;

	for (i=0; i<9; i=i+1){
	LCD_GoTo(i,0);
	LCD_WriteText(tab[i]);
	}*/

	/*int i;
	char ch[7];
	for (i=0; i<9; i=i+1){
		LCD_GoTo(0,0);
		itoa (i,ch,10);
		LCD_WriteText(i);
		_delay_ms(1000);
		LCD_Clear();
		}*/


/*
char ch[7];
int i=34;
itoa (i,ch,10);
LCD_WriteText(ch);
*/

for(;;);
}
