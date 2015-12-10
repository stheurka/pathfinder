/*
 * motor_control.h
 *
 *  Created on: 10-Dec-2015
 *      Author: vmware
 */

#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include"l293d.h"

namespace motorcontrol
{
	class motor_control
	{
	private :
		L293D left_motor;
		L293D right_motor;
		int speed;

		motor_control();
	public :
		motor_control
		(int m1enable, int m1inp1, int m1inp2,
		 int m2enable, int m2inp1, int m2inp2,
		 int mode);

		void forward();
		void reverse();
		void left();
		void right();
		void change_speed(int speed);
		void stop();

		void run_at_angle(int degree);
	};
}


#endif /* MOTOR_CONTROL_H_ */
