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
	DDRA = 0xFF;
	PORTA = ~(A | B);
	int i;
	for(;;)for(i=0; i<8; i++)
	{
		PORTA = ~(1<<i);
		_delay_ms(100);
	}
	for(;;);

	return 0;
}
