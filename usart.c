#include "rcc.h"
#include "usart.h"


/*=========================================================
 * CHECK TXE STATUS
 *=========================================================*/

uint8_t USART_IsTXE(void)
{
    return (USART1->SR & (1U << USART_SR_TXE_POS)) != 0U;
}


/*=========================================================
 * SEND BYTE
 *=========================================================*/

void USART_SendByte(uint8_t Data)
{
    while ((USART1->SR & (1U << USART_SR_TXE_POS)) == 0U)
    {
        /* Wait until transmit data register is empty */
    }

    USART1->DR = Data;
}


/*=========================================================
 * RECEIVE BYTE
 *=========================================================*/

uint8_t USART_ReceiveByte(void)
{
    while ((USART1->SR & (1U << USART_SR_RXNE_POS)) == 0U)
    {
        /* Wait until data is received */
    }

    return (uint8_t)USART1->DR;
}


/*=========================================================
 * USART ENABLE / DISABLE
 *=========================================================*/

void USART_Enable(void)
{
    USART1->CR1 |= (1U << USART_CR1_UE_POS);
}


void USART_Disable(void)
{
    USART1->CR1 &= ~(1U << USART_CR1_UE_POS);
}


/*=========================================================
 * TRANSMITTER AND RECEIVER
 *=========================================================*/

void USART_EnableTransmitter(void)
{
    USART1->CR1 |= (1U << USART_CR1_TE_POS);
}


void USART_EnableReceiver(void)
{
    USART1->CR1 |= (1U << USART_CR1_RE_POS);
}


/*=========================================================
 * BAUD RATE CONFIGURATION
 *=========================================================*/

void USART_SetBaudRate(uint32_t PCLK, uint32_t BaudRate)
{
    uint32_t USARTDIV;
    uint32_t Mantissa;
    uint32_t Fraction;

    USARTDIV = (PCLK + (BaudRate / 2U)) / BaudRate;

    Mantissa = USARTDIV / 16U;

    Fraction = USARTDIV % 16U;

    USART1->BRR = (Mantissa << USART_BRR_DIV_MANTISSA_POS)
                | (Fraction << USART_BRR_DIV_FRACTION_POS);
}


/*=========================================================
 * USART INITIALIZATION
 *=========================================================*/

void USART_Init(uint32_t PCLK, uint32_t BaudRate)
{
    /* Enable USART1 clock */
    RCC_EnableUSART1Clock();

    /* Configure baud rate */
    USART_SetBaudRate(PCLK, BaudRate);

    /* Enable transmitter */
    USART_EnableTransmitter();

    /* Enable receiver */
    USART_EnableReceiver();

    /* Enable USART */
    USART_Enable();
}
