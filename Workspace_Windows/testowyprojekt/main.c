#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRA = 0xFF;
	while(1)
	{
		PORTA = 0x00;
		_delay_ms(30);
		PORTA= 0x80;
		_delay_ms(30);
		PORTA= 0x40;
		_delay_ms(30);
		PORTA= 0x20;
		_delay_ms(30);
		PORTA= 0x10;
		_delay_ms(30);
		PORTA= 0x8;
		_delay_ms(30);
		PORTA= 0x4;
		_delay_ms(30);
		PORTA= 0x2;
		_delay_ms(30);
		PORTA= 0x1;
		_delay_ms(30);


		PORTA= 0x1;
		_delay_ms(30);
		PORTA= 0x2;
		_delay_ms(30);
		PORTA= 0x4;
		_delay_ms(30);
		PORTA= 0x8;
		_delay_ms(30);
		PORTA= 0x10;
		_delay_ms(30);
		PORTA= 0x20;
		_delay_ms(30);
		PORTA= 0x40;
		_delay_ms(30);
		PORTA= 0x80;
		_delay_ms(30);
		PORTA = 0x00;
		_delay_ms(30);

		/*PORTA= 0xaa;
		_delay_ms(30);
		PORTA= 0x55;
		_delay_ms(30);
*/

	}

	return 0;
}
