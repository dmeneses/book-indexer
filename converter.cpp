/* 
 * File:   newClass.cpp
 * Author: Daniela
 * 
 * Created on July 16, 2013, 5:27 PM
 */

#include "converter.h"
#include "bitmanipulation.h"
#include <list>

using namespace std;

int getBytesToRead(char charHeader);
int convertCharacter(list<char>& content, int bytesToRead);
int getBits(char byte, int sizeToGet);

ConversionResponse convertUTF8toUnicode(list<char> &input, list<int> &output)
{
    if (input.size() == 0)
    {
        return WrongInput;
    }

    int unicodeChar = 0;
    int bytesToRead = 0;
    int i = 0;
    while (input.size() > 0)
    {
        bytesToRead = getBytesToRead(input.front());
        if (bytesToRead == 0 || bytesToRead > input.size())
        {
            return WrongUTF8;
        }

        unicodeChar = convertCharacter(input, bytesToRead);
        output.push_back(unicodeChar);
        i += bytesToRead;
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

int convertCharacter(list<char>& content, int bytesToRead)
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


