#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H


#include "GPIO_Interface.h"
#include <stdint.h>

typedef struct{
	Port_t port;
	PinNum_t pin;
	PinMode_t mode;
}KEYPAD_Config;


void KEYPAD_init(void);

uint8_t KEYPAD_read(void);


#endif