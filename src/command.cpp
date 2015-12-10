/*
 * command.cpp
 *
 *  Created on: 10-Dec-2015
 *      Author: vmware
 */
namespace command
{
#include <iostream>
using namespace std;
class command
{
private:
		string command;
		string type;
		string parameters;
		command();
public :
		command(string pCommand, string pType, string parameters);
};
}
