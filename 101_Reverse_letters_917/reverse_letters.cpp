#include "reverse_letters.h"
#include <algorithm>
#include <string>

// link: https://leetcode.com/problems/reverse-only-letters/

// date: 6/30/2020

// description: given a string, reverse only the characters, leaving any non characters in their original places

std::string Solution::reverseOnlyLetters(std::string S) 
{
    int left_counter = 0;
    int right_counter = S.size() - 1;
        
    while(left_counter < right_counter)
    {
        if(!((S[left_counter] >= 'a' && S[left_counter] <= 'z') || 
             (S[left_counter] >= 'A' && S[left_counter] <= 'Z')))
        {
            left_counter++;
            continue;
        }
        
            if(!((S[right_counter] >= 'a' && S[right_counter] <= 'z') || 
             (S[right_counter] >= 'A' && S[right_counter] <= 'Z')))
        {
            right_counter--;
            continue;
        }
            
        std::swap(S[left_counter], S[right_counter]);
        left_counter++;
        right_counter--;
    }
        
    return S;
}

int main()
{
    std::string S;
    std::cout << "Enter string you want reversed, you can include non characters as well!" << std::endl;
    std::cout << "NOTE: Only the characters will be reversed." << std::endl;
    std::cin >> S;

    Solution solution;
    std::string reversed = solution.reverseOnlyLetters(S);

    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}