#ifndef GPIO_H// providing gaurd band
#define  GPIO_H// defining the gaurd band
#include<stdint.h>


// typedf  enumaration  of gpio ports 

typedef enum
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C
}GPIO_Port;



// GPIO_Pinn NUMBERS 
typedef enum
{
GPIO_PIN_0 = 0,
GPIO_PIN_1,
GPIO_PIN_2,
GPIO_PIN_3,
GPIO_PIN_4,
GPIO_PIN_5,
GPIO_PIN_6,
GPIO_PIN_7,
GPIO_PIN_8,
GPIO_PIN_9,
GPIO_PIN_10,
GPIO_PIN_11,
GPIO_PIN_12,
GPIO_PIN_13,
GPIO_PIN_14,
GPIO_PIN_15,


}GPIO_Pin;


// DEFINING REGISTER STRUCTURE 

//  each one has 4 bit of data and hexadecimal values 


typedef struct
{
    volatile uint32_t CRL;      // 0x00
    volatile uint32_t CRH;      // 0x04
    volatile uint32_t IDR;      // 0x08
    volatile uint32_t ODR;      // 0x0C
    volatile uint32_t BSRR;     // 0x10
    volatile uint32_t BRR;      // 0x14
    volatile uint32_t LCKR;     // 0x18

} GPIO_TypeDef;

// PORT BASE ADDRESS 

#define GPIO_PORT_A_BASE 0x40010800UL
#define GPIO_PORT_B_BASE 0x40010C00UL
#define GPIO_PORT_C_BASE 0x40011000UL




// PORT BASE BASE ADDRES CONFIGRAT9INO WITNH PYPEDEF PINS 
#define GPIOA ((GPIO_TypeDef*) GPIO_PORT_A_BASE)
#define GPIOB ((GPIO_TypeDef*) GPIO_PORT_B_BASE)
#define GPIOC ((GPIO_TypeDef*) GPIO_PORT_C_BASE)



//  mode config 
#define GPIO_MODE_INPUT          0x0U
#define GPIO_MODE_OUTPUT_10MHZ   0x1U
#define GPIO_MODE_OUTPUT_2MHZ    0x2U
#define GPIO_MODE_OUTPUT_50MHZ   0x3U


// input config congig
#define GPIO_INPUT_ANALOG        0x0U
#define GPIO_INPUT_FLOATING      0x1U
#define GPIO_INPUT_PULL          0x2U

// 
#define GPIO_OUTPUT_PUSH_PULL    0x0U
#define GPIO_OUTPUT_OPEN_DRAIN   0x1U
#define GPIO_OUTPUT_AF_PP        0x2U
#define GPIO_OUTPUT_AF_OD        0x3U

// state 
typedef enum
{
    GPIO_STATE_LOW = 0,
    GPIO_STATE_HIGH = 1
} GPIO_State;


void GPIO_Init(GPIO_TypeDef *GPIOx,
                   GPIO_Pin pin,
                   uint32_t mode,
                   uint32_t cnf);

void GPIO_Write(GPIO_TypeDef *GPIOx,
                GPIO_Pin pin,
                GPIO_State state);


GPIO_State GPIO_Read(GPIO_TypeDef *GPIOx,
                     GPIO_Pin pin);


#endif// ending guard band 

