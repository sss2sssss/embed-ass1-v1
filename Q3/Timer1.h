#ifndef TIMER1_H
#define	TIMER1_H

#define Timer1_ON		T1CONbits.TON = 1		//start 16bit timer1
#define Timer1_OFF		T1CONbits.TON = 0		//stop 16bit timer1

void Timer1_Init();

#endif