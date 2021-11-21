#include "motor.h"

void car_ctrl(int flag_mid, int flag_left, int flag_right)
{
	if (flag_mid == 0 && flag_left == 0 && flag_right == 0)
	{
		FORWARD();
	}
	else if (flag_left == 1 && flag_left == 0 && flag_mid == 0)
	{
		STOP();
		HAL_Delay(500);
		RIGHT_N(45);
	}
	else if (flag_right == 1 && flag_left == 0 && flag_mid == 0)
	{
		STOP();
		HAL_Delay(500);
		LEFT_N(45);
	}
	else
	{
		STOP();
		HAL_Delay(500);
		BACKWARD();
		HAL_Delay(500);
		LEFT_N(45);
	}
}
