#ifndef ADC_H
#define	ADC_H

#define ADC_ON      AD1CON1bits.ADON=1;		//turn on ADC module
#define ADC_OFF     AD1CON1bits.ADON=0;		//disable ADC module

void ADC_Init();
void ADC_Convert();

#endif