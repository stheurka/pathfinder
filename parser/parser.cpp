#include "parser.h"
/**************************************************************/
/* GetNextLine_CPP()                                          */
/*                                                            */
/* Purpose: Read a line from a data file.                     */
/*  Language: C                                               */
/* Args: inFile -- istream pointer                            */
/*       line -- Character array to place the line in.        */
/*       lineLen -- Length of the character array line.       */
/* Returns: void                                              */
/**************************************************************/
void cParser::getNextLine(ifstream& inFile, char *line, int lineLen)
{
    int    done = false;
    while(!done)
    {
        inFile.getline(line, 128);

        if(inFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            //configmap[line]=line;

/*            std::vector<std::string> fields;
            boost::split(fields, line, boost::is_any_of(":"));
                for (const auto& field : fields)
                    //std::cout << "\"" << field << "\"\n";
                	configmap[line]=line;
*/
         }


            return;
        }

}
