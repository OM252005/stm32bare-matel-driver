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
    if (state == GPIO_STATE_HIGH)
    {
        GPIOx->BSRR = (1U << (uint32_t )pin);// note that i have weri
      // im typacasting the input of the given senari  so i have written /* (uint32_t)  */
    }
    else
    {
        GPIOx->BRR = (1U << (uint32_t)pin);
    }
}// the high state is becayse bsrr use for the write the data available space id approcx 32 bits (0 to 31) 
// but in  low state we have available register called bsr we just have to set and reset theem 
// in memoury map we have only 16 bit abvilabl spaece for writng  the register brr;
//  now we got to know tha why we need state of the pin ???? inn weitng 


/*=========================================================
 * GPIO READ
 *=========================================================*/


GPIO_State GPIO_Read(GPIO_TypeDef *GPIOx,
                     GPIO_Pin pin)
{
    if ((GPIOx->IDR & (1U << (uint32_t)pin)) != 0U)
    {
        return GPIO_STATE_HIGH;
    }

    return GPIO_STATE_LOW;
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

void GPIO_WritePort(GPIO_TypeDef *GPIOx,    // note that odr is 16 bit regisetr
                    uint16_t value)
{
    GPIOx->ODR = value;// this is write port not write 
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
{  // ask your self what do i have to do if i have to deinitilze a poert 
  // odr
  // crl 
  // crh bas itna hi hai 
    GPIOx->CRL  = 0x44444444U;
    GPIOx->CRH  = 0x44444444U;
    GPIOx->ODR  = 0x00000000U;
}
