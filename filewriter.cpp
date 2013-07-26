/* 
 * File:   FileWriter.cpp
 * Author: administrator
 * 
 * Created on July 26, 2013, 12:52 PM
 */

#include <list>

#include "filewriter.h"

void FileWriter::close()
{
    outputFile_.close();
}

bool FileWriter::write(std::list<short> &data)
{
    for (std::list<short>::iterator it = data.begin(); it != data.end(); ++it)
    {
        unsigned short bytes = *it;
        outputFile_.write((char*) &bytes, sizeof (bytes));
    }
}


