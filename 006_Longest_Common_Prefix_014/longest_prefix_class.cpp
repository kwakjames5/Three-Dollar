#include "longest_prefix_class.h"
#include <iostream>
#include <algorithm>

Solution::Solution()
{
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
	std::string outputString = "";
	int letterIndex = 0;
	int size = strs.size();

	// Sorts alphabetically
	std::sort(strs.begin(), strs.begin() + size);
	
	for(int i = 0; i < strs[0].size(); i++)
	{
		if(strs[0][0] != strs[size - 1][0])
		{
			outputString = "No common prefixes available";
			return outputString;
		}

		if(strs[0][i] != strs[size - 1][i])
		{
			return outputString;
		}
		else if(strs[0][i] == strs[size - 1][i])
		{
			outputString.push_back(strs[0][i]);
		}
	}

	/*
	for(int i = 0; i < strs[0].size(); i++)
	{
		for(int j = 1; j < size; j++)
		{
			if(i == 0 && strs[j][i] != strs[j - 1][i])
			{
				outputString = "No common prefixes available";
				return outputString;
			}

			if(strs[j][i] != strs[j - 1][i])
			{
				return outputString;
			}
			else if(j == strs.size() - 1)
			{
				outputString.push_back(strs[0][i]);
			}
		}
	}
	*/
}

int main()
{
	std::vector<std::string> inputArray;
	inputArray.push_back("flower");
	inputArray.push_back("flow");
	inputArray.push_back("flight");

	Solution* item = new Solution();

	std::string prefix = item->longestCommonPrefix(inputArray);

	std::cout << "Input: [flower, flow, flight]" << std::endl;
	std::cout << "Expected output: fl" << std::endl;

	std::cout << "Output: " <<  prefix << std::endl;

	return 0;
}