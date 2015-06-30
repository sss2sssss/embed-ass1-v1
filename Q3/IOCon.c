#include <xc.h>
#include "IOCon.h"

void IO_Init()
{
	TRISBbits.TRISB9 = 0;				// LED1 as output
    TRISBbits.TRISB10 = 0;				// LED2 as output
	TRISBbits.TRISB11 = 0;				// LED3 as output

	TRISBbits.TRISB8 = 1;				// SW1 as input

	TRISAbits.TRISA0 = 1;				// AN0 as input
	TRISAbits.TRISA1 = 1;				// AN1 as input
	TRISBbits.TRISB2 = 1;				// AN4 as input
}