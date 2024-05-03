#ifndef  __motor_controll_H
#define  __motor_controll_H


//extern u8 key,last_key;//记录按键数字
//extern int toggle1,toggle2;//反转

#include "PS2.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_hal_gpio.h"

//led，buzzer接口
#define red_Pin GPIO_PIN_6
#define red_GPIO_Port GPIOF
#define green_Pin GPIO_PIN_7
#define green_GPIO_Port GPIOF
#define blue_Pin GPIO_PIN_8
#define blue_GPIO_Port GPIOF

#define Buzzer_GPIO_Port    GPIOG
#define Buzzer_GPIO_Pin     GPIO_PIN_7

/*//电机接口
#define MotorL1_GPIO_Port   GPIOD
#define MotorL1_Pin         GPIO_PIN_0
#define MotorL2_GPIO_Port   GPIOD
#define MotorL2_Pin         GPIO_PIN_11
#define MotorR1_GPIO_Port   GPIOF
#define MotorR1_Pin         GPIO_PIN_0
#define MotorR2_GPIO_Port   GPIOG
#define MotorR2_Pin         GPIO_PIN_0*/



/*void left_forwardRun(void);
void left_backwardRun(void);
void right_forwardRun(void);
void right_backwardRun(void);
void left_stop(void);
void right_stop(void);*/
void motor_controll_V1(void);
void motor_controll_wifi(void);
void wifi_order_swtich(void);       

void turn_left_forward(void);
void turn_left_back(void);
void turn_right_forward(void);
void turn_right_back(void);
void all_turnoff(void);
void move_forward(void);
void move_back(void);

extern uint16_t wifi_order[6];
extern uint16_t wifi_order_fin;
extern uint16_t wifi_order_num;
extern uint16_t wifi_flag;
extern uint8_t Flag;




#endif

