#include "first_unique_char.h"
#include <iostream>
#include <string>
#include <map>

// link: https://leetcode.com/problems/first-unique-character-in-a-string/

// date: 6/19/2020

// description: given a string, returns the index of the first character in the string that only appears once in the string
// ex) leetcode
// output = 0

// reason: 'l' is one of the characters that only appears once in the string. since it is on index 0, the function returns this

int Solution::firstUniqChar(std::string s) 
{
    std::map<char, int> char_track;
    for(int i = 0; i < s.size(); i++)
    {
        char_track[s[i]]++;
    }
        
    for(int j = 0; j < s.size(); j++)
    {
        if(char_track[s[j]] == 1)
        {
            return j;
        }
    }
        
    return -1;
}

int main()
{
    std::cout << "Enter string: " << std::endl;
    std::string input_string;
    std::cin >> input_string;

    Solution solution;
    int index = solution.firstUniqChar(input_string);

    std::cout << "Index of first unique character is " << index << std::endl;

    return 0;
}