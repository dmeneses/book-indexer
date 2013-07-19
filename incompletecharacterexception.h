/* 
 * File:   incompletecharacterexception.h
 * Author: Daniela
 *
 * Created on July 19, 2013, 5:41 PM
 */

#ifndef INCOMPLETECHARACTEREXCEPTION_H
#define	INCOMPLETECHARACTEREXCEPTION_H
#include <exception>

class IncompleteCharacterException : public std::exception
{
public:
    IncompleteCharacterException(){};
    IncompleteCharacterException(const IncompleteCharacterException& orig){};

    virtual const char* what() const throw ()
    {
        return "A character is incomplete.";
    }
};

#endif	/* INCOMPLETECHARACTEREXCEPTION_H */

