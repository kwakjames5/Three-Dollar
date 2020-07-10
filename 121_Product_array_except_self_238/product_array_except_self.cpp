#include "product_array_except_self.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/product-of-array-except-self/

// date: 7/9/2020

// description: Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

std::vector<int> Solution::productExceptSelf(std::vector<int>& nums) {
    std::vector<int> return_vec(nums.size());
    return_vec[0] = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        return_vec[i] = nums[i - 1] * return_vec[i - 1];
    }
        
    int right_product = 1;
    for(int j = nums.size() - 1; j >= 0; j--)
    {
        return_vec[j] *= right_product;
        right_product *= nums[j];
    }
        
    return return_vec;
}

int main()
{
    std::vector<int> nums;
    std::cout << "How many numbers?" << std::endl;
    int num_count;
    std::cin >> num_count;
    int temp = 0;
    std::cout << "Enter numbers:" << std::endl;
    for(int i = 0; i < num_count; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }

    Solution solution;
    std::vector<int> products = solution.productExceptSelf(nums);
    std::cout << "Products: ";
    for(int i = 0; i < products.size(); i++)
    {
        std::cout << products[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}