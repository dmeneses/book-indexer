/*
 * File:   filewritertest.cpp
 * Author: Daniela
 *
 * Created on Jul 29, 2013, 2:13:09 PM
 */

#include "filewritertest.h"
#include <fstream>

CPPUNIT_TEST_SUITE_REGISTRATION(FileWriterTest);
#define WRITER_TEST_FILE "testwriter1"

FileWriterTest::FileWriterTest()
{
}

FileWriterTest::~FileWriterTest()
{
}

void FileWriterTest::setUp()
{
    fileWriter_ = new FileWriter(WRITER_TEST_FILE);
}

void FileWriterTest::tearDown()
{
    remove(WRITER_TEST_FILE);
    delete fileWriter_;
}

void FileWriterTest::testWrite()
{
    short originalData[] = {10, 20, 30, 40, 50};
    std::list<short> data(originalData, originalData + sizeof (originalData) / sizeof (int));
    bool result = fileWriter_->write(data);
    fileWriter_->close();
    
    if (result)
    {
        short readNum = 0;
        int index = 0;
        std::ifstream fileToValidate(WRITER_TEST_FILE, std::ifstream::binary);
        while (fileToValidate.read((char *) &readNum, sizeof (short)))
        {
            CPPUNIT_ASSERT_EQUAL(originalData[index], readNum);
            index++;
        }
        fileToValidate.close();
    }
}

