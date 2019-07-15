#ifndef __USRATX_H
#define __USRATX_H 
#include "sys.h"	  	
void usart3_send(u8 data);
void usart3_sendString(char *data,u8 len);
void uart3_init(u32 pclk2,u32 bound);
//int USART3_IRQHandler(void);

void usart2_send(u8 data);
void usart2_sendString(char *data,u8 len);
void uart2_init(u32 pclk2,u32 bound);
//int USART2_IRQHandler(void);

void uart4_send(u8 data);
void uart4_sendString(char *data,u8 len);
void uart4_init(u32 pclk2,u32 bound);

void uart5_send(u8 data);
void uart5_sendString(char *data,u8 len);
void uart5_init(u32 pclk2,u32 bound);

#endif

