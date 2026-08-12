#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;      //0
    volatile uint32_t OTYPER;        
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;   
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;  // 024
     

}GPIO_TypeDef;




#define GPIOA_BASE 0x48000000UL
#define GPIOB_BASE 0x48000400UL
#define GPIOC_BASE 0x48000800UL
#define GPIOD_BASE 0x48000C00UL
#define GPIOE_BASE 0x48001000UL
#define GPIOF_BASE 0x48001400UL




// defining the marcos 

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE) 
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)







typedef enum // REMEMBER THET ENUM ALWAY DEFINE THE NUMBER IN SEQUENCED AND PLS DO'NOT MISS TYH NUMBER CONFIG ACCORDING TO THE MAIN FUNCTION 
 // 
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
    GPIO_PIN_15

} GPIO_Pin_t;



typedef enum{// moder gpio
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG

}GPIO_Mode_t;




typedef enum{  //otyper gpio
    GPIO_OTYPER_PP = 0,
    GPIO_OTYPER_OD

}GPIO_OutputType_t;


typedef enum //speed gpio
{
    GPIO_SPEEDR_LOW = 0,
    GPIO_SPEEDR_MEDIUM,
    GPIO_SPEEDR_HIGH, 
    GPIO_SPEEDR_VERY_HIGH

}GPIO_Speed_t;


typedef enum // pull up and down gpio
{
    GPIO_NOPULL = 0,
    GPIO_PULLUP,
    GPIO_PULLDOWN

} GPIO_Pull_t;


typedef enum // alternate function 
{
    GPIO_AF0 = 0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15

} GPIO_AF_t;

typedef struct// pin configrations 
{
    GPIO_Pin_t        Pin;
    GPIO_Mode_t       Mode;
    GPIO_OutputType_t OutputType;
    GPIO_Speed_t      Speed;
    GPIO_Pull_t       Pull;
    GPIO_AF_t         Alternate;

} GPIO_PinConfig_t;

typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET

} GPIO_PinState_t;



void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *Config);

void GPIO_DeInit(GPIO_TypeDef *GPIOx);

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t Pin, uint8_t State);

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t Pin);

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t Pin);

void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);

uint16_t GPIO_ReadPort(GPIO_TypeDef *GPIOx);


#endif