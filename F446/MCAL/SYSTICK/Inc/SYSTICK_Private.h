#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define T_OV 	  			0x800000U   /* 8388608 usec   AHB/8 --> 16/8 = 2Mhz then Tclock=0.5us .. 2^24 *0.5  */   
#define T_MSTuS 			1000U       /* to convert to uSec */
#define TO_TICK				2U			/* 1/Fsystick 1/2 every pulse take 0.5u then To get Nof pulses T_desiredinUs/0.5 then we will Multiply by 2*/	
#define MAX_TICKS			0xFFFFFFU

//#define F_SYSTICK			2000000U	
//#define T_TICK 			(1.0/F_SYSTICK)F
//#define T_OV				(MAX_TICKS*T_TICK)U 
//#define TO_TICK			(1/T_TICK)U	

#endif