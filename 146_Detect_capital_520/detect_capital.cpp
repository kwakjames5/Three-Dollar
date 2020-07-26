#include "detect_capital.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/detect-capital/

// date: 7/24/2020

// description: Given a word, you need to judge whether the usage of capitals in it is right or not.
// We define the usage of capitals in a word to be right when one of the following cases holds:
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.

bool Solution::detectCapitalUse(std::string word) {
    bool proper_use = true;
    bool upper_case = false;
    if(word[1] >= 'A' && word[1] <= 'Z')
    {
        upper_case = true;
        if(word[0] >= 'a' && word[0] <= 'z')
        {
            proper_use = false;
            return proper_use;
        }
    }
        
    if(word.size() <= 2)
    {
        return proper_use;
    }
        
    for(int i = 2; i < word.size(); i++)
    {
        if(!upper_case)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
            {
                proper_use = false;
                break;
            }
        }
        else
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                proper_use = false;
                 break;
            }
        }
    }
        
    return proper_use;
}

int main()
{
    std::cout << "Enter word:" << std::endl;
    std::string word;
    std::cin >> word;
    Solution solution;
    bool proper = solution.detectCapitalUse(word);
    if(proper)
    {
        std::cout << "Capitalization done properly" << std::endl;
    }
    else
    {
        std::cout << "Capitalization done improperly" << std::endl;
    }

    return 0;
}