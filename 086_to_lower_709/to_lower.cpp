#include "to_lower.h"
#include <iostream>

// link: https://leetcode.com/problems/to-lower-case/

// date: 6/23/2020

// description: given a string, returns a copy that has all lower case letters only

std::string Solution::toLowerCase(std::string str) 
{
    std::string return_string;
    for(int i = 0; i < str.size(); i++)
    {
        if((int)(str[i]) > 64 && (int)(str[i]) < 91)
        {
            return_string += (int)(str[i]) + 32;
        }
        else
        {
            return_string += (int)(str[i]);
        }
    }
     
    return return_string;
}

int main()
{
	std::cout << "Enter string to be lowered: " << std::endl;
	std::string input_string;
	std::cin >> input_string;

	Solution solution;
	std::string result_string = solution.toLowerCase(input_string);

	std::cout << "Result: " << result_string << std::endl;

	return 0;
}