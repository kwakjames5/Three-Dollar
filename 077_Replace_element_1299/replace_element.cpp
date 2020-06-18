#include "replace_element.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// date: 6/18/2020

// description: given a vector of ints, replace each element with the greatest element that 
// exists to its right. replace the last element with a -1

std::vector<int> Solution::replaceElements(std::vector<int>& arr) 
{
    for(int i = 0; i < arr.size(); i++)
    {
        arr[i] = 0;
        for(int j = i + 1; j < arr.size(); j++)
        {
                
            if(arr[j] > arr[i])
            {
                arr[i] = arr[j];
            }
        }
        if(i == arr.size() - 1)
        {
            arr[i] = -1;
        }
    }
    return arr;
}

int main()
{
    std::vector<int> arr;

    std::cout << "Enter size of vector: " << std::endl;
    int size = 0;
    std::cin >> size;

    std::cout << "Enter elements: " << std::endl;
    int element = 0;
    for(int i = 0; i < size; i++)
    {
        std::cin >> element;
        arr.push_back(element);
    }

    Solution solution;
    std::vector<int> result = solution.replaceElements(arr);

    std::cout << "Result: " << std::endl;
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}