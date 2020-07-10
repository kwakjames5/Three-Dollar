#include "valid_palindrome.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/valid-palindrome/

// date: 7/9/2020

// description: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

bool Solution::isPalindrome(std::string s) 
{
    int l = 0;
    int r = s.size() - 1;
        
    while(l < r)
    {
        while(l < r && !std::isalnum(s[l]))
        {
            l++;
        }
        while(l < r && !std::isalnum(s[r]))
        {
            r--;
        }
        if(std::tolower(s[l]) != std::tolower(s[r]))
        {
            return false;
        }
            
        l++;
        r--;
    }
        
    return true;
}

int main()
{
    std::cout << "Enter string" << std::endl;
    std::string input;
    std::cin >> input;
    Solution solution;
    bool palindrome = solution.isPalindrome(input);
    if(palindrome)
    {
        std::cout << "The string is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "The string is not a palindrome" << std::endl;
    }

    return 0;
}