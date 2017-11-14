
#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#include "ds18b20.h"
#include "ds18b20_2.h"
#include "ds18b20_3.h"
#include "ds18b20_4.h"
//#define ADCIN PC5;
#define VREF 4.99

char str[17]="   Termometr    ";
char str_2[17]="   Termometr    ";
char str_3[17]="   Termometr    ";
char str_4[17]="   Termometr    ";

void main(void){
char wynik[]="           ";
char t_wynik[]="           ";
char adc_string[]="           ";
float adc;
double therm, temp_pt;

double temp, temp_2, temp_3, temp_4;
unsigned char ds18b20_pad[9], ds18b20_pad_2[9], ds18b20_pad_3[9], ds18b20_pad_4[9];


LCD_Initalize();
LCD_GoTo(0, 0);
LCD_WriteText("THERM :)");

ADCSRA = (1<<ADEN) | (1<<ADPS2); //Init + presc
ADMUX  =    (1<<REFS0) | (1<<MUX2) | (1<<MUX0);  //kanal + v (5.0)
DDRC &=~ (1<<PC5);

for(;;)
 {
     ADCSRA |= (1<<ADSC);//ADSC: Uruchomienie pojedynczej konwersji
     while(ADCSRA & (1<<ADSC)); //czeka na zakończenie konwersji
    ADC;
    adc=ADC*VREF/1024;      //przeliczenie wartości na napięcie
    temp_pt=ADC;
    therm=temp_pt/3.41;



    if(ds18b20_ConvertT())
      {
         _delay_ms(750);
         ds18b20_Read(ds18b20_pad);
         temp = ((ds18b20_pad[1] << 8) + ds18b20_pad[0]) / 16.0 ;
         sprintf(str,"Wew=%4.1f", temp);
         LCD_GoTo(0,0);
         LCD_WriteText("         ");
         LCD_GoTo(0,0);
         LCD_WriteText(str);
      }


    if(ds18b20_ConvertT_2())
        {
           _delay_ms(750);
           ds18b20_Read_2(ds18b20_pad_2);
           temp_2 = ((ds18b20_pad_2[1] << 8) + ds18b20_pad_2[0]) / 16.0 ;
           sprintf(str_2,"Zew=%4.1f", temp_2);
           LCD_GoTo(10,0);
           LCD_WriteText("         ");
           LCD_GoTo(10,0);
           LCD_WriteText(str_2);
        }

    if(ds18b20_ConvertT_3())
        {
           _delay_ms(750);
           ds18b20_Read_3(ds18b20_pad_3);
           temp_3 = ((ds18b20_pad_3[1] << 8) + ds18b20_pad_3[0]) / 16.0 ;
           sprintf(str_3,"Lodowka=%4.1f", temp_3);
           LCD_GoTo(0,1);
           LCD_WriteText("                   ");
           LCD_GoTo(0,1);
           LCD_WriteText(str_3);
        }

    if(ds18b20_ConvertT_4())
        {
           _delay_ms(750);
           ds18b20_Read_4(ds18b20_pad_4);
           temp_4 = ((ds18b20_pad_4[1] << 8) + ds18b20_pad_4[0]) / 16.0 ;
           sprintf(str_4,"Zamrazarka=%4.1f", temp_4);
           LCD_GoTo(0,2);
           LCD_WriteText("                   ");
           LCD_GoTo(0,2);
           LCD_WriteText(str_4);
        }



    if(therm>45){
     sprintf(t_wynik, "Piekarnik=%4.1f", therm);
     LCD_GoTo(0,3);
     LCD_WriteText("                    ");
     LCD_GoTo(0,3);
     LCD_WriteText(t_wynik);
    } else{
        LCD_GoTo(0,3);
        LCD_WriteText("                    ");
        LCD_GoTo(0,3);
        LCD_WriteText("Piekarnik=OFF  ");
    	}


     _delay_ms(5000);
 }

}

//vcc/vmax*100 vcc=7,6
