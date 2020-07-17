#include "compare_strings_freq_smallest_char.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

// date: 7/16/2020

// description: Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. 
// For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.
// Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

std::vector<int> Solution::numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words) {
    std::vector<int> vec_1, vec_2, vec_3;
        
    for(int i = 0; i < queries.size(); i++)
    {
        std::string temp = queries[i];
        std::sort(temp.begin(), temp.end());
        int smallest_total = 1;
        for(int j = 1; j < temp.size(); j++)
        {
            if(temp[j] == temp[0])
            {
                smallest_total++;
            }
        }
            
        vec_1.push_back(smallest_total);
    }
        
    for(int i = 0; i < words.size(); i++)
    {
        std::string temp = words[i];
        std::sort(temp.begin(), temp.end());
        int smallest_total = 1;
        for(int j = 1; j < temp.size(); j++)
        {
            if(temp[j] == temp[0])
            {
                smallest_total++;
            }
        }
            
        vec_2.push_back(smallest_total);
    }
        
    for(int i = 0; i < vec_1.size(); i++)
    {
        int total = 0;
        for(int j = 0; j < vec_2.size(); j++)
        {
            if(vec_1[i] < vec_2[j])
            {
                total++;
            }
        }
            
        vec_3.push_back(total);
    }
        
    return vec_3;
}

int main()
{
    std::vector<std::string> queries, words;
    int queries_count, words_count;
    std::cout << "How many words in the word bank? " << std::endl;
    std::cin >> words_count;
    std::string temp;
    std::cout << "Enter word bank" << std::endl;
    for(int i = 0; i < words_count; i++)
    {
        std::cin >> temp;
        words.push_back(temp);
    }

    std::cout << "How many words to check?" << std::endl;
    std::cin >> queries_count;
    std::cout << "Enter words to be checked" << std::endl;
    for(int i = 0; i < queries_count; i++)
    {
        std::cin >> temp;
        queries.push_back(temp);
    }

    Solution solution;
    std::vector<int> result = solution.numSmallerByFrequency(queries, words);

    std::cout << "Result: ";
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}