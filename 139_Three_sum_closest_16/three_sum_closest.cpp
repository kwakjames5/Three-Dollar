#include "three_sum_closest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// link: https://leetcode.com/problems/3sum-closest/

// date: 7/20/2020

// description: Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
// Return the sum of the three integers. You may assume that each input would have exactly one solution.

int Solution::threeSumClosest(std::vector<int>& nums, int target) {
    int min_diff = INT_MAX;
    int output;
    std::sort(nums.begin(), nums.end());
       
    for(int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k)
        {
            int sum_target_diff = nums[i] + nums[j] + nums[k] - target;
            if(abs(sum_target_diff) < min_diff)
            {
                min_diff = abs(sum_target_diff);
                output = sum_target_diff + target;
            }
                
            if(sum_target_diff < 0)
            {
                j++;
            }
              
            if(sum_target_diff > 0)
            {
                k--;
            }
               
            if(sum_target_diff == 0)
            {
                return target;
            }
        }
    }
        
    return output;
}

int main()
{
	std::vector<int> nums;
	int target, nums_size;
	std::cout << "Enter size of array" << std::endl;
	std::cin >> nums_size;
	int input;
	std::cout << "Enter numbers" << std::endl;
	for(int i = 0; i < nums_size; i++)
	{
		std::cin >> input;
		nums.push_back(input);
	}
    std::cout << "Enter target sum" << std::endl;
    std::cin >> target;
	Solution solution;
	int closest_sum = solution.threeSumClosest(nums, target);
    std::cout << "Closest sum to target: " << closest_sum << std::endl;

    return 0;
}