/*
 * main.c
 *
 *  Created on: 03-06-2013
 *      Author: Marwis95
 */


#include <avr/io.h>

int main() {
     DDRD |= _BV(PD0); //ustawiamy port PD0 jako wyjœcie
     PORTD |= _BV(PD0); //i ustawiamy to wyjœcie w stan wysoki (dioda nie œwieci siê)

     DDRC &= ~_BV(PC0); //PC0 jako wejœcie
     PORTC |= _BV(PC0); //które podci¹gamy do plusa

     while(1) {//nasz program nigdy siê nie koñczy
          if(bit_is_clear(PINC, PC0)) { //jeœli wejœcie jest w stanie niskim
               if(bit_is_set(PORTD, PD0)) //jeœli bit by³ ustawiony
                    PORTD &= ~_BV(PD0); //to go wyczyœæ
               else
                    PORTD |= _BV(PD0);//jeœli nie - ustaw go
          }
     }
}
