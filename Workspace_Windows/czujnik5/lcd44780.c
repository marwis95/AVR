//-----------------------------------------------------------------------------------------------------------
// *** Obs�uga wy�wietlaczy alfanumerycznych zgodnych z HD44780 ***
//
// - Sterowanie: tryb 4-bitowy
// - Dowolne przypisanie ka�dego sygna�u steruj�cego do dowolnego pinu mikrokontrolera
// - Praca z pinem RW pod��czonym do GND lub do mikrokontrolera (sprawdzanie BusyFLAG - szybkie operacje LCD)
//
// Pliki 			: lcd44780.c , lcd44780.h
// Mikrokontrolery 	: Atmel AVR
// Kompilator 		: avr-gcc
// �r�d�o 			: http://www.atnel.pl
// Data 			: marzec 2010
// Autor 			: Miros�aw Karda�
//----------------------------------------------------------------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <util/delay.h>

#include "lcd44780.h"

// reszt� biblioteki mo�na znale�� na p�ycie DVD do��czonej do drugiej ksi��ki

//  http://atnel.pl/jezyk-c-pasja-programowania.html
