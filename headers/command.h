/*
 * command.h
 *
 *  Created on: 10-Dec-2015
 *      Author: vmware
 */
#include <iostream>
#include<map>
#include<string>

namespace command
{
using namespace std;


class command
{
private:
		string cmd;
		string type;
		map<string, string> parameters;
		command();
public :
		command(string pCommand, string pType, string parameters);
};
}



