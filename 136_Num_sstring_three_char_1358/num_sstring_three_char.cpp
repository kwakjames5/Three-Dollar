#include "num_sstring_three_char.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// date: 7/16/2020

// description: Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

int Solution::numberOfSubstrings(std::string s) {
    // A B C will hold the indexes of where these letters occurred in the string
    std::vector<int> A, B, C;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
        {
            A.push_back(i);
        }
        else if(s[i] == 'b')
        {
            B.push_back(i);
        }
        else
        {
            C.push_back(i);
        }
    }
        
    int total = 0, i = 0, j = 0, k = 0;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        // figure out the first index where 'a', 'b' AND 'c' are all present
        int max_index = std::max(A[i], std::max(B[j], C[k]));
            
        // s.size() - max_index is because now that a substring with all three letters are found,
        // any substrings until the end of the string including these three letters
        // will add to the total
        // s.size() is the total number of substrings that can be made with this current substring
        // and max_index is the last index of the current substring
        total += s.size() - max_index;
            
        if(A[i] < B[j] && A[i] < C[k])
        {
            i++;
        }
        else if(B[j] < A[i] && B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
        
    return total;
        
}

int main()
{
	std::string input;
	std::cout << "Enter a string that only contains 'a', 'b', 'c': " << std::endl;
	std::cin >> input;

	Solution solution;

	int num_sstring = solution.numberOfSubstrings(input);
	std::cout << "Number of substrings that contain 'a', 'b' and 'c': " << num_sstring << std::endl;

	return 0;
}