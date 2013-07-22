/*
 * File:   convertertest.cpp
 * Author: Daniela
 *
 * Created on Jul 18, 2013, 11:13:16 AM
 */

#include "utf8convertertest.h"
#include "../incompletecharacterexception.h"

using namespace std;


CPPUNIT_TEST_SUITE_REGISTRATION(UTF8ConverterTest);

UTF8ConverterTest::UTF8ConverterTest()
{
}

UTF8ConverterTest::~UTF8ConverterTest()
{
}

void UTF8ConverterTest::setUp()
{
}

void UTF8ConverterTest::tearDown()
{
}

int convertCharacter(list<char>& content, int bytesToRead);

void UTF8ConverterTest::testConvertCharacterWithOneByte()
{
    //Character A
    list<char> content;
    content.push_back(0x41);
    validateConversion(content, 0x41);
}

void UTF8ConverterTest::testConvertCharacterWithTwoBytes()
{
    //Character ñ
    list<char> content;
    content.push_back(0xC3);
    content.push_back(0xB1);
    validateConversion(content, 0xF1);
}

void UTF8ConverterTest::testConvertCharacterWithThreeBytes()
{
    //Character - (Minus sign)
    list<char> content;
    content.push_back(0xe2);
    content.push_back(0x88);
    content.push_back(0x92);
    validateConversion(content, 0x2212);
}

void UTF8ConverterTest::testConvertCharacterWithFourBytes()
{
    //MATHEMATICAL BOLD CAPITAL A
    list<char> content;
    content.push_back(0xF0);
    content.push_back(0x9D);
    content.push_back(0x90);
    content.push_back(0x80);
    validateConversion(content, 0x1D400);
}

void UTF8ConverterTest::testConvertCharacterWithWrongBytes()
{
    //MATHEMATICAL BOLD CAPITAL A
    list<char> content;
    content.push_back(0xF0);
    content.push_back(0x9D);
    content.push_back(0x01); //Wrong!! must be 0x90. It doesn't have the bit header -10- for the byte.
    content.push_back(0x80);
    CPPUNIT_ASSERT_THROW_MESSAGE("The expected exception was not received", 
                                 convertCharacter(content, content.size()), 
                                 IncompleteCharacterException);
}

void validateConversion(std::list<char>& content, int expected)
{
    int result = convertCharacter(content, content.size());
    CPPUNIT_ASSERT_EQUAL(expected, result);
}

int getBytesToRead(char charHeader);

void UTF8ConverterTest::testGetBytesToReadLimits()
{
    //255 = 11111111 Max 4 bytes to read for UTF-8.
    validBytesToRead(255, 4);
}

void UTF8ConverterTest::testGetBytesToReadWhenCharHasInvalidHeader()
{
    //Invalid header for a UTF8 Character: 10000000
    validBytesToRead(128, 0);
}

void UTF8ConverterTest::testGetBytesToReadWhenIsOnlyOneByte()
{
    //127 = 01111111
    validBytesToRead(127, 1);
}

void UTF8ConverterTest::testGetBytesToReadWhenIsTwoBytes()
{
    //195 = 11000011
    validBytesToRead(195, 2);
}

void UTF8ConverterTest::testGetBytesToReadWhenIsThreeBytes()
{
    //227 = 11100011
    validBytesToRead(227, 3);
}

void UTF8ConverterTest::testGetBytesToReadWhenIsFourBytes()
{
    //247 = 11110111
    validBytesToRead(247, 4);
}

void validBytesToRead(char toTest, int expectedNumber)
{
    int result = getBytesToRead(toTest);
    CPPUNIT_ASSERT_EQUAL(expectedNumber, result);
}

ConversionResponse convertUTF8toUnicode(list<char>& input, list<int>& output);

void UTF8ConverterTest::testConvertUTF8toUnicodeWithThreeCharacters()
{
    list<char> input;
    input.push_back(0xC3);
    input.push_back(0xB1);
    input.push_back(0xE2);
    input.push_back(0x88);
    input.push_back(0x92);
    input.push_back(0x41);

    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    int resultSize = output.size();
    CPPUNIT_ASSERT_EQUAL(3, resultSize);
    CPPUNIT_ASSERT_EQUAL(0xF1, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL(0x2212, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL(0x41, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
}

void UTF8ConverterTest::testConvertUTF8toUnicodeWithWrongCharacterAtTheBegining()
{
    //Putting invalid character 10000000 = 0x80
    list<char> input;
    input.push_back(0x80);
    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    CPPUNIT_ASSERT_EQUAL(WrongUTF8, result);
}

void UTF8ConverterTest::testConvertUTF8toUnicodeWithWrongCharacterInTheMiddle()
{
    //Putting invalid character 10000000 = 0x80
    list<char> input;
    input.push_back(0xC3);
    input.push_back(0xB1);
    input.push_back(0x80);
    input.push_back(0xE2);
    input.push_back(0x88);
    input.push_back(0x92);
    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    int resultSize = output.size();
    CPPUNIT_ASSERT_EQUAL(WrongUTF8, result);
    CPPUNIT_ASSERT_EQUAL(1, resultSize);
    CPPUNIT_ASSERT_EQUAL(0xF1, output.front());
}

void UTF8ConverterTest::testConvertUTF8toUnicodeWithAEmptyInput()
{
    list<char> input;
    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    int resultSize = output.size();
    CPPUNIT_ASSERT_EQUAL(EmptyStream, result);
    CPPUNIT_ASSERT_EQUAL(0, resultSize);
}

void UTF8ConverterTest::testConvertUTF8toUnicodeWithAIncompleteCharacterAtTheBegining()
{
    list<char> input;
    input.push_back(0xC3);
    input.push_back(0xB1);
    input.push_back(0xE2);
    input.push_back(0x41);
    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    int resultSize = output.size();
    CPPUNIT_ASSERT_EQUAL(IncompleteCharater, result);
    CPPUNIT_ASSERT_EQUAL(1, resultSize);
    CPPUNIT_ASSERT_EQUAL(0xF1, output.front());
}

void UTF8ConverterTest::testConvertUTF8toUnicodeWithAIncompleteCharaterAtTheMiddle()
{
    list<char> input;
    input.push_back(0xC3);
    input.push_back(0xE2);
    input.push_back(0x88);
    input.push_back(0x92);
    list<int> output;
    ConversionResponse result = convertUTF8toUnicode(input, output);
    int resultSize = output.size();
    CPPUNIT_ASSERT_EQUAL(IncompleteCharater, result);
    CPPUNIT_ASSERT_EQUAL(0, resultSize);
}

