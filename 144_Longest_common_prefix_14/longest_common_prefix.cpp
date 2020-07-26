#include "longest_common_prefix.h"
#include <vector>
#include <string>
#include <iostream>

// link: https://leetcode.com/problems/longest-common-prefix/

// date: 7/23/2020

// description: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
    int i = 0;
    int j;
    if(strs.empty())
    {
        return "";
    }
        
    while(i < strs[0].size())
    {
        for(j = 1; j < strs.size(); j++)
        {
            if(strs[0][i] != strs[j][i])
            {
                break;
            }
        }
        if(j == strs.size())
        {
            i++;
        }
        else
        {
            break;
        }
    }
        
    if(i == 0)
    {
        return "";
    }
    else
    {
        return strs[0].substr(0,i);
    }
}

int main()
{
    std::vector<std::string> strs;
    std::cout << "How many words?" << std::endl;
    int word_count;
    std::cin >> word_count;
    std::cout << "Enter words" << std::endl;
    std::string temp;
    for(int i = 0; i < word_count; i++)
    {
        std::cin >> temp;
        strs.push_back(temp);
    }

    Solution solution;
    std::string prefix = solution.longestCommonPrefix(strs);
    std::cout << "prefix: " << prefix << std::endl;

    return 0;
}