#include "string_match.h"
#include <iostream>
#include <vector>
#include <string>

// link: https://leetcode.com/problems/string-matching-in-an-array/

// date; 6/26/2020

// description: given a vector of strings, return a vector of the strings which are substrings of another string in the original vector

std::vector<std::string> Solution::stringMatching(std::vector<std::string>& words) 
{
    std::vector<std::string> return_vector;
        
    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words.size(); j++)
        {
            if(i != j && words[j].find(words[i]) != -1)
            {
                return_vector.push_back(words[i]);
                break;
            }
        }
    }
    return return_vector;
}

int main()
{
    std::vector<std::string> words;

    std::cout << "How many words? " << std::endl;
    int word_count = 0;
    std::cin >> word_count;
    std::string temp;

    std::cout << "Enter words: " << std::endl;
    for(int i = 0; i < word_count; i++)
    {
        std::cin >> temp;
        words.push_back(temp);
    }

    Solution solution;
    std::vector<std::string> result = solution.stringMatching(words);

    std::cout << "Resulting words: " << std::endl;
    for(int j = 0; j < result.size(); j++)
    {
        std::cout << result[j] << " ";
    }

    std::cout << std::endl;

    return 0;
}
