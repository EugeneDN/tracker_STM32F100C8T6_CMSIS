#ifndef CODE_SRC_UART_H_
#define CODE_SRC_UART_H_

#include "stm32f10x.h"

void uart1_init(void);
void uart1_tx(char *str);

#endif /* CODE_SRC_UART_H_ */
