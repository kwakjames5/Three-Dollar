#include "squares_sorted_array.h"
#include <vector>
#include <iostream>
#include <algorithm>

// link: https://leetcode.com/problems/squares-of-a-sorted-array/

// date: 7/1/2020

// description: Given an array of integers A sorted in non-decreasing order, 
// return an array of the squares of each number, also in sorted non-decreasing order.

std::vector<int> Solution::sortedSquares(std::vector<int>& A) 
{
    std::vector<int> sorted_result(A.size());
    int left = 0;
    int right = A.size() - 1;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(abs(A[left]) > abs(A[right]))
        {
            sorted_result[i] = A[left] * A[left];
            left++;
        }
        else
        {
            sorted_result[i] = A[right] * A[right];
            right--;
        }
    }
        
    return sorted_result;
        
        /*
        for(int i = 0; i < A.size(); i++)
        {
            A[i] = A[i] * A[i];
        }
        
        sort(A.begin(), A.end());
        
        return A;
        */
}

int main()
{
    std::cout << "How many integers?: " << std::endl;
    int int_count;
    std::cin >> int_count;

    std::cout << "Enter integers from least to greatest in order: " << std::endl;
    std::vector<int> A;
    int temp;

    for(int i = 0; i < int_count; i++)
    {
        std::cin >> temp;
        A.push_back(temp);
    }

    Solution solution;
    std::vector<int> result = solution.sortedSquares(A);

    std::cout << "Results: ";
    for(int j = 0; j < result.size(); j++)
    {
        std::cout << result[j] << " ";
    }

    std::cout << std::endl;

    return 0;
    
}