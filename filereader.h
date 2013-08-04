/* 
 * File:   FileReader.h
 * Author: Daniela
 *
 * Created on July 25, 2013, 11:40 AM
 */

#ifndef FILEREADER_H
#define	FILEREADER_H
#include <fstream>
#include <vector>
#include "converter.h"

enum FileEncoding
{
    UTF8,
    UTF16,
    UNICODE
};

class FileReader
{
public:
    FileReader(const FileReader & orig);
    static FileReader* buildFileReader(const char* path, FileEncoding encoding);
    virtual ~FileReader();
    int readBuffer(int size, bool checkCompleteChars, std::vector<char>& output);
    bool end();
    void close();
    bool isSameFormat(Endianness requiredEndianness);
private:
    FileReader(const char* path, FileEncoding encoding);
    int removeUntilLastCompleteChar(std::vector<char>& output);
    static bool validFile(const char* path);

    std::ifstream openFile_;
    char* path_;
    FileEncoding encoding_;
    int fileSize_;
};

#endif	/* FILEREADER_H */

