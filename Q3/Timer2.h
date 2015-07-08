#ifndef TIMER2_H
#define	TIMER2_H

#define Timer2_ON		T2CONbits.TON = 1		//start 16bit timer2
#define Timer2_OFF		T2CONbits.TON = 0		//stop 16bit timer2

void Timer2_Init();

#endif