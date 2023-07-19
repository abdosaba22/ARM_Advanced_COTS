#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "GPIO_Interface.h"
#include <stdint.h>

typedef struct{
	Port_t port,
	PinNum_t pin
}LCD_Config;

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_num(uint16_t);
void LCD_write_string(uint8_t *);

#endif
