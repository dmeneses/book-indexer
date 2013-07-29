/* 
 * File:   FileReader.cpp
 * Author: Daniela
 * 
 * Created on July 25, 2013, 11:40 AM
 */

#include "filereader.h"
#include <sys/stat.h>
#include <string.h>
#include "bitmanipulation.h"

FileReader::FileReader(const char* path, FileEncoding encoding)
{
    this->path_ = new char[strlen(path) + 1];
    strcpy(path_, path);
    this->encoding_ = encoding;
    this->openFile_.open(path_, std::ifstream::binary);
    this->openFile_.seekg(0, openFile_.end);
    this->fileSize_ = openFile_.tellg();
    this->openFile_.seekg(0, openFile_.beg);
}

FileReader* FileReader::buildFileReader(const char* path, FileEncoding encoding)
{
    if (!validFile(path))
    {
        return NULL;
    }

    FileReader* reader = new FileReader(path, encoding);
    return reader;
}

FileReader::~FileReader()
{
    if (path_)
        delete[] path_;

    if (openFile_.is_open())
        openFile_.close();
}

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
    openFile_.read(buffer, length);
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
            int toRemove = removedBytes;
            while (toRemove)
            {
                output.pop_back();
                toRemove--;
            }
            int currentIndex = openFile_.tellg();
            currentIndex -= removedBytes;
            openFile_.seekg(currentIndex);
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

int FileReader::removeUntilLastCompleteChar(std::list<char>& output)
{
    int res = 0;
    bool validChar = false;
    std::list<char>::reverse_iterator it = output.rbegin();

    while (!validChar && it != output.rend())
    {
        char testedChar = *it;

        //Is a simple ASCII char. 0...
        if (!isOn(testedChar, 7))
        {
            break;
        }

        //Is a header of a character. 11....
        //If is false is the sequence of a character. 10...
        if (isOn(testedChar, 6))
        {
            validChar = true;
        }

        res++;
        ++it;
    }

    return res;
}
