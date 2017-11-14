/*******************************************************************************/
/*					             PROPOX                                        */
/*                           www.propox.com                                    */
/*                                                                             */
/* Program demonsturjacy dzilanie przetwornika ADC oraz termometru LM35.       */
/* - PA0 wejscie analogowe polaczone z wyjsciem TEM                            */
/* - AREF = 1V !!!                                                             */
/* This program show how to use ADC converter and LM35.                        */
/* - PA0 analog input connect to TEM output                                    */
/* - AREF = 1V !!!                                                             */
/*******************************************************************************/
// wewnetrzny zegar 1MHz (internal oscillator 1MHz)
// LCD
// PD0 - R/S
// PD1 - E
// PD2 - D4
// PD3 - D5
// PD4 - D6
// PD5 - D7
// LM35
// PA0 - TEM
// AREF zworte, ustawione na 1V (AREF short, set to 1V)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <string.h>

#include "char_code.h"
#include "LCD_lib.h"


uint16_t  value_low;
uint16_t  value_high;
uint16_t  value;

uint8_t   themp[4];

uint8_t tytul[] = ("Jebac Ciapatych");
uint8_t wartosc[] = ("T : ");
uint8_t kropka[] = (".");
uint8_t jednostka[2] = {0xDF,67};


//przerwanie z przetwornika ADC
SIGNAL(SIG_ADC)
{
  	value_low = ADCL;
	value_high = ADCH;
	value = ((value_high<<2)|(value_low>>6));
	itoa(value,themp,10);

	LCDGotoXY(6,1);
    LCDstring(themp,2);
	LCDstring(kropka,1);
	LCDstring(themp+2,1);
	ADCSRA = _BV(ADEN)|_BV(ADIE)|_BV(ADSC)|_BV(ADPS1)|_BV(ADPS0);
}


int main(void)
{
//LCD
LCDinit();
LCDcursorOFF();
LCDGotoXY(1,0);
LCDstring(tytul,14);
LCDGotoXY(4,1);
LCDstring(wartosc,2);
LCDGotoXY(10,1);
LCDstring(jednostka,2);

//Sleep mode
set_sleep_mode(SLEEP_MODE_ADC);

//ADC
ADMUX  = _BV(ADLAR);
ADCSRA = _BV(ADEN)|_BV(ADIE)|_BV(ADSC)|_BV(ADPS1)|_BV(ADPS0);
//Przerwania wlaczone
sei();
//Sleep
sleep_mode();

	while(1)
	{
	}

return 0;
}
