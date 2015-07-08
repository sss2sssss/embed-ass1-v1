#ifndef PARAM_H
#define	PARAM_H

// LED1 @ RB9/pin18  // LED2 @ RB10/pin21  // LED3 @ RB11/pin22
#define    LED1     LATBbits.LATB9
#define    LED2     LATBbits.LATB10
#define    LED3     LATBbits.LATB11

// SW1 @ RB8/pin17  //  SW2 @ RB7/pin16
#define    SW1_d		PORTBbits.RB8
#define    SW2_d		PORTBbits.RB7

// Extern Variable
extern unsigned int avgADCValue;
extern int SW1;
extern int SW2;

#endif