/*
 * File:   utf16convertertest.cpp
 * Author: Daniela
 *
 * Created on Jul 22, 2013, 3:48:38 PM
 */

#include "utf16convertertest.h"
#include "converter.h"
#include <iostream>


CPPUNIT_TEST_SUITE_REGISTRATION(UTF16ConverterTest);

UTF16ConverterTest::UTF16ConverterTest()
{
}

UTF16ConverterTest::~UTF16ConverterTest()
{
}

void UTF16ConverterTest::setUp()
{
}

void UTF16ConverterTest::tearDown()
{

}

void UTF16ConverterTest::testUnicodeToUTF16ToGetWithSurrogatedPair()
{
    //PRIVATE USE CHARACTER-10FFFD (last Unicode code point)	
    //UTF16 = DBFF DFFD
    std::list<long> input;
    input.push_back(0x10FFFD);
    std::list<short> output;
    ConversionResponse result = unicodeToUTF16(input, output);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(2, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0xDBFF, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL((short) 0xDFFD, output.front());
    output.pop_front();
}

void UTF16ConverterTest::testUnicodeToUTF16ToGetWithoutSurrogatedPair()
{
    //CJK UNIFIED IDEOGRAPH-6C34 (water)
    //UTF16 = 6C34
    std::list<long> input;
    input.push_back(0x6C34);
    std::list<short> output;
    ConversionResponse result = unicodeToUTF16(input, output);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(1, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0x6C34, output.front());
    output.pop_front();
}

void UTF16ConverterTest::testUnicodeToUTF16WithEmptyStream()
{
    std::list<long> input;
    std::list<short> output;
    ConversionResponse result = unicodeToUTF16(input, output);
    CPPUNIT_ASSERT_EQUAL(EmptyStream, result);
    CPPUNIT_ASSERT_EQUAL(0, (int) output.size());
}

void UTF16ConverterTest::testUnicodeToUTF16ToGetLEOrder()
{
    std::list<long> input;
    input.push_back(0x10FFFD);
    std::list<short> output;
    ConversionResponse result = unicodeToUTF16(input, output);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(2, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0xFFDB, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL((short) 0xFDDF, output.front());
    output.pop_front();
}
