#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h" 
//ALIENTEK Mini STM32�����巶������3
//����ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
# define DATA_LEN 13

extern u8 startOpen,startClose,isOpen;
extern u8 USART2_RX_FLAG;
extern u8 USART2_RX_BUF[64]; //���յ�������
extern u8 USART3_RX_BUF[64]; //���յ�������
extern u8 UART5_RX_BUF[64]; //���յ�������
extern double d2;
extern double d3;
extern double d5;



int main(void)
{			


	
	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ�� 
	uart_init(72,115200);	 
	uart2_init(36,115200);
	uart3_init(36,115200);
	uart4_init(36,115200);
	uart5_init(36,115200);

	delay_ms(1000);
	


	while(1)
	{

	}	 
}














