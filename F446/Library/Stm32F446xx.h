#ifndef STM32F446XX_H
#define STM32F446XX_H

#include <stdint.h>
/********************* Varions Memories Base Addresses ****************/

#define FLASH_BASE_ADDRESS      	0x08000000UL
#define TOM_BASE_ADDRESS 			0x1FFF0000UL
#define SRAM_BASE_ADDRESS 			0x20000000UL

/****************************** Core peripheral Base Addresses ***************************/ 


/******************* NVIC Peripheral Base Addresses ********************/ 

#define SYSTICK_BASE_ADDRESS		0xE000E010U

/******************* NVIC Peripheral Base Addresses ********************/

#define NVIC_BASE_ADDRESS			0xE000E100UL
	
/******************* SCB Peripheral Base Addresses ****************/

#define SCB_BASE_ADDRESS		0xE000ED00UL

 
/********************* AHB1 Peripheral Base Addresses *****************/
#define GPIOA_BASE_ADDRESS  		0x40020000U
#define GPIOB_BASE_ADDRESS  		0x40020400U
#define GPIOC_BASE_ADDRESS  		0x40020800U
#define GPIOD_BASE_ADDRESS  		0x40020C00U
#define GPIOE_BASE_ADDRESS  		0x40021000U
#define GPIOF_BASE_ADDRESS  		0x40021400U
#define GPIOG_BASE_ADDRESS  		0x40021800U
#define GPIOH_BASE_ADDRESS  		0x40021C00U

#define RCC_BASE_ADDRESS  			0x40023800U


/********************* AHB2 Peripheral Base Addresses *****************/



/********************* AHB3 Peripheral Base Addresses *****************/



/********************* APB1 Peripheral Base Addresses *****************/



/********************* APB2 Peripheral Base Addresses *****************/

#define SYSCFG_BASE_ADDRESS		0x40013800UL
#define EXTI_BASE_ADDRESS		0x40013C00UL


/******************* GPIO Register Definition Structure **************/

typedef struct
{
	volatile uint32_t 	MODER;		/*GPIO PORT */
	volatile uint32_t 	OTYPER;		/*GPIO PORT */
	volatile uint32_t 	OSPEEDR;	/*GPIO PORT */
	volatile uint32_t 	PUPDR;		/*GPIO PORT */
	volatile uint32_t 	IDR;		/*GPIO PORT */
	volatile uint32_t 	ODR;		/*GPIO PORT */
	volatile uint32_t 	BSRR;		/*GPIO PORT */
	volatile uint32_t 	LCKR;		/*GPIO PORT */
	volatile uint32_t 	ARF[2];		/*GPIO PORT */
}GPIO_RegDef_t;

/******************* RCC Register Definition Structure **************/

typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                   */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                               */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                             */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                 */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                           */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                           */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                           */
  uint32_t      RESERVED0;     		/*!< Reserved, 0x1C                                                */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                           */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                           */
  uint32_t      RESERVED1[2];  		/*!< Reserved, 0x28-0x2C                                           */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                           */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                           */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                           */
  uint32_t      RESERVED2;     		/*!< Reserved, 0x3C                                                */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                    */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                    */
  uint32_t      RESERVED3[2];  		/*!< Reserved, 0x48-0x4C                                           */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED4;     		/*!< Reserved, 0x5C                                                */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED5[2];  		/*!< Reserved, 0x68-0x6C                                           */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                           */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                          */
  uint32_t      RESERVED6[2];  		/*!< Reserved, 0x78-0x7C                                           */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,                */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                            */
  volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                            */
  volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                  */
  volatile uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                             */
  volatile uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,                */
} RCC_RegDef_t;


/*************** SYSTICK Register Definition Structure **********/

typedef struct {
  volatile uint32_t CSR;       /*!< SYSTICK Control and Status Register,                        */
  volatile uint32_t RVR;       /*!< SYSTICK Reload Value Register,                              */
  volatile uint32_t CVR;       /*!< SYSTICK Current Value Register,                             */
  volatile uint32_t CALIB;     /*!< SYSTICK Calibration Value Register,                         */	
} SYSTICK_RegDef_t;

/************************** SCB Register Definition Structure ***********************/

typedef struct
{
	volatile uint32_t CPUID;					/*CPUID base register*/
	volatile uint32_t ICSR;                  /*Interrupt control and state register*/
	volatile uint32_t VTOR;                  /*Vector table offset register*/
	volatile uint32_t AIRCR;                 /*Application interrupt and reset control register*/
	volatile uint32_t SCR;                   /*System control register*/
	volatile uint32_t CCR;                   /*Configuration and control register*/
	volatile uint32_t SHPR[3];               /*System handler priority registers*/
	volatile uint32_t SHCSR;                 /*System handler control and state register*/
	volatile uint32_t CFSR;                  /*Configurable fault status register*/
	volatile uint32_t HFSR;                  /*Hard fault status register*/
	volatile uint32_t Reserved;
	volatile uint32_t MMAR;                  /*Memory management fault address register*/
	volatile uint32_t BFAR;                  /*Bus fault status register*/
	volatile uint32_t AFSR;                  /*Auxiliary fault status register*/
}SCB_RegDef_t;



/************************* NVIC Register Definition Structure ***********************/


typedef struct 
{
    volatile uint32_t ISER[8];      /* Interrupt Set-enable Registers */
    uint32_t 		reserved1[24];        
    volatile uint32_t ICER[8];      /* Interrupt Clear-enable Registers */
    uint32_t 		reserved2[24];        
    volatile uint32_t ISPR[8];      /* Interrupt Set-pending Registers */
    uint32_t 		reserved3[24];        
    volatile uint32_t ICPR[8];      /* Interrupt Clear-pending Registers */
    uint32_t 		reserved4[24];        
    volatile uint32_t IABR[8];      /* Interrupt Active Bit Registers */
    uint32_t 		reserved5[56];
    volatile uint8_t IPR[240];      /* Interrupt Priority Registers  */    
    uint32_t 		reserved6[228];
    volatile uint32_t STIR;              /* Software Trigger Interrupt Register */
}NVIC_RegDef_t;


/************************* EXTI Register Definition Structure ***********************/

typedef struct
{
	volatile uint32_t IMR;               /*Interrupt mask register*/
	volatile uint32_t EMR;               /*Event mask register*/
	volatile uint32_t RTSR;              /*Rising trigger selection register*/
	volatile uint32_t FTSR;              /*Falling trigger selection register*/
	volatile uint32_t SWIER;             /*Software interrupt event register*/
	volatile uint32_t PR;                /*Pending register*/
}EXTI_RegDef_t;


/************** SYSCFG Register Definition Structure ****************/

typedef struct
{
	volatile uint32_t MEMRMP;			/*SYSCFG memory remap register*/
	volatile uint32_t PMC;				/*SYSCFG peripheral mode configuration register*/
	volatile uint32_t EXTICR[4];			/*SYSCFG external interrupt configuration registers*/
	uint32_t Reserved[2];
	volatile uint32_t CMPCR;				/*Compensation cell control register*/
	uint32_t Reserved2[2];
	volatile uint32_t CFGR;				/*SYSCFG configuration register*/
}SYSCFG_RegDef_t;


/******************* GPIO Peripheral Definition **************/

#define GPIOA                ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD                ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE                ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF                ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG                ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH                ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/******************* RCC Peripheral Definition **************/

#define RCC 				 ((RCC_RegDef_t*) RCC_BASE_ADDRESS)

/******************* SYSTICK Peripheral Definition **************/

#define SYSTICK 			 ((SYSTICK_RegDef_t*) SYSTICK_BASE_ADDRESS)

/************************ SCB Peripheral Definition **********************/

#define SCB					((SCB_RegDef_t*) SCB_BASE_ADDRESS)

/************************ NVIC Peripheral Definition **********************/

#define NVIC				 ((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)

/***************************** EXTI Peripheral Definitions **************************/

#define EXTI					((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)

/***************************** SYSCFG Peripheral Definitions **************************/

#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)


#endif
