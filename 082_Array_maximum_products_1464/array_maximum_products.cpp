#include "array_maximum_products.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// date: 6/22/2020

// description: given a vector of numbers, return the product of the two largest elements in the vector with 1 subtracted from both
// aka (nums[i] - 1) * (nums[j] - 1)

int Solution::maxProduct(std::vector<int>& nums) 
{
    int max_int_1 = 0;
    int index_1;
    int max_int_2 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > max_int_1)
        {
            max_int_1 = nums[i];
            index_1 = i;
        }
    }
    // max_int_1 is now the biggest element in the array right now
    // index_1 is the index that this first max element is on
     
    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] > max_int_2 && j != index_1)
        {
            max_int_2 = nums[j];
        }
    }
        
    return (max_int_1 - 1) * (max_int_2 - 1);        
}

int main()
{
    std::vector<int> nums;
    std::cout << "Enter array size: " << std::endl;
    int array_size = 0;
    std::cin >> array_size;
    std::cout << "Enter elements: " << std::endl;
    int input = 0;

    for(int i = 0; i < array_size; i++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    int max_product = solution.maxProduct(nums);

    std::cout << "Max product: " << max_product << std::endl;

    return 0;
}