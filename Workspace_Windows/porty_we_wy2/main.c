/*
 * main.c
 * C 2,3,4,5 NIE DZIA£A
 *  Created on: 04-06-2013
 *      Author: Marwis95
 */


/* przyk³ad 2.3 "leds3.c" */
/* 8 diod LED prz³¹czonych do portu D */
/* 4 przyciski przy³¹czone do PB0..PB3 */
/* ATmega 1MHz */

#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Wszystkie linie portu D bêd¹ wyjœciami */

    DDRD  = 0xff;

    /* Linie portu B bêd¹ wejœciami z podci¹gniêciem do VCC */
    DDRB  = 0x00;

    PORTB = 0xff;

    /* Pocz¹tek nieskoñczonej pêtli */
    for(;;)
    {
        /* Przepisanie zawartoœci PINB do PORTD */
        PORTD = PINB;
        //PORTD = ~PINB & 0x0f;
    }
}
