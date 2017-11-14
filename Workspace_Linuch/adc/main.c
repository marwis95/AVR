//Pomiar napięcia przetwornikiem A/C i prezentacja wyniku na LCD 2x16 HD44780

#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"


//definicja napięcia referencyjnego
#define VREF 5.0
//definicja ADCIN (wejście ADC)
#define ADCIN PA0

void main(void)
{
   char wynik[]="           ";//bufor tekstowy, wyczyszczenie bufora
   float adc;//zmienna do obliczeń napięcia



   LCD_Initalize();   //inicjalizacja LCD
   LCD_GoTo(0, 0);      //Ustawienie kursora w pozycji (0,0)
   LCD_WriteText("ADC test: 10 bit");

   //Inicjalizacja ADC
   ADCSRA =   (1<<ADEN) //włączenie ADC
            |(1<<ADPS0) //ADPS2:0 ustawienie preskalera na 128
            |(1<<ADPS1)
            |(1<<ADPS2);


   ADMUX  =    (1<<REFS0)          //VCC jako napięcie referencyjne
            |(1<<MUX2) | (1<<MUX0); //wybór kanału pomiarowego ADC5

   DDRA &=~ (1<<ADCIN);               //Ustawienie Wejścia ADC

  for(;;)
  {
      ADCSRA |= (1<<ADSC);//ADSC: Uruchomienie pojedynczej konwersji

      while(ADCSRA & (1<<ADSC)); //czeka na zakończenie konwersji

      adc=ADC*VREF/1024;      //przeliczenie wartości na napięcie
      sprintf(wynik,"U=%1.3f [V]",adc);   //konwersja na łańcuch znakowy
      LCD_GoTo(3, 1);         //Ustawienie kursora w pozycji (1,1)
      LCD_WriteText(wynik);   //Wyświetlenie wyniku
      _delay_ms(500);         //opóźnienie
  }
}
