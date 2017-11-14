/*
 * main.c
 *
 *  Created on: 17-05-2013
 *      Author: Marwis95
 */
//PA0-6 7seg
//PB4-7 zasilanie
#include <avr/io.h>
#include <util/delay.h>
#include "font.h"


int main(void)
{
	DDRC = 0xFF;
	DDRB = 0xFF;

	DDRA = 0xFF;

	//PORTB = ~0xFF;
	init_font();
	PORTA = ~(font[0]);
	int i;


	//PORTB = ~0x02;
	//PORTA = ~(font[0]);


	while(1){
			PORTB = ~0x80;
			PORTA = ~(font[3]);


			_delay_ms(1000);
			PORTB = ~0x40;
			PORTA = ~(font[2]);


			_delay_ms(1000);
			PORTB = ~0x20;
			PORTA = ~(font[1]);


			_delay_ms(1000);
			PORTB = ~0x10;
			PORTA = ~(font[0]);
			_delay_ms(1000);
	}

	for(;;)

	return 0;
}
