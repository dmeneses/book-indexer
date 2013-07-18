/* 
 * File:   main.cpp
 * Author: Daniela
 *
 * Created on July 16, 2013, 5:27 PM
 */

#include <cstdlib>
#include <iostream> // for including cin cout
#include <bitset>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    char a = 195;
    char b = 177;
    bitset<8> ax(a);
    cout << 195 << " Which is: " << ax << std::endl;
    bitset<8> bx(b);
    cout << 177 << " Which is: " << bx << std::endl;


    a <<= 2;
    bitset<8> ax1(a);
    cout << "Left shift a: " << ax1 << std::endl;

    b <<= 2;
    bitset<8> bx1(b);
    cout << "Left shift b: " << bx1 << std::endl;

    int d = 0;
    d = (unsigned char) a;
    bitset<32> dx(d);
    cout << dx << std::endl;

    d <<= 6;
    bitset<32> dx1(d);
    cout << "Left shift d: " << dx1 << std::endl;

    d += (unsigned char) b;
    bitset<32> dx2(d);
    cout << "Left shift d: " << dx2 << std::endl;

    return 0;
}

