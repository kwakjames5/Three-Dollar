#include "ransom_note.h"
#include <string>
#include <iostream>
#include <vector>

//link: https://leetcode.com/problems/ransom-note/

// date: 6/30/2020

// description: Given an arbitrary ransom note string and another string containing letters from all the magazines, 
// write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// ex) Input: magazine = "aab" ], ransomNote = "aa"
// Output: true

bool Solution::canConstruct(std::string ransomNote, std::string magazine) 
{
    std::vector<int> magazine_track(26);
    for(int i = 0; i < magazine.size(); i++)
    {
        magazine_track[magazine[i] - 'a']++;
    }
        
    for(int j = 0; j < ransomNote.size(); j++)
    {
        if(magazine_track[ransomNote[j] - 'a'] > 0)
        {
            magazine_track[ransomNote[j] - 'a']--;
        }
        else
        {
            return false;
        }
    }
        
    return true;
}

int main()
{
    std::string ransom, magazine;

    std::cout << "Enter the magazine string, then the ransom string." << std::endl;
    std::cin >> magazine >> ransom;

    Solution solution;
    bool can_construct = solution.canConstruct(ransom, magazine);

    if(can_construct)
    {
        std::cout << "The ransom can be made from the magazine" << std::endl;
    }
    else
    {
        std::cout << "The ransom cannot be made from the magazine" << std::endl;
    }

    return 0;
}