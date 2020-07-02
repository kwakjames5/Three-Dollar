#include "split_max_score.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/

// date: 7/1/2020

// description: Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings 
// (i.e. left substring and right substring).
// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

int Solution::maxScore(std::string s) 
{
    int max_score = 0;
    int curr_score = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        int counter = 0;
        while(counter <= i)
        {
            if(s[counter] == '0')
            {
                curr_score++;
            }
            counter++;
        }
            
        for(int j = i + 1; j < s.size(); j++)
        {
            if(s[j] == '1')
            {
                curr_score++;
            }
        }
            
        if(curr_score > max_score)
        {
            max_score = curr_score;
        }
        curr_score = 0;
    }
        
    return max_score;
}

int main()
{
    std::cout << "Enter string" << std::endl;
    std::string s;
    std::cin >> s;

    Solution solution;
    int max_score = solution.maxScore(s);

    std::cout << "Max score: " << max_score << std::endl;

    return 0;
}