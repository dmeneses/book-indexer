/* 
 * File:   main.cpp
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#include <cstdlib>
#include <iostream> // for including cin cout
#include <bitset>
#include "bitmanipulation.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    //    cout << isOn(128, 6);
    long v = 0x64321;
    long v1 = v - 0x10000;
    long vh = v1 >> 10;
    cout << v1 << endl;
    cout << vh << endl;
    return 0;
}

