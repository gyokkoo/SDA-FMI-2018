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

	for (size_t i = 0; i < myArray.getLength(); i++)
	{
		myArray[i] = myArray[i] * 10;
	}

	myArray.print();

	std::cout << "\n";

	const DynamicArray& constArray = myArray;
	std::cout << constArray[0] << "\n"; // OK
	// Invalid !
	// constArray[0] = 0;

	try
	{
		myArray.getAt(myArray.getAt(COUNT + 1));
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

    return 0;
}