#include <avr/io.h>

#define LED1 PB0    //definicja LED1 (do którego pinu pod³¹czony LED1)
#define LED2 PB1    //definicja LED2 (do którego pinu pod³¹czony LED2)
#define KLAWISZ PC0 //definicja KLAWISZ (do którego pinu pod³¹czony klawisz)
#define ADCIN PC5   //definicja ADCIN (wejœcie ADC)

void main(void)
{
  //Uruchomienie ADC, wewnêtrzne napiecie odniesienia, tryb pojedynczej konwersji, preskaler 128, wejœcie PIN5, wynik do prawej
  ADCSRA =   (1<<ADEN) //ADEN: ADC Enable (uruchomienie przetwornika)

   //ADPS2:0: ustawienie preskalera, preskaler= 128
   |(1<<ADPS0)
   |(1<<ADPS1)
   |(1<<ADPS2);

  ADMUX  =  (1<<REFS1) | (1<<REFS0) //REFS1:0: Reference Selection Bits
         //Internal 2.56V Voltage Reference with external capacitor at AREF pin
    |(1<<MUX2) | (1<<MUX0); //Input Channel Selections (ADC5 - Pin 5 )

  //ustawienie wejœc/wyjœæ
  DDRB  |= (1<<LED1) | (1<<LED2); //Ustawienie pinów steruj¹cych diodami jako wyjœcia
  DDRC=0xff;                      //Nieu¿ywane Piny na porcie C jako wyjœcia
  DDRC  &=~ (1<<KLAWISZ);         //Ustawienie pinu klawisza jako wejœcie
  DDRC &=~ (1<<ADCIN);            //Ustawienie Wejœcia ADC

  PORTC |=  (1<<KLAWISZ);         //Pull_up klawisz

  for(;;)//pêtla g³ówna
  {
    if(!(PINC & (1<<KLAWISZ)))//jeœli klawisz wciœniety
    {
    ADCSRA |= (1<<ADSC); //ADSC: uruchomienie pojedynczej konwersji

    while(ADCSRA & (1<<ADSC)); //czeka na zakoñczenie konwersji

  if(ADC<350)//jeœli wynik ADC mniejszy od 350 gasi obydwie diody
  {
    PORTB  &=~ (1<<LED1);
    PORTB  &=~ (1<<LED2);
  }
  else if(ADC<700)//jeœli 700>ADC>=350 LED1 œwieci
  {
    PORTB  |= (1<<LED1);
    PORTB  &=~ (1<<LED2);
  }
  else //jeœli ADC>=700 œwiec¹ obydwie diody
                {
    PORTB  |= (1<<LED1);
    PORTB  |= (1<<LED2);
  }
    }

  }
}
