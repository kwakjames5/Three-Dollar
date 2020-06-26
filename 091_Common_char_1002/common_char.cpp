#include "common_char.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

// link: https://leetcode.com/problems/find-common-characters/

// date: 6/25/2020

// description: given a vector of strings, return a vector containing strings of each char that is common in all strings in the vector
// meaning, if for example the letter 't' was shared by all of the words in the vector 3 times in each word, the returning vector will have
// three strings "t" in it

std::vector<std::string> Solution::commonChars(std::vector<std::string>& A) {
    std::map<char, int> char_count;
    std::map<char, int>::iterator map_it;
        
    // get the character counts in the first string
    // we will compare any future strings with this first string to start
    std::string string_1 = A[0];
    for(int i = 0; i < string_1.size(); i++)
    {
        char_count[string_1[i]]++;
    }
        
    // now iterate the rest of the vector for the other strings
    for(int j = 1; j < A.size(); j++)
    {
        // get the letters for the current string
        std::map<char, int> char_count_1;
        for(int k = 0; k < A[j].size(); k++)
        {
            char_count_1[A[j][k]]++;
        }
            
        // for each letter in the outer char_count, check if the letter from the previous string(s)
        // is also in this current string
            
        for(map_it = char_count.begin(); map_it != char_count.end(); map_it++)
        {
            // find_it checks if the letter being checked from the outer map is in the current string
            std::map<char, int>::iterator find_it = char_count_1.find(map_it->first);
                
            // if the current string shares a letter with the previous strings, check if we need to update the count
            // aka, if the previous strings had more of the letter currently being checked,
            // update the outer char_count to be lower for the current char
            if(find_it != char_count_1.end())
            {
                if(map_it->second > find_it->second)
                {
                    map_it->second = find_it->second;
                }
            }
            else
            {
                // if the new word does not contain one of the letters from previous strings,
                // that means the outer map must be updated to not include a count of this current char
                map_it->second = -1;
            }
        }
    }
        
    std::vector<std::string> output;
    for(map_it = char_count.begin(); map_it != char_count.end(); map_it++)
    {
        if(map_it->second != -1)
        {
            for (int i = 0; i < map_it->second; i++) 
            {
                std::string temp(1, map_it->first);
                output.push_back(temp);
            }
        }
    }
        
    return output;
}

int main()
{
    std::cout << "How many strings? " << std::endl;
    int string_count = 0;
    std::cin >> string_count;

    std::cout << "Enter strings:" << std::endl;

    std::vector<std::string> string_vector;
    std::string temp;

    for(int i = 0; i < string_count; i++)
    {
        std::cin >> temp;
        string_vector.push_back(temp);
    }

    Solution solution;
    std::vector<std::string> solution_vector = solution.commonChars(string_vector);

    std::cout << "List of letters that are common in all " << string_count << " strings:" << std::endl;
    for(int j = 0; j < solution_vector.size(); j++)
    {
        std::cout << solution_vector[j] << std::endl;
    }

    return 0;
}
