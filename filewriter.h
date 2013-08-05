/* 
 * File:   FileWriter.h
 * Author: administrator
 *
 * Created on July 26, 2013, 12:52 PM
 */

#ifndef FILEWRITER_H
#define	FILEWRITER_H
#include <fstream>
#include <vector>

class FileWriter
{
public:   
    FileWriter(const char* path);
    FileWriter(const FileWriter& orig);
    virtual ~FileWriter();
    void close();
    bool write(std::vector<short> &data);
    
private:
    void resize(int newSize);
    std::ofstream outputFile_;
    unsigned short* buffer;
    int currentSize;
};

#endif	/* FILEWRITER_H */

