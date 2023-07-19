#include "Stm32F446xx.h"
#include "BITMATH.h"
#include "ERRORTYPE.h"
#include <stdint.h>

#include "GPIO_Private.h"
#include "GPIO_Interface.h"

/* Static Array of 8 Pointers --> The GPIO Ports to avoid using "Switch(){ case: }" */
static GPIO_RegDef_t *GPIOPortArray[GPIO_PERIPHERAL_NUM] = {
	GPIOA, GPIOB, GPIOC, GPIOD,
	GPIOE, GPIOF, GPIOG, GPIOH };

/* another option  instead of array & Switch USE this MAcro MY_GPIO_PORT(PinConfig->Port)->REG */


/**
 ******************************************************************************
 * @fn      : GPIO_u8PinInit
 * @brief   : The function initializes the Gpio pin according to the parameter
 * @param   : [in]*PinConfig , get options @GPIO_PinConfig_t enum
 * @retval ErrorStatus
 ******************************************************************************/

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t * PinConfig)
{
	uint8_t LocalErrorState=OK;
	/* Make sure that the pointer Was Allocated */
	if(PinConfig != NULL){
		if(PinConfig->Port <= PORTH && PinConfig->Pin <= PIN15)
		{
			/*** these steps in all Cases of Pin Mode Must be done ***/
			/* Clear Mode Bits of the portX pinY */
			GPIOPortArray[PinConfig->Port]->MODER &= ~(MODEBIT_MASK << (MODERPIN_ACCESS* PinConfig->Pin));
			/* Set the Mode of the Given PinY */
			GPIOPortArray[PinConfig->Port]->MODER |= (PinConfig->Mode) << (MODERPIN_ACCESS* PinConfig->Pin);
			
			/* Clear PUPD Bits of the portX pinY*/
			GPIOPortArray[PinConfig->Port]->PUPDR &= ~(PUDBIT_MASK << (PUDPIN_ACCESS* PinConfig->Pin));
			/* Set the PUPD of the Given PinY */
			GPIOPortArray[PinConfig->Port]->PUPDR |= (PinConfig->PullType) << (PUDPIN_ACCESS* PinConfig->Pin);
			
			/*** Depending on Mode O/P or ALTFunc will Config Some Regs ***/
			if( PinConfig->Mode == OUTPUT || PinConfig->Mode == ALTERNATE_FUNCTION){
				/*** Configure the SPEEDR & OTYPER for the Given PinY ***/
				/* Clear SPEED Bits of the portX pinY */
				GPIOPortArray[PinConfig->Port]->OSPEEDR &= ~(SPEEDBIT_MASK << (SPEEDPIN_ACCESS*PinConfig->Pin));
				/* Set the SPEED of the Given PinY */
				GPIOPortArray[PinConfig->Port]->OSPEEDR |= (PinConfig->speed) << (SPEEDPIN_ACCESS*PinConfig->Pin);
				/* Clear OTYPE Bit of the portX pinY */
				GPIOPortArray[PinConfig->Port]->OTYPER &= ~(OTYPEBIT_MASK << (OTYPEPIN_ACCESS*PinConfig->Pin));
				/* Set the OTYPE of the Given PinY */
				GPIOPortArray[PinConfig->Port]->OTYPER |= (PinConfig->OutputType) << (OTYPEPIN_ACCESS*PinConfig->Pin);

				if(PinConfig->Mode == ALTERNATE_FUNCTION){
					/*** Configure the ALTER FUNC for the Given PinY ***/
					/* Clear ARF Bits of the portX pinY */
					//GPIOPortArray[PinConfig->Port]->ARF[0] &= ~(ALTFUNCBIT_MASK << ((4*PinConfig->Pin)));
					GPIOPortArray[PinConfig->Port]->ARF[PinConfig->Pin >> ALTFUNCLOWHIGHRSHIFT] &= ~(ALTFUNCBIT_MASK << (ALTFUNCPIN_ACCESS*(PinConfig->Pin%ALTFUNCPINSHIFTING))); // Note arrow  pinnumber %
					/* Set the ARF of the Given PinY */
					GPIOPortArray[PinConfig->Port]->ARF[PinConfig->Pin >> ALTFUNCLOWHIGHRSHIFT] |= (PinConfig->AltFunc) << (ALTFUNCPIN_ACCESS*(PinConfig->Pin%ALTFUNCPINSHIFTING));
				}

			}


		}
		else LocalErrorState=NOK; // Wrong option	

	}
	else LocalErrorState=NULL_POINTER_ERR; // the struct is Null pointer ..

	
	return LocalErrorState;
}

/**
 ******************************************************************************
 * @fn             : GPIO_u8setpinValue
 * @brief          : The function outputs a certain value on an output pin
 * @param[in]Port  : the port number, get options @Port_t enum
 * @param[in]PinNum: the pin number, get options @PinNum_t enum
 * @param[in]PinVal: the pin Value, get options @PinVal_t enum
 * @return
 ******************************************************************************/

uint8_t GPIO_u8setpinValue(Port_t Port, PinNum_t PinNum, PinVal_t PinVal)
{
	uint8_t LocalErrorState=OK;
	if( Port <= PORTH && PinNum <= PIN15)
	{
		/*** Configure the ODR for the Given PinY to be H or L ***/
		/* Clear ODR Bit of the portX pinY  USE BSRR to Clear*/
		GPIOPortArray[Port]->ODR &= ~(ODRBIT_MASK << PinNum);
		/*GPIOPortArray[Port]->ODR |= ( ODRBIT_MASK << (PinNum+16) );  and use #define to replace 16 */

		/* Set the ODR Value for the Given PinY */
		GPIOPortArray[Port]->ODR |= PinVal << PinNum;
	}	
	else LocalErrorState=NOK; // Wrong option
	
	return LocalErrorState;
}

uint8_t GPIO_u8TogglepinValue(Port_t Port, PinNum_t PinNum)
{
	uint8_t LocalErrorState=OK;
	if( Port <= PORTH && PinNum <= PIN15)
	{
		/*** Toggle the ODR Value for the Given PinY ***/
		/* Set the ODR Value for the Given PinY */
		GPIOPortArray[Port]->ODR ^= ODRBIT_MASK << PinNum;
	}	
	else LocalErrorState=NOK; // Wrong option
	
	return LocalErrorState;
}

uint8_t GPIO_u8ReadpinValue(Port_t Port, PinNum_t PinNum, PinVal_t* PinVal)
{
	uint8_t LocalErrorState=OK;
	/* Make sure that the pointer Was Allocated */
	if(PinVal != NULL){
		if( Port <= PORTH && PinNum <= PIN15)
		{
			/*** Read the IDR Value for the Given PinY ***/
			*PinVal = (GPIOPortArray[Port]->IDR >> PinNum) & ODRBIT_MASK;
		}	
		else LocalErrorState=NOK; // Wrong option
		
	}
	else LocalErrorState=NULL_POINTER_ERR; // the struct is Null pointer ..
	return LocalErrorState;	
}
