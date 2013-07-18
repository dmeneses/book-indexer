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
        if (bytesToRead == 0 || i + bytesToRead > input.size())
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
    int i = 7;
    if (!isOn(charHeader, i))
    {
        return 1;
    }

    int res = 0;
    while (isOn(charHeader, i))
    {
        res++;
        i--;
    }

    return res > 1 ? res : 0;
}

int convertCharacter(list<char>& content, int bytesToRead)
{
    char header = content.front();
    content.pop_front();

    if (bytesToRead == 1)
    {
        return header;
    }

    int res = 0;
    header <<= bytesToRead;
    res += (unsigned char) header;
    bytesToRead--;

    while (bytesToRead)
    {
        header = content.front();
        content.pop_front();
        header <<= 2;
        res <<= 6;
        res += (unsigned char) header;
        bytesToRead--;
    }

    res <<= 2l;
}


