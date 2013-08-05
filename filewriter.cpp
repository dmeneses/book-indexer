/* 
 * File:   FileWriter.cpp
 * Author: administrator
 * 
 * Created on July 26, 2013, 12:52 PM
 */
#include "filewriter.h"
#include <algorithm>
#define DEFAULT_SIZE 100

FileWriter::FileWriter(const char* path)
{
    outputFile_.open(path, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
    buffer = new unsigned short[DEFAULT_SIZE];
    currentSize = DEFAULT_SIZE;
}

FileWriter::~FileWriter()
{
    if (outputFile_.is_open())
        outputFile_.close();
    if (buffer)
    {
        delete[] buffer;
        buffer = 0;
    }
}

void FileWriter::close()
{
    outputFile_.close();
}

bool FileWriter::write(std::vector<short> &data)
{
    if (data.size() > currentSize) resize(data.size());

    for (int i = 0; i < data.size(); i++)
    {
        buffer[i] = data.at(i);
    }

    outputFile_.write((char*)&buffer, data.size());
    return outputFile_;
}

void FileWriter::resize(int newSize)
{
    delete[] buffer;
    currentSize = newSize;
    buffer = new unsigned short[newSize];
}
