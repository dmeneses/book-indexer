/*
 * File:   utf16convertertest.h
 * Author: Daniela
 *
 * Created on Jul 22, 2013, 3:48:38 PM
 */

#ifndef UTF16CONVERTERTEST_H
#define	UTF16CONVERTERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class UTF16ConverterTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(UTF16ConverterTest);

    CPPUNIT_TEST(testUnicodeToUTF16ToGetWithSurrogatedPair);
    CPPUNIT_TEST(testUnicodeToUTF16ToGetWithoutSurrogatedPair);
    CPPUNIT_TEST(testUnicodeToUTF16WithEmptyStream);

    CPPUNIT_TEST_SUITE_END();

public:
    UTF16ConverterTest();
    virtual ~UTF16ConverterTest();
    void setUp();
    void tearDown();

private:
    void testUnicodeToUTF16ToGetWithSurrogatedPair();
    void testUnicodeToUTF16ToGetWithoutSurrogatedPair();   
    void testUnicodeToUTF16WithEmptyStream();   
};

#endif	/* UTF16CONVERTERTEST_H */
