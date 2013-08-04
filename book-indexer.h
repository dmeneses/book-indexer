/* 
 * File:   book-indexer.h
 * Author: Daniela
 *
 * Created on July 24, 2013, 2:27 PM
 */

#ifndef BOOK_INDEXER_H
#define	BOOK_INDEXER_H
#include "converter.h"

ConversionResponse convertUTF8toUTF16(const char* inputPath, const char* outputPath, Endianness type = BE);

#endif	/* BOOK_INDEXER_H */

