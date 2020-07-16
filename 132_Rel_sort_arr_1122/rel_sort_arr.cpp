#include "rel_sort_arr.h"
#include <iostream>
#include <vector>
#include <map>

// link: https://leetcode.com/problems/relative-sort-array/

// date: 7/15/2020

// description: Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19] size = 11, arr2 = [2,1,4,3,9,6] size = 6
// Output: [2,2,2,1,4,3,3,9,6,7,19]

std::vector<int> Solution::relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    if(arr2.size() == 0)
    {
        return arr1;
    }
        
    std::vector<int> result;
    std::map<int, int> arr_track;
        
    for(int i = 0; i < arr1.size(); i++)
    {
        arr_track[arr1[i]]++;
    }
        
    for(int i = 0; i < arr2.size(); i++)
    {
        while(arr_track[arr2[i]] > 0)
        {
            result.push_back(arr2[i]);
            arr_track[arr2[i]]--;
        }
    }
    
    std::map<int, int>::iterator map_it;
        
    for(map_it = arr_track.begin(); map_it != arr_track.end(); map_it++)
    {
        if(map_it->second > 0)
        {
            while(map_it->second > 0)
            {
                result.push_back(map_it->first);
                map_it->second--;
            }
        }
    }
        
    return result;
}

int main()
{
    std::cout << "Enter size of arr2" << std::endl;
    int arr2_size;
    std::cin >> arr2_size;
    int input;
    std::vector<int> arr2;
    std::cout << "Enter numbers for arr2. Each number must be unique AKA no repeats" << std::endl;
    for(int i = 0; i < arr2_size; i++)
    {
        std::cin >> input;
        arr2.push_back(input);
    }

    std::cout << "Enter size of arr1 (must at least be as big as arr2)" << std::endl;
    int arr1_size;
    std::cin >> arr1_size;
    std::vector<int> arr1;
    std::cout << "Enter numbers for arr1. Repeats are allowed now and every number in arr2 must be included at least once each." << std::endl;
    for(int i = 0; i < arr1_size; i++)
    {
        std::cin >> input;
        arr1.push_back(input);
    }

    Solution solution;
    std::vector<int> result = solution.relativeSortArray(arr1, arr2);
    std::cout << "result: ";
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;

    return 0;

}