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
// Rozmiar kodu z za≥πczonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str() 				(RW<-->GND)
// dla procesorÛw AVR: 240 bajtÛw !!!
// Rozmiar kodu z za≥πczonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str(), lcd_locate()	(RW<-->GND)
// dla procesorÛw AVR: 254 bajty
// Rozmiar kodu z za≥πczonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str() 				(RW<-->uC)
// dla procesorÛw AVR: 326 bajtÛw !!!
// Rozmiar kodu z za≥πczonymi tylko funkcjami: lcd_init(), lcd_cls(), lcd_str(), lcd_locate()	(RW<-->uC)
// dla procesorÛw AVR: 340 bajtÛw
//-----------------------------------------------------------------------------------------------------------
#ifndef LCD_H_
#define LCD_H_
//----------------------------------------------------------------------------------------
//
//		Parametry pracy sterownika
//
//----------------------------------------------------------------------------------------
// rozdzielczoúÊ wyúwietlacza LCD (wiersze/kolumny)
#define LCD_Y 4		// iloúÊ wierszy wyúwietlacza LCD
#define LCD_X 16	// iloúÊ kolumn wyúwietlacza LCD

// tu ustalamy za pomocπ zera lub jedynki czy sterujemy pinem RW
//	0 - pin RW pod≥πczony na sta≥e do GND
//	1 - pin RW pod≥πczony do mikrokontrolera
#define USE_RW 1

//----------------------------------------------------------------------------------------
//
//		Ustawienia sprzÍtowe po≥πczeÒ sterownika z mikrokontrolerem
//
//----------------------------------------------------------------------------------------
// tu konfigurujemy port i piny do jakich pod≥πczymy linie D7..D4 LCD
#define LCD_D7PORT  A
#define LCD_D7 6
#define LCD_D6PORT  A
#define LCD_D6 5
#define LCD_D5PORT  A
#define LCD_D5 4
#define LCD_D4PORT  A
#define LCD_D4 3


// tu definiujemy piny procesora do ktÛrych pod≥πczamy sygna≥y RS,RW, E
#define LCD_RSPORT A
#define LCD_RS 0

#define LCD_RWPORT A
#define LCD_RW 1

#define LCD_EPORT A
#define LCD_E 2
//------------------------------------------------  koniec ustawieÒ sprzÍtowych ---------------




// resztÍ biblioteki moøna znaleüÊ na p≥ycie DVD do≥πczonej do drugiej ksiπøki
//  http://atnel.pl/jezyk-c-pasja-programowania.html





#endif /* LCD_H_ */
