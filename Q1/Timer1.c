#include <xc.h>
#include "Timer1.h"
#include "System.h"
#include "Param.h"

unsigned int DutyCycle1=0;
unsigned int DutyCycle2=0;
void LED_Duty_Cycle();

void Timer1_Init(void)
{
    Timer1_OFF;					//stop 16 bit timer
    T1CONbits.TSIDL = 0;		// Continue module operation in Idle mode
    T1CONbits.TSYNC = 0;		// do not synchonize internal clock
    T1CONbits.TGATE = 0;		// 0 for normal, 1 for gated
    T1CONbits.TCS = 0;			// 0 for timer, 1 for Asynchronous counter
    T1CONbits.TCKPS = 0b01;		// Select 1:8 Prescaler
    PR1 = 625;					// 1.25mS

    IPC0bits.T1IP = 0b001; 		// Set Timer1 Interrupt Priority Level 1
    TMR1 = 0x00; 				// Clear timer register
    IFS0bits.T1IF = 0; 			// Clear Timer1 Interrupt Flag
    IEC0bits.T1IE = 1; 			// Enable Timer1 interrupt
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0;		//reset timer1 interrupt flag to 0
	LED_Duty_Cycle();
}

void LED_Duty_Cycle()
{
	DutyCycle1++;
	DutyCycle2++;
	
	//50% duty cycle
	if(DutyCycle1<=5)
		LED1=1;
	else if(DutyCycle1>5 && DutyCycle1<=10)
		LED1=0;
	else
		DutyCycle1=0;

	//30%duty cycle
	if(DutyCycle2<=3)
		LED2=1;
	else if(DutyCycle1>3 && DutyCycle1<=10)
		LED2=0;
	else
		DutyCycle2=0;
}