
#include "converter.h"
#include "book-indexer.h"
#include "filereader.h"
#include "filewriter.h"
#include <list>
#define READ_SIZE 100

using namespace std;

const char* concat(const char* string1, const char* string2);

ConversionResponse convertUTF8toUTF16(const char* path, UTF16Type type)
{
    FileReader* reader = FileReader::buildFileReader(path, UTF8);
    if (!reader) return FileNotFound;
    FileWriter* writer = new FileWriter(concat(path, "UTF16"));

    list<char> buffer;
    list<long> unicode;
    list<short> converted;

    while (!reader->end())
    {
        int readBytes = reader->readBuffer(READ_SIZE, true, buffer);
        if (readBytes > 0)
        {
            ConversionResponse response = convertUTF8toUnicode(buffer, unicode);

            if (response != ConversionOK)
            {
                return response;
            }

            response = unicodeToUTF16(unicode, converted, type);

            if (response != ConversionOK)
            {
                return response;
            }

            writer->write(converted);
        }

        buffer.clear();
        unicode.clear();
        converted.clear();
    }

    delete reader;
    delete writer;
    return ConversionOK;
}

const char* concat(const char* string1, const char* string2)
{
    string res(string1);
    res.append(string2);
    return res.c_str();
}
