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
// Rozmiar kodu z za��czonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str() 				(RW<-->GND)
// dla procesor�w AVR: 240 bajt�w !!!
// Rozmiar kodu z za��czonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str(), lcd_locate()	(RW<-->GND)
// dla procesor�w AVR: 254 bajty
// Rozmiar kodu z za��czonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str() 				(RW<-->uC)
// dla procesor�w AVR: 326 bajt�w !!!
// Rozmiar kodu z za��czonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str(), lcd_locate()	(RW<-->uC)
// dla procesor�w AVR: 340 bajt�w
//-----------------------------------------------------------------------------------------------------------
#ifndef LCD_H_
#define LCD_H_
//----------------------------------------------------------------------------------------
//
//		Parametry pracy sterownika
//
//----------------------------------------------------------------------------------------
// rozdzielczo�� wy�wietlacza LCD (wiersze/kolumny)
#define LCD_Y 4		// ilo�� wierszy wy�wietlacza LCD
#define LCD_X 16	// ilo�� kolumn wy�wietlacza LCD

// tu ustalamy za pomoc� zera lub jedynki czy sterujemy pinem RW
//	0 - pin RW pod��czony na sta�e do GND
//	1 - pin RW pod��czony do mikrokontrolera
#define USE_RW 1

//----------------------------------------------------------------------------------------
//
//		Ustawienia sprz�towe po��cze� sterownika z mikrokontrolerem
//
//----------------------------------------------------------------------------------------
// tu konfigurujemy port i piny do jakich pod��czymy linie D7..D4 LCD
#define LCD_D7PORT  A
#define LCD_D7 6
#define LCD_D6PORT  A
#define LCD_D6 5
#define LCD_D5PORT  A
#define LCD_D5 4
#define LCD_D4PORT  A
#define LCD_D4 3


// tu definiujemy piny procesora do kt�rych pod��czamy sygna�y RS,RW, E
#define LCD_RSPORT A
#define LCD_RS 0

#define LCD_RWPORT A
#define LCD_RW 1

#define LCD_EPORT A
#define LCD_E 2
//------------------------------------------------  koniec ustawie� sprz�towych ---------------




// reszt� biblioteki mo�na znale�� na p�ycie DVD do��czonej do drugiej ksi��ki
//  http://atnel.pl/jezyk-c-pasja-programowania.html





#endif /* LCD_H_ */
