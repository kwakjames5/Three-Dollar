#include "find_dup.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

// 1 ≤ a[i] ≤ n (n = size of array)
// This means that every element in the nums array is between 1 and the size of the array
// IMPORTANT ^^

// Logic: each element in nums can be used to reference a different index on nums by doing element - 1
// example: nums[3] = 5; 5 - 1 = 4 -> nums[4] = 2
// find an element in the nums array (5 in index 3). when 1 is subtracted (5 - 1 = 4), the difference
// can be used to reference the 4th index in the nums array

// since the most an element can appear in the nums array is maximum TWICE, we can keep track of if a element
// in the nums array has already been checked by modifying the element that is being referenced by the difference
//example: nums[3] = 5; 5 - 1 = 4 -> nums[4] = 2 * -1 = -2
// now, the next time a nums[i] has a 5, we can check if the element at the index it is referring to has already been
// modified
// if it has, push it into the output_array

// when checking for the nums[nums[i] - 1] aka the element at the index found by subtracting 1 from the element on i
// the element on i from nums must be absolute valued
// just because an element is changed to negative does not mean it is not to be checked for duplicates
// each element is essentially its own element as well as another's flag

// link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// date: 5/23/2020

std::vector<int> Solution::findDuplicates(std::vector<int>& nums)
{
	std::vector<int> output_array;
        
    for(int i = 0; i < nums.size(); i++)
    {
    	if(nums[abs(nums[i]) - 1] > 0)
    	{
        	nums[abs(nums[i]) - 1] *= -1;
    	}
    	else
    	{
        	output_array.push_back(abs(nums[i]));
    	}
    }
        
    return output_array;
}

int main()
{
	int array_size;
	int element_input;
	std::vector<int> input_array;

	std::cout << "Enter size:" << std::endl;
	std::cin >> array_size;

	std::cout << "Enter elements accordingly (Only between 1 and size, elements may only appear once or twice): " << std::endl;
	for(int i = 0; i < array_size; i++)
	{
		std::cin >> element_input;
		input_array.push_back(element_input);
	}

	Solution* solution;
	std::vector<int> answer_array = solution->findDuplicates(input_array);

	std::cout << "Duplicate elements: " << std::endl;
	for(int j = 0; j < answer_array.size(); j++)
	{
		std::cout << answer_array[j] << std::endl;
	}

	return 0;
}