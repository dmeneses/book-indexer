/*
 * File:   convertertest.h
 * Author: Daniela
 *
 * Created on Jul 18, 2013, 11:13:15 AM
 */

#ifndef CONVERTERTEST_H
#define	CONVERTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../converter.h"
#include <list>

class ConverterTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(ConverterTest);

    CPPUNIT_TEST(testConvertCharacterWithOneByte);
    CPPUNIT_TEST(testConvertCharacterWithTwoBytes);
    CPPUNIT_TEST(testConvertCharacterWithThreeBytes);
    CPPUNIT_TEST(testConvertCharacterWithFourBytes);
    CPPUNIT_TEST(testGetBytesToReadLimits);
    CPPUNIT_TEST(testGetBytesToReadWhenCharHasInvalidHeader);
    CPPUNIT_TEST(testGetBytesToReadWhenIsOnlyOneByte);
    CPPUNIT_TEST(testGetBytesToReadWhenIsTwoBytes);
    CPPUNIT_TEST(testGetBytesToReadWhenIsThreeBytes);
    CPPUNIT_TEST(testGetBytesToReadWhenIsFourBytes);
    CPPUNIT_TEST(testConvertUTF8toUnicode);

    CPPUNIT_TEST_SUITE_END();

public:
    ConverterTest();
    virtual ~ConverterTest();
    void setUp();
    void tearDown();

private:
    
    void testConvertCharacterWithOneByte();
    void testConvertCharacterWithTwoBytes();
    void testConvertCharacterWithThreeBytes();
    void testConvertCharacterWithFourBytes();
    void testGetBytesToReadLimits();
    void testGetBytesToReadWhenCharHasInvalidHeader();
    void testGetBytesToReadWhenIsOnlyOneByte();
    void testGetBytesToReadWhenIsTwoBytes();
    void testGetBytesToReadWhenIsThreeBytes();
    void testGetBytesToReadWhenIsFourBytes();
    void testConvertUTF8toUnicode();

};

void validBytesToRead(char toTest, int expectedNumber);
void validateConversion(std::list<char>& content, int expected);

#endif	/* CONVERTERTEST_H */
