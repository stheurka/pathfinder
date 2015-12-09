/*
 * HCS04.h
 *
 *  Created on: 06-Dec-2015
 *      Author: sagar
 */
#include<pthread.h>
#ifndef HCS04_H_
#define HCS04_H_

#define HCS04_TRIG "HCS04_TRIG"
#define HCS04_ECHO "HCS04_ECHO"
#define TRIGGERTIME 10 //microseconds

namespace HCS04 {

class HCS04
{
private:
	int trig;
	int echo;
	HCS04();
	void initialize(int trig, int echo);

public:
	HCS04(int trig, int echo);

	int get_distance();

	virtual ~HCS04();
};

} /* namespace HCS04 */
#endif /* HCS04_H_ */
