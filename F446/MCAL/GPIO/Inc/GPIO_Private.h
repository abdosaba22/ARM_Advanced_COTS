#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIO_PERIPHERAL_NUM  	    8U

#define MODEBIT_MASK				0b11
#define MODERPIN_ACCESS 			2U

#define PUDBIT_MASK					0b11
#define PUDPIN_ACCESS	 			2U

#define SPEEDBIT_MASK				0b11
#define SPEEDPIN_ACCESS	 			2U

#define OTYPEBIT_MASK				0b1
#define OTYPEPIN_ACCESS	 			1U

#define ALTFUNCBIT_MASK				0b1111
#define ALTFUNCPIN_ACCESS	 		4U
#define ALTFUNCPINSHIFTING			8U
#define ALTFUNCLOWHIGHRSHIFT		3U




#define ODRBIT_MASK					0b1
#define ODRPIN_ACCESS	 			1U

//#define MY_GPIO_PORT(PORT_ID) 	(GPIOA + (PORT_ID*0x400))
/* instead of using Array */
//#define MY_GPIO_PORT(PORT_ID) ((GPIO_RegDef_t*)(GPIOA_BASE_ADDRESS + (PORT_ID) * 0x0400))

#endif
