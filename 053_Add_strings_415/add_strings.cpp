#include "add_strings.h"
#include <iostream>
#include <algorithm>

// link: https://leetcode.com/problems/add-strings/

// date: 6/2/2020

// description: takes in two integers as strings. without using any immediate convertors like stoi or to_string(), add the two integers and return the sum as a string

std::string Solution::addStrings(std::string num1, std::string num2) 
{
    std::string output;
    int num1_track = num1.length() - 1;
    int num2_track = num2.length() - 1;
    int carry = 0;
        
    while(num1_track >= 0 || num2_track >= 0)
    {
        int sum = carry;
        if(num1_track >= 0)
        {
            sum += num1.at(num1_track) - '0';
            num1_track--;
        }
        if(num2_track >= 0)
        {
            sum += num2.at(num2_track) - '0';
            num2_track--;
        }
        output.push_back(sum%10 + '0');
        
        carry = sum/10;
    }
   
    if(carry != 0)
    {
        output.push_back(carry + '0');
    }
    
    reverse(output.begin(), output.end());
    return output;
}

int main()
{
	std::string input1, input2;

	std::cout << "Enter numbers to be added" << std::endl;
	std::cin >> input1 >> input2;

	Solution solution;
	std::string output = solution.addStrings(input1, input2);

	std::cout << "Sum: " << output << std::endl;

	return 0;
}
