#include "sort_array_parity.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/sort-array-by-parity/

// date: 7/3/2020

// description: Given an array A of non-negative integers, 
// return an array consisting of all the even elements of A, 
// followed by all the odd elements of A.

std::vector<int> Solution::sortArrayByParity(std::vector<int>& A) 
{
    std::vector<int> result;
        
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i]%2 == 0)
        {
            result.push_back(A[i]);
        }
    }
        
    for(int j = 0; j < A.size(); j++)
    {
        if(A[j]%2 == 1)
        {
            result.push_back(A[j]);
        }
    }
      
    return result;
}

int main()
{
    std::vector<int> A;
    std::cout << "Enter size of array" << std::endl;
    int array_size;
    std::cin >> array_size;
    int input;
    std::cout << "Enter elements" << std::endl;
    for(int i = 0; i < array_size; i++)
    {
        std::cin >> input;
        A.push_back(input);
    }

    Solution solution;
    std::vector<int> result = solution.sortArrayByParity(A);

    std::cout << "Result: ";
    for(int j = 0; j < result.size(); j++)
    {
        std::cout << result[j] << " ";
    }

    return 0;
}