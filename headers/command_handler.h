/*
 * command_handler.h
 *
 *  Created on: 14-Dec-2015
 *      Author: vmware
 */

#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

namespace n_command_handler
{
#include "command.h"
#include <pthread.h>
using namespace command;

template<int n>
class c_command_handler
{
private:
command * queue[n];
pthread_mutex_t mutex;
pthread_cond_t cond;
int read_index;
int write_index;
int size;

public :
c_command_handler();

void write(command * p);
command read();

virtual ~c_command_handler();

};

}


#endif /* COMMAND_HANDLER_H_ */
