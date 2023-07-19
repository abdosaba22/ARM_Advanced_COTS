#ifndef KEYPAD_PRIVATE_H
#define KEYPAD_PRIVATE_H

#define NUMOF_KEYPADPINS 					8

#define KP0(x) 								GPIO_u8setpinValue(KEYPAD_ROW_PORT,KP0_PIN,x)
#define KP1(x) 								GPIO_u8setpinValue(KEYPAD_ROW_PORT,KP1_PIN,x)
#define KP2(x) 								GPIO_u8setpinValue(KEYPAD_ROW_PORT,KP2_PIN,x)
#define KP3(x) 								GPIO_u8setpinValue(KEYPAD_ROW_PORT,KP3_PIN,x)

#define KP4(x) 								GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP4_PIN,x)
#define KP5(x) 								GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP5_PIN,x)
#define KP6(x) 								GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP6_PIN,x)
#define KP7(x) 								GPIO_u8ReadpinValue(KEYPAD_COL_PORT,KP7_PIN,x)



#endif
