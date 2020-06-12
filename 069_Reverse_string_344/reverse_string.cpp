#include "reverse_string.h"
#include <iostream>
#include <vector>
#include <string>

void Solution::reverseString(std::vector<char>& s) 
{
    for(int i = 0; i < s.size()/2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}

int main()
{
	std::vector<char> string_vector;

	std::string input;

	std::cout << "Enter string: " << std::endl;
	std::cin >> input;

	for(int i = 0; i < input.length(); i++)
	{
		string_vector.push_back(input[i]);
	}

	Solution solution;
	solution.reverseString(string_vector);

	std::cout << "Reversed string:" << std::endl;
	for(int j = 0; j < string_vector.size(); j++)
	{
		std::cout << string_vector[j];
	}

	return 0;
}