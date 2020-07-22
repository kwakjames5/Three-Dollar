#include "num_subarray_bounded_max.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

// date; 7/21/2020

// description: We are given an array A of positive integers, and two positive integers L and R (L <= R).
// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

int Solution::numSubarrayBoundedMax(std::vector<int>& A, int L, int R) {
    int result = 0;
    int left = -1;
    int right = -1;
        
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= L && A[i] <= R)
        {
            right = i;
        }
        else if(A[i] > R)
        {
            left = right = i;
        }
            
        result += right - left;
    }
        
    return result;
}

int main()
{
    std::vector<int> A;
    int L, R;
    int arr_size;
    std::cout << "Enter array size" << std::endl;
    std::cin >> arr_size;
    int temp;
    std::cout << "Enter array elements" << std::endl;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> temp;
        A.push_back(temp);
    }
    std::cout << "Enter lower and upper limits to check " << std::endl;
    std::cin >> L >> R;
    Solution solution;
    int subarray_bounded_count = solution.numSubarrayBoundedMax(A, L, R);
    std::cout << "Number of subarrays that contain a element within bound: " << subarray_bounded_count << std::endl;

    return 0;
}