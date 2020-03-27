#include "palindrome_num_class.h"
#include <iostream>
#include <string>
#include <algorithm>

Solution::Solution()
{
}

bool Solution::isPalindrome(int x)
{
	std::string stringStore = std::to_string(x);
	std::string reversedString = std::to_string(x);
	int stringLength = reversedString.size();

	// When int x is negative, it will never be a palindrome
	if(x < 0)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < stringLength / 2; i++)
		{
			std::swap(reversedString[i], reversedString[stringLength - i - 1]);
		}

		// Returns respective answers depending on whether the stored value is the same as the original
		if(reversedString == stringStore)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	int num = -1456;
	Solution* item = new Solution();

	std::cout << "INPUT: " << num << std::endl;
	std::cout << "OUTPUT: Is not a palindrome" << std::endl;

	if(item->isPalindrome(num))
	{
		std::cout << "Is a palindrome" << std::endl;
	}
	else
	{
		std::cout << "Is not a palindrome" << std::endl;
	}

	return 0;
}	