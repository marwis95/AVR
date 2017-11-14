/*
   Plik ds18b20.c
   (minimum kodu do odczytu temperatury z ds18b20)

   xyz.isgreat.org
*/

#include <avr/io.h>
#include <util/delay.h>
#include "ds18b20_2.h"


/**********************************************************/

unsigned char ds18b20_ConvertT_2(void)
{
  if (!OneWireReset_2()) return 0;

  OneWireWriteByte_2(0xcc); // SKIP ROM
  OneWireWriteByte_2(0x44); // CONVERT T

  return -1;
}

/***********************************************************/

int ds18b20_Read_2(unsigned char scratchpad[])
{
  unsigned char i;

  if (!OneWireReset_2()) return 0;

  OneWireWriteByte_2(0xcc); // SKIP ROM
  OneWireWriteByte_2(0xbe); // READ SCRATCHPAD

  for(i=0; i<9; i++) scratchpad[i] = OneWireReadByte_2();

  return 1;
}

/**********************************************************/

void OneWireStrong_2(char s)
{
  if (s)
  {
     SET_ONEWIRE_PORT_2;
     SET_OUT_ONEWIRE_DDR_2;
  }
  else
  {
     SET_IN_ONEWIRE_DDR_2;
  }
}

/**********************************************************/

unsigned char OneWireReset_2()
{
  CLR_ONEWIRE_PORT_2;

  if (!(IS_SET_ONEWIRE_PIN_2)) return 0;

  SET_OUT_ONEWIRE_DDR_2;
  _delay_us(500);
  SET_IN_ONEWIRE_DDR_2;
  _delay_us(70);

  if(!(IS_SET_ONEWIRE_PIN_2))
  {
    _delay_us(500);
    return(1);
  }

  _delay_us(500);

return(0);
}

/**********************************************************/

void OneWireWriteByte_2(unsigned char byte)
{
   unsigned char i;

   CLR_ONEWIRE_PORT_2;

   for (i=0; i<8; i++)
   {
     SET_OUT_ONEWIRE_DDR_2;

     if (byte & 0x01)
     {
       _delay_us(7);
       SET_IN_ONEWIRE_DDR_2;
       _delay_us(70);
     }
     else
     {
        _delay_us(70);
        SET_IN_ONEWIRE_DDR_2;
        _delay_us(7);
     }

     byte >>= 1;
   }
}

/***********************************************************/

unsigned char OneWireReadByte_2(void)
{
  unsigned char i, byte = 0;

  SET_IN_ONEWIRE_DDR_2;

  for (i=0; i<8; i++)
  {
     SET_OUT_ONEWIRE_DDR_2;
     _delay_us(7);
     SET_IN_ONEWIRE_DDR_2;
     _delay_us(7);
     byte >>= 1;

     if(IS_SET_ONEWIRE_PIN_2) byte |= 0x80;

     _delay_us(70);
  }

  return byte;
}
