/*
 * File:   filewritertest.h
 * Author: Daniela
 *
 * Created on Jul 29, 2013, 2:13:08 PM
 */

#ifndef FILEWRITERTEST_H
#define	FILEWRITERTEST_H
#include "../filewriter.h"
#include <cppunit/extensions/HelperMacros.h>

class FileWriterTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(FileWriterTest);

    CPPUNIT_TEST(testWrite);

    CPPUNIT_TEST_SUITE_END();

public:
    FileWriterTest();
    virtual ~FileWriterTest();
    void setUp();
    void tearDown();

private:
    void testWrite();
    FileWriter* fileWriter_;

};

#endif	/* FILEWRITERTEST_H */

