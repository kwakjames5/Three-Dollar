#include "reverse_words_sentence.h"
#include <iostream>
#include <string>
#include <vector>

// link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

// date: 6/24/2020

// description: given a sentence, reverse each word in the sentence without changing the order of the words

std::string Solution::reverseWords(std::string s) 
{
    std::string return_string = "";
        
    std::vector<std::string> word_store;
    std::string temp_string = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            word_store.push_back(temp_string);
            temp_string.clear();
        }
        else
        {
            temp_string += s[i];
        }
            
        if(i == s.size() - 1)
        {
            word_store.push_back(temp_string);
            temp_string.clear();
        }
    }
        
    for(int j = 0; j < word_store.size(); j++)
    {
        std::string curr_word = word_store[j];
        for(int k = curr_word.size() - 1; k >= 0; k--)
        {
            return_string += curr_word[k];
        }
            
        if(j != word_store.size() - 1)
        {
            return_string += ' '; 
        }
    }
        
    return return_string;
}

int main()
{
    std::cout << "Enter sentence: " << std::endl;
    std::string sentence;
    getline(std::cin, sentence);

    Solution solution;
    std::string reverse_sentence = solution.reverseWords(sentence);
    std::cout << "Reversed sentence: " << reverse_sentence << std::endl;

    return 0;

}