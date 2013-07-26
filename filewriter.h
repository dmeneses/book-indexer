/* 
 * File:   FileWriter.h
 * Author: administrator
 *
 * Created on July 26, 2013, 12:52 PM
 */

#ifndef FILEWRITER_H
#define	FILEWRITER_H
#include <fstream>

class FileWriter
{
public:

    FileWriter(const char* path)
    {
        outputFile_.open(path);
    }
    
    FileWriter(const FileWriter& orig);

    virtual ~FileWriter()
    {
        if (outputFile_.is_open())
            outputFile_.close();
    }
    
    void close();
    bool write(std::list<short> &data);
    
private:
    std::ofstream outputFile_;
};

#endif	/* FILEWRITER_H */

