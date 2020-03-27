#include <iostream>
#include "reverse_integer_class.h"
#include <string>
#include <algorithm>

Solution::Solution()
{
}

std::string Solution::stringReverse(int x)
{
	// convert in x into a string
	// also store the length of the string after we define it
	std::string reversedString = std::to_string(x);
	int stringLength = reversedString.size();

	// if there is no negative sign, we can just reverse the string
	if(x > 0)
	{
		for(int i = 0; i < stringLength / 2; i++)
		{
			std::swap(reversedString[i], reversedString[stringLength - i - 1]);
		}
	}

	// if there is a negative sign, we need to accomodate for that and make sure we only swap starting AFTER the - sign
	// to do this, we start at the first index (-123; index[0] = '-', index[1] = '1') and swap normally
	if(x < 0)
	{
		for(int i = 1; i < stringLength / 2; i++)
		{
			std::swap(reversedString[i], reversedString[stringLength - i]);
		}
	}
	

	return reversedString;
}

int main()
{
	int originalInt = -123;
	Solution* item = new Solution();
	std::string reversedInt = item->stringReverse(originalInt);

	std::cout << "Reverse of " << originalInt << " is " << reversedInt << std::endl;

	return 0;
}