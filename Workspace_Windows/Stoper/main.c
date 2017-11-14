/*
 * main.c
 *
 *  Created on: 30-05-2013
 *      Author: Marwis95
 */


#include <avr/io.h>
#include <util/delay.h>
#include "font.h"



int main(void){
DDRB = 0xFF; //wyjscia zasilania
DDRA = 0xFF; //sterowanie wyswietlaczem

DDRC |= 1<<1; //port C bedzie wejsciem
PORTC |= 1 << 1; //wywo³anie C

init_font();

while(1){
	PORTB = ~0xF; //zapalam 4 pierwsze piny
	if(!(PINA & 1)) PORTA = ~(font[0]); else PORTA = ~(font[1]); //wyswietlam 0
	_delay_ms(1000);
	PORTB = ~0x0; //na 1 sec gasnie
	_delay_ms(1000);
}




for(;;);
return 0;
}
