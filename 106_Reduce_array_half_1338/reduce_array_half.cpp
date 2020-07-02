#include "reduce_array_half.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// link: https://leetcode.com/problems/reduce-array-size-to-the-half/

// date: 7/1/2020

// description: Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.
// Return the minimum size of the set so that at least half of the integers of the array are removed

int Solution::minSetSize(std::vector<int>& arr) {
    std::map<int, int> int_track;
    for(int i = 0; i < arr.size(); i++)
    {
        int_track[arr[i]]++;
    }
    std::vector<int> int_count_vec;
    std::map<int, int>::iterator map_it;
    for(map_it = int_track.begin(); map_it != int_track.end(); map_it++)
    {
        int_count_vec.push_back(map_it->second);
    }
    std::sort(int_count_vec.begin(), int_count_vec.end(), std::greater<int>());
    int remove_set_count = 0;
    int half_check = 0;
        
    std::vector<int>::iterator vector_it;
    for(vector_it = int_count_vec.begin(); vector_it != int_count_vec.end(); vector_it++)
    {
        if(2 * half_check >= arr.size())
        {
            break;
        }
        remove_set_count++;
        half_check += *vector_it;
    }
        
    return remove_set_count;
        
}

int main()
{
    std::vector<int> arr;
    std::cout << "Enter array size:" << std::endl;
    int arr_size;
    std::cin >> arr_size;
    std::cout << "Enter integers: " << std::endl;
    int temp;

    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }

    Solution solution;
    int min_set = solution.minSetSize(arr);

    std::cout << "Minimum number of sets of integers removed to make the arr at least half: " << min_set << std::endl;

    return 0;
}