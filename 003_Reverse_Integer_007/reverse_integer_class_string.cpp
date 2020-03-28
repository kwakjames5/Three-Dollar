#include <iostream>
#include "reverse_integer_class.h"
#include <string>
#include <algorithm>

// 	g++ -g -Wall -std=c++11 name.cpp -o name

Solution::Solution()
{
}

/*
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
*/

std::string Solution::stringReverse(std::string x)
{
	int stringLength = x.size();
	std::string reversedString = x;

	// if there is no negative sign, we can just reverse the string
	if(x[0] != '-')
	{
		for(int i = 0; i < stringLength / 2; i++)
		{
			std::swap(reversedString[i], reversedString[stringLength - i - 1]);
		}
	}

	// if there is a negative sign, we need to accomodate for that and make sure we only swap starting AFTER the - sign
	// to do this, we start at the first index (-123; index[0] = '-', index[1] = '1') and swap normally
	if(x[0] == '-')
	{
		for(int i = 1; i < stringLength / 2; i++)
		{
			std::swap(reversedString[i], reversedString[stringLength - i]);
		}
	}
	

	return reversedString;
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
	std::string originalString = "-123";

	Solution* item = new Solution();
	
	std::string reversedString = item->stringReverse(originalString);
	int reversedInt = item->reverse(originalInt);

	std::cout << "Reverse of " << originalString << " is " << reversedString << " (This is the result of the string method)" <<  std::endl;
	std::cout << "Reverse of " << originalInt << " is " << reversedInt << " (This is the result of the int method)" <<  std::endl;

	return 0;
}