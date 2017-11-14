/*
 * main.c
 *
 *  Created on: 21-06-2013
 *      Author: Marwis95
 */

#include <avr/io.h>
//#include "hd44780.h"
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#define INSTR_PER_US 12                   // instructions per microsecond (depends on MCU clock, 12MHz current)
#define INSTR_PER_MS 12000                // instructions per millisecond (depends on MCU clock, 12MHz current)
#define MAX_RESP_TIME_MS 200      // timeout - max time to wait for low voltage drop (higher value increases measuring distance at the price of slower sampling)
#define DELAY_BETWEEN_TESTS_MS 50 // echo cancelling time between sampling



volatile unsigned char up = 0;
volatile unsigned long result = 0;
volatile uint32_t timerCounter = 0;
volatile unsigned char running=0;

void sonar(){
PORTB = 0x00;
_delay_us(1);

PORTB = 0x01;
running = 1;
_delay_us(10);

PORTB = 0x00;

}

SIGNAL (INT1_vect){
if (running){
	if (up == 0) {
		up = 1;
		timerCounter = 0;
		TCNT0 = 0;

		} else {
			up = 0;
			result = (timerCounter * 256 + TCNT0) / 58;
			running = 0;
			}
	}

}

SIGNAL (TIMER0_OVF_vect){
	if (up){
		timerCounter++;
		uint32_t ticks = timerCounter * 256 + TCNT0;
		uint32_t max_ticks = (uint32_t)MAX_RESP_TIME_MS * INSTR_PER_MS;

		if (ticks > max_ticks){
			up = 0;
			running = 0;
			result = -1;
			}
		}
}



int main (void){

MCUCR |= (0<<ISC11) | (1 << ISC10);
GICR |= (1 << INT1);

TCCR0 = (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0 = 0;
TIMSK = 1<<TOIE0;

sei();

DDRB = 0xFF;
PORTB = 0x00;

for(;;){
	if (running == 0){
		_delay_ms(DELAY_BETWEEN_TESTS_MS);
		sonar();
		}
}


	return 0;
}
