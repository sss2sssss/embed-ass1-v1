#include <xc.h>
#include "System.h"

void MCU_Init(void)
{

	OSCCONbits.SOSCEN=0;			//Disable secondary osc
	OSCCONbits.OSWEN-0;				//no oscillator switch
	OSCTUNbits.TUN=0b000000;		//no tuning, running at factory freq	

	INTCON1bits.NSTDIS = 0;			// Interrupt nesting enabled
	SRbits.IPL = 0;					// CPU interrupt priority level is 0
	CORCONbits.IPL3 = 0;			// CPU interrupt priority level is 7 or less
}
