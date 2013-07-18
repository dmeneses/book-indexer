/*
 * File:   convertertest.cpp
 * Author: Daniela
 *
 * Created on Jul 18, 2013, 11:13:16 AM
 */

#include "convertertest.h"

using namespace std;


CPPUNIT_TEST_SUITE_REGISTRATION(ConverterTest);

ConverterTest::ConverterTest()
{
}

ConverterTest::~ConverterTest()
{
}

void ConverterTest::setUp()
{
}

void ConverterTest::tearDown()
{
}

int convertCharacter(list<char>& content, int bytesToRead);

void ConverterTest::testConvertCharacterWithOneByte()
{
    //Character A
    list<char> content;
    content.push_back(0x41);
    validateConversion(content, 0x41);
}

void ConverterTest::testConvertCharacterWithTwoBytes()
{
    //Character ñ
    list<char> content;
    content.push_back(0xC3);
    content.push_back(0xB1);
    validateConversion(content, 0xF1);
}

void ConverterTest::testConvertCharacterWithThreeBytes()
{
    //Character - (Minus sign)
    list<char> content;
    content.push_back(0xe2);
    content.push_back(0x88);
    content.push_back(0x92);
    validateConversion(content, 0x2212);
}

void validateConversion(std::list<char>& content, int expected)
{
    int result = convertCharacter(content, content.size());
    CPPUNIT_ASSERT_EQUAL(expected, result);
}

int getBytesToRead(char charHeader);

void ConverterTest::testGetBytesToReadWhenIsOnlyOneByte()
{
    //127 = 01111111
    validBytesToRead(127, 1);
}

void ConverterTest::testGetBytesToReadWhenIsTwoBytes()
{
    //195 = 11000011
    validBytesToRead(195, 2);
}

void ConverterTest::testGetBytesToReadWhenIsThreeBytes()
{
    //227 = 11100011
    validBytesToRead(227, 3);
}

void validBytesToRead(char toTest, int expectedNumber)
{
    int result = getBytesToRead(toTest);
    CPPUNIT_ASSERT_EQUAL(expectedNumber, result);
}

