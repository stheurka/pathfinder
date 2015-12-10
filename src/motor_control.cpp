/*
 * motor_control.cpp
 *
 *  Created on: 10-Dec-2015
 *      Author: vmware
 */
#include"l293d.h"

namespace motorcontrol
{
motor_control::motor_control
		(int m1enable, int m1inp1, int m1inp2,
		 int m2enable, int m2inp1, int m2inp2,
		 int mode) :
		 left_motor(m1enable, m1inp1, m1inp2, 1, mode),
		 right_motor(m2enable, m2inp1, m2inp2, 1, mode)
{
	change_speed(0);
}

void motor_control::change_speed(int speed)
{
	this->speed = speed;
	left_motor.set_range_unit1(speed);
	right_motor.set_range_unit1(speed);
}

void motor_control::forward()
{
	left_motor.set_pin1();
	left_motor.reset_pin2();

	right_motor.set_pin1();
	right_motor.reset_pin2();
}

void motor_control::reverse()
{
	left_motor.reset_pin1();
	left_motor.set_pin2();

	right_motor.reset_pin1();
	right_motor.set_pin2();
}

void motor_control::left()
{
	left_motor.reset_pin1();
	left_motor.reset_pin2();

	right_motor.set_pin1();
	right_motor.reset_pin2();
}

void motor_control::right()
{
	left_motor.set_pin1();
	left_motor.reset_pin2();

	right_motor.reset_pin1();
	right_motor.reset_pin2();
}

void motor_control::stop()
{
	left_motor.reset_pin1();
	left_motor.reset_pin2();

	right_motor.reset_pin1();
	right_motor.reset_pin2();
}

inline void round_to_ten(int& value)
{
	int mod5 = value % 5;
	int mod10 = value % 10;

	if(mod5 == mod10)
		value -= mod5;
	else
		value += (5 - mod5);
}

void motor_control::run_at_angle(int degree)
{
	if(degree < 0 || degree >= 360 || speed == 0)
		return;

	round_to_ten(degree);
	int qdegree = degree%90;
	int offset = (speed/9);
	int speed_off;

	if(degree >=0 && degree <= 90)
	{
		speed_off = speed - (offset * (qdegree/10));
		left_motor.set_range_unit1(speed);
		right_motor.set_range_unit1(speed_off);
		forward();
	}
	else if(degree > 90 && degree < 180)
	{
		speed_off = (offset *(qdegree/10));
		left_motor.set_range_unit1(speed);
		right_motor.set_range_unit1(speed_off);
		reverse();
	}
	else if(degree >= 180 && degree < 270)
	{
		speed_off = speed - (offset * (qdegree/10));
		right_motor.set_range_unit1(speed);
		left_motor.set_range_unit1(speed_off);
		reverse();
	}
	else if(degree >= 270 && degree < 360)
	{
		speed_off = (offset *(qdegree/10));
		right_motor.set_range_unit1(speed);
		left_motor.set_range_unit1(speed_off);
		forward();
	}
}
}
