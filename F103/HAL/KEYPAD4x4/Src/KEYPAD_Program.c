#include "KEYPAD_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Private.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

#include "BITMATH.h"

const uint8_t keypad_matrix[] = {
        '1','2','3','/',
        '4','5','6','*',
        '7','8','9','-',
        'c','0','=','+'};

static KEYPAD_Config KEYPAD_arr[NUMOF_KEYPADPINS]={
	{KEYPAD_ROW_PORT,KP0_PIN,GPO_PUSH_PULL_02_MHZ},{KEYPAD_ROW_PORT,KP1_PIN,GPO_PUSH_PULL_02_MHZ},{KEYPAD_ROW_PORT,KP2_PIN,GPO_PUSH_PULL_02_MHZ},{KEYPAD_ROW_PORT,KP3_PIN,GPO_PUSH_PULL_02_MHZ},
	{KEYPAD_COL_PORT,KP4_PIN,I_FLOATING},{KEYPAD_COL_PORT,KP5_PIN,I_FLOATING},{KEYPAD_COL_PORT,KP6_PIN,I_FLOATING},{KEYPAD_COL_PORT,KP7_PIN,I_FLOATING}
};

void KEYPAD_init(void){
        for(uint8_t i=0; i< NUMOF_LCDPINS;i++){

		GPIO_u8PinInit(KEYPAD_arr[i].port,KEYPAD_arr[i].pin,KEYPAD_arr[i].mode);

	}
       // Enable internal pull-up resistors for PORTD

}

uint8_t KEYPAD_read(void){
uint8_t i,VAL=1;

//portd=0xFF;
//TRISD |= (1 << 7); // Set RD7 as input (button)
KP0(1);KP1(1);KP2(1);KP3(1);
for(i = 0; i < 4;i++)
      {
          switch(i){
                  case 0: KP0(0);KP1(1);KP2(1);KP3(1); break;
                  case 1: KP0(1);KP1(0);KP2(1);KP3(1); break;
                  case 2: KP0(1);KP1(1);KP2(0);KP3(1); break;
                  case 3: KP0(1);KP1(1);KP2(1);KP3(0); break;
        }
        if (KP4(&VAL)&& VAL==0) return keypad_matrix[0 + i*4];
        if (KP5(&VAL)&& VAL==0) return keypad_matrix[1 + i*4];
        if (KP6(&VAL)&& VAL==0) return keypad_matrix[2 + i*4];
        if (KP7(&VAL)&& VAL==0) return keypad_matrix[3 + i*4];


      }
          return 0;


}