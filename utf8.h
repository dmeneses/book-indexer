/* 
 * File:   utf8.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:36 PM
 */

#ifndef UTF8_H
#define	UTF8_H

#include "encodingformat.h"

class UTF8 : public EncodingFormat
{
public:

    UTF8() : EncodingFormat(0)
    {
        content_ = 0;
    }

    UTF8(int size) : EncodingFormat(size)
    {
        content_ = new char*[size];
    }
    UTF8(const UTF8& orig);
    virtual ~UTF8();

    char** getContent() const
    {
        return content_;
    }

    void setContent(char** content)
    {
        this->content_ = content;
    }

private:
    char** content_;
};

#endif	/* UTF8_H */

