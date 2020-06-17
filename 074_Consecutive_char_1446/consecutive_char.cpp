#include "consecutive_char.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/consecutive-characters/

// date: 6/16/2020

// description: given a string, return the highest number of consecutive characters

int Solution::maxPower(std::string s) 
{
    char curr = s[0];
    int max_track = 0;
    int true_max = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == curr)
        {
            max_track++;
            if(max_track > true_max)
            {
                true_max = max_track;
            }
        }
        else
        {
            if(max_track > true_max)
            {
                true_max = max_track;
            }
            curr = s[i];
            max_track = 1;
        }
    }
        
    return true_max;
}

int main()
{
    std::cout << "Enter string: " << std::endl;
    std::string input;
    std::cin >> input;

    Solution solution;
    int max = solution.maxPower(input);

    std::cout << "Max consecutive: " << max << std::endl;

    return 0;
}