/*
 * File:   convertertest.cpp
 * Author: Dann
 *
 * Created on 04-08-2013, 01:22:13 PM
 */

#include "convertertest.h"
#define FILE_TO_CONVERT "resources/conversiontestUTF8.txt"
#define EMPTY_FILE_TO_CONVERT "resources/emptyFile.txt"
#define FILE_COMPARE_LE "resources/conversiontestUTF16-NPC-LE.txt"
#define FILE_COMPARE_BE "resources/conversiontestUTF16-NPC-BE.txt"
#define OUTPUT_FILE "resources/output.txt"
#define BUFFER_SIZE 500
CPPUNIT_TEST_SUITE_REGISTRATION(convertertest);

convertertest::convertertest()
{
}

convertertest::~convertertest()
{
}

void convertertest::setUp()
{
}

void convertertest::tearDown()
{
    remove(OUTPUT_FILE);
}

void convertertest::convertAnEmptyFile()
{
    ConversionResponse response = convertUTF8toUTF16(EMPTY_FILE_TO_CONVERT, OUTPUT_FILE, BE);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, response);
}

void convertertest::convertAFileWithContentUTF8BEtoUTF16BE()
{
    ConversionResponse response = convertUTF8toUTF16(FILE_TO_CONVERT, OUTPUT_FILE, BE);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, response);
    CPPUNIT_ASSERT(compareFiles(OUTPUT_FILE, FILE_COMPARE_BE));
}

void convertertest::convertAFileWithContentUTF8BEtoUTF16LE()
{
    ConversionResponse response = convertUTF8toUTF16(FILE_TO_CONVERT, OUTPUT_FILE, LE);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, response);
    CPPUNIT_ASSERT(compareFiles(OUTPUT_FILE, FILE_COMPARE_LE));
}

int compareFiles(const char* file1, const char* file2)
{
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    do
    {
        size_t r1 = fread(buf1, 1, BUFFER_SIZE, f1);
        size_t r2 = fread(buf2, 1, BUFFER_SIZE, f2);

        if (r1 != r2 || memcmp(buf1, buf2, r1))
        {
            return 0; // Files are not equal
        }
    }
    while (!feof(f1) && !feof(f2));

    return feof(f1) && feof(f2);
}

