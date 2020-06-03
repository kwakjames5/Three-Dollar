#include "majority_element.h"
#include <iostream>
#include <vector>
#include <map>

// link: https://leetcode.com/problems/majority-element/

// date: 6/3/2020

// description: given a nums vector of ints, returns the int that comes up more at least nums.size()/2

int Solution::majorityElement(std::vector<int>& nums) 
{
    // when nums only has 1 int, return that int
    if(nums.size() == 1)
    {
        return nums[0];
    }
        
    // map to keep track of count of integers in nums
    std::map<int, int> track_map;
            
    // iterate nums
    for(int i = 0; i < nums.size();i++)
    {
        // make a pair if nums[i] is not in track_map yet
        if(track_map.find(nums[i]) == track_map.end())
        {
            track_map.insert(std::pair<int, int>(nums[i], 1));
        }
        else if(track_map.find(nums[i]) != track_map.end())
        {
            // if the pair already is in the map, increment the count by 1
            track_map[nums[i]]++;
        }
            
        // if ever the nums[i]'s count is greater than half of the size of 
        // the nums vector, return the majority element
        if(track_map[nums[i]] > nums.size()/2)
        {
            return nums[i];
        }
    }
        
    return 0;
}

int main()
{
    std::vector<int> nums;
    int temp;
    int input_size;

    std::cout << "Enter input size, then numbers:" << std::endl;
    std::cin >> input_size;

    for(int i = 0; i < input_size; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }

    Solution solution;
    int result = solution.majorityElement(nums);

    std::cout << "Majority element: " << result << std::endl;
    
    return 0;
}