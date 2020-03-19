///////////////////////////////////////////////////////////////////////////////////

// Function: Longest Common Prefix

// Description : Finds the longest common prefix of strings given in an array. Returns "" if there is no common prefix.

// Date : 03/18/2020

// input: ["flower","flow","flight"]

// output: "fl"

#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) 
{
	std::string outputString = "";
	int letterIndex = 0;

	for(int i = 0; i < strs[0].size(); i++)
	{
		for(int j = 1; j < strs.size(); j++)
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
}

int main()
{
	std::vector<std::string> inputArray;
	inputArray.push_back("flower");
	inputArray.push_back("flow");
	inputArray.push_back("flight");

	std::string prefix = longestCommonPrefix(inputArray);

	std::cout << "Input: [flower, flow, flight]" << std::endl;
	std::cout << "Expected output: fl" << std::endl;

	std::cout << "Output: " <<  prefix << std::endl;

	return 0;
}