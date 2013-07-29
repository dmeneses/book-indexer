/*
 * File:   filereadertest.cpp
 * Author: Daniela
 *
 * Created on Jul 29, 2013, 12:37:34 PM
 */

#include "filereadertest.h"
#include <list>
#define TEST_FILE1 "resources/filereadertest"
#define TEST_FILE2 "resources/filereadertest2"

CPPUNIT_TEST_SUITE_REGISTRATION(FileReaderTest);

FileReaderTest::FileReaderTest()
{

}

FileReaderTest::~FileReaderTest()
{
}

void FileReaderTest::setUp()
{
    fileReader1_ = FileReader::buildFileReader(TEST_FILE1, UTF8);
    fileReader2_ = FileReader::buildFileReader(TEST_FILE2, UTF8);
}

void FileReaderTest::tearDown()
{
    delete fileReader1_;
    delete fileReader2_;
}

void FileReaderTest::testEndOfAFileWhenEverythingIsRead()
{
    int size = 350;
    bool checkCompleteChars = true;
    std::list<char> output;
    int result = fileReader1_->readBuffer(size, checkCompleteChars, output);
    CPPUNIT_ASSERT_EQUAL(322, result);
    CPPUNIT_ASSERT_EQUAL(true, fileReader1_->end());
    CPPUNIT_ASSERT_EQUAL(322, (int) output.size());
}

void FileReaderTest::testReadBuffer100ASCIICharacters()
{
    int size = 100;
    bool checkCompleteChars = true;
    std::list<char> output;
    int result = fileReader1_->readBuffer(size, checkCompleteChars, output);
    CPPUNIT_ASSERT_EQUAL(100, result);
    CPPUNIT_ASSERT_EQUAL(false, fileReader1_->end());
    CPPUNIT_ASSERT_EQUAL(100, (int) output.size());
}

void FileReaderTest::testReadBufferIncompleteComplexCharacters()
{
    int size = 17;
    bool checkCompleteChars = true;
    std::list<char> output;
    int result = fileReader2_->readBuffer(size, checkCompleteChars, output);
    CPPUNIT_ASSERT_EQUAL(15, result);
    CPPUNIT_ASSERT_EQUAL(false, fileReader2_->end());
    CPPUNIT_ASSERT_EQUAL(15, (int) output.size());
}

void FileReaderTest::testReadBufferIncompleteComplexCharsAndKeepReadingAnotherChars()
{
    int size = 17;
    bool checkCompleteChars = true;
    std::list<char> output;
    int result = fileReader2_->readBuffer(size, checkCompleteChars, output);
    CPPUNIT_ASSERT_EQUAL(15, result);
    CPPUNIT_ASSERT_EQUAL(false, fileReader2_->end());
    CPPUNIT_ASSERT_EQUAL(15, (int) output.size());

    size = 3;
    output.clear();
    result = fileReader2_->readBuffer(size, checkCompleteChars, output);
    CPPUNIT_ASSERT_EQUAL(2, result);
    CPPUNIT_ASSERT_EQUAL(false, fileReader2_->end());
    CPPUNIT_ASSERT_EQUAL(2, (int) output.size());
    CPPUNIT_ASSERT_EQUAL((char)0xD7, output.front());
    output.pop_front();
    CPPUNIT_ASSERT_EQUAL((char)0x95, output.front());
    output.pop_front();
}

