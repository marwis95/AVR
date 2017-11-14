//-----------------------------------------------------------------------------------------------------------
// *** Obs≥uga wyúwietlaczy alfanumerycznych zgodnych z HD44780 ***
//
// - Sterowanie: tryb 4-bitowy
// - Dowolne przypisanie kaødego sygna≥u sterujπcego do dowolnego pinu mikrokontrolera
// - Praca z pinem RW pod≥πczonym do GND lub do mikrokontrolera (sprawdzanie BusyFLAG - szybkie operacje LCD)
//
// Pliki 			: lcd44780.c , lcd44780.h
// Mikrokontrolery 	: Atmel AVR
// Kompilator 		: avr-gcc
// èrÛd≥o 			: http://www.atnel.pl
// Data 			: marzec 2010
// Autor 			: Miros≥aw Kardaú
//----------------------------------------------------------------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <util/delay.h>

#include "lcd44780.h"

// resztÍ biblioteki moøna znaleüÊ na p≥ycie DVD do≥πczonej do drugiej ksiπøki

//  http://atnel.pl/jezyk-c-pasja-programowania.html
