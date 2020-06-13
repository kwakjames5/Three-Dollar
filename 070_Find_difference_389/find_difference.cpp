#include "find_difference.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/find-the-difference/

// date; 6/12/2020

// description: string s is a random arrangement of chars. string t is a shuffled version of string s with a extra random letter added.
// compare s and t and find which random letter was added to t

char Solution::findTheDifference(std::string s, std::string t) {
    int s_sum = 0;
    int t_sum = 0;
        
    for(int i = 0; i < s.size(); i++)
    {
       s_sum += s[i];
    }
       
    for(int j = 0; j < t.size(); j++)
    {
        t_sum += t[j];
    }
     
    return (char)(t_sum - s_sum);
        
        /*
        map<char, int> letter_store;
        char output;
        for(int i = 0; i < s.size(); i++)
        {
            if(letter_store.find(s[i]) == letter_store.end())
            {
                letter_store.insert(pair<char, int>(s[i], 1));
            }
            else
            {
                letter_store[s[i]]++;
            }
            
        }
        
        for(int j = 0; j < t.size(); j++)
        {
            if(letter_store.find(t[j]) != letter_store.end() && letter_store[t[j]] > 0)
            {
                letter_store[t[j]]--;
            }
            else if(letter_store.find(t[j]) == letter_store.end())
            {
                output = t[j];
            }
        }
        
        map<char, int>::iterator it;
        
        for(it = letter_store.begin(); it != letter_store.end(); it++)
        {
            if(it->second > 0)
            {
                output = it->first;
            }
        }
        
        return output;
        
        //return NULL;
        
        */
}

int main()
{
	std::string string_s;
	std::string string_t;

	std::cout << "Enter two strings containing the same letters except one has a extra random letter (example: abcd and bcdae; e was added): " << std::endl;
	std::cin >> string_s >> string_t;

	Solution solution;
	char diff_char = solution.findTheDifference(string_s, string_t);

	std::cout << "The random letter was: " << diff_char << std::endl;

	return 0;
}