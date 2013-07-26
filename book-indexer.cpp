
#include "converter.h"
#include "book-indexer.h"
#include "filereader.h"
#include "filewriter.h"
#include <list>
using namespace std;

ConversionResponse convertUTF8toUTF16(const char* path, UTF16Type type)
{
    if (!path)
    {
        return FileNotFound;
    }

    FileReader reader(path, UTF8);
    FileWriter writer(path);
    while (!reader.end())
    {
        list<char> buffer;
        int readBytes = reader.readBuffer(100, true, buffer);
        if (readBytes > 0)
        {
            list<long> unicode;
            ConversionResponse response = convertUTF8toUnicode(buffer, unicode);

            if (response != ConversionOK)
            {
                return response;
            }

            list<short> converted;
            response = unicodeToUTF16(unicode, converted, type);

            if (response != ConversionOK)
            {
                return response;
            }

            writer.write(converted);
        }
    }

    reader.close();
    writer.close();
    return ConversionOK;
}
