#ifndef USART_H
#define USART_H

#include <stdint.h>

/*=========================================================
 * USART Register Definition
 *=========================================================*/

typedef struct
{
    volatile uint32_t SR;       // 0x00
    volatile uint32_t DR;       // 0x04
    volatile uint32_t BRR;      // 0x08
    volatile uint32_t CR1;      // 0x0C
    volatile uint32_t CR2;      // 0x10
    volatile uint32_t CR3;      // 0x14
    volatile uint32_t GTPR;     // 0x18

} USART_TypeDef;


/*=========================================================
 * USART BASE ADDRESS
 *=========================================================*/

#define USART1_BASE  0x40013800UL

#define USART1  ((USART_TypeDef *)USART1_BASE)


/*=========================================================
 * USART STATUS REGISTER (SR)
 *=========================================================*/

#define USART_SR_RXNE_POS   5U
#define USART_SR_TC_POS     6U
#define USART_SR_TXE_POS    7U


/*=========================================================
 * USART STATUS APIs
 *=========================================================*/

uint8_t USART_IsTXE(void);


/*=========================================================
 * USART DATA APIs
 *=========================================================*/

void USART_SendByte(uint8_t Data);

uint8_t USART_ReceiveByte(void);


/*=========================================================
 * USART CONTROL REGISTER 1 (CR1)
 *=========================================================*/

#define USART_CR1_RE_POS    2U
#define USART_CR1_TE_POS    3U
#define USART_CR1_UE_POS    13U


/*=========================================================
 * USART ENABLE / DISABLE APIs
 *=========================================================*/

void USART_Enable(void);
void USART_Disable(void);

void USART_EnableTransmitter(void);
void USART_EnableReceiver(void);


/*=========================================================
 * USART BAUD RATE REGISTER (BRR)
 *=========================================================*/

#define USART_BRR_DIV_FRACTION_POS   0U
#define USART_BRR_DIV_MANTISSA_POS   4U

#define USART_BRR_DIV_FRACTION_MASK  0x0FU
#define USART_BRR_DIV_MANTISSA_MASK  0x0FFFU


/*=========================================================
 * USART BAUD RATE API
 *=========================================================*/

void USART_SetBaudRate(uint32_t PCLK,
                       uint32_t BaudRate);


/*=========================================================
 * USART INITIALIZATION
 *=========================================================*/

void USART_Init(uint32_t PCLK,
                uint32_t BaudRate);


#endif
