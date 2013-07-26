/* 
 * File:   FileReader.h
 * Author: Daniela
 *
 * Created on July 25, 2013, 11:40 AM
 */

#ifndef FILEREADER_H
#define	FILEREADER_H
#include <list>
#include <iostream>
#include <fstream>

enum FileEncoding
{
    UTF8,
    UTF16,
    UNICODE
};

class FileReader
{
public:

    FileReader(const char* path, FileEncoding encoding)
    {
        if (!validFile(path))
        {
            //throw exception
        }

        path_ = new char[strlen(path) + 1];
        strcpy(path_, path);
        this->encoding_ = encoding;
        openFile_.open(path_, std::ifstream::binary);
        openFile_.seekg(0, openFile_.end);
        fileSize_ = openFile_.tellg();
        openFile_.seekg(0, openFile_.beg);
        int currentIndex_ = 0;
    }

    FileReader(const FileReader & orig);

    virtual ~FileReader()
    {
        if (path_)
            delete[] path_;

        if (openFile_.is_open())
            openFile_.close();
    }

    int readBuffer(int size, bool checkCompleteChars, std::list<char>& output);
    bool end();
    void close();
private:
    bool validFile(const char* path);
    int removeUntilLastCompleteChar(std::list<char> output);
    
    std::ifstream openFile_;
    char* path_;
    FileEncoding encoding_;
    int currentIndex_;
    int fileSize_;
};

#endif	/* FILEREADER_H */

