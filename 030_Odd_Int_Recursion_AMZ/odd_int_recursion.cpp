///////////////////////////////////////////////////////////////////////////////////

// Function: Odd Integer Recursion

// Description : Write a function to print odd number from 1 to 100 using recursion

// Date : 04/20/2020

// output: Every odd integer

#include <iostream>

void odd_int_recursion(int x)
{
	if(x > 100)
	{
		return;
	}

	if(x%2 != 0)
	{
		std::cout << x << std::endl;
	}

	odd_int_recursion(x + 1);
}

int main()
{
	int x = 0;

	odd_int_recursion(x);

	return 0;
}