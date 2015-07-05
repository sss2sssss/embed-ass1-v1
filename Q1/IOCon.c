#include <xc.h>
#include "IOCon.h"

void IO_Init()
{
        TRISBbits.TRISB10 = 0;				// LED1 as output @ RB10/pin21
		TRISBbits.TRISB11 = 0;				// LED2 as output @ RB11/pin22
}