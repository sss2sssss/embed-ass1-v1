#include <xc.h>
#include "Timer2.h"
#include "System.h"
#include "Param.h"

int debouncing_counter=0, SW1=1, SW2=1;
void sw_debouncing();

void Timer2_Init(void)
{
    Timer2_OFF;
    T2CONbits.TSIDL = 0;		// Continue module operation in Idle mode
    T2CONbits.T32 = 0;			// Timer2 is 16-bits Timer
    T2CONbits.TGATE = 0;		// 0 for normal, 1 for gated
    T2CONbits.TCS = 0;			// 0 for timer, 1 for Asynchronous counter
    T2CONbits.TCKPS = 0b01;		// Select 1:8 Prescaler
    PR2 = 5000;					// 10mS

    IPC1bits.T2IP = 0b010; 		// Set Timer2 Interrupt Priority Level 2
    TMR2 = 0x00; 				// Clear timer register
    IFS0bits.T2IF = 0; 			// Clear Timer2 Interrupt Flag
    IEC0bits.T2IE = 1; 			// Enable Timer2 interrupt
}

void __attribute__((__interrupt__, auto_psv)) _T2Interrupt(void)
{
	IFS0bits.T2IF = 0;		//reset timer2 interrupt flag to 0
	sw_debouncing();
}

//Switch Debouncing
void sw_debouncing()
{
	debouncing_counter++;
	if(debouncing_counter>3)
	{
		if(SW1_d!=SW1)
		{
			if(SW1_d==0)
				SW1=0;
			if(SW1_d==1)
				SW1=1;
		}
	
		if(SW2_d!=SW2)
		{
			if(SW2_d==0)
				SW2=0;
			if(SW2_d==1)
				SW2=1;
		}
		debouncing_counter=0;
	}
}
