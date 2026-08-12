#ifndef RCC_H
#define RCC_H
// detail to note RCC_h capital and small leters 
#include<stdint.h>
// library for the uint_ data types so.




typedef struct
{
    volatile uint32_t CR;          // 0x00
    volatile uint32_t CFGR;        // 0x04
    volatile uint32_t CIR;         // 0x08
    volatile uint32_t APB2RSTR;    // 0x0C
    volatile uint32_t APB1RSTR;    // 0x10
    volatile uint32_t AHBENR;      // 0x14
    volatile uint32_t APB2ENR;     // 0x18
    volatile uint32_t APB1ENR;     // 0x1C
    volatile uint32_t BDCR;        // 0x20
    volatile uint32_t CSR;         // 0x24

} RCC_TypeDef;

/*RCC BASE ADDRESSS 
_________________________________________________________
_________________________________________________________*/
#define RCC_BASE    0x40021000UL
#define RCC  ((RCC_TypeDef *)RCC_BASE)//must have space in defining 


// creating api 
/*

void RCC_EnableGPIOCLOCK(GPIO_Typedef*GPIOx);


*/

// definig the numbers to the pins 



/*CR REGISTERS 
_______________________________________________
_______________________________________________*/
// HSI HIGH SPEED INTER NAL
#define RCC_CR_HSION_POS    0U
#define RCC_CR_HSIRDY_POS   1U
// HIGH SPEDD EXTERNAL
#define RCC_CR_HSEON_POS          16U
#define RCC_CR_HSERDY_POS         17U
//PLL REGISTERS 
#define RCC_CR_PLLON_POS     24U
#define RCC_CR_PLLRDY_POS    25U






/*
CFGR REGISTERS
_______________________________________________________________________
_______________________________________________________


*/



#define RCC_CFGR_SW_POS          0U
#define RCC_CFGR_SWS_POS         2U


#define RCC_CFGR_HPRE_POS     4U
#define RCC_CFGR_PPRE1_POS    8U
#define RCC_CFGR_PPRE2_POS     11U



#define RCC_CFGR_PLLSRC_POS      16U
#define RCC_CFGR_PLLXTPRE_POS    17U
#define RCC_CFGR_PLLMUL_POS      18U

/*
MASK REGISTERS
_____________________________________________________________________
______________________________________________________________________________
_____________________________________________________________
*/

#define RCC_CFGR_SW_MASK    0x3U
#define RCC_CFGR_SWS_MASK   0x3U

#define RCC_CFGR_HPRE_MASK 0xfU
#define RCC_CFGR_PPRE1_MASK 0x7U
#define RCC_CFGR_PPRE2_MASK 0x7U

#define RCC_CFGR_PLLSRC_MASK      0x1U
#define RCC_CFGR_PLLXTPRE_MASK    0x1U
#define RCC_CFGR_PLLMUL_MASK      0xFU



/*
POSITION REGISTERS 
_______________________________________________________________
_____________________________________________________________________
*/


#define RCC_APB2ENR_IOPAEN_POS  2U
#define RCC_APB2ENR_IOPBEN_POS  3U
#define RCC_APB2ENR_IOPCEN_POS  4U
#define RCC_APB2ENR_IOPDEN_POS  5U
#define RCC_APB2ENR_IOPEEN_POS  6U


/*
PORT ENUMERATION ___________________________________________
\
_________________________________________________________________
_____________________________________________________________________

*/

typedef enum
{
    RCC_GPIOA = 0U,
    RCC_GPIOB,
    RCC_GPIOC,
    RCC_GPIOD
    

} RCC_GPIO_Port_t;

/*
PLL CONFIG 
___________________________________________
\
_________________________________________________________________
_____________________________________________________________________

*/


#define RCC_PLL_SOURCE_HSI_DIV2    0U
#define RCC_PLL_SOURCE_HSE         1U

#define RCC_PLL_SOURCE_HSE_DIV2 2U
// pll config 
#define RCC_PLLMUL_2               0U
#define RCC_PLLMUL_3               1U
#define RCC_PLLMUL_4               2U
#define RCC_PLLMUL_5               3U
#define RCC_PLLMUL_6               4U
#define RCC_PLLMUL_7               5U
#define RCC_PLLMUL_8               6U
#define RCC_PLLMUL_9               7U
#define RCC_PLLMUL_10              8U
#define RCC_PLLMUL_11              9U
#define RCC_PLLMUL_12              10U
#define RCC_PLLMUL_13              11U
#define RCC_PLLMUL_14              12U
#define RCC_PLLMUL_15              13U
#define RCC_PLLMUL_16              14U







// cfgr i configration registers  we have to congigure the registers and msk it 
// so that it does not occupie another value insted of any one value 






// masking of the cfgr regisyers


//3. Define the prescaler encodings of ahb 

/*=========================================================
 * AHB Prescaler
 *=========================================================*/

#define RCC_AHB_DIV1 0U
#define RCC_AHB_DIV2 8U
#define RCC_AHB_DIV4 9U
#define RCC_AHB_DIV8 10U
#define RCC_AHB_DIV16 11U// div 32 is not available 
#define RCC_AHB_DIV64 12U
#define RCC_AHB_DIV128 13U
#define RCC_AHB_DIV256 14U
#define RCC_AHB_DIV512 15U


/*=========================================================
 * APB Prescaler
 *=========================================================*/
// for the APB

#define RCC_APB_DIV1     0U
#define RCC_APB_DIV2     4U
#define RCC_APB_DIV4     5U
#define RCC_APB_DIV8     6U
#define RCC_APB_DIV16    7U

//only up to the 16 divison 



// AHP HAVING MAXIMUM OF 32 mZ OFV FREQ







// APIS 
/*_____________________________________________________________________________________________________

_______________________________________________________________________________________________________

__________________________________________________________________________________________________________*/
/* GPIO Clock */
void RCC_EnableGPIOClock(RCC_GPIO_Port_t GPIO_Port);
void RCC_DisableGPIOClock(RCC_GPIO_Port_t GPIO_Port);
uint8_t RCC_IsGPIOClockEnabled(RCC_GPIO_Port_t GPIO_Port);


/* HSI */
void RCC_EnableHSI(void);
void RCC_DisableHSI(void);
uint8_t RCC_IsHSIReady(void);


/* HSE */
void RCC_EnableHSE(void);
void RCC_DisableHSE(void);
uint8_t RCC_IsHSEReady(void);


/* PLL */
void RCC_ConfigPLL(uint32_t PLL_Source, uint32_t PLL_Multiplier);
void RCC_EnablePLL(void);
void RCC_DisablePLL(void);
uint8_t RCC_IsPLLReady(void);


/* Bus Prescalers */
void RCC_SetAHBPrescaler(uint32_t Prescaler);
void RCC_SetAPB1Prescaler(uint32_t Prescaler);
void RCC_SetAPB2Prescaler(uint32_t Prescaler);


/* Clock Information */
uint32_t RCC_GetSYSCLK(void);
uint32_t RCC_GetHCLK(void);
uint32_t RCC_GetPCLK1(void);
uint32_t RCC_GetPCLK2(void);

#endif