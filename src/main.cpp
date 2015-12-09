#include "parser.h"

class cinitialize
{

	cParser *parserObj;
	//std::map<std::string,std::string> *configmap;

public:
	cinitialize()
	{
		parserObj = new cParser();

	}

void init()
{

	    ifstream    inFile;
	    char    str[128];
	    inFile.open(datafile, ifstream::in);
	    if(!inFile.is_open())
	    {
	        cout << "Unable to open file %s\nProgram terminating...\n";

	    }

	    while(true)
	    {
	        parserObj->getNextLine(inFile, str, strlen(str));
	        if(inFile.good())
	            cout << str << "\n";
	        else
	            break;

	    }

}

~cinitialize()
{
 delete parserObj;

}
};

int main (void)
{

  cinitialize *initObj = new cinitialize();
  initObj->init();

  return 0 ;
}

