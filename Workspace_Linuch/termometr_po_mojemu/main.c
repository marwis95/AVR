#include <avr/io.h>
#include<util/delay.h>
#include<math.h>
#include<stdlib.h>
#define LCD_PRT PORTC
#define LCD_PIN PINC
#define LCD_DDR DDRC
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2
#define LS_NULL 0B00000000


void delay_us(int d)
{
_delay_us(d);
}


void delay_ms(int d)
{
_delay_ms(d);
}

void lcdcommand(unsigned char cmnd)
{
LCD_PRT = (LCD_PRT & 0x0F)| (cmnd & 0xF0);
LCD_PRT &=~(1<<LCD_RS);
LCD_PRT &=~(1<<LCD_RW);
LCD_PRT |=(1<<LCD_EN);
delay_us(1);
LCD_PRT &=~(1<<LCD_EN);
delay_us(20);
LCD_PRT = (LCD_PRT & 0x0F) | (cmnd<<4);
LCD_PRT |= (1<<LCD_EN);
delay_us(1);
LCD_PRT &=~ (1<<LCD_EN);
}

void lcddata(unsigned char data)
{
LCD_PRT = (LCD_PRT & 0x0F) | (data & 0xF0);
LCD_PRT |= (1<<LCD_RS);
LCD_PRT &=~ (1<<LCD_RW);
LCD_PRT |= (1<<LCD_EN);
delay_us(1);
LCD_PRT &=~ (1<<LCD_EN);
delay_us(20);
LCD_PRT = (LCD_PRT & 0x0F) | (data << 4);
LCD_PRT |= (1<<LCD_EN);
delay_us(1);
LCD_PRT &=~ (1<<LCD_EN);
}


void LCD_init()
{
LCD_DDR = 0xFF;
LCD_PRT &=~(1<<LCD_EN);
delay_us(2000);
lcdcommand(0x33);
delay_us(100);
lcdcommand(0x32);
delay_us(100);
lcdcommand(0x28);
delay_us(100);
lcdcommand(0x0E);
delay_us(100);
lcdcommand(0x01);
delay_us(2000);
lcdcommand(0x06);
delay_us(100);
}

unsigned int adc_conv(void)
{
DDRA=0;
ADCSRA=0x87;
ADMUX=0xE0;
ADCSRA|=(1<<ADSC);
while((ADCSRA&(1<<ADIF))==0);
return ADCH;
}

void LCD_gotoxy(unsigned char x, unsigned char y)
{
unsigned char firstcharadr[]={0x80, 0x85};
lcdcommand(firstcharadr[y-1] + x - 1);
delay_us(100);
}


void LCD_print(char * str)
{
unsigned char i=0;
while(str[i]!=0)
{
lcddata(str[i]);
i++;
}
}




int main(void)
{
MCUCSR|= (1<<JTD);      //disaleb JTAG
MCUCSR|= (1<<JTD);

unsigned char val,t;
LCD_init(LS_NULL);
LCD_gotoxy(1,1);
LCD_print("Temperature ");
LCD_gotoxy(10,2);
LCD_print("*c");
while(1)
{

LCD_gotoxy(8,2);
val=adc_conv();
t=round(val*0.48876);
char buffer[10];
itoa(val,buffer,10);
LCD_print(buffer);


delay_ms(100);
}
return 0;
}
