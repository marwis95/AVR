/*
 * main.c
 *
 *  Created on: 16-06-2013
 *      Author: Marwis95
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//#include "hd44780.h"

volatile uint8_t triger_ON = 0;		//pomiar trwa
volatile uint32_t duration=0;		//czas pomiaru

int main()
{

	//DDRB=0xFF;
	//PORTB=0xFF;
	//_delay_ms(2000);
	//TIMER0 czas po jakim nast¹pi przerwanie 1us
	OCR0 = 2;
	TCCR0 |= (1<<WGM01);
	TCCR0 |= (1<<CS01);		//preskaler 8
	TIMSK |= (1<<OCIE0);

	//INT1
	//pod³¹czyæ ECHO
	MCUCR |= (1<<ISC10) | (1<<ISC11);
	GICR |= (1<<INT1);
	PORTD |= (1<<PD3);
	DDRD &= ~(1<<PD3);

	DDRA |= (1<<PA6);		//trig
	PORTA &= ~(1<<PA6);
	//LCD_Initalize();//lcd_init();
	sei();
	while(1)
	{
		/*
		 * start pomiaru
		 */
		PORTA &= ~(1<<PA6);
		_delay_us(2);
		PORTA |= (1<<PA6);
		_delay_us(10);
		triger_ON =1;
		PORTA &= ~(1<<PA6);
		/*
		 * oczekiwanie na pomiar
		 */
		while(triger_ON);
		/*
		 * wypisanie czasu trwania pomiaru na LCD
		 */

		//LCD_GoTo(0,0); //lcd_locate(0,0);
		//LCD_WriteText(duration);//lcd_int(duration);
		//duration=0;		//wyzerowanie czasu trwania pomiaru

		_delay_ms(300);
		//LCD_Clear();//lcd_cls();
		triger_ON = 1;
	}
}


ISR(TIMER0_COMP_vect)
{
	if(triger_ON)
	{
		duration++;
	}
}

ISR(INT1_vect)
{
	triger_ON=0;
}
