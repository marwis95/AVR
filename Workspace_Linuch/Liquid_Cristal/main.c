#include <avr/io.h>
#include "hd44780.h"
#include <stdio.h>
#include <util/delay.h>

int main(void){
	LCD_Initalize();
	LCD_Home();
	LCD_Clear();
	LCD_WriteText("testttt");


for(;;);
}
