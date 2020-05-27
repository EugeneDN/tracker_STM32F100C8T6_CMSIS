/*
 * main.c
 */

#include "main.h"

int main(void) {
  mcu_init();
  while(1) {

  }
}

void mcu_init(void) {
  rcc_init();
  uart1_init();
}
