#include <xc.h>
#include "IOCon.h"

void IO_Init()
{
	TRISBbits.TRISB9 = 0;				// LED1 as output @ RB9 /pin18
    TRISBbits.TRISB10 = 0;				// LED2 as output @ RB10/pin21
	TRISBbits.TRISB11 = 0;				// LED3 as output @ RB11/pin22

	TRISBbits.TRISB8 = 1;				// SW1 as input @ RB8/pin17

	TRISAbits.TRISA0 = 1;				// AN0 as input @ RA0/pin2
	TRISAbits.TRISA1 = 1;				// AN1 as input @ RA1/pin3
	TRISBbits.TRISB2 = 1;				// AN4 as input @ RB2/pin6
}