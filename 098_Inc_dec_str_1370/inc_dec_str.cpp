#include "inc_dec_str.h"
#include <iostream>
#include <string>
#include <vector>

// link: https://leetcode.com/problems/increasing-decreasing-string/

// date: 6/29/2020

// description: given a string, take all unique characters in it and append them to a result string in alphabetical order
// after this, do the same thing but in reverse alphabetical order
// do this until you run out of letters and reutrn the result

// ex) Input: s = "aaaabbbbcccc"
// Output: "abccbaabccba"

std::string Solution::sortString(std::string s) 
{
    std::string result;
    std::vector<int> char_count(26);
    for(int i = 0; i < s.size(); i++)
    {
        char_count[s[i] - 'a']++;
    }
        
    while(result.size() < s.size())
    {
        for(int i = 0; i < 26; i++)
        {
            if(char_count[i] != 0)
            {
                result.push_back(i + 'a');
                char_count[i]--;
            }
        }
            
        for(int i = 25; i >= 0; i--)
        {
            if(char_count[i] != 0)
            {
               result.push_back(i + 'a');
               char_count[i]--;
            }
        }
    }
        
    return result;
}

int main()
{
    std::string s;
    std::cout << "Enter string to be sorted: " << std::endl;
    std::cin >> s;

    Solution solution;
    std::string sorted_s = solution.sortString(s);

    std::cout << "Sorted string: " << sorted_s << std::endl;

    return 0;
}
