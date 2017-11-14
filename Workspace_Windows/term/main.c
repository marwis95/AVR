#include <avr/io.h>

#define LED1 PB0    //definicja LED1 (do kt�rego pinu pod��czony LED1)
#define LED2 PB1    //definicja LED2 (do kt�rego pinu pod��czony LED2)
#define KLAWISZ PC0 //definicja KLAWISZ (do kt�rego pinu pod��czony klawisz)
#define ADCIN PC5   //definicja ADCIN (wej�cie ADC)

void main(void)
{
  //Uruchomienie ADC, wewn�trzne napiecie odniesienia, tryb pojedynczej konwersji, preskaler 128, wej�cie PIN5, wynik do prawej
  ADCSRA =   (1<<ADEN) //ADEN: ADC Enable (uruchomienie przetwornika)

   //ADPS2:0: ustawienie preskalera, preskaler= 128
   |(1<<ADPS0)
   |(1<<ADPS1)
   |(1<<ADPS2);

  ADMUX  =  (1<<REFS1) | (1<<REFS0) //REFS1:0: Reference Selection Bits
         //Internal 2.56V Voltage Reference with external capacitor at AREF pin
    |(1<<MUX2) | (1<<MUX0); //Input Channel Selections (ADC5 - Pin 5 )

  //ustawienie wej�c/wyj��
  DDRB  |= (1<<LED1) | (1<<LED2); //Ustawienie pin�w steruj�cych diodami jako wyj�cia
  DDRC=0xff;                      //Nieu�ywane Piny na porcie C jako wyj�cia
  DDRC  &=~ (1<<KLAWISZ);         //Ustawienie pinu klawisza jako wej�cie
  DDRC &=~ (1<<ADCIN);            //Ustawienie Wej�cia ADC

  PORTC |=  (1<<KLAWISZ);         //Pull_up klawisz

  for(;;)//p�tla g��wna
  {
    if(!(PINC & (1<<KLAWISZ)))//je�li klawisz wci�niety
    {
    ADCSRA |= (1<<ADSC); //ADSC: uruchomienie pojedynczej konwersji

    while(ADCSRA & (1<<ADSC)); //czeka na zako�czenie konwersji

  if(ADC<350)//je�li wynik ADC mniejszy od 350 gasi obydwie diody
  {
    PORTB  &=~ (1<<LED1);
    PORTB  &=~ (1<<LED2);
  }
  else if(ADC<700)//je�li 700>ADC>=350 LED1 �wieci
  {
    PORTB  |= (1<<LED1);
    PORTB  &=~ (1<<LED2);
  }
  else //je�li ADC>=700 �wiec� obydwie diody
                {
    PORTB  |= (1<<LED1);
    PORTB  |= (1<<LED2);
  }
    }

  }
}
