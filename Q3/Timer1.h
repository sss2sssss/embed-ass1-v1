#ifndef TIMER1_H
#define	TIMER1_H

#define Timer1_ON		T1CONbits.TON = 1
#define Timer1_OFF		T1CONbits.TON = 0

void Timer1_Init();

#endif