/*
 * main.c
 *
 *  Created on: 14-06-2013
 *      Author: Marwis95
 */


      #include <avr/io.h>
     #include <avr/interrupt.h>
     #include <util/delay.h>
     #define F_CPU 8000000UL

     #define SetBit(reg, bit) ((reg) |= (0x01 << (bit)))         // Ustawienie danego bitu w rejestrze
     #define ClrBit(reg, bit) ((reg) &= ~(0x01 << (bit)))        // Wyzerowanie danego bitu w rejestrze
     int licznik, odl0, flaga;

     #define RS_BAUD 9600
     #define RS_UBRR F_CPU / 16 / RS_BAUD - 1

    void start(uint16_t ubrr)
    {
        // Ustawienie prêdkoœci transmisji
        UBRRH = (uint8_t)(ubrr >> 8);
        UBRRL = (uint8_t)ubrr;

        // W³¹czenie nadajnika i odbiornika
        UCSRB = (1 << RXEN) | (1 << TXEN);

        // Ustawienie formatu ramki:
        // 8 bitów danych, 1 bit stopu, brak parzystoœci
        UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
    }
    void nadaj(uint8_t data)
    {
        // Oczekiwanie na zakoñczenie nadawania
        while (!(UCSRA & (1 << UDRE)));

        // Wys³anie danych
        UDR = data;
    }
    uint8_t uart_ischar()
    {
        // Czy w buforze s¹ dane?
        return (UCSRA & (1 << RXC));
    }
    uint8_t uart_getc()
    {
        // Czy w buforze s¹ dane?
        while(!uart_ischar());

        // Dane z bufora
        return UDR;
    }





     //F-cja inicjuj¹ca przerwania zawnêtrzne i timer2
       void InitInterrupt(void)
       {
       //PRZERWANIA ZEWNÊTRZNE

           DDRD = 0xFF;                            //PD2 - wejscie (Echo)

           MCUCR = (1<<ISC01) | (1<<ISC00);        //Przerwanie zostanie wywo³ane zboczem narastaj¹ym
                                                   //na wejœciach INT0, INT1, INT2
       //TIMER2
           TCNT2 = 0x00;                           //Zerowanie rejestru TCNT2 (Rejestr jednostki zegara)

           TCCR2 = (1<<WGM21)|(1<<CS20);           //Ustawia timer2 w tryb CTC bez preskalera
                                                   //Czestotliwoœæ 16Mhz/1=16MHz

           OCR2 = 0x01;                            //Górna wartoœæ licznika wynosi 16
                                                   //Przerwania bêd¹ nastêpowaæ co 1us //
           //sei();
           SREG = 0x80;
     }


       double l_pomiar(void)
       {
           SetBit(MCUCR, INT0);
           SetBit(PORTD, 3);
           _delay_us(20);
           ClrBit(PORTD, 3);
           _delay_ms(8);
           ClrBit(MCUCR, INT0);
           return odl0;
       }

      int main(void)
      {
        DDRD=0xFF;
         while(1)
          {
            start(RS_UBRR);
             InitInterrupt();
            l_pomiar();
             nadaj(odl0);
         }
      }

     SIGNAL(TIMER2_COMP_vect)
       {
           licznik++;
       }


       //F-cja przerwania zewnêtrznego INT0



       SIGNAL(INT0_vect)
       {
           if(flaga==0)
           {
               TIMSK = (1<<OCIE2);                //w³¹cza Timer2 w trybie dopasowania (START)
               ClrBit(MCUCR, INT0);
               MCUCR = 0x00;                      //Przerwanie zostanie wywo³ane zboczem opadaj¹cym
               MCUCR = (1<<ISC01);                //na wejœciu INT0
               SetBit(MCUCR, INT0);
               flaga=1;
           }

           else if(flaga==1)
           {
               TIMSK &=~(1<<OCIE2);                //zatrzymuje Timer2 (STOP)

               ClrBit(MCUCR, INT0);

               MCUCR = 0x00;                        //Przerwanie zostanie wywo³ane zboczem rosn¹cym
               MCUCR = (1<<ISC01)|(1<<ISC00);        //na wejœciu INT0

               SetBit(MCUCR, INT0);

               odl0=licznik;                        //Zapisuje wartoœæ licznika do zmiennej "odl"
               odl0/=20;                            //oraz skaluje go

               licznik=0;                            //Zerowanie licznika
               flaga=0;

           }
           }
