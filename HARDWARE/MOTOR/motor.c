#include "sys.h"   
#include "motor.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/05
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   


//------------------------------命令--------------------------------------------
u8 reset_cmd[10] = 							{0x23 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 speed_mode_cmd[10] = 				{0x23 ,0x01 ,0x03 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55	};
u8 set_speed_cmd[10] = 					{0x23 ,0x04 ,0x13 ,0x88 ,0x01 ,0xF4 ,0x55 ,0x55 ,0x55 ,0x55	};
u8 stop_cmd[10] = 							{0x23 ,0x04 ,0x13 ,0x88 ,0x00 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 receive_data_cmd[10] = 			{0x23 ,0x0A ,0x09 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 stop_receive_data_cmd[10] = 	{0x23 ,0x0A ,0x00 ,0x00 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };
u8 check_online_cmd[10] = 			{0x23 ,0x0F ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 ,0x55 };

//------------------------------方法--------------------------------------------
//复位需要约500ms
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

//连续发送的时间间隔不能小于 2 毫秒，建议以10 毫秒为周期。
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



