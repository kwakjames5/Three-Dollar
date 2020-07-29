#include "subarrays_size_k_threshold.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

// date: 7/28/2020

// description: Given an array of integers arr and two integers k and threshold.
// Return the number of sub-arrays of size k and average greater than or equal to threshold.

int Solution::numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    int sum = 0;
    int sub_count = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if(i >= k)
        {
            sum -= arr[i - k];
        }
        if(sum/k >= threshold && i >= k - 1)
        {
            sub_count++;
        }
    }
        
    return sub_count;
}

int main()
{
    std::cout << "Enter size of array: " << std::endl;
    int arr_size;
    std::cin >> arr_size;
    std::vector<int> arr;
    std::cout << "Enter array elements:" << std::endl;
    int temp;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> temp; 
        arr.push_back(temp);
    }
    std::cout << "Enter size of subarrays: " << std::endl;
    int k;
    std::cin >> k;
    std::cout << "Enter threshold for average of " << k << " sized subarrays: " << std::endl;
    int threshold;
    std::cin >> threshold;

    Solution solution;
    int num_sub = solution.numOfSubarrays(arr, k, threshold);
    std::cout << "Number of subarrays with size " << k << " and average equal to or above " << threshold << ": " << num_sub << std::endl;

    return 0;
}