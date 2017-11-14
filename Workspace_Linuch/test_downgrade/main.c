/*
 * main.c
 *
 *  Created on: 04-12-2013
 *      Author: root
 */


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

   DDRA = 0xFF;
   DDRB = 0xFF;
   DDRC = 0xFF;
   DDRD = 0xFF;

   /* Pocz¹tek nieskoñczonej pêtli */
   while(1)
   {
	PORTA=0x00;
	PORTB=0x00;
	PORTC=0x00;
	PORTD=0x00;
   }
}
