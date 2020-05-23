#include <iostream>
#include <vector>
#include "max_con_one.h"

// link: https://leetcode.com/problems/max-consecutive-ones/
// date: 5/23/2020
// description:
// given an input array, finds and returns the highest streak of 1's the array has
// example: 011111001 would return 5 for the 11111 in the middle

int Solution::findMaxConsecutiveOnes(std::vector<int>& nums) 
{
    if(nums.size() == 1 && nums[0] == 1)
    {
        return 1;
    }
    else if(nums.size() == 1 && nums[0] == 0)
    {
        return 0;
    }
    
    int max = 0;
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        if(nums[i] == 0 && count != 0)
        {
            if(count > max)
            {
                max = count;
                count = 0;
            }
            else
            {
                count = 0;
            }                
        }
        if(i == nums.size() - 1 && count != 0)
        {
            if(count > max)
            {
                max = count;
                count = 0;
            }
            else
            {
                count = 0;
            }
        }
    }
        
    return max;
}

int main()
{
	int array_size;
	int element_input;
	std::vector<int> input_array;

	std::cout << "Enter size:" << std::endl;
	std::cin >> array_size;

	std::cout << "Enter elements (0s and 1s only): " << std::endl;
	for(int i = 0; i < array_size; i++)
	{
		std::cin >> element_input;
		input_array.push_back(element_input);
	}

	Solution* solution;
	int output = solution->findMaxConsecutiveOnes(input_array);

	std::cout << "Maximum consecutive of one: " << std::endl;
	std::cout << output << std::endl;

	return 0;
}