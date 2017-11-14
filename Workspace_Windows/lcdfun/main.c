/*
 * main.c
 *
 *  Created on: 17-05-2013
 *      Author: Marwis95
 */

#include <avr/io.h>
#include <util/delay.h>
#include "font.h"


int main(void)
{
	DDRC = 0xFF;

	DDRA = 0xFF;
	init_font();
	PORTA = ~(font[0]);
	int i;



	while(1)
	{

		for(int i=0; i<10; i++)
		{
			PORTA = ~(font[i]);
			_delay_ms(1000);


		}

	}

	for(;;)

	return 0;
}
