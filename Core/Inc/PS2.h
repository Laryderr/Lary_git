#ifndef  __PS2_H
#define  __PS2_H

/*********************************************************
Copyright (C), 2015-2025, YFRobot.
www.yfrobot.com
File：PS2驱动程序
Author：pinggai    Version:1.1     Data:2015/10/20
Description: PS2驱动程序
             增加功能：
			 1、软件设置“红灯模式”、“绿灯模式”，并可以设置“保存”，通过手柄“模式按键”无法改变
			 2、设置手柄震动：通过数值的设置，改变左侧大震动电机震动频率。
			                  通过数值的设置，开关右侧小震动电机。
History:  
V1.0: 	2015/05/16
1、手柄解码，识别按键值，读取模拟值。       
**********************************************************/	 
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "gpio.h"

typedef uint16_t u16;
typedef uint8_t u8;


//接收器各个接口
#define CLK_Pin			GPIO_PIN_13
#define CLK_GPIO_Port 	GPIOB
#define CMD_Pin 		GPIO_PIN_14
#define CMD_GPIO_Port 	GPIOB
#define DAT_Pin 		GPIO_PIN_15
#define DAT_GPIO_Port 	GPIOB
#define CS_Pin		 	GPIO_PIN_6
#define CS_GPIO_Port 	GPIOA

//*********************第二版*******
/*#define PS2_CS_GPIOx    GPIOA
#define PS2_CS_Pin      GPIO_PIN_6

#define PS2_CLK_GPIOx   GPIOB
#define PS2_CLK_Pin     GPIO_PIN_13

#define PS2_DO_GPIOx    GPIOB
#define PS2_DO_Pin      GPIO_PIN_14

#define PS2_DI_GPIOx    GPIOB
#define PS2_DI_Pin      GPIO_PIN_15

typedef struct
{
    uint8_t A_D;                                       //模拟(红灯)为1 数字(无灯)为0
    int8_t Rocker_RX, Rocker_RY, Rocker_LX, Rocker_LY; //摇杆值(模拟状态为实际值0-0xFF)(数字态为等效的值0,0x80,0xFF)
    //按键值0为未触发,1为触发态
    uint8_t Key_L1, Key_L2, Key_R1, Key_R2;                //后侧大按键
    uint8_t Key_L_Right, Key_L_Left, Key_L_Up, Key_L_Down; //左侧按键
    uint8_t Key_R_Right, Key_R_Left, Key_R_Up, Key_R_Down; //右侧按键
    uint8_t Key_Select;                                    //选择键
    uint8_t Key_Start;                                     //开始键
    uint8_t Key_Rocker_Left, Key_Rocker_Right;             //摇杆按键

} PS2_TypeDef;
extern PS2_TypeDef PS2_Data;
void PS2_Read_Data(void);*/
//*********************************version2.0*********************

#define DI    HAL_GPIO_ReadPin(DAT_GPIO_Port,DAT_Pin)                      //PA0  输入
                                                                           
#define DO_H  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_SET);       //命令位高
#define DO_L  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_RESET);     //命令位低
                                                                           
#define CS_H  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET);         //CS拉高
#define CS_L  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET);       //CS拉低
                                                                           
#define CLK_H HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_SET);       //时钟拉高
#define CLK_L HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_RESET);     //时钟拉低


//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      16

void delay_us(uint32_t us);

//#define WHAMMY_BAR		8

//These are stick values
#define PSS_RX 5                //右摇杆X轴数据
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;

void PS2_Init(void);
u8 PS2_RedLight(void);   //判断是否为红灯模式
void PS2_ReadData(void); //读手柄数据
void PS2_Cmd(u8 CMD);		  //向手柄发送命令
u8 PS2_DataKey(void);		  //按键值读取
u8 PS2_AnologData(u8 button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
void PS2_Vibration(u8 motor1, u8 motor2);//振动设置motor1  0xFF开，其他关，motor2  0x40~0xFF

void PS2_EnterConfing(void);	 //进入配置
void PS2_TurnOnAnalogMode(void); //发送模拟量
void PS2_VibrationMode(void);    //振动设置
void PS2_ExitConfing(void);	     //完成配置
void PS2_SetInit(void);		     //配置初始化

#endif
