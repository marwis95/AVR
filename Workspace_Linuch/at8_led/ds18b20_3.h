/*
   Plik ds18b20.h

   (xyz.isgreat.org)
*/

#ifndef DS18B20_H_3
#define DS18B20_H_3

/* DS18B20 przyłączony do portu  PD7 AVRa  */
#define SET_ONEWIRE_PORT_3     PORTB  |=  _BV(3) //pc1
#define CLR_ONEWIRE_PORT_3     PORTB  &= ~_BV(3)
#define IS_SET_ONEWIRE_PIN_3   PINB   &   _BV(3)
#define SET_OUT_ONEWIRE_DDR_3  DDRB   |=  _BV(3)
#define SET_IN_ONEWIRE_DDR_3   DDRB   &= ~_BV(3)

unsigned char ds18b20_ConvertT_3(void);
int ds18b20_Read_3(unsigned char []);
void OneWireStrong_3(char);
unsigned char OneWireReset_3(void);
void OneWireWriteByte_3(unsigned char);
unsigned char OneWireReadByte_3(void);

#endif
