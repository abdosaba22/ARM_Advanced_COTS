#include "Stm32F103xx.h"
#include "BITMATH.h"
#include "ERRORTYPE.h"
#include <stdint.h>

#include "SYSTICK_Private.h"
#include "SYSTICK_Interface.h"
/*  uint32_t -- max 65535 so max val 65535 in ms to us 65535 * 1000 to be greater than the max value of over flow*/
void STK_voidDelayms(uint32_t Delayms)
{	
	/* Disable Counter*/
	SYSTICK->CSR &= ~(1<<0);
	SYSTICK->CVR=0;
	Delayms*=T_MSTuS; /* to usc*/
	SYSTICK->CSR &= ~(1<<2);/* Choose Clock Source*/
	if(Delayms>T_OV){
		uint8_t counters=Delayms/T_OV;
		Delayms-=(counters*T_OV); /*remove overflow ticks*/
		SYSTICK->RVR=MAX_TICKS;
		/* Enable Counter*/
		SYSTICK->CSR |= 1<<0;
		while(counters>0){
			while( ( ( (SYSTICK->CSR )>>16 ) &1) == 0);
			counters--;
		}
		/* Disable Counter*/
		SYSTICK->CSR &= ~(1<<0);
		SYSTICK->CVR=0; /* Clear current value */
	}
	SYSTICK->RVR=Delayms*TO_TICK;/* Load the value of Delay */
	SYSTICK-> CSR|= 1;/* Enable Counter*/
	while( ( ( (SYSTICK->CSR )>>16 ) &1) == 0);/* Busy waiting until Counter is zero*/
	SYSTICK->CSR &= ~(1<<0);/* Disable Counter*/
}

void STK_voidDelayus(uint32_t Delayus)
{
	
	SYSTICK->CSR &= ~(1<<0);/* Disable Counter*/
	SYSTICK->CVR=0;
	
	SYSTICK->CSR &= ~(1<<2);/* Choose Clock Source*/
	SYSTICK->RVR=Delayus*TO_TICK;/* Load the value of Delay */
	
	SYSTICK->CSR |= 1;/* Enable Counter*/
	while( ( ( (SYSTICK->CSR )>>16 ) &1) == 0);/* Busy waiting until Counter is zero*/
	SYSTICK->CSR &= ~(1<<0);/* Disable Counter*/
}