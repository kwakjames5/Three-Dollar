#include "rem_dup_sorted_arr_ii.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// date: 7/14/2020

// description: Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// ex) INPUT: nums = [0,0,1,1,1,1,2,3,3]
// OUTPUT: length = 7; nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively AKA [0, 0, 1, 1, 2, 3, 3]

int Solution::removeDuplicates(std::vector<int>& nums) {
    if(nums.size() == 0)
    {
        return 0;
    }
        
    int length = 0;
    int curr_track = 1;
        
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i - 1])
        {
            curr_track = 1;
            length++;
            nums[length] = nums[i];
        }
        else if(nums[i] == nums[i - 1] && curr_track < 2)
        {
            length++;
            curr_track++;
            nums[length] = nums[i];
        }
    }

    std::cout << "New list: " << std::endl;
    for(int i = 0; i < length + 1; i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << std::endl;
        
    // + 1 bc the first element was not counted b/c length starts as 0 initially
    return length + 1;
}

int main()
{
    std::cout << "How many numbers? " << std::endl;
    int num_count = 0;
    std::cin >> num_count;
    int temp;
    std::cout << "Enter numbers" << std::endl;
    std::vector<int> nums;
    for(int i = 0; i < num_count; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }

    Solution solution;
    int list_length = solution.removeDuplicates(nums);

    std::cout << "New list length: " << list_length << std::endl;

    return 0;
}