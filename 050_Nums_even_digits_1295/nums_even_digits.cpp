#include "nums_even_digits.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// date: 5/27/2020

// description: given an inputted vector of integers, returns the total number of integers with an even number of digits

int Solution::findNumbers(std::vector<int>& nums) 
{
    int count = 0;
        
    //iterate through the nums vector
    for(int i = 0; i < nums.size(); i++)
    {
        // change each int into a string to easily check if its length is even or odd
        if(std::to_string(nums[i]).length()%2 == 0)
        {
            // update count for evens
            count++;
        }
    }
        
    return count;
}

int main()
{
    std::vector<int> nums;
    int input;
    int flag = 0;

    std::cout << "Enter numbers (Enter 0 when you want to stop): " << std::endl;
    
    while(flag == 0)
    {
        std::cin >> input;

        if(input == 0)
        {
            flag = 1;
            break;
        }

        nums.push_back(input);
    }

    Solution solution;
    int even_count = solution.findNumbers(nums);

    std::cout << "Even count: " << even_count << std::endl;

    return 0;
}