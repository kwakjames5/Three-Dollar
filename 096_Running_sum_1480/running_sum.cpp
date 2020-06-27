#include "running_sum.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/running-sum-of-1d-array/

// date: 6/26/2020

// description: for each in in the vector, return another vector in which each of its elements is a summation of all elements in the original
// vector from 0 to n - 1

std::vector<int> Solution::runningSum(std::vector<int>& nums) 
{
    int curr_num = 0;
    std::vector<int> return_vector;
    for(int i = 0; i < nums.size(); i++)
    {
        curr_num += nums[i];
        return_vector.push_back(curr_num);
    }
        
    return return_vector;
}

int main()
{
	std::cout << "How many integers?" << std::endl;
	int int_count = 0;
	std::cin >> int_count;

	int temp;

	std::vector<int> nums;
	std::cout << "Enter integers to be summed: " << std::endl;
	for(int i = 0; i < int_count; i++)
	{
		std::cin >> temp;
		nums.push_back(temp);
	}

	Solution solution;
	std::vector<int> running_sum = solution.runningSum(nums);

	std::cout << "Resulting list: " << std::endl;
	for(int j = 0; j < running_sum.size(); j++)
	{
		std::cout << running_sum[j] << " ";
	}
	std::cout << std::endl;

	return 0;
}