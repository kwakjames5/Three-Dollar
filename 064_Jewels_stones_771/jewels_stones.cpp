#include "jewels_stones.h"
#include <string>
#include <set>
#include <iostream>

// link: https://leetcode.com/problems/jewels-and-stones/

// date: 6/9/2020

// description: J contains a string of chars that each stand for a type of jewel ('a' can be a jewel, 'B' can be a jewewl, so on)
// S contains a string of chars of stones you have (can be a combination of any letters and the jewel letters)
// return the total number of jewels in the stones string

int Solution::numJewelsInStones(std::string J, std::string S) 
{
    int jewel_count = 0;
        
    std::set<char> check_set;
    for(int i = 0; i < J.length(); i++)
    {
        if(check_set.find(J[i]) == check_set.end())
        {
            check_set.insert(J[i]);
        }
    }
        
    for(int j = 0; j < S.length(); j++)
    {
        if(check_set.find(S[j]) != check_set.end())
        {
            jewel_count++;
        }
    }
        
    return jewel_count;
}

int main()
{
    std::string jewels;
    std::string stones;

    std::cout << "Enter line for jewels:" << std::endl;
    std::cin >> jewels;

    std::cout << "Enter line for stones:" << std::endl;
    std::cin >> stones;

    Solution solution;
    int jewel_total = solution.numJewelsInStones(jewels, stones);

    std::cout << "Total number of jewel: " << jewel_total << std::endl;

    return 0;
}