#include "bitmanipulation.h"

bool isOn(char byteToTest, int position)
{
    int test = byteToTest & 1 << position;
    return test != 0 ? true : false;
}

char setOn(char byteToChange, int position)
{
    return byteToChange | 1 << position;
}

char setOff(char byteToChange, int position)
{
    return byteToChange & ~(1 << position);
}

char flipState(char byteToFlip, int position)
{
    return byteToFlip ^ 1 << position;
}
