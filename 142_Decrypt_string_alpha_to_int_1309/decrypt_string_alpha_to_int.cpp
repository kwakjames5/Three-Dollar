#include "decrypt_string_alpha_to_int.h"
#include <string>
#include <iostream>

// link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

// date: 7/22/2020

// description: Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:
// Characters ('a' to 'i') are represented by ('1' to '9') respectively.
// Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
// Return the string formed after mapping.
// It's guaranteed that a unique mapping will always exist.

// ex) input: 12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#
// output: abcdefghijklmnopqrstuvwxyz

std::string Solution::freqAlphabets(std::string s) {
    std::string return_str = "";
    for(int i = 0; i < s.size();)
    {
        if(i + 2 < s.size() && s[i + 2] == '#')
        {
            int temp = (s[i] - 48) * 10 + (s[i + 1] - 48);
            return_str += char(temp + 96);
            i += 3;
        }
        else
        {
            return_str += char(s[i] - 48 + 96);
            i++;
        }
    }
        
    return return_str;
}

int main()
{
    std::string s;
    std::cout << "Enter string of integer map (a - i = 1 - 9; j - z = 10#, 11#, 12#, ...): " << std::endl;
    std::cin >> s;
    Solution solution;
    std::string output = solution.freqAlphabets(s);

    std::cout << "Alphabet string: " << output << std::endl;

    return 0;
}