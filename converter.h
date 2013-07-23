/* 
 * File:   newClass.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#ifndef NEWCLASS_H
#define	NEWCLASS_H
#include <list>

enum ConversionResponse
{
    ConversionOK,
    EmptyStream,
    IncompleteCharater,
    WrongUTF8
};

enum UTF16Type
{
    BE,
    LE
};

ConversionResponse convertUTF8toUnicode(std::list<char>& input, std::list<long>& output);
ConversionResponse unicodeToUTF16(std::list<long>& input, std::list<short>& output, UTF16Type type = BE);

#endif	/* NEWCLASS_H */

