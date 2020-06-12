#include "smaller_than_curr.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// date: 6/11/2020 

// description: given a vector of integers, return a vector which has the total number of elements smaller than each element in the vector

// ex) nums = [8,1,2,2,3]
// output = [4,0,1,1,3]

std::vector<int> Solution::smallerNumbersThanCurrent(std::vector<int>& nums) 
{
    std::vector<int> result;
    
    for(int i = 0; i < nums.size(); i++)
    {
        int curr_num = nums[i];
        int count = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(j != i)
            {
                if(nums[j] < curr_num)
                {
                    count++;
                }
            }
        }
            
        result.push_back(count);
    }
       
    return result;
}

int main()
{
	std::vector<int> nums;
	int size;

	std::cout << "Enter vector size: " << std::endl;
	std::cin >> size;

	std::cout << "Enter vector elements: " << std::endl;

	for(int i = 0; i < size; i++)
	{
		int input;
		std::cin >> input;
		nums.push_back(input);
	}

	Solution solution;
	std::vector<int> result = solution.smallerNumbersThanCurrent(nums);

	std::cout << "Result: " << std::endl;
	for(int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}

	return 0;
}