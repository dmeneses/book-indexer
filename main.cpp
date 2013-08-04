/* 
 * File:   main.cpp
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#include <cstdlib>
#include <iostream> // for including cin cout
#include <bitset>
#include "bitmanipulation.h"
#include "converter.h"
#include "book-indexer.h"
#include <string.h>

using namespace std;
#define CONVERSION "Conversion: "
#define INDEXER "Indexer: "
#define MISSING_PARAMENTERS "Missing paramenters. Use -h to check the necessary parameters.\n"
#define INVALID_OPTION "Invalid option. Use -h to check the necessary parameters and available options.\n"
#define CONVERSION_OK "Successful Conversion\n"
#define EMPTY_STREAM "The file is empty.\n"
#define INCOMPLETE_CHARACTERS "Incomplete or malformed character inside the input file.\n"
#define WRONG_UTF8 "The file is not in UTF8 format.\n"
#define FILE_NOT_FOUND "File not found.\n"
#define PRINT cout <<

char** arguments;
int argsCount;

void checkParamenters();
void convertFile();
void printResult(ConversionResponse response);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << MISSING_PARAMENTERS;
        return 0;
    }

    arguments = argv;
    argsCount = argc;
    checkParamenters();
    return 0;
}

void checkParamenters()
{
    if (strlen(arguments[1]) != 2 || arguments[1][0] != '-')
    {
        cout << INVALID_OPTION;
        return;
    }

    char option = arguments[1][1];

    switch (option)
    {
    case 'c': convertFile();
        break;
    default: cout << INVALID_OPTION;
    }
}

void convertFile()
{
    if (argsCount != 5)
    {
        cout << CONVERSION << MISSING_PARAMENTERS;
        return;
    }

    if (strlen(arguments[2]) != 2 || arguments[2][0] != '-')
    {
        cout << CONVERSION << INVALID_OPTION;
        return;
    }

    char option = arguments[2][1];

    switch (option)
    {
    case 'l': printResult(convertUTF8toUTF16(arguments[3], arguments[4], LE));
        break;
    case 'b': printResult(convertUTF8toUTF16(arguments[3], arguments[4], BE));
        break;
    default: cout << CONVERSION << INVALID_OPTION;
    }
}

void printResult(ConversionResponse response)
{
    PRINT CONVERSION;
    switch (response)
    {
    case ConversionOK: PRINT CONVERSION_OK;
        break;
    case EmptyStream: PRINT EMPTY_STREAM;
        break;
    case IncompleteCharater: PRINT INCOMPLETE_CHARACTERS;
        break;
    case WrongUTF8: PRINT WRONG_UTF8;
        break;
    case FileNotFound: PRINT FILE_NOT_FOUND;
        break;
    default: cout << CONVERSION << INVALID_OPTION;
    }
}
