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
#define DEFAULT_LENGTH 100

FileReader::FileReader(const char* path, FileEncoding encoding)
{
    this->path_ = new char[strlen(path) + 1];
    strcpy(path_, path);
    this->encoding_ = encoding;
    this->openFile_.open(path_, std::ifstream::binary);
    this->openFile_.seekg(0, openFile_.end);
    this->fileSize_ = openFile_.tellg();
    this->openFile_.seekg(0, openFile_.beg);
    this->buffer_ = new char [DEFAULT_LENGTH];
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
    {
        delete[] path_;
        path_ = 0;
    }

    if (openFile_.is_open())
        openFile_.close();

    if (buffer_)
    {
        delete[] buffer_;
        buffer_ = 0;
    }
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

    return false;
}

bool FileReader::end()
{
    return openFile_.eof();
}

void FileReader::close()
{
    openFile_.close();
}

void FileReader::resize(int newSize)
{
    delete[] buffer_;
    buffer_ = new char[newSize];
    currentSize_ = newSize;
}

int FileReader::readBuffer(int length, bool checkCompleteChars, std::vector<char>& output)
{
    if (currentSize_ < length) resize(length);

    openFile_.read(buffer_, length);
    int readBytesCount = openFile_.gcount();

    if (readBytesCount == 0) return 0;

    for (int i = 0; i < readBytesCount; i++)
    {
        output.push_back(buffer_[i]);
    }

    if (checkCompleteChars && !end())
        readBytesCount -= checkBytesOfCharacters(output);

    return readBytesCount;
}

int FileReader::checkBytesOfCharacters(std::vector<char>& output)
{
    int removedBytes = removeUntilLastCompleteChar(output);

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

    return removedBytes;
}

int FileReader::removeUntilLastCompleteChar(std::vector<char>& output)
{
    int res = 0;
    bool validChar = false;
    std::vector<char>::reverse_iterator it = output.rbegin();

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

bool FileReader::isSameFormat(Endianness requiredEndianness)
{
    bool res = false;
    char * buffer = new char [3];
    this->openFile_.read(buffer, 3);
    int readBytesCount = openFile_.gcount();

    if (readBytesCount == 0)
        res = true;

    unsigned char header = buffer[0];
    unsigned char byte1 = buffer[1];
    unsigned char byte2 = buffer[2];

    if (header == 0xEF && byte1 == 0xBB && byte2 == 0xBF && requiredEndianness == BE)
        res = true;
    if (header == 0xEF && byte1 == 0xBF && byte2 == 0xBE && requiredEndianness == LE)
        res = true;

    this->openFile_.seekg(0, openFile_.beg);
    delete buffer;
    return res;
}
