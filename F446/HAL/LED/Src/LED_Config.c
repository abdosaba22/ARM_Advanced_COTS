#include "LED_Private.h"
#include "LED_Interface.h"
#include "GPIO_Interface.h"

/* config LED one */
LED_t LEDOne ; 

LEDOne.LedPin.Port=PORTA;
LEDOne.LedPin.Pin=PIN5;
LEDOne.LedPin.Mode=LED_MODE;
LEDOne.LedPin.speed=LED_SPEED;	
LEDOne.LedPin.OutputType= LED_OUTPTYPE;
LEDOne.LedPin.PullType= LED_PULLTYPE;
LEDOne.conn_type=LED_SourceConnnec;

