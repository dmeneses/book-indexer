/* 
 * File:   EncodingFormat.h
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:34 PM
 */

#ifndef ENCODINGFORMAT_H
#define	ENCODINGFORMAT_H

class EncodingFormat
{
public:

    EncodingFormat()
    {
    }

    EncodingFormat(int size) : size_(size)
    {
    }
    EncodingFormat(const EncodingFormat& orig);
    virtual ~EncodingFormat();

    int getSize() const
    {
        return size_;
    }

    void setSize(int size)
    {
        this->size_ = size;
    }

private:
    int size_;
};

#endif	/* ENCODINGFORMAT_H */

