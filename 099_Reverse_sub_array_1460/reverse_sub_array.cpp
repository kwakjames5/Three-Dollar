#include "reverse_sub_array.h"
#include <iostream>
#include <vector>
#include <map>

// link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

// date: 6/29/2020

// description: in a single step, you are allowed to reverse the order of any sub array in arr to get to target. 
// you can take as many steps as you want. return whether or not the two arrays can eventually be equal

// Input: target = [1,2,3,4], arr = [2,4,1,3]
// Output: true

bool Solution::canBeEqual(std::vector<int>& target, std::vector<int>& arr) 
{
    if(target.size() != arr.size())
    {
        return false;
    }       
        
    std::map<int, int> target_map;
    for(int i = 0; i < target.size(); i++)
    {
        target_map[target[i]]++;
    }
        
    for(int i = 0; i < arr.size(); i++)
    {
        if(target_map.find(arr[i]) != target_map.end())
        {
            target_map[arr[i]]--;
            if(target_map[arr[i]] == 0)
            {
                target_map.erase(arr[i]);
            }
        }
    }
        
    if(target_map.empty())
    {
        return true;
    }
    else
    {
        return false;
    }                                      
}

int main()
{
    std::cout << "How big do you want the arrays?" << std::endl;
    std::vector<int> target;
    std::vector<int> arr;
    int arr_size = 0;
    std::cin >> arr_size;
    int input;

    std::cout << "Enter elements for the target array:" << std::endl;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> input;
        target.push_back(input);
    }

    std::cout << "Enter elements for the checked array: " << std::endl;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> input;
        arr.push_back(input);
    }

    Solution solution;
    bool can_be_equal = solution.canBeEqual(target, arr);

    if(can_be_equal)
    {
        std::cout << "The arrays can be equal by reversing subarrays" << std::endl;
    }
    else
    {
        std::cout << "Subarrays cannot be reversed to make the two arrays equal" << std::endl;
    }

    return 0;

}