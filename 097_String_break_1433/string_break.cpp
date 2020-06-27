#include "string_break.h"
#include <iostream>
#include <string>
#include <algorithm>

// link: https://leetcode.com/problems/check-if-a-string-can-break-another-string/

// date: 6/26/2020

// description: given two strings, check if either can break the other
// a string can break another string when a string has chars which are greater than all of the other string's chars

bool Solution::checkIfCanBreak(std::string s1, std::string s2) 
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    bool s1_breaks_s2 = true;
    bool s2_breaks_s1 = true;
        
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] < s2[i])
        {
            s1_breaks_s2 = false;
        }
        
        if(s2[i] < s1[i])
        {
            s2_breaks_s1 = false;
        }
    }
        
    bool final_answer = s1_breaks_s2 || s2_breaks_s1;
        
    return final_answer;
}

int main()
{
    std::string s1, s2;

    std::cout << "Enter strings: " << std::endl;

    std::cin >> s1 >> s2;

    Solution solution;
    bool break_check = solution.checkIfCanBreak(s1, s2);

    if(break_check)
    {
        std::cout << "The strings are able to break eachother" << std::endl;
    }
    else
    {
        std::cout << "The strings cannot break eachother" << std::endl;
    }

    return 0;
}