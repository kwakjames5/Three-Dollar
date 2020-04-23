///////////////////////////////////////////////////////////////////////////////////

// Function: Change Hexa

// Description : Given a hexa value, changes it

// Date : 04/22/2020

// input: Input = 0x12345678

// output: Output = 0x56781234

#include <iostream>
#include <iomanip> // This might be necessary
#include <bitset>

/*
int main()
{
	int x = 255;
  	for (int i=0; i<256; i++)
  	{
    	std::cout << std::dec << i ;
    	std::cout << std::hex << "=>  0x" << i << std::endl;
  	}
  	int a = 167;
  	std::bitset<8> yy(a);
  	std::cout << "0x" << a << "  bin => " << yy << '\n';

  	return 0;
}
*/

/*
NOTES:
	- when you compare with bitwise operators (&, ^, /), you need to consider the position of the bits
	- for example, given a binary number of 11110000, if i wanted to use a bitwise operator to modify of access
	the 1's, i would need to shift the binary number over 4 times and compare it to 1111 or something

	- in this program specifically, since we are dealing with the numbers in hexa values, we need to consider
	that each number after the 0x in a hexa value is 4 bits
	- thus, when we apply the last tip of having to shift binary numbers, when dealing with numbers in terms of hexa,
	you must shift over the number in multiples of 4 bits for each number or letter you want to shift in the hexa value
	- for example, given 0x12345678, if you want to shift it over so you get 0x1234, you would have to do (0x12345678 >> 16 [4 * 4]) = 0x1234
*/

int swap(int x)
{
	//std::cout << std::hex << (x >> 16) << std::endl;
	
	// x & 0x5678 = 0x5678
	// (x & 0x5678) << 16 = 0x56780000

	// (x >> 16) & 0x1234 =     0x1234
	// (x >> 16 & 0x1234) >> 4 = 0x123;

	// use or 
	// using bitwise or basically returns a combined version of 0x56780000 and 0x1234
	// since 5678 and 1234 are the values that are will satisfy this or operator
	// return this combined value

	

	return ((x & 0x5678) << 16) | ((x >> 16) & 0x1234);
}

int main()
{
	int x = 305419896; // decimal value of 0x1234 5678

	std::cout << std::hex << x << std::endl;

	int swapped_x = swap(x);

	std::cout << "0x" << std::hex << swapped_x << std::endl;
}