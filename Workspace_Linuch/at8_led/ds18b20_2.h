/*
   Plik ds18b20.h

   (xyz.isgreat.org)
*/

#ifndef DS18B20_H_2
#define DS18B20_H_2

/* DS18B20 przyłączony do portu  PD7 AVRa  */
#define SET_ONEWIRE_PORT_2     PORTB  |=  _BV(2) //pc1
#define CLR_ONEWIRE_PORT_2     PORTB  &= ~_BV(2)
#define IS_SET_ONEWIRE_PIN_2   PINB   &   _BV(2)
#define SET_OUT_ONEWIRE_DDR_2  DDRB   |=  _BV(2)
#define SET_IN_ONEWIRE_DDR_2   DDRB   &= ~_BV(2)

unsigned char ds18b20_ConvertT_2(void);
int ds18b20_Read_2(unsigned char []);
void OneWireStrong_2(char);
unsigned char OneWireReset_2(void);
void OneWireWriteByte_2(unsigned char);
unsigned char OneWireReadByte_2(void);

#endif
