#include "array_part_i.h"
#include <vector>
#include <algorithm>
#include <iostream>

// link: https://leetcode.com/problems/array-partition-i/

// date: 7/6/2020

// description: Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

int Solution::arrayPairSum(std::vector<int>& nums) 
{
    int sum = 0;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i = i + 2)
    {
        if(nums[i] < nums[i + 1])
        {
            sum += nums[i];
        }
        else
        {
            sum += nums[i + 1];
        }
    }
        
    return sum;
}

int main()
{
	std::vector<int> nums;
	std::cout << "Enter vector size" << std::endl;
	int vector_size; 
	std::cin >> vector_size;
	std::cout << "Enter integers to sum up " << std::endl;
	int input;
	for(int i = 0; i < vector_size; i++)
	{
		std::cin >> input;
		nums.push_back(input);
	}

	Solution solution;
	int sum = solution.arrayPairSum(nums);

	std::cout << "Sum of minimum of every sorted two integers: " << sum << std::endl;

	return 0;
}