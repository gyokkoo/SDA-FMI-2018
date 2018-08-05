#include <iostream>
#include "DynamicArray.h"

int main()
{
    DynamicArray myArray;

    const int COUNT = 10;
    for (int i = 0; i < COUNT; i++)
    {
        myArray.add(i);
    }

    myArray.print();

    return 0;
}