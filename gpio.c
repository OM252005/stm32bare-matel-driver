#include "gpio.h"

// use api and write data in the file of gpio.c 

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *Config)
{
       uint32_t position     =   Config->Pin;
       uint32_t mode         =   Config->Mode;
       uint32_t output_type  =   Config->OutputType;
       uint32_t output_speed =   Config->Speed;
       uint32_t pull         =   Config->Pull;
       uint32_t alternate    =   Config->Alternate;
       

// this will connect the  pin_Config  ration
GPIOx->MODER &=    ~(0x3U << (position * 2U));
GPIOx->MODER |=     (mode << (position * 2U)); //moving value of position pin in to mode


GPIOx->OTYPER &=   ~(1U<<position);
GPIOx->OTYPER |=    (output_type << position);  // moving value of position pin to the outputtyper


GPIOx->OSPEEDR &=   (0x2U << (position*2u ));
GPIOx->OSPEEDR |=   (output_speed << (position*2U)) ;  // moving value of position ppin to the ospeedr


GPIOx->PUPDR   &=  ~(0x3u << (position*2u));
GPIOx->PUPDR  |=    (pull << (position*2U)); //moving value of position


GPIOx->AFRL &= ~(0xFu << (position * 4U));
GPIOx->AFRL |= (alternate << (position * 4U));// remember that alternate function register uses position vectors at 4bype


GPIOx->AFRH &= ~(0xFu << (position * 4U));
GPIOx->AFRH |= (alternate << (position * 4U));
}

void GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
    GPIOx->MODER   = 0x00000000U;
    GPIOx->OTYPER  = 0x00000000U;
    GPIOx->OSPEEDR = 0x00000000U;
    GPIOx->PUPDR   = 0x00000000U;
    GPIOx->ODR     = 0x00000000U;
    GPIOx->AFRL    = 0x00000000U;
    GPIOx->AFRH    = 0x00000000U;
}

 void GPTIO_WritePin(GPIO_TypeDef*GPIOx,uint8_t Pin,uint8_t State)
{
    if(State ==GPIO_PIN_SET)
    {
        GPIOx->ODR |= (1u<<Pin);
    }
    else
    {
        GPIOx->ODR &= ~(1u<<Pin);
    }
}
void GPIO_TogglePin (GPIO_TypeDef*GPIOx,uint8_t Pin)
{
    GPIOx->ODR ^= (1u<<Pin);
}
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t Pin)
{
    return (GPIOx->IDR >> Pin) & 1U;
}

void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
// remember thet write pin need 16 byte data 
// and value reguster 
{
    GPIOx->ODR = Value;
}
uint16_t GPIO_ReadPort(GPIO_TypeDef *GPIOx)

//remember that read port and read pin uses only of the uint16_t function only ;)) 
{
    return (uint16_t)GPIOx->IDR;
}