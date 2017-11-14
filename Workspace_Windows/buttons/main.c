/*
 * main.c
 *
 *  Created on: 25-05-2013
 *      Author: Marwis95
 */


#include <avr/io.h>
#include <util/delay.h>
int main(void)
{

	DDRA |= 1<<1;
	PORTA |= 1 << 1;
	while(1)
	{
		if(!(PINA & 1))
		{
			PORTA = 1;
		}
		else PORTA = 3;

	}



	return 0;
}
