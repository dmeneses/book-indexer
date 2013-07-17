/* 
 * File:   newClass.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#ifndef NEWCLASS_H
#define	NEWCLASS_H

#include "unicode.h"
#include "utf8.h"

enum ConversionResponse
{
    ConversionOK,
    WrongInput,
    IncompleteCarater,
    WrongUTF8
};

ConversionResponse convertUTF8toUnicode(UTF8& content, Unicode& output);


#endif	/* NEWCLASS_H */

