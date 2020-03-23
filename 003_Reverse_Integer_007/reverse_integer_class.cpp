#include <iostream>
#include "reverse_integer_class.h"

Solution::Solution()
{
}

int Solution::reverse(int x)
{
	// Integers for storage
	int reverseStore = 0;
	int temp;

	// While loop runs until the program cannot divide by 10 further
	while(x != 0)
	{
		// Store the ones place of the input into temp
		temp = x%10;

		// Update the reverseStore by adding the temp to the ones place and multiplying and shifting up the previous reverseStore by 10
		reverseStore = (reverseStore * 10) + temp;

		// Divides the input x by 10 every time we take one of its digits
		x = x/10;
	}

	return reverseStore;
}

int main()
{
	int originalInt = -123;
	Solution* item = new Solution();
	int reversedInt = item->reverse(originalInt);

	std::cout << "Reverse of " << originalInt << " is " << reversedInt << std::endl;

	return 0;
}