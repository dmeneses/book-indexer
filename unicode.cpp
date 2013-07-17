/* 
 * File:   unicode.cpp
 * Author: Daniela
 * 
 * Created on July 16, 2013, 5:37 PM
 */

#include "unicode.h"

Unicode::Unicode(const Unicode& orig)
{
}

Unicode::~Unicode()
{
    if (content_)
    {
        delete[] content_;
        content_ = 0;
    }
}

