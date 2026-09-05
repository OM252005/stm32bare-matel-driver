#include "gpio.h"


/*=========================================================
 * GPIO INITIALIZATION
 *=========================================================*/

void GPIO_Init(GPIO_TypeDef *GPIOx,
               GPIO_Pin pin,
               uint32_t mode,
               uint32_t cnf)
{
    uint32_t position;
    uint32_t config;

    /*
     * STM32F1:
     *
     * Each GPIO pin uses 4 configuration bits:
     *
     * [3:2] = CNF
     * [1:0] = MODE
     */
    config = (mode & 0x3U) | ((cnf & 0x3U) << 2U);


    /*-----------------------------------------------------
     * Pins 0 - 7  -> CRL
     *-----------------------------------------------------*/

    if (pin <= GPIO_PIN_7)
    {
        position = ((uint32_t)pin * 4U);

        /* Clear existing configuration */
        GPIOx->CRL &= ~(0xFU << position);

        /* Write new configuration */
        GPIOx->CRL |= (config << position);
    }


    /*-----------------------------------------------------
     * Pins 8 - 15 -> CRH
     *-----------------------------------------------------*/

    else
    {
        position = (((uint32_t)pin - 8U) * 4U);

        /* Clear existing configuration */
        GPIOx->CRH &= ~(0xFU << position);

        /* Write new configuration */
        GPIOx->CRH |= (config << position);
    }
}


/*=========================================================
 * GPIO WRITE
 *=========================================================*/

void GPIO_Write(GPIO_TypeDef *GPIOx,
                GPIO_Pin pin,
                GPIO_State state)
{
    if (state == GPIO_PIN_SET)
    {
        /*
         * BSRR lower 16 bits -> SET
         */
        GPIOx->BSRR = (1U << (uint32_t)pin);
    }
    else
    {
        /*
         * BRR -> RESET
         */
        GPIOx->BRR = (1U << (uint32_t)pin);
    }
}


/*=========================================================
 * GPIO READ
 *=========================================================*/

GPIO_State GPIO_Read(GPIO_TypeDef *GPIOx,
                     GPIO_Pin pin)
{
    if ((GPIOx->IDR & (1U << (uint32_t)pin)) != 0U)
    {
        return GPIO_PIN_SET;
    }

    return GPIO_PIN_RESET;
}


/*=========================================================
 * GPIO TOGGLE
 *=========================================================*/

void GPIO_Toggle(GPIO_TypeDef *GPIOx,
                 GPIO_Pin pin)
{
    GPIOx->ODR ^= (1U << (uint32_t)pin);
}


/*=========================================================
 * GPIO WRITE PORT
 *=========================================================*/

void GPIO_WritePort(GPIO_TypeDef *GPIOx,
                    uint16_t value)
{
    GPIOx->ODR = value;
}


/*=========================================================
 * GPIO READ PORT
 *=========================================================*/

uint16_t GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
    return (uint16_t)GPIOx->IDR;
}


/*=========================================================
 * GPIO DE-INITIALIZATION
 *=========================================================*/

void GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
    GPIOx->CRL  = 0x44444444U;
    GPIOx->CRH  = 0x44444444U;
    GPIOx->ODR  = 0x00000000U;
}
