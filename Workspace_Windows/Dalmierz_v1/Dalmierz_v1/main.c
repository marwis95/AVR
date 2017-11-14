/*
 * main.c
 *
 *  Created on: 23-07-2013
 *      Author: unborn
 */
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "hd44780/HD44780.h"

#define ECHO_PORT PORTA
#define ECHO_READ PINA
#define ECHO_DDR DDRA
#define ECHO_PIN 1

#define TRIG_PORT PORTA
#define TRIG_DDR DDRA
#define TRIG_PIN 0

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

void init(void)
{
	TRIG_DDR |= (1<<TRIG_PIN);
	ECHO_DDR &= ~(1<<ECHO_PIN);

	TRIG_PORT &= ~(1<<TRIG_PIN);
	ECHO_PORT &= ~(1<<ECHO_PIN);


}
void out(unsigned char c)
{
	unsigned char buffer[2] = {c, '\0'};
	LCD_WriteText(buffer);
}

unsigned long pulseIn()
{
        // cache the port and bit of the pin in order to speed up the
        // pulse width measuring loop and achieve finer resolution.  calling
        // digitalRead() instead yields much coarser resolution.
        uint8_t bit = 1<<ECHO_PIN;
        unsigned long width = 0; // keep initialization out of time critical area

        // convert the timeout from microseconds to a number of times through
        // the initial loop; it takes 16 clock cycles per iteration.
        unsigned long numloops = 0;
        unsigned long maxloops = microsecondsToClockCycles(1000) / 16;

        // wait for any previous pulse to end
        while ((ECHO_READ & bit) == bit)
                if (numloops++ == maxloops)
                        return 0;

        // wait for the pulse to start
        while ((ECHO_READ & bit) != bit)
                if (numloops++ == maxloops)
                        return 0;

        // wait for the pulse to stop
        while ((ECHO_READ & bit) == bit)
                width++;

        // convert the reading to microseconds. The loop has been determined
        // to be 10 clock cycles long and have about 16 clocks between the edge
        // and the start of the loop. There will be some error introduced by
        // the interrupt handlers.
        return clockCyclesToMicroseconds(width * 7 + 100);
}


int main(void)
{

	FILE usart_streaam = FDEV_SETUP_STREAM(out,NULL,  _FDEV_SETUP_WRITE);
	stdout = &usart_streaam;

	init();
	PORTA = 0x00;


	LCD_Initalize();
	LCD_Home();
	LCD_WriteText("Jebac ciapatych");



	while(1)
	{
		//Boom
		TRIG_PORT |= (1<<TRIG_PIN);
		_delay_us(10);
		TRIG_PORT &= ~(1<<TRIG_PIN);
		//Kaboom
		 unsigned long pomiar = pulseIn();
		LCD_Clear();
		LCD_Home();

		printf("Liczba: %i", pomiar/58	);

		_delay_ms(300);
	}







	for(;;);


	return 0;
}

