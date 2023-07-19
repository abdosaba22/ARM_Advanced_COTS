#ifndef STM32F103XX_H
#define STM32F103XX_H

#include <stdint.h>

/********************* Various Memories Base Addresses ****************/

#define FLASH_BASE_ADDRESS      0x08000000UL
#define SRAM_BASE_ADDRESS       0x20000000UL


/********************* Core peripheral Base Addresses *****************/ 
 
#define SYSTICK_BASE_ADDRESS		0xE000E010U
 
/********************* AHB Peripheral Base Addresses ****************/

#define GPIOA_BASE_ADDRESS      0x40010800U
#define GPIOB_BASE_ADDRESS      0x40010C00U
#define GPIOC_BASE_ADDRESS      0x40011000U
#define GPIOD_BASE_ADDRESS      0x40011400U
#define GPIOE_BASE_ADDRESS      0x40011800U
#define GPIOF_BASE_ADDRESS      0x40011C00U
#define GPIOG_BASE_ADDRESS      0x40012000U

#define AFIO_BASE_ADDRESS  	 	0x40010000U

#define RCC_BASE_ADDRESS        0x40021000U

/********************* APB1 Peripheral Base Addresses ****************/

/********************* APB2 Peripheral Base Addresses ****************/


/******************* GPIO Register Definition Structure **************/

typedef struct
{
    volatile uint32_t  CRL;        /*!< GPIO port configuration register low,                   Address offset: 0x00 */
    volatile uint32_t  CRH;        /*!< GPIO port configuration register high,                  Address offset: 0x04 */
    volatile uint32_t  IDR;        /*!< GPIO port input data register,                          Address offset: 0x08 */
    volatile uint32_t  ODR;        /*!< GPIO port output data register,                         Address offset: 0x0C */
    volatile uint32_t  BSRR;       /*!< GPIO port bit set/reset register,                       Address offset: 0x10 */
    volatile uint32_t  BRR;        /*!< GPIO port bit reset register,                           Address offset: 0x14 */
    volatile uint32_t  LCKR;       /*!< GPIO port configuration lock register,                  Address offset: 0x18 */
} GPIO_RegDef_t;


/******************* AFIO Register Definition Structure **************/

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICRx[4];
	volatile uint32_t MAPR2;
} AFIO_Type;


/******************* RCC Register Definition Structure **************/

typedef struct
{
    volatile uint32_t CR;          /*!< RCC clock control register,                                        Address offset: 0x00 */
    volatile uint32_t CFGR;        /*!< RCC clock configuration register,                                  Address offset: 0x04 */
    volatile uint32_t CIR;         /*!< RCC clock interrupt register,                                      Address offset: 0x08 */
    volatile uint32_t APB2RSTR;    /*!< RCC APB2 peripheral reset register,                                Address offset: 0x0C */
    volatile uint32_t APB1RSTR;    /*!< RCC APB1 peripheral reset register,                                Address offset: 0x10 */
    volatile uint32_t AHBENR;      /*!< RCC AHB peripheral clock enable register,                          Address offset: 0x14 */
    volatile uint32_t APB2ENR;     /*!< RCC APB2 peripheral clock enable register,                          Address offset: 0x18 */
    volatile uint32_t APB1ENR;     /*!< RCC APB1 peripheral clock enable register,                          Address offset: 0x1C */
    volatile uint32_t BDCR;        /*!< RCC Backup domain control register,                                 Address offset: 0x20 */
    volatile uint32_t CSR;         /*!< RCC clock control & status register,                                Address offset: 0x24 */
} RCC_RegDef_t;


/*************** SYSTICK Register Definition Structure **********/
typedef struct {
  volatile uint32_t CSR;       /*!< SYSTICK Control and Status Register,                                   */
  volatile uint32_t RVR;       /*!< SYSTICK Reload Value Register,                               */
  volatile uint32_t CVR;       /*!< SYSTICK Current Value Register,                             */
  volatile uint32_t CALIB;     /*!< SYSTICK Calibration Value Register,                                 */	
} SYSTICK_RegDef_t;


/******************* GPIO Peripheral Definition **************/

#define GPIOA               ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB               ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC               ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD               ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE               ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF               ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG               ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

#define MY_AFIOK            ((AFIO_Type*)AFIO_BASE_ADDRESS)

/******************* RCC Peripheral Definition **************/

#define RCC                 ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/******************* SYSTICK Peripheral Definition **************/

#define SYSTICK 			 ((SYSTICK_RegDef_t*) SYSTICK_BASE_ADDRESS)



#endif 