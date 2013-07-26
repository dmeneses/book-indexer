/* 
 * File:   FileReader.cpp
 * Author: Daniela
 * 
 * Created on July 25, 2013, 11:40 AM
 */

#include "filereader.h"
#include <sys/stat.h>

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

int FileReader::removeUntilLastCompleteChar(std::list<char> output)
{
    return 0;
}
