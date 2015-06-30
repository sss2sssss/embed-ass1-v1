#ifndef ADC_H
#define	ADC_H

#define ADC_ON      AD1CON1bits.ADON=1;
#define ADC_OFF     AD1CON1bits.ADON=0;

void ADC_Init();
void ADC_Convert();

#endif