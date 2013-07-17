/* 
 * File:   unicode.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:37 PM
 */

#ifndef UNICODE_H
#define	UNICODE_H

#include "encodingformat.h"

class Unicode : public EncodingFormat
{
public:

    Unicode() : EncodingFormat(0)
    {
        content_ = 0;
    }

    Unicode(int size) : EncodingFormat(size)
    {
        content_ = new long*[size];
    }
    Unicode(const Unicode& orig);
    virtual ~Unicode();

    long** getContent_() const
    {
        return content_;
    }

    void setContent_(long** content_)
    {
        this->content_ = content_;
    }

private:
    long** content_;
};

#endif	/* UNICODE_H */

