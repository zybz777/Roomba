#include "state_machine.h"
#include "tim.h"
STATE state_car = state_forward;
//  状态机转移
void state_trans()
{
    static int road = 0; // 轨迹序号
    static int go_long = 3000;
    static int go_short = 1000;
    static int turn_time = 1500;
    static int stop_time = 500;
    switch (state_car)
    {
    case state_forward:
        if (road == 2 || road == 6)
        {
            HAL_Delay(go_short);
        }
        else
        {
            HAL_Delay(go_long);
        }
        state_car = state_stop;
        break;
    case state_left:
        HAL_Delay(turn_time);
        state_car = state_stop;
        break;
    case state_right:
        HAL_Delay(turn_time);
        state_car = state_stop;
        break;
    case state_stop:
        road++;
        HAL_Delay(stop_time);
        switch (road)
        {
        case 1:
            state_car = state_left;
            break;
        case 2:
            state_car = state_forward;
            break;
        case 3:
            state_car = state_left;
            break;
        case 4:
            state_car = state_forward;
            break;
        case 5:
            state_car = state_right;
            break;
        case 6:
            state_car = state_forward;
            break;
        case 7:
            state_car = state_right;
            break;
        default:
            state_car = state_forward;
            road = 0;
            break;
        }
        break;
    default:
        break;
    }
}
// 状态机执行
void state_exe()
{
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 1000);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 1000);
    switch (state_car)
    {
    case state_forward:
        car_forward(); // 直行
        break;
    case state_left:
        car_left(); // 左转
        break;
    case state_right:
        car_right(); // 右转
        break;
    case state_stop:
        car_stop();
        break;
    default:
        break;
    }
    state_trans();
}
