#include "missing_num.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/missing-number/

// date: 6/3/2020

// description: given a vector with one element missing, return the missing element

int Solution::missingNumber(std::vector<int>& nums) 
{
    int result;
       
    // nums_sum is the total of the ints in nums vector
    int nums_sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        nums_sum += nums[i];
    }
      
    // since we want to find the missing element, compare_sum is the sum of the
    // nums vector if it were not missing a element. this is achieved by using <= instead of <
    int compare_sum = 0;
    for(int j = 0; j <= nums.size(); j++)
    {
        compare_sum += j;
    }
        
    // compare_sum - nums_sum is the hypothetical sum minus the real sum, leaving behind the missing element
    result = compare_sum - nums_sum;
        
    return result;
        
        /*vector<int> nums_store;
        
        for(int i = 0; i < nums.size(); i++)
        {
            nums_store.push_back(nums[i]);
        }
        
        for(int j = 0; j <= nums_store.size(); j++)
        {
            if(find(nums_store.begin(), nums_store.end(), j) == nums_store.end())
            {
                return j;
            }
        }
        
        return -1;
        */
}

int main()
{
	std::vector<int> nums;
	int temp;

	std::cout << "Enter numbers from 0 - n with one element missing: (-1 to exit)" << std::endl;
	while(std::cin >> temp)
	{
		if(temp == -1)
		{
			break;
		}
		else
		{
			nums.push_back(temp);
		}
	}

	Solution solution;
	int result = solution.missingNumber(nums);

	std::cout << result << std::endl;
	
	return 0;
}