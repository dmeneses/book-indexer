/* 
 * File:   FileReader.cpp
 * Author: Daniela
 * 
 * Created on July 25, 2013, 11:40 AM
 */

#include "filereader.h"
#include <sys/stat.h>

bool FileReader::end()
{
    return openFile_.eof();
}

void FileReader::close()
{
    openFile_.close();
}

int FileReader::readBuffer(int length, bool checkCompleteChars, std::list<char>& output)
{
    char * buffer = new char [length];
    openFile_.read(buffer, fileSize_ - currentIndex_);
    int readBytesCount = openFile_.gcount();

    if (readBytesCount < 0)
    {
        return 0;
    }

    for (int i = 0; i < readBytesCount; i++)
    {
        output.push_back(buffer[i]);
    }
    delete[] buffer;
    int removedBytes = 0;
    if (checkCompleteChars)
    {
        removedBytes = removeUntilLastCompleteChar(output);

        if (removedBytes > 0)
        {
            currentIndex_ = openFile_.tellg();
            currentIndex_ -= removedBytes;
            openFile_.seekg(currentIndex_);
        }
    }

    return readBytesCount - removedBytes;
}

bool FileReader::validFile(const char* path)
{
    struct stat st_info;

    if (path)
    {
        if (stat(path, &st_info) == 0)
        {
            return S_ISREG(st_info.st_mode);
        }
    }
}

int FileReader::removeUntilLastCompleteChar(std::list<char> output)
{

}
