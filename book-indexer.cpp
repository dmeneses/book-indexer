
#include "converter.h"
#include "book-indexer.h"
#include "filereader.h"
#include "filewriter.h"
#include <list>
#define READ_SIZE 100

using namespace std;

ConversionResponse convertUTF8toUTF16(const char* inputPath, const char* outputPath, Endianness type)
{
    ConversionResponse response = ConversionOK;
    FileReader* reader = FileReader::buildFileReader(inputPath, UTF8);
    if (!reader) return FileNotFound;
    bool isTheSameFormat = reader->isSameFormat(type);
    FileWriter* writer = new FileWriter(outputPath);//TODO: Manage name of the output file.

    //TODO: A vector will be a better option.
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

        response = convertUTF8toUnicode(buffer, unicode);

        if (response != ConversionOK)
        {
            break;
        }

        response = unicodeToUTF16(unicode, converted, isTheSameFormat);

        if (response != ConversionOK)
        {
            break;
        }

        writer->write(converted);

        buffer.clear();
        unicode.clear();
        converted.clear();
    }

    delete reader;
    delete writer;
    return response;
}
