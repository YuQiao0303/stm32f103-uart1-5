#include "sys.h"   
#include "motor.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK Mini STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2014/3/05
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   


//------------------------------����--------------------------------------------
u8 reset_cmd[10] = 							{0x23 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 speed_mode_cmd[10] = 				{0x23 ,0x01 ,0x03 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55	};
u8 set_speed_cmd[10] = 					{0x23 ,0x04 ,0x13 ,0x88 ,0x01 ,0xF4 ,0x55 ,0x55 ,0x55 ,0x55	};
u8 stop_cmd[10] = 							{0x23 ,0x04 ,0x13 ,0x88 ,0x00 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 receive_data_cmd[10] = 			{0x23 ,0x0A ,0x09 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 stop_receive_data_cmd[10] = 	{0x23 ,0x0A ,0x00 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 check_online_cmd[10] = 			{0x23 ,0x0F ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };

//------------------------------����--------------------------------------------
//��λ��ҪԼ500ms
void motor_reset()
{
	usart3_sendString((char *)reset_cmd,10) ;
}
void motor_enter_speed_mode()
{
	usart3_sendString((char *)speed_mode_cmd,10) ;	
}
void motor_init()
{
	motor_reset();
	delay_ms(550);
	motor_enter_speed_mode();
	delay_ms(200);
}

//�������͵�ʱ��������С�� 2 ���룬������10 ����Ϊ���ڡ�
void motor_set_speed(u16 temp_velocity)
{
	set_speed_cmd[2] = (u8)((temp_pwm>>8)&0xff);
	set_speed_cmd[3] = (u8)(temp_pwm&0xff);
	set_speed_cmd[4] = (u8)((temp_velocity>>8)&0xff);
	set_speed_cmd[5] = (u8)(temp_velocity&0xff);
	
	usart3_sendString((char *)set_speed_cmd,10) ;	
}

void motor_stop()
{
	usart3_sendString((char *)stop_cmd,10) ;	
}
void motor_check_on_line()
{
	usart3_sendString((char *)check_online_cmd,10) ;	
}



