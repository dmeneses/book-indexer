/* 
 * File:   FileWriter.cpp
 * Author: administrator
 * 
 * Created on July 26, 2013, 12:52 PM
 */
#include "filewriter.h"

FileWriter::FileWriter(const char* path)
{
    outputFile_.open(path, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
}

FileWriter::~FileWriter()
{
    if (outputFile_.is_open())
        outputFile_.close();
}

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


