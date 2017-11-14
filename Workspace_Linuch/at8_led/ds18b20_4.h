/*
   Plik ds18b20.h

   (xyz.isgreat.org)
*/

#ifndef DS18B20_H_4
#define DS18B20_H_4

/* DS18B20 przyłączony do portu  PD7 AVRa  */
#define SET_ONEWIRE_PORT_4     PORTB  |=  _BV(4) //pc1
#define CLR_ONEWIRE_PORT_4     PORTB  &= ~_BV(4)
#define IS_SET_ONEWIRE_PIN_4   PINB   &   _BV(4)
#define SET_OUT_ONEWIRE_DDR_4  DDRB   |=  _BV(4)
#define SET_IN_ONEWIRE_DDR_4   DDRB   &= ~_BV(4)

unsigned char ds18b20_ConvertT_4(void);
int ds18b20_Read_4(unsigned char []);
void OneWireStrong_4(char);
unsigned char OneWireReset_4(void);
void OneWireWriteByte_4(unsigned char);
unsigned char OneWireReadByte_4(void);

#endif
