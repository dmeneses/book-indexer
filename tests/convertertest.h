/*
 * File:   convertertest.h
 * Author: Dann
 *
 * Created on 04-08-2013, 01:22:12 PM
 */

#ifndef CONVERTERTEST_H
#define	CONVERTERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../book-indexer.h"

class convertertest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(convertertest);

    CPPUNIT_TEST(convertAnEmptyFile);
    CPPUNIT_TEST(convertAFileWithContentUTF8BEtoUTF16BE);
    CPPUNIT_TEST(convertAFileWithContentUTF8BEtoUTF16LE);

    CPPUNIT_TEST_SUITE_END();

public:
    convertertest();
    virtual ~convertertest();
    void setUp();
    void tearDown();

private:
    void convertAnEmptyFile();
    void convertAFileWithContentUTF8BEtoUTF16BE();
    void convertAFileWithContentUTF8BEtoUTF16LE();
};

int compareFiles(const char* file1, const char* file2);

#endif	/* CONVERTERTEST_H */

