/* 
 * File:   newClass.cpp
 * Author: Daniela
 * 
 * Created on July 16, 2013, 5:27 PM
 */

#include "converter.h"
#include "bitmanipulation.h"
#include "incompletecharacterexception.h"
#include <list>

using namespace std;

int getBytesToRead(char charHeader);
int convertCharacter(list<char>& content, int bytesToRead) throw (IncompleteCharacterException);
int getBits(char byte, int sizeToGet);
void convertToUTF16(long unicodeChar, short outputConversion[2], UTF16Type type = BE);
unsigned short flipOrder(unsigned short word);

ConversionResponse convertUTF8toUnicode(list<char> &input, list<long> &output)
{
    if (input.size() == 0)
    {
        return EmptyStream;
    }

    long unicodeChar = 0;
    int bytesToRead = 0;
    while (input.size() > 0)
    {
        bytesToRead = getBytesToRead(input.front());

        if (bytesToRead == 0)
            return WrongUTF8;
        if (bytesToRead > input.size())
            return IncompleteCharater;

        try
        {
            unicodeChar = convertCharacter(input, bytesToRead);
        }
        catch (IncompleteCharacterException)
        {
            return IncompleteCharater;
        }

        output.push_back(unicodeChar);
    }

    return ConversionOK;
}

int getBytesToRead(char charHeader)
{
    if ((charHeader & 240) == 240) // then there will be 4 bytes in this character
        return 4;
    if ((charHeader & 224) == 224) // then there will be 3 bytes in this character
        return 3;
    if ((charHeader & 192) == 192) // then there will be 2 bytes in this character
        return 2;
    if ((charHeader & 128) == 128) // then ERROR, this is a continuation byte!
        return 0;

    return 1;
}

int convertCharacter(list<char>& content, int bytesToRead) throw (IncompleteCharacterException)
{
    unsigned char header = content.front();
    content.pop_front();

    if (bytesToRead == 1)
    {
        return header;
    }

    int res = getBits(header, 7 - bytesToRead);
    bytesToRead--;

    while (bytesToRead)
    {
        header = content.front();
        content.pop_front();

        if (!isOn(header, 7) || isOn(header, 6))
        {
            throw IncompleteCharacterException();
        }

        header = getBits(header, 6);
        res <<= 6;
        res += (unsigned char) header;
        bytesToRead--;
    }

    return res;
}

int getBits(char byte, int sizeToGet)
{
    switch (sizeToGet)
    {
    case 6: return byte & 63;
    case 5: return byte & 31;
    case 4: return byte & 15;
    case 3: return byte & 7;
    default: return 0;
    }
}

ConversionResponse unicodeToUTF16(std::list<long>& input, std::list<short>& output, UTF16Type type)
{
    if (input.size() == 0)
    {
        return EmptyStream;
    }

    unsigned long unicode = 0;
    short* converted = new short[2];
    while (input.size() > 0)
    {
        unicode = input.front();
        convertToUTF16(unicode, converted, type);

        if (type == LE && converted[1])
        {
            short temp = converted[0];
            converted[0] = converted[1];
            converted[1] = temp;
        }

        output.push_back(converted[0]);

        if (converted[1])
            output.push_back(converted[1]);

        input.pop_front();
    }

    delete[] converted;
    return ConversionOK;
}

void convertToUTF16(long unicodeChar, short* outputConversion, UTF16Type type)
{
    if (unicodeChar <= 0xFFFF)
    {
        unsigned short character = type == LE ? flipOrder(unicodeChar) : unicodeChar;
        outputConversion[0] = character;
        outputConversion[1] = 0;
        return;
    }

    unicodeChar -= 0x10000;
    unsigned short hword = unicodeChar >> 10;
    unsigned short lword = unicodeChar & 0x3FF;
    hword += 0xD800;
    lword += 0xDC00;

    if (type == LE)
    {
        hword = flipOrder(hword);
        lword = flipOrder(lword);
    }

    outputConversion[0] = hword;
    outputConversion[1] = lword;
}

unsigned short flipOrder(unsigned short word)
{
    unsigned char hword = word >> 8;
    word <<= 8;
    word += hword;
    return word;
}
