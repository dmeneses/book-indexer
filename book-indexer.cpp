
#include "converter.h"
#include "book-indexer.h"
#include "filereader.h"
#include "filewriter.h"
#include <list>
#define READ_SIZE 100
#include <iostream>
using namespace std;

ConversionResponse convertUTF8toUTF16(const char* path, Endianness type)
{
    FileReader* reader = FileReader::buildFileReader(path, UTF8);
    if (!reader) return FileNotFound;
    bool isTheSameFormat = reader->isSameFormat(type);
    FileWriter* writer = new FileWriter(strcat("UTF16", path));

    list<char> buffer;
    list<long> unicode;
    list<short> converted;

    while (!reader->end())
    {
        int readBytes = reader->readBuffer(READ_SIZE, true, buffer);

        if (!readBytes)
        {
            break;
        }

        ConversionResponse response = convertUTF8toUnicode(buffer, unicode);

        if (response != ConversionOK)
        {
            return response;
        }

        response = unicodeToUTF16(unicode, converted, isTheSameFormat);

        if (response != ConversionOK)
        {
            return response;
        }

        for (std::list<short>::iterator it = converted.begin(); it != converted.end(); it++)
            std::cout << hex << *it << '\n';

        writer->write(converted);

        buffer.clear();
        unicode.clear();
        converted.clear();
    }

    delete reader;
    delete writer;
    return ConversionOK;
}
