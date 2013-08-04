/*
 * File:   utf16convertertest.cpp
 * Author: Daniela
 *
 * Created on Jul 22, 2013, 3:48:38 PM
 */

#include "utf16convertertest.h"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(UTF16ConverterTest);
unsigned short flipOrder(unsigned short word);

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
    std::vector<long> input;
    input.push_back(0x10FFFD);
    std::vector<short> output;
    ConversionResponse result = unicodeToUTF16(input, output, false);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(2, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0xDBFF, output.at(0));
    CPPUNIT_ASSERT_EQUAL((short) 0xDFFD, output.at(1));
}

void UTF16ConverterTest::testUnicodeToUTF16ToGetWithoutSurrogatedPair()
{
    //CJK UNIFIED IDEOGRAPH-6C34 (water)
    //UTF16 = 6C34
    std::vector<long> input;
    input.push_back(0x6C34);
    std::vector<short> output;
    ConversionResponse result = unicodeToUTF16(input, output, false);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(1, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0x6C34, output.at(0));
}

void UTF16ConverterTest::testUnicodeToUTF16WithEmptyStream()
{
    std::vector<long> input;
    std::vector<short> output;
    ConversionResponse result = unicodeToUTF16(input, output, false);
    CPPUNIT_ASSERT_EQUAL(EmptyStream, result);
    CPPUNIT_ASSERT_EQUAL(0, (int) output.size());
}

void UTF16ConverterTest::testUnicodeToUTF16ToGetLEOrderWithSurrogatedPair()
{
    //PRIVATE USE CHARACTER-10FFFD (last Unicode code point)	
    //UTF16 = DBFF DFFD
    //UTF16 LITTLE ENDIAN = FDDF DBFF
    std::vector<long> input;
    input.push_back(0x10FFFD);
    std::vector<short> output;
    ConversionResponse result = unicodeToUTF16(input, output, true);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(2, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0xFDDF, output.at(0));
    CPPUNIT_ASSERT_EQUAL((short) 0xFFDB, output.at(1));
}

void UTF16ConverterTest::testUnicodeToUTF16ToGetLEOrderWithoutSurrogatedPair()
{
    //CJK UNIFIED IDEOGRAPH-6C34 (water)
    //UTF16 = 6C34
    //UTF16 = 346C
    std::vector<long> input;
    input.push_back(0x6C34);
    std::vector<short> output;
    ConversionResponse result = unicodeToUTF16(input, output, true);
    CPPUNIT_ASSERT_EQUAL(ConversionOK, result);
    CPPUNIT_ASSERT_EQUAL(1, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((short) 0x346C, output.at(0));
}

void UTF16ConverterTest::testFlipOrder()
{
    int result = flipOrder(0xFFEE);
    CPPUNIT_ASSERT_EQUAL(0xEEFF, result);
}
