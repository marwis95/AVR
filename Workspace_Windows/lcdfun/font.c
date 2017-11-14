/*
 * font.c
 *
 *  Created on: 17-05-2013
 *      Author: Marwis95
 */
#include "font.h"
void init_font()
{
	font[0] = A | B | C | D | E | F;
	font[1] = B | C ;
	font[2] = A | B | D | E |  G;
	font[3] = A | B | C | D | G;
	font[4] = B | C | F | G;
	font[5] = A | C | D | F | G;
	font[6] = A | C | E | D | F | G ;
	font[7] = A | B | C;
	font[8] = A | B | C | D | E | F | G;
	font[9] = A | B | C | D | F | G;

}
