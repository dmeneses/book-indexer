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

ConversionResponse convertUTF8toUnicode(std::list<char>& content, std::list<long>& output);


#endif	/* NEWCLASS_H */

