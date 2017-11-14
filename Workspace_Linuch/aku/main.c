/*
 * main.c
 *
 *  Created on: 06-02-2014
 *      Author: root
 */

#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#define ADCIN PC5
#define VREF 5.0

void main(void){
	char wynik[4];//bufor
	char p_string[4];
	float adc;
	float procent;
	float temp;

	LCD_Initalize();
	LCD_GoTo(0, 0);
	LCD_WriteText("TEST");

	ADCSRA = (1<<ADEN) | (1<<ADPS2); //Init + presc
	ADMUX  =    (1<<REFS0) | (1<<MUX2) | (1<<MUX0);  //kanal + v (5.0)
	DDRC &=~ (1<<PC5);

	for(;;){
	     ADCSRA |= (1<<ADSC);//ADSC: Uruchomienie pojedynczej konwersji
	     while(ADCSRA & (1<<ADSC)); //czeka na zakończenie konwersji

	     adc=ADC*VREF/256;
	     sprintf(wynik,"U=%1.1f [V]",adc);
	     LCD_GoTo(0, 0);
	     LCD_Clear;
	     LCD_WriteText(wynik);

	     //LCD_GoTo(0, 1);
	    // LCD_WriteText("Procent: ");

	     	 	LCD_GoTo(0,1);
	     	 	if(adc>13) LCD_WriteText("Procent=OVER");	else
	     	 		if((adc<13)&&(adc>=12.6)); else
	     	 			if ((adc<12.6)&&(adc>=11.8)) {
	     	 				    		 temp=adc-11.8;
	     	 				    		 procent=temp/0.008;
	     	 				    		 sprintf(p_string,"Procent=%1.1f ",procent);
	     	 				    		 LCD_GoTo(0, 1);
	     	 				    		 LCD_WriteText(p_string);
	     	 				    		 }
	     	 			else LCD_WriteText("Procent=00.0");






	     _delay_ms(250);
	}

}
