
#include "converter.h"
#include "book-indexer.h"
#include <list>
using namespace std;

ConversionResponse convertUTF8toUTF16(const char* path, UTF16Type type)
{
    if (!path)
    {
        return FileNotFound;
    }

    FileReader reader(path);
    FileWriter writer(path);
    while (!reader.end())
    {
        list<char> buffer = reader.readBuffer(100);
        list<long> unicode;
        ConversionResponse response = convertUTF8toUnicode(buffer, unicode);

        if (response != ConversionOK)
        {
            return response;
        }

        list<short> converted;
        response = unicodeToUTF16(buffer, converted, type);

        if (response != ConversionOK)
        {
            return response;
        }

        writer.write(converted);
    }

    reader.close;
    writer.close;
    return ConversionOK;
}
