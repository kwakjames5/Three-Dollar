#include "xor_in_array.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/xor-operation-in-an-array/

// date: 7/10/2020

// description: Given an integer n and an integer start.
// Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.
// Return the bitwise XOR of all elements of nums.

int Solution::xorOperation(int n, int start) 
{
    std::vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        nums.push_back(start + 2 * i);
    }
    
    int result = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        result = result ^ nums[i];
    }
        
    return result;
}

int main()
{
    int start, n;
    std::cout << "Enter the num you want to start and how many increments you want to go." << std::endl;
    std::cin >> start >> n;

    Solution solution;
    int xor_result = solution.xorOperation(start, n);
    std::cout << "The XOR result of the given array: " << xor_result << std::endl;

    return 0;
}