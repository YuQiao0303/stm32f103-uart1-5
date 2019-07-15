#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"

#define temp_pwm  2500

//------------------------------√¸¡Ó--------------------------------------------
extern u8 reset_cmd[10] ;
extern u8 speed_mode_cmd[10] ;
extern u8 set_speed_cmd[10] ;
extern u8 stop_cmd[10] ;
extern u8 receive_data_cmd[10] ;
extern u8 stop_receive_data_cmd[10] ;
extern u8 check_online_cmd[10] ;

//------------------------------∑Ω∑®--------------------------------------------
void motor_reset(void);
void motor_enter_speed_mode(void);
void motor_init(void);
void motor_set_speed(u16 speed);
void motor_stop(void);
void motor_check_on_line(void);
				    
#endif

















