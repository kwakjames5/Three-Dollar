#include "num_good_pairs.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/number-of-good-pairs/

// date: 7/13/2020

// description: Given an array of integers nums.
// A pair (i,j) is called good if nums[i] == nums[j] and i < j.
// Return the number of good pairs.

int Solution::numIdenticalPairs(std::vector<int>& nums) {
    int total_good_pairs = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] == nums[j])
            {
                total_good_pairs++;
            }
        }
    }
        
    return total_good_pairs;
}

int main()
{
    std::vector<int> nums;
    int nums_size;
    std::cout << "How many numbers?" << std::endl;
    std::cin >> nums_size;
    std::cout << "Enter numbers" << std::endl;
    int input;
    for(int i = 0; i < nums_size; i++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    int num_identical_pairs = solution.numIdenticalPairs(nums);
    std::cout << "Total number of identical pairs: " << num_identical_pairs << std::endl;

    return 0;
} 