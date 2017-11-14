#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "hd44780.h"	//LCD
#include <avr/wdt.h>    //watchdog

//czestotliwosc kwarca i czas trwania 1 cyklu
#define clk_freq 		16000000UL
#define clk_period_us 	1*200*1000000UL/clk_freq

volatile uint16_t   starting_edge, ending_edge;
volatile uint16_t 	count_pulse;
volatile uint32_t 	clocks;
volatile char 	    trigger;
volatile double 	distance;
volatile char 		triggered;

char buf_lcd1[16];

//-------------------------------------------------------------//
//Timer1 overflow interrupt
ISR(TIMER1_OVF_vect)
{
    //zliczaj przeoe³nienia od T1
    ++count_pulse;
}
//-------------------------------------------------------------//

//-------------------------------------------------------------//
//Timer1 capture interrupt
ISR(TIMER1_CAPT_vect)
{
    /*procedura wykonywana przy wykryciu kazdego typu zbocza na ICP1*/

    //jesli stan wysoki na ICP1 zapamietaj TCNT1 w ICR1
    if (bit_is_set(PIND, 6))
    {
        //zapamietaj TCNT1 (poczatek impulsu)
        starting_edge	=	ICR1;
        //od teraz ICP1 reaguje na opadajace zbocze
        TCCR1B = TCCR1B & ~_BV(ICES1);
    }
    else
    {
        //zapamietaj TCNT1 (koniec impulsu)
        ending_edge		=	ICR1;
        //od teraz ICP1 reaguje na rosnace zbocze
        TCCR1B = TCCR1B | _BV(ICES1);
        //oznacz gotowosc dla kolejnego impulsu TRIG
        triggered=0;
    }
}
//-------------------------------------------------------------//

ISR(BADISR_vect){};

//-------------------------------------------------------------//
//wyslij sygnal TRIG do SRF05 na PD5
void send_trigger(void)
{
    PORTD = PORTD | _BV(PD5);		//
    _delay_us(20);          //czas trwania impulsu TRIG 20us
    PORTD = PORTD & ~_BV(PD5);		//
    triggered=1;
}
//-------------------------------------------------------------//

//-------------------------------------------------------------//
//Configure ports as inputs and outputs.
void init_ports(void)
{
    DDRA = 0xff;
    DDRC = 0xff;
    DDRB = 0xff;
    DDRD = 0b10111111;
}
//-------------------------------------------------------------//

//-------------------------------------------------------------//
int main(void)
{
    //Init
    ending_edge		=	0;
    starting_edge	=	0;
    triggered		=	0;
    count_pulse		=	0;


    init_ports();
    LCD_Initalize();

    //zezwolenie na Input Capture Interrupt oraz ustawienie filtrowania na ICP1
    //przerwanie na ICP1 wyzwalane narastajacym zboczem
    //prescaler fn/1
    TCCR1B = (1<<ICNC1) | (1<<ICES1) | (1<<CS10);
    TIMSK = (1<<TICIE1) | (1<<TOIE1);

    //wlacz przerwania
    sei();

    //ustaw pozycje na wyswietlaczu i wypisz napis
    //LCD_GoTo(0,0);
    //LCD_WriteText("ATMEGA32: SRF05");

    //wlacz watchdog-a
    wdt_enable(WDTO_1S);

    while(1)
    {
        if(triggered == 0)
        {
        //ilosc zliczonych cykli
        clocks = ((uint32_t)count_pulse*65536 + (uint32_t)ending_edge) - (uint32_t)starting_edge;
        distance = ((double)clocks)/(58.0*clk_period_us);

        dtostrf(distance,2,2,buf_lcd1);
        LCD_GoTo(0,1);
        LCD_WriteText(buf_lcd1);


        _delay_ms(200);
        //wyzeruj licznik T1 i licznik przepelnen od T1 OVF
        TCNT1 = 0;
        count_pulse = 0;

        //Wyslij sygnal TRIG do SRF05
        send_trigger();

        //wyzeruj watchdog-a
        wdt_reset();
        }
    }
    return 0;
}
