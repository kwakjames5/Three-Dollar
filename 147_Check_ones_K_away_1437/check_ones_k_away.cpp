#include "check_ones_k_away.h"
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

// link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

// date: 7/24/2020

// description: Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

bool Solution::kLengthApart(std::vector<int>& nums, int k) {
    int min_distance = INT_MAX;
    int last_one_pos = -1;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            if(last_one_pos != -1)
            {
                min_distance = std::min(min_distance, i - last_one_pos - 1);
            }
            last_one_pos = i;
        }
    }

    return k <= min_distance;
}

int main()
{
    std::cout << "Enter size of vector: " << std::endl;
    int vector_size = 0;
    std::cin >> vector_size;
    std::vector<int> nums;
    std::cout << "Enter 0's and 1's ONLY" << std::endl;
    int temp;
    for(int i = 0; i < vector_size; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::cout << "Minimum distance that must be kept between 1s?" << std::endl;
    int k;
    std::cin >> k;

    Solution solution;
    bool k_apart = solution.kLengthApart(nums, k);
    if(k_apart)
    {
        std::cout << "The '1's were all at least " << k << " apart!" << std::endl;
    }
    else
    {
        std::cout << "The '1's were all not at least " << k << " apart." << std::endl;
    }

    return 0;
}