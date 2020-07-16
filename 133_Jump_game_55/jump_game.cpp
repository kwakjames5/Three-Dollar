#include "jump_game.h"
#include <iostream>
#include <vector>
#include <algorithm>

// link: https://leetcode.com/problems/jump-game/

// date: 7/15/2020

// description: Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

bool Solution::canJump(std::vector<int>& nums) {
    int vector_size = nums.size();
    int max_index = 0;
    for(int i = 0; i < vector_size; i++)
    {
        if(max_index < i)
        {
            return false;
        }
        int curr_index = i + nums[i];
        max_index = std::max(curr_index, max_index);
    }
        
    return true;
}

int main()
{
    std::vector<int> nums;
    int size;
    std::cout << "Enter size of array" << std::endl;
    std::cin >> size;
    int input;
    std::cout << "Enter the jump amount per index" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    bool can_jump = solution.canJump(nums);

    if(can_jump)
    {
        std::cout << "You are able to jump to the end given the array" << std::endl;
    }
    else
    {
        std::cout << "You cannot jump to the end!" << std::endl;
    }

    return 0;
}