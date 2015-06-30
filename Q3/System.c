#include <xc.h>
#include "System.h"

void MCU_Init(void)
{
	OSCCONbits.COSC = 0b000;		
	OSCCONbits.LOCK = 0;
	OSCCONbits.SOSCEN=0;
	OSCCONbits.OSWEN-0;
	OSCCONbits.CF=0;
	OSCTUNbits.TUN=0b000000;			

	INTCON1bits.NSTDIS = 0;			// Interrupt nesting enabled
	SRbits.IPL = 0;					// CPU interrupt priority level is 0
	CORCONbits.IPL3 = 0;			// CPU interrupt priority level is 7 or less
}
