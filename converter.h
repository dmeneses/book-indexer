/* 
 * File:   newClass.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#ifndef NEWCLASS_H
#define	NEWCLASS_H
#include <vector>

enum ConversionResponse
{
    ConversionOK,
    EmptyStream,
    IncompleteCharater,
    WrongUTF8,
    FileNotFound
};

enum Endianness
{
    BE,
    LE
};

ConversionResponse convertUTF8toUnicode(std::vector<char>& input, std::vector<long>& output);
ConversionResponse unicodeToUTF16(std::vector<long>& input, std::vector<short>& output, bool changeByteOrder);

#endif	/* NEWCLASS_H */

