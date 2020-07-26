#include "camelcase_match.h"
#include <vector>
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/camelcase-matching/

// date: 7/23/2020

// description: A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. 
// (We may insert each character at any position, and may insert 0 characters.)
// Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

std::vector<bool> Solution::camelMatch(std::vector<std::string>& queries, std::string pattern) {
    std::vector<bool> return_vector;
    for(int i = 0; i < queries.size(); i++)
    {
        std::string curr = queries[i];
        int j = 0;
        int k = 0;
        bool to_push = true;
            
        while(j < curr.size())
        {
            if(k < pattern.size() && pattern[k] == curr[j])
            {
                k++;
            }
            else if(curr[j] >= 'A' && curr[j] <= 'Z')
            {
                to_push = false;
                break;
            }
                
            j++;
        }
            
        if(to_push && k == pattern.size())
        {
            return_vector.push_back(true);
        }
        else
        {
            return_vector.push_back(false);
        }
    }
        
    return return_vector;
}

int main()
{
    std::vector<std::string> queries;
    std::string pattern;
    std::cout << "How many words to check? " << std::endl;
    int queries_size;
    std::cin >> queries_size;
    std::cout << "Enter pattern" << std::endl;
    std::cin >> pattern;
    std::cout << "Enter words to check " << std::endl;
    std::string temp;
    for(int i = 0; i < queries_size; i++)
    {
        std::cin >> temp;
        queries.push_back(temp);
    }

    Solution solution;
    std::vector<bool> result = solution.camelMatch(queries, pattern);
    std::cout << "Result:" << std::endl;
    for(int i = 0; i < result.size(); i++)
    {
        if(result[i])
        {
            std::cout << queries[i] << " matches the pattern" << std::endl;
        }
        else
        {
            std::cout << queries[i] << " does not match the pattern" << std::endl;
        }
    }

    return 0;
}