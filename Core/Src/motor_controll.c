#include "motor_controll.h"

uint16_t wifi_order[6]={2,2,2,2,2,2};
// uint16_t wifi_order_fin=0;
extern uint16_t wifi_order_fin;
uint16_t wifi_order_num=0;
uint16_t wifi_flag=0;
extern u8 key;
u8 Flag=0;


void turn_left_forward()
{
        // HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_SET);
        // HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);

        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);

}

void turn_left_back()
{
        // HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_SET);

        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);
        
}

void turn_right_forward()
{
//         HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_SET);
//         HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
//         HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
//         HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);

        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);
        
}

void turn_right_back()
{
        // HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_SET);
        // HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        // HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);

        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_SET);
}

void all_turnoff()
{
        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);
}

void move_forward()
{
        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_RESET);
}

void move_back()
{
        HAL_GPIO_WritePin(MotorL2_A_GPIO_Port,MotorL2_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorL2_B_GPIO_Port,MotorL2_B_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MotorR1_A_GPIO_Port,MotorR1_A_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MotorR1_B_GPIO_Port,MotorR1_B_Pin,GPIO_PIN_SET);
}

void wifi_order_swtich(void)
{
        // wifi_order[0] = HAL_GPIO_ReadPin(left_1_GPIO_Port,left_1_Pin);
        // wifi_order[1] = HAL_GPIO_ReadPin(left_2_GPIO_Port,left_2_Pin);
        // wifi_order[2] = HAL_GPIO_ReadPin(right_1_GPIO_Port,right_1_Pin);
        // wifi_order[3] = HAL_GPIO_ReadPin(right_2_GPIO_Port,right_2_Pin);

        
        wifi_order[0] = HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_9);
        wifi_order[1] = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8);
        wifi_order[2] = HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_9);
        wifi_order[3] = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9);
        wifi_order[4] = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10);
        wifi_order[5] = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5);


        wifi_order_fin=wifi_order[0]*1000 + wifi_order[1]*100 + wifi_order[2]*10 + wifi_order[3];

}


void motor_controll_V1(void)
{
    u8 key =PS2_DataKey();//获取手柄按键状态

/*    if(key==PSB_START)
    {
        wifi_flag=1;
    }

    if(wifi_flag==1&&key==PSB_START)
    {
        wifi_flag = 0;
    }

    if(wifi_flag==0){*/
        switch (key) {
                case PSB_PAD_LEFT://往前左转
                        turn_left_forward();
                        //HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_SET);//红灯亮
                        //toggle1=0;
                        break;
                case PSB_PAD_RIGHT://往前右转
                        turn_right_forward();
                        //HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_RESET);//红灯灭
                        //toggle1=1;
                        break;
                case PSB_PAD_UP://前进
                        move_forward();
                        //HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);//buzzer开
                        break;
                case PSB_PAD_DOWN://后退
                        move_back();
                        //HAL_GPIO_WritePin(blue_GPIO_Port,blue_Pin,GPIO_PIN_SET);//蓝灯开
                         // toggle2=0;
                        break;
                case PSB_PINK: //往后左转
                        turn_left_back();
                        //HAL_GPIO_WritePin(blue_GPIO_Port,blue_Pin,GPIO_PIN_RESET);//蓝灯灭
                        //toggle2=1;
                        break;
                case PSB_RED://往后右转
                        turn_right_back();
                        //HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);//buzzer关
                        break;
                case PSB_L1://开启刀片电机
                        HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_SET);
                        HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
                        break;
                        
                case PSB_L2://关闭刀片电机
                        HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                        break;
                case PSB_R1://开启皮带电机
                        HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_SET);
                        HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
                        //HAL_Delay(1000);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                        break;
                case PSB_R2://关闭皮带电机
                        HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
                        //HAL_Delay(500);
                        HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                        break;
                case PSB_BLUE://轮子停止
                        all_turnoff();
                        break;
                case PSB_SELECT://
                        all_turnoff();
                        HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
                        break;
                default:
                        all_turnoff();
                        break;  
        }
    //}

}

void motor_controll_wifi(void)
{
        switch (wifi_order_fin) {
        case 11://往前左转
                turn_left_forward();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_SET);//红灯亮
                //toggle1=0;
                break;
        case 1100://往前右转
                turn_right_forward();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_RESET);//红灯灭
                //toggle1=1;
                break;
        case 1111://前进
                move_forward();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);//buzzer开
                break;
        case 0://后退
                move_back();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(blue_GPIO_Port,blue_Pin,GPIO_PIN_SET);//蓝灯开
               // toggle2=0;
                break;
        case 1000: //往后左转
                turn_left_back();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(blue_GPIO_Port,blue_Pin,GPIO_PIN_RESET);//蓝灯灭
                //toggle2=1;
                break;
        case 10://往后右转
                turn_right_back();
                HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                //HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);//buzzer关
                break;
        case 1010://轮子停止
                all_turnoff();
                Flag=0;

                break;
        case 101://刀片電機

                HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
                // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);

                HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
                // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
                //HAL_Delay(1000);
                // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
                break;
        case 1://刀片電機guan
                HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);

                HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
                break;
        case 111:
                Flag=1;//
                //HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_SET);
                break;

        default:
                Flag=0;
                break;
    }

//     if(wifi_order[4]==1)
//     {
//         HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_SET);
//         HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);
//         // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);

//         HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_SET);
//         HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);
//         // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
//         //HAL_Delay(1000);
//         // HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
//     }else{
//         HAL_GPIO_WritePin(blade_motor_A_GPIO_Port,blade_motor_A_Pin,GPIO_PIN_RESET);
//         HAL_GPIO_WritePin(blade_motor_B_GPIO_Port,blade_motor_B_Pin,GPIO_PIN_RESET);

//         HAL_GPIO_WritePin(belt_motor_A_GPIO_Port,belt_motor_A_Pin,GPIO_PIN_RESET);
//         HAL_GPIO_WritePin(belt_motor_B_GPIO_Port,belt_motor_B_Pin,GPIO_PIN_RESET);

//         }



//       if(wifi_order[5]==1)
//     {
//         HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_SET);
        
//     }else{
//         HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_GPIO_Pin,GPIO_PIN_RESET);
//         }

}