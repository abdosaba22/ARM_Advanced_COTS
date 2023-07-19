#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

	

/*
 * KEYPAD.h
 *
 * Created: 12/4/2021 5:58:00 PM
 *  Author: Abdalrahman_Amin
 */

/*
-------------------------
|     |     |     |     | <---------- KP0 - PA
-------------------------                    
|     |     |     |     | <---------- KP1 - PA
-------------------------                      
|     |     |     |     | <---------- KP2 - PA 
-------------------------                    
|     |     |     |     | <---------- KP3 - PA
-------------------------
|     |     |     | PULL UP
|     |     |     |
KP4   KP5   KP6   KP7




*/



#define KEYPAD_ROW_PORT 				PORTA
#define KEYPAD_COL_PORT 				PORTB

#define KP0_PIN 					PIN4
#define KP1_PIN 					PIN5
#define KP2_PIN 					PIN6
#define KP3_PIN 					PIN7

#define KP4_PIN 					PIN11
#define KP5_PIN 					PIN10
#define KP6_PIN 					PIN1
#define KP7_PIN 					PIN0


#endif
