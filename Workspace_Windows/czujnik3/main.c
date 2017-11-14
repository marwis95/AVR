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
        // Ustawienie pr�dko�ci transmisji
        UBRRH = (uint8_t)(ubrr >> 8);
        UBRRL = (uint8_t)ubrr;

        // W��czenie nadajnika i odbiornika
        UCSRB = (1 << RXEN) | (1 << TXEN);

        // Ustawienie formatu ramki:
        // 8 bit�w danych, 1 bit stopu, brak parzysto�ci
        UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
    }
    void nadaj(uint8_t data)
    {
        // Oczekiwanie na zako�czenie nadawania
        while (!(UCSRA & (1 << UDRE)));

        // Wys�anie danych
        UDR = data;
    }
    uint8_t uart_ischar()
    {
        // Czy w buforze s� dane?
        return (UCSRA & (1 << RXC));
    }
    uint8_t uart_getc()
    {
        // Czy w buforze s� dane?
        while(!uart_ischar());

        // Dane z bufora
        return UDR;
    }





     //F-cja inicjuj�ca przerwania zawn�trzne i timer2
       void InitInterrupt(void)
       {
       //PRZERWANIA ZEWN�TRZNE

           DDRD = 0xFF;                            //PD2 - wejscie (Echo)

           MCUCR = (1<<ISC01) | (1<<ISC00);        //Przerwanie zostanie wywo�ane zboczem narastaj�ym
                                                   //na wej�ciach INT0, INT1, INT2
       //TIMER2
           TCNT2 = 0x00;                           //Zerowanie rejestru TCNT2 (Rejestr jednostki zegara)

           TCCR2 = (1<<WGM21)|(1<<CS20);           //Ustawia timer2 w tryb CTC bez preskalera
                                                   //Czestotliwo�� 16Mhz/1=16MHz

           OCR2 = 0x01;                            //G�rna warto�� licznika wynosi 16
                                                   //Przerwania b�d� nast�powa� co 1us //
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


       //F-cja przerwania zewn�trznego INT0



       SIGNAL(INT0_vect)
       {
           if(flaga==0)
           {
               TIMSK = (1<<OCIE2);                //w��cza Timer2 w trybie dopasowania (START)
               ClrBit(MCUCR, INT0);
               MCUCR = 0x00;                      //Przerwanie zostanie wywo�ane zboczem opadaj�cym
               MCUCR = (1<<ISC01);                //na wej�ciu INT0
               SetBit(MCUCR, INT0);
               flaga=1;
           }

           else if(flaga==1)
           {
               TIMSK &=~(1<<OCIE2);                //zatrzymuje Timer2 (STOP)

               ClrBit(MCUCR, INT0);

               MCUCR = 0x00;                        //Przerwanie zostanie wywo�ane zboczem rosn�cym
               MCUCR = (1<<ISC01)|(1<<ISC00);        //na wej�ciu INT0

               SetBit(MCUCR, INT0);

               odl0=licznik;                        //Zapisuje warto�� licznika do zmiennej "odl"
               odl0/=20;                            //oraz skaluje go

               licznik=0;                            //Zerowanie licznika
               flaga=0;

           }
           }
