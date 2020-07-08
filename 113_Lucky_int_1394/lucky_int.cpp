#include "lucky_int.h"
#include <vector>
#include <iostream>
#include <map>

// link: https://leetcode.com/problems/find-lucky-integer-in-an-array/

// date: 7/7/2020

// description: Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.
// Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1.

int Solution::findLucky(std::vector<int>& arr) {
    std::map<int, int> arr_track;
    for(int i = 0; i < arr.size(); i++)
    {
        arr_track[arr[i]]++;
    }
        
    std::map<int, int>::iterator map_it;
    int largest_lucky = -1;
    for(map_it = arr_track.begin(); map_it != arr_track.end(); map_it++)
    {
        if(map_it->first == map_it->second && map_it->first > largest_lucky)
        {
            largest_lucky = map_it->first;
        }
    }
        
     return largest_lucky;
}

int main()
{
    std::vector<int> arr;
    std::cout << "Enter array size" << std::endl;
    int arr_size;
    std::cin >> arr_size;
    std::cout << "Enter elements" << std::endl;
    int input;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> input;
        arr.push_back(input);
    }

    Solution solution;
    int lucky_int_largest = solution.findLucky(arr);

    if(lucky_int_largest != -1)
    {
        std::cout << "Lucky int: " << lucky_int_largest << std::endl;
    }
    else
    {
        std::cout << "No lucky ints" << std::endl;
    }

    return 0;

}