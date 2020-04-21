/////////////////////////////////////////////////////

// Function: Bit reverse

// Description : Write a function that swaps the bits in place across in the passed in int and returns the swapped int 

// Date : 04/20/2020

// input: 
// swap(int x, int length)
// 10100111 (passed in arg) 
// swap(167,8)

// output: 
// 11100101 (return value)
// 229

#include <iostream>
#include <cmath>

int swap(int x, int length)
{
	int return_val = 0;

	for(int i = 0; i < length; i++)
	{
		if(x > 0)
		{
			int temp = x%2;
			x = x/2;
			return_val += temp * pow(2, length - i - 1);
		}
	}

	return return_val;
}

int main()
{
	int input = 3;
	int bitLength = 8;

	int swapped = swap(input, bitLength);

	std::cout << swapped << std::endl;

	return 0;
}