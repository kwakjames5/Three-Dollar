#include "pow_of_two.h"
#include <iostream>

// date: 7/15/2020

// description: given a input, determine if this input is a power of two or not

bool Solution::isPowOfTwo(int num)
{
	if(num <= 1)
	{
		return false;
	}

	while(num > 1)
	{
		if(num % 2 != 0)
		{
			return false;
		}

		num /= 2;
	}

	return true;
}

int main()
{
	std::cout << "Enter number to check" << std::endl;
	int input = 0;
	std::cin >> input;
	Solution solution;
	bool is_pow_of_two = solution.isPowOfTwo(input);

	if(is_pow_of_two)
	{
		std::cout << input << " is a power of two. " << std::endl;
	}
	else
	{
		std::cout << input << " is not a power of two. " << std::endl;
	}

	return 0;
}