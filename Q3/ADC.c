#include <xc.h>
#include "ADC.h"
#include "System.h"
#include "Param.h"

unsigned int ADCValue, avgADCValue = 0, count;
volatile unsigned int *ADCPtr;

void ADC_Init(void)
{
	ADC_OFF;
	AD1PCFG = 0xFFEC;
	AD1CON1bits.ADSIDL=0;
	AD1CON1bits.FORM=0b00;
	AD1CON1bits.SSRC=0b111;
	AD1CON1bits.ASAM=0;
	AD1CON1bits.SAMP=0;
	AD1CON1bits.DONE=0;
	
	AD1CHSbits.CH0NA=0;
	AD1CHSbits.CH0SA=0b00100;		//AN4

	AD1CON3bits.ADRC=0;
	AD1CON3bits.SAMC=0b11110; 		//Auto-Sample Time = 30 Tad = 0.075 ms
	AD1CON3bits.ADCS=0b00000101;	//Tad = 10 Tcy

	AD1CSSL=0;

	AD1CON2bits.VCFG=0b011;			//V+ and V- are Vref+ and Vref-, 3.3V
	AD1CON2bits.CSCNA=0;
	AD1CON2bits.BUFS=0;
	AD1CON2bits.SMPI=0b0001;		//Set AD1IF after 2 samples
	AD1CON2bits.BUFM=0;
	AD1CON2bits.ALTS=0;
}

void ADC_Convert()
{
	ADCValue = 0;                         
	ADCPtr = (unsigned int *)&ADC1BUF0;   // initialize ADC1BUF pointer
	IFS0bits.AD1IF = 0;                   // clear ADC interrupt flag
	AD1CON1bits.ASAM = 1;                 
	while (!IFS0bits.AD1IF){};            
	AD1CON1bits.ASAM = 0;                 
	for(count = 0; count < 2; count++)
	{
		ADCValue = ADCValue + *ADCPtr++;
	}
	ADCValue = ADCValue >> 1;
	avgADCValue = ADCValue;
}