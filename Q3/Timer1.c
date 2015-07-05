#include <xc.h>
#include "Timer1.h"
#include "System.h"
#include "Param.h"

#define Cycle3Counter avgADCValue

unsigned int Cycle1=0;
unsigned int Cycle2=0;
unsigned int Cycle3=0;
int status=0;
int divider=0;
void LED_Blinking();

void Timer1_Init(void)
{
    Timer1_OFF;
    T1CONbits.TSIDL = 0;		// Continue module operation in Idle mode
    T1CONbits.TSYNC = 0;		// do not synchonize internal clock
    T1CONbits.TGATE = 0;		// 0 for normal, 1 for gated
    T1CONbits.TCS = 0;			// 0 for timer, 1 for Asynchronous counter
    T1CONbits.TCKPS = 0b01;		// Select 1:8 Prescaler
    PR1 = 5000;					// 10mS

    IPC0bits.T1IP = 0b001; 		// Set Timer1 Interrupt Priority Level 1
    TMR1 = 0x00; 				// Clear timer register
    IFS0bits.T1IF = 0; 			// Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1; 			// Enable Timer1 interrupt
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0;		//reset timer1 interrupt flag to 0
	LED_Blinking();
}

void LED_Blinking()
{
	//LED 3 always blink at 1 Hz
	Cycle1++;
	if(Cycle1<=50)
		LED3=1;
	else if (Cycle1>50 && Cycle1<=100)
		LED3=0;
	else
		Cycle1=0;
	
	
	//Run when switch 1 is press
	if(SW1==1)
	{
		switch(status)
		{
			case 0:
				LED1=0;
				break;
			case 1:
				if(divider==0)
				{
					divider+=1;
					status=2;
				}
				else if(divider>0 && divider<4)
				{
					divider*=2;
					status=2;
				}
				else if(divider>=4)
				{
					divider=0;
					status=0;
				}
				break;
			case 2:
				Cycle2++;
				if(Cycle2<=(100/divider))
					LED1=1;
				else if (Cycle2>(100/divider) && Cycle2<=(200/divider))
					LED1=0;
				else
					Cycle2=0;
				break;
		}
	}
	else if(SW1==0)
	{
		if(divider==0)
		{
			LED1=0;
			Cycle2=0;
			status=1;
		}
		else if(divider>0)
		{
			status=1;
			Cycle2++;
			if(Cycle2<=(100/divider))
				LED1=1;
			else if (Cycle2>(100/divider) && Cycle2<=(200/divider))
				LED1=0;
			else
				Cycle2=0;
		}
	}
	
	
	//Run when switch 2 is press
	if(SW2==1)
	{
		LED2=0;
		Cycle3=0;
	}
	else if(SW2==0)
	{
		Cycle3++;
		if(Cycle3<=(Cycle3Counter/2))
			LED2=1;
		else if ((Cycle3>(Cycle3Counter/2)) && (Cycle3<=Cycle3Counter))
			LED2=0;
		else
			Cycle3=0;
	}
}