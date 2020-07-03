#include "single_number.h"
#include <vector>
#include <iostream>
#include <map>

// link: https://leetcode.com/problems/single-number/

// date: 7/3/2020

// description: Given a non-empty array of integers, 
// every element appears twice except for one. Find that single one.

int Solution::singleNumber(std::vector<int>& nums) 
{
    std::map<int, int> int_count;
    for(int i = 0; i < nums.size(); i++)
    {
        int_count[nums[i]]++;
    }
        
    std::map<int, int>::iterator map_it;
    for(map_it = int_count.begin(); map_it != int_count.end(); map_it++)
    {
        if(map_it->second == 1)
        {
            return map_it->first;
        }
    }
        
    return 0;
}

int main()
{
    std::vector<int> nums;
    std::cout << "Enter vector size" << std::endl;
    int vector_size;
    std::cin >> vector_size;

    std::cout << "Enter elements" << std::endl;
    int input;
    for(int i = 0; i < vector_size; i++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    int single_num = solution.singleNumber(nums);

    std::cout << "Single number: " << single_num << std::endl;

    return 0;
}