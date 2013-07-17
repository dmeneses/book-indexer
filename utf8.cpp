/* 
 * File:   utf8.cpp
 * Author: Daniela
 * 
 * Created on July 16, 2013, 5:36 PM
 */

#include <stdlib.h>

#include "utf8.h"

UTF8::UTF8(const UTF8& orig)
{
}

UTF8::~UTF8()
{
    if (content_)
    {
        delete[] content_;
        content_ = 0;
    }
}

