/*
 * L293D.cpp
 *
 *  Created on: 06-Dec-2015
 *      Author: sagar
 */

#include "l293d.h"
#include <fstream>
#include <string>
#include <wiringPi.h>
#include <softPwm.h>

L293D::L293D(int enable, int inp1, int inp2, int unit, int mode)
{
	if (wiringPiSetup () == -1)
	    throw("Error setting up wiring Pi.");

	if(unit == 1)
	{
		initialize_unit1(enable, inp1, inp2, mode);
	}
	else if(unit == 2)
	{
		initialize_unit2(enable, inp1, inp2, mode);
	}
}

L293D::L293D(int en12, int inp1, int inp2, int mode12, int en34, int inp3, int inp4, int mode34)
{
	if (wiringPiSetup () == -1)
		    throw("Error setting up wiring Pi.");

	initialize_unit1(en12, inp1, inp2, mode12);
	initialize_unit2(en34, inp3, inp4, mode34);
}

L293D::L293D(char * filepath)
{
	if (wiringPiSetup () == -1)
		    throw("Error setting up wiring Pi.");

	intialize(filepath);
}

void L293D::initialize_unit1(int en12, int inp1, int inp2, int mode)
{
	enable_p12 = en12;
	inp_p1 = inp1;
	inp_p2 = inp2;

	if(mode == L293D_NORMALMODE)
	{
		pinMode(enable_p12, OUTPUT);
		digitalWrite(enable_p12, LOW);
	}
	else if(mode == L293D_PWMMODE)
	{
		softPwmStop(enable_p12);
		//range set to 90 so that angle control is easier;
		softPwmCreate(enable_p12, 0, 90);
	}

	pinMode(inp_p1, OUTPUT);
	pinMode(inp_p2, OUTPUT);


	digitalWrite(inp_p1, LOW);
	digitalWrite(inp_p2, LOW);
}

void L293D::initialize_unit2(int en34, int inp3, int inp4, int mode)
{
	enable_p34 = en34;
	inp_p3 = inp3;
	inp_p4 = inp4;

	if(mode == L293D_NORMALMODE)
	{
		pinMode(enable_p34, OUTPUT);
		digitalWrite(enable_p34, LOW);
	}
	else if(mode == L293D_PWMMODE)
	{
		softPwmStop(enable_p342);
		//range set to 90 so that angle control is easier;
		softPwmCreate(enable_p34, 0, 90);
	}

	pinMode(inp_p3, OUTPUT);
	pinMode(inp_p4, OUTPUT);

	digitalWrite(inp_p3, LOW);
	digitalWrite(inp_p4, LOW);
}

void L293D::intialize(int en12, int inp1, int inp2, int mode12, int en34, int inp3, int inp4, int mode34)
{
	initialize_unit1(en12, inp1, inp2, mode12);
	initialize_unit2(en34, inp3, inp4, mode34);
}

void L293D::intialize(char * filepath)
{
	using std::ifstream;
		using namespace std;

		ifstream fin;
		fin.open("data.txt"); // open a file
		if (!fin.good())
			throw("File not found");

		while (!fin.eof())
		{

		}
}

//only for normal mode
void L293D::enable_unit1()
{
	digitalWrite(enable_p12, HIGH);
}

void L293D::enable_unit2()
{
	digitalWrite(enable_p34, HIGH);
}

void L293D::disable_unit1()
{
	digitalWrite(enable_p12, LOW);
}

void L293D::disable_unit2()
{
	digitalWrite(enable_p12, LOW);
}
//

//only for pwm mode
void L293D::set_range_unit1(int range)
{
	range1 = range;
	softPwmWrite(enable_p12, range);
}

void L293D::set_range_unit2(int range)
{
	range2 = range;
	softPwmWrite(enable_p34, range);
}

void L293D::set_pin1()
{
	inp_p1_state = HIGH;
	digitalWrite(inp_p1, HIGH);
}

void L293D::set_pin2()
{
	inp_p2_state = HIGH;
	digitalWrite(inp_p2, HIGH);
}

void L293D::set_pin3()
{
	inp_p3_state = HIGH;
	digitalWrite(inp_p3, HIGH);
}

void L293D::set_pin4()
{
	inp_p4_state = HIGH;
	digitalWrite(inp_p4, HIGH);
}

void L293D::reset_pin1()
{
	inp_p1_state = LOW;
	digitalWrite(inp_p1, LOW);
}

void L293D::reset_pin2()
{
	inp_p2_state = LOW;
	digitalWrite(inp_p2, LOW);
}

void L293D::reset_pin3()
{
	inp_p3_state = LOW;
	digitalWrite(inp_p3, LOW);
}

void L293D::reset_pin4()
{
	inp_p4_state = LOW;
	digitalWrite(inp_p4, LOW);
}

int L293D::read_pin1()
{
	return inp_p1_state;
}

int L293D::read_pin2()
{
	return inp_p2_state;
}

int L293D::read_pin3()
{
	return inp_p3_state;
}

int L293D::read_pin4()
{
	return inp_p4_state;
}

int L293D::get_range1()
{
	return range1;
}

int L293D::get_range2()
{
	return range2;
}

L293D::~L293D()
{

}
