#include "summary_range.h"
#include <iostream>
#include <vector>
#include <string>

// link: https://leetcode.com/problems/summary-ranges/

// date: 7/3/2020

// description: Given a sorted integer array without duplicates, 
// return the summary of its ranges.

std::vector<std::string> Solution::summaryRanges(std::vector<int>& nums) 
{
    std::vector<std::string> res;
    int i = 0;
    while(i < nums.size())
    {
        int curr = i;
        int curr_check = curr + 1;
        while(curr_check < nums.size() && nums[curr_check - 1] == nums[curr_check] - 1)
        {
            curr_check++;
        }
        if(curr_check - 1 == curr)
        {
            res.push_back(std::to_string(nums[curr]));
        }
        else
        {
            std::string temp;
            temp += (std::to_string(nums[curr]) + "->" + std::to_string(nums[curr_check - 1]));
            res.push_back(temp);
        }
            
            
        i = curr_check;
    }
        
        
    return res;
}

int main()
{
    std::vector<int> nums;
    std::cout << "Enter array size: " << std::endl;
    int arr_size = 0;
    std::cin >> arr_size;
    std::cout << "Enter elements" << std::endl;
    int input;
    for(int j = 0; j < arr_size; j++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    std::vector<std::string> summary = solution.summaryRanges(nums);

    std::cout << "Summary: ";
    for(int i = 0; i < summary.size(); i++)
    {
        std::cout << summary[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}