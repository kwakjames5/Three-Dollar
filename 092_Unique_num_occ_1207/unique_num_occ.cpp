#include "unique_num_occ.h"
#include <iostream>
#include <vector>
#include <map>

// link: https://leetcode.com/problems/unique-number-of-occurrences/

// date: 6/25/2020

// description: given a vector of ints, return whether or not each int appeared a unique number of times or not

bool Solution::uniqueOccurrences(std::vector<int>& arr) 
{
    std::map<int, int> int_count;
    for(int i = 0; i < arr.size(); i++)
    {
        int_count[arr[i]]++;
    }
        
    std::map<int, int> occurence_count;
    std::map<int, int>::iterator map_it;
    bool unique_or_not = true;
    for(map_it = int_count.begin(); map_it != int_count.end(); map_it++)
    {
        if(occurence_count.find(map_it->second) == occurence_count.end())
        {
            occurence_count[map_it->second]++;
        }
        else
        {
            unique_or_not = false;
            return unique_or_not;
        }
    }
        
    return unique_or_not;
}

int main()
{
    std::vector<int> input_arr;
    std::cout << "How many integers? " << std::endl;
    int integer_count = 0;
    std::cin >> integer_count;

    std::cout << "Enter integers:" << std::endl;
    int input;

    for(int i = 0; i < integer_count; i++)
    {
        std::cin >> input;
        input_arr.push_back(input);
    }

    Solution solution;
    bool unique_or_not = solution.uniqueOccurrences(input_arr);

    if(unique_or_not)
    {
        std::cout << "Each integer has a unique count." << std::endl;
    }
    else
    {
        std::cout << "The integers do not have a unique count." << std::endl;
    }

    return 0;
}