#include "n_unique_zero.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

// date: 7/17/2020

// description: given a length, produce a vector of unique ints that add up to 0

std::vector<int> Solution::sumZero(int n) {
    std::vector<int> return_vec;
    for(int i = 0; i < n/2; i++)
    {
        return_vec.push_back(i + 1);
        return_vec.push_back(-i - 1);
    }
        
    if(n % 2 != 0)
    {
        return_vec.push_back(0);
    }
        
    return return_vec;
}

int main()
{
    int length;
    std::cout << "How long do you want the result? " << std::endl;
    std::cin >> length;
    
    Solution solution;
    std::vector<int> result = solution.sumZero(length);

    std::cout << "Result: ";
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}