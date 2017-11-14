/*
 * main.c
 *
 *  Created on: 14-06-2013
 *      Author: Marwis95
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd44780.h"

#define KEY_DOWN !(PINA & (1<<PA1))

void triger(void);
uint8_t licznik_switch=0;

volatile uint16_t PulseWidth;
uint16_t licznik_us=0;


int main()
{

	DDRA |= (1<<PA0);	//wyjscie
	PORTA &= ~(1<<PA0); //TRIGER

	DDRD &= ~(1<<PD6);	//wejscie ECHO
	PORTD &= ~(1<<PD6);	//ICP

	DDRA &= ~(1<<PA1); // wejscie
	PORTA |= (1<<PA1); // uSWITCH

	lcd_initialize();

    TCCR1B |= (1<<ICES1);  /* Zbocze narastaj¹ce wywo³a przerwanie*/
    TCCR1B |= (1<<CS11);   /* preskaler = 8 */
    //TCCR1B |= (1<<ICNC1); //NOISE CANCELLER
    TIMSK |=  (1<<TICIE1);   /* zezwolenie na przerwanie od ICP */

    sei();                 /* globalne zezwolenie na przerwania */

    lcd_cls();

	while(1)
	{
		licznik_us=(PulseWidth-7)/2;//7ms opoznienia z przerwañ dziele na 2 bo 2MHz
		lcd_locate(0,0);
		lcd_int(licznik_switch);
		lcd_locate(1,1);
		lcd_int(PulseWidth);
		lcd_locate(1,10);
		lcd_int(licznik_us);


		if(KEY_DOWN)
				{
					_delay_ms(80);
					if(KEY_DOWN)
					{
						lcd_cls();
						triger(); //wyzwolenie
						licznik_switch++;//potwierdzenie wyzwolenia na LCD
					}
				}
	}//koniec while(1)


}//koniec main
ISR(TIMER1_CAPT_vect)
{
    static uint16_t LastCapture;

    if( !(TCCR1B & (1<<ICES1)) ) PulseWidth = ICR1 - LastCapture;
    LastCapture = ICR1;

    TCCR1B ^= (1<<ICES1); //zmiana zbocza
}

void triger(void)
	{
		PORTA &= ~(1<<PA0);
		_delay_us(2);
		PORTA |= (1<<PA0); //wystawienie jedynki na TRIG
		_delay_us(10);		//wymagane 10 uS stanu wysokiego
		PORTA &= ~(1<<PA0);	//wystawienie zera na TRIG
	}
