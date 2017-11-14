/*
 * main.c
 *
 *  Created on: 16-06-2013
 *      Author: Marwis95
 */


	#include <avr/io.h>
   #include <util/delay.h>

   // #include "lcd.h"

    /********************************************************************

    Configuration Area.
    UltraSonic (US) sensor connection.

   in this example it is connected to PORTA bit 0

    Adjust the following to connect is to different i/o

    ********************************************************************/

    #define US_PORT PORTA
    #define  US_PIN   PINA
    #define US_DDR    DDRA

    #define US_POS PA0      //PORTA0


    /********************************************************************
    This function measusers the width of high pulse in micro second.
    ********************************************************************/

    #define US_ERROR 0xffff
    #define  US_NO_OBSTACLE 0xfffe

    uint16_t getPulseWidth()
    {
       uint32_t i,result;

       //Wait for the rising edge
       for(i=0;i<600000;i++)
       {
          if(!(US_PIN & (1<<US_POS))) continue; else break;
       }

       if(i==600000)
          return 0xffff; //Indicates time out

       //High Edge Found

       //Setup Timer1
       TCCR1A=0X00;
       TCCR1B=(1<<CS11); //Prescaler = Fcpu/8
       TCNT1=0x00;       //Init counter

       //Now wait for the falling edge
       for(i=0;i<600000;i++)
       {
          if(US_PIN & (1<<US_POS))
          {
            if(TCNT1 > 60000) break; else continue;
          }
         else
             break;
       }

       if(i==600000)
          return 0xffff; //Indicates time out

       //Falling edge found

       result=TCNT1;

       //Stop Timer
       TCCR1B=0x00;

       if(result > 60000)
          return 0xfffe; //No obstacle
       else
          return (result>>1);
    }

   void Wait()
   {
      uint8_t i;
      for(i=0;i<10;i++)
         _delay_loop_2(0);
   }
   void main()
   {
      uint16_t r;

      Wait();

      //Initialize the LCD Module
      LCDInit(LS_NONE);

      Wait();

      LCDClear();
      LCDWriteString("Ultra Sonic");
      LCDWriteStringXY(0,1,"Sensor Test");

      Wait();
      Wait();
      Wait();
      Wait();
      Wait();
      Wait();

     LCDClear();

      while(1)
    {

         //Set Ultra Sonic Port as out
         US_DDR|=(1<<US_POS);

         _delay_us(10);

         //Give the US pin a 15us High Pulse
         US_PORT|=(1<<US_POS);   //High

        _delay_us(15);

        US_PORT&=(~(1<<US_POS));//Low

         _delay_us(20);

         //Now make the pin input
         US_DDR&=(~(1<<US_POS));

         //Measure the width of pulse
         r=getPulseWidth();
         //Handle Errors
         if(r==US_ERROR)
         {
           LCDWriteStringXY(0,0,"Error !");
         }
         else  if(r==US_NO_OBSTACLE)
         {
            LCDWriteStringXY(0,0,"Clear !");
         }
         else
         {

            int d;

            d=(r/58.0); //Convert to cm

            LCDWriteIntXY(0,0,d,4);
            LCDWriteString(" cm");
            Wait();
         }
      }

  }
