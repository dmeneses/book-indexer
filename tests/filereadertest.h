/*
 * File:   filereadertest.h
 * Author: Daniela
 *
 * Created on Jul 29, 2013, 12:37:33 PM
 */

#ifndef FILEREADERTEST_H
#define	FILEREADERTEST_H
#include "../filereader.h"

#include <cppunit/extensions/HelperMacros.h>

class FileReaderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(FileReaderTest);

    CPPUNIT_TEST(testEndOfAFileWhenEverythingIsRead);
    CPPUNIT_TEST(testReadBuffer100ASCIICharacters);
    CPPUNIT_TEST(testReadBufferIncompleteComplexCharacters);
    CPPUNIT_TEST(testReadBufferIncompleteComplexCharsAndKeepReadingAnotherChars);

    CPPUNIT_TEST_SUITE_END();

public:
    FileReaderTest();
    virtual ~FileReaderTest();
    void setUp();
    void tearDown();

private:   
    void testEndOfAFileWhenEverythingIsRead();
    void testReadBuffer100ASCIICharacters();
    void testReadBufferIncompleteComplexCharacters();
    void testReadBufferIncompleteComplexCharsAndKeepReadingAnotherChars();
    FileReader* fileReader1_;
    FileReader* fileReader2_;
};

#endif	/* FILEREADERTEST_H */

