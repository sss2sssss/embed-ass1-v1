#ifndef PARAM_H
#define	PARAM_H

// LED
#define    LED1     LATBbits.LATB9
#define    LED2     LATBbits.LATB10
#define    LED3     LATBbits.LATB11

// SW
#define    SW1		PORTBbits.RB8
#define    SW2		PORTBbits.RB7

// Extern Variable
extern unsigned int avgADCValue;

#endif