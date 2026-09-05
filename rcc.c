#include "rcc.h"


/*=========================================================
 * GPIO CLOCK ENABLE
 *=========================================================*/

void RCC_EnableGPIOClock(RCC_GPIO_Port_t GPIO_Port)
{
    if (GPIO_Port == RCC_GPIOA)
    {
        RCC->APB2ENR |= (1U << RCC_APB2ENR_IOPAEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOB)
    {
        RCC->APB2ENR |= (1U << RCC_APB2ENR_IOPBEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOC)
    {
        RCC->APB2ENR |= (1U << RCC_APB2ENR_IOPCEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOD)
    {
        RCC->APB2ENR |= (1U << RCC_APB2ENR_IOPDEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOE)
    {
        RCC->APB2ENR |= (1U << RCC_APB2ENR_IOPEEN_POS);
    }
}


/*=========================================================
 * GPIO CLOCK DISABLE
 *=========================================================*/

void RCC_DisableGPIOClock(RCC_GPIO_Port_t GPIO_Port)
{
    if (GPIO_Port == RCC_GPIOA)
    {
        RCC->APB2ENR &= ~(1U << RCC_APB2ENR_IOPAEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOB)
    {
        RCC->APB2ENR &= ~(1U << RCC_APB2ENR_IOPBEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOC)
    {
        RCC->APB2ENR &= ~(1U << RCC_APB2ENR_IOPCEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOD)
    {
        RCC->APB2ENR &= ~(1U << RCC_APB2ENR_IOPDEN_POS);
    }
    else if (GPIO_Port == RCC_GPIOE)
    {
        RCC->APB2ENR &= ~(1U << RCC_APB2ENR_IOPEEN_POS);
    }
}


/*=========================================================
 * CHECK GPIO CLOCK STATUS
 *=========================================================*/

uint8_t RCC_IsGPIOClockEnabled(RCC_GPIO_Port_t GPIO_Port)
{
    if (GPIO_Port == RCC_GPIOA)
    {
        return (RCC->APB2ENR &
                (1U << RCC_APB2ENR_IOPAEN_POS)) != 0U;
    }
    else if (GPIO_Port == RCC_GPIOB)
    {
        return (RCC->APB2ENR &
                (1U << RCC_APB2ENR_IOPBEN_POS)) != 0U;
    }
    else if (GPIO_Port == RCC_GPIOC)
    {
        return (RCC->APB2ENR &
                (1U << RCC_APB2ENR_IOPCEN_POS)) != 0U;
    }
    else if (GPIO_Port == RCC_GPIOD)
    {
        return (RCC->APB2ENR &
                (1U << RCC_APB2ENR_IOPDEN_POS)) != 0U;
    }
    else if (GPIO_Port == RCC_GPIOE)
    {
        return (RCC->APB2ENR &
                (1U << RCC_APB2ENR_IOPEEN_POS)) != 0U;
    }

    return 0U;
}


void RCC_EnableHSI(void)
{
    RCC->CR |= (1U << RCC_CR_HSION_POS);
}

void RCC_DisableHSI(void)
{
    RCC->CR &= ~(1U << RCC_CR_HSION_POS);
}

uint8_t RCC_IsHSIReady(void)
{
    return (RCC->CR & (1U << RCC_CR_HSIRDY_POS)) != 0U;
}


// HSE code 
void RCC_EnableHSE(void)
{
    RCC->CR |= (1U << RCC_CR_HSEON_POS);
}

void RCC_DisableHSE(void)
{
    RCC->CR &= ~(1U << RCC_CR_HSEON_POS);
}

uint8_t RCC_IsHSEReady(void)
{
    return (RCC->CR & (1U << RCC_CR_HSERDY_POS)) != 0U;
}


void RCC_SetAHBPrescaler(uint32_t Prescaler)
{
    RCC->CFGR &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_POS);

    RCC->CFGR |= (Prescaler << RCC_CFGR_HPRE_POS);
}

void RCC_SetAPB1Prescaler(uint32_t Prescaler)
{
    RCC->CFGR &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_POS);

    RCC->CFGR |= (Prescaler << RCC_CFGR_PPRE1_POS);
}



void RCC_SetAPB2Prescaler(uint32_t Prescaler)
{
    RCC->CFGR &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_POS);

    RCC->CFGR |= (Prescaler << RCC_CFGR_PPRE2_POS);
}




void RCC_EnablePLL(void)
{
    RCC->CR |= (1U << RCC_CR_PLLON_POS);
}


void RCC_DisablePLL(void)
{
    RCC->CR &= ~(1U << RCC_CR_PLLON_POS);
}


uint8_t RCC_IsPLLReady(void)
{
    return (RCC->CR & (1U << RCC_CR_PLLRDY_POS)) != 0U;
}



void RCC_ConfigPLL(uint32_t PLL_Source, uint32_t PLL_Multiplier)
{
    RCC->CFGR &= ~(RCC_CFGR_PLLSRC_MASK << RCC_CFGR_PLLSRC_POS);
    RCC->CFGR &= ~(RCC_CFGR_PLLMUL_MASK << RCC_CFGR_PLLMUL_POS);

    RCC->CFGR |= (PLL_Source << RCC_CFGR_PLLSRC_POS);uint32_t RCC_GetSYSCLKSource(void)
{
    return (RCC->CFGR >> RCC_CFGR_SWS_POS) & RCC_CFGR_SWS_MASK;
}
    RCC->CFGR |= (PLL_Multiplier << RCC_CFGR_PLLMUL_POS);
}



void RCC_SelectSYSCLK(uint32_t Source)
{
    RCC->CFGR &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_POS);

    RCC->CFGR |= (Source << RCC_CFGR_SW_POS);
}

 
/*_____________________________________________________________________________________________________

_______________________________________________________________________________________________________

__________________________________________________________________________________________________________*/
/* USART CLOCK CONFIGRATIONS  */

void rcc_EnableUSART1Clock(void)
{
    RCC->APB2ENR |= (1U << RCC_APB2ENR_USART1EN_POS);
}
void  RCC_DicsableUSARTClock(void)
{
    RCC->APB2ENR &= ~(1U << RCC_APB2ENR_USART1EN_POS);
}
