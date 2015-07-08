#include <xc.h>
#include "System.h"
#include "Timer1.h"
#include "Timer2.h"
#include "IOCon.h"
#include "ADC.h"

_CONFIG1(JTAGEN_OFF & FWDTEN_OFF & BKBUG_OFF)
_CONFIG2(FNOSC_FRC & POSCMOD_NONE & OSCIOFNC_ON & FCKSM_CSDCMD)

int main()
{
	MCU_Init();
	Timer1_Init();
	Timer2_Init();
	IO_Init();
	ADC_Init();
	Timer1_ON;		//start 16 bit timer1
	Timer2_ON;		//start 16 bit timer2
	ADC_ON;			//turns on ADC module

	while(1)
	{
		ADC_Convert();
	}
}