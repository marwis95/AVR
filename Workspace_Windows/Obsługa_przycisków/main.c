/*
 * main.c
 *
 *  Created on: 03-06-2013
 *      Author: Marwis95
 */


#include <avr/io.h>

int main() {
     DDRD |= _BV(PD0); //ustawiamy port PD0 jako wyj�cie
     PORTD |= _BV(PD0); //i ustawiamy to wyj�cie w stan wysoki (dioda nie �wieci si�)

     DDRC &= ~_BV(PC0); //PC0 jako wej�cie
     PORTC |= _BV(PC0); //kt�re podci�gamy do plusa

     while(1) {//nasz program nigdy si� nie ko�czy
          if(bit_is_clear(PINC, PC0)) { //je�li wej�cie jest w stanie niskim
               if(bit_is_set(PORTD, PD0)) //je�li bit by� ustawiony
                    PORTD &= ~_BV(PD0); //to go wyczy��
               else
                    PORTD |= _BV(PD0);//je�li nie - ustaw go
          }
     }
}
