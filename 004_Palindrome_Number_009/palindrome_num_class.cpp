#include "palindrome_num_class.h"
#include <iostream>

Solution::Solution()
{
}

bool Solution::isPalindrome(int x)
{
	// Set an integer to hold the original value of x to compare later
	int originalValue = x;

	// Set 0 int to store the reverse of int x
	int store = 0;

	// Use temp to hold digits while the program reverses the number
	int temp;

	// When int x is negative, it will never be a palindrome
	if(x < 0)
	{
		return false;
	}
	else
	{
		// Standard reverse function
		while(x != 0)
		{
			temp = x%10;
			store = (store * 10) + temp;
			x = x/10;
		}

		// Returns respective answers depending on whether the stored value is the same as the original
		if(store == originalValue)
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