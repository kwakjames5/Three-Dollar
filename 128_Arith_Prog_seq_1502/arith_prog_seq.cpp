#include "arith_prog_seq.h"
#include <iostream>
#include <vector>
#include <algorithm>

// link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// date: 7/14/2020

// description: Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
// Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.

bool Solution::canMakeArithmeticProgression(std::vector<int>& arr) 
{
    std::sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
        
    for(int i = 2; i < arr.size(); i++)
    {
        if(arr[i] - arr[i - 1] != diff)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "How many ints in sequence?" << std::endl;
    int arr_size;
    std::cin >> arr_size;
    std::cout << "Enter elemenets in sequence" << std::endl;
    std::vector<int> arr;
    int temp;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }

    Solution solution;
    bool arith_prog = solution.canMakeArithmeticProgression(arr);

    if(arith_prog)
    {
        std::cout << "Arithmetic progression can be made from the given sequence" << std::endl;
    }
    else
    {
        std::cout << "Arithmetic progression cannot be made from the given sequence" << std::endl;
    }

    return 0;
}