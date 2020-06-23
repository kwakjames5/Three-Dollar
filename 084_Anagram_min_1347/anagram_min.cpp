#include "anagram_min.h"
#include <string>
#include <map>
#include <iostream>

int Solution::minSteps(std::string s, std::string t) 
{
    std::map<char, int> s_char_track;
    int count = 0;
        
    // s_char_track will keep track of all of the characters from string s that we want to create an anagram of
    for(int i = 0; i < s.size(); i++)
    {
        s_char_track[s[i]]++;
    }
        
    // since we only care about creating an anagram from s's letters, 
    // only iterate the size of s
    for(int j = 0; j < s.size(); j++)
    {
        // start from the start of string t
        // if the current char of string t was included in string s
        if(s_char_track.find(t[j]) != s_char_track.end())
        {
            // decrement the count of the letter
            s_char_track[t[j]]--;
                
            // when the letter runs out, delete it so it is not called on the if statement
            if(s_char_track[t[j]] == 0)
            {
                s_char_track.erase(t[j]);
            }
                
            // this int count is the total number of letters that do not need to be changed
            count++;
        }
    }
        
    // since we need to change a maximum of s.size() chars in t to make it a anagram of s
    // subtract the count from s.size()
    // since this count is the total number of letters in string t which were already found in s
    // s.size() - count ends up being all of the chars in the worst case scenario minus the chars
    // that are already in place
    return s.size() - count;
}

int main()
{
    std::string s, t;
    std::cout << "Enter the two strings: " << std::endl;
    std::cin >> s >> t;

    Solution solution;
    int steps_needed = solution.minSteps(s, t);

    std::cout << "Number of changes needed to change second string into anagram of the first: " << steps_needed << std::endl;

    return 0;
}