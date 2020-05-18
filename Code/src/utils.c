/*
 * utils.c
 */

#include "utils.h"

/*
 * rcc_init
 * External High Speed clock = 8MHz;
 * AHB = APB1 = APB2 = 24MHz;
 * HSE selected as system clock
 */
uint8_t rcc_init(void) {
  
  RCC->CR |= RCC_CR_HSEON;

  for(uint16_t i = 0; ; i++) {
    if(RCC->CR & RCC_CR_HSERDY) 
      break;
    if(i > 0x500) {
      RCC->CR &= ~(RCC_CR_HSEON);
      return 1;
    }
  }

  RCC->CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1;

  RCC->CFGR |= RCC_CFGR_PLLMULL_3;

  RCC->CFGR |=RCC_CFGR_PLLSRC_PREDIV1;

  RCC->CR |= RCC_CR_PLLON;

  for(uint16_t i = 0; ; i++) {
    if(RCC->CR & RCC_CR_PLLRDY) 
      break;
    if(i > 0x500) {
      RCC->CR &= ~(RCC_CR_PLLON);
      RCC->CR &= ~(RCC_CR_HSEON);
      return 2;
    }
  }

  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

  RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;

  RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

  RCC->CFGR |= RCC_CFGR_SW_HSE;

  while((RCC->CFGR & RCC_CFGR_SW_0) != RCC_CFGR_SW_HSE)
	  ;

  return 0;
}
