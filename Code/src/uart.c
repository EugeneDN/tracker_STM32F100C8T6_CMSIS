/*
 * uart.c
 */

#include "uart.h"

void uart1_init(void) {
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

  GPIOA->CRH |= GPIO_CRH_MODE9_1;
  GPIOA->CRH &= ~(GPIO_CRH_MODE9_0);
  GPIOA->CRH |= GPIO_CRH_CNF9_1;
  GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);

  GPIOA->CRH &= ~(GPIO_CRH_MODE10);
  GPIOA->CRH |= GPIO_CRH_CNF10_0;
  GPIOA->CRH &= ~(GPIO_CRH_CNF10_1);

  USART1->BRR = 0x9C4;

  USART1->CR1 |= USART_CR1_UE;
  USART1->CR1 |= USART_CR1_TE;
  USART1->CR1 |= USART_CR1_RE;
}

void uart1_tx(char *str) {
  while(*str) {
    if(USART1->SR & USART_SR_TC) {
      USART1->DR = *str++;
    }
  }
}
