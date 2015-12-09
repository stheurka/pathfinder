/*
 * HCS04.cpp
 *
 *  Created on: 06-Dec-2015
 *      Author: sagar
 */
#include "hcs04.h"
#include <wiringPi.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

namespace HCS04 {

HCS04::HCS04(int trig, int echo)
{
	if (wiringPiSetup () == -1)
		    throw("Error setting up wiring Pi.");

	initialize(trig, echo);
}

void HCS04::initialize(int pTrig, int pEcho)
{
	trig = pTrig;
	echo = pEcho;

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

	digitalWrite(trig, LOW);
}

//inline from performance
int HCS04::get_distance()
{
	//Send the trigger
	//A pulse of 10 micro seconds duration

	digitalWrite(trig, HIGH);

	usleep(TRIGGERTIME);

	digitalWrite(trig, LOW);

	//Check the time calculated
	//Listen on echo pin
	//pin will be high for the time t
	//t : time for wave to travel from the sensor to the obstacle
	struct timeval start, stop, diff;

	while(digitalRead(echo) == LOW)
		gettimeofday(&start, NULL);

	while(digitalRead(echo) == HIGH)
		gettimeofday(&start, NULL);

	timersub(&stop, &start, &diff);

	int time_in_usec = (diff.tv_sec * 1000000) + diff.tv_usec/1000000;

	//From HCS04 manual
	//Formula: uS / 58 = centimeters or uS / 148 =inch; or: the
	//range = high level time * velocity (340M/S) / 2; we suggest to use over 60ms
	//measurement cycle, in order to prevent trigger signal to the echo signal.
	int distance_in_cm = time_in_usec/58;

	return distance_in_cm;
}

HCS04::~HCS04()
{

}

} /* namespace HCS04 */
