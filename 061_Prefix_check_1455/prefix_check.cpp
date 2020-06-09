#include "prefix_check.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>

// link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

// date: 6/8/2020

// description: given a sentence, returns the index of a word in the sentence that contains searchWord

int Solution::isPrefixOfWord(std::string sentence, std::string searchWord) 
{
	std::stringstream ss(sentence);
    std::string word;
    int index = 1;

    while(ss >> word)
    {
    	std::cout << word << std::endl;
        std::string temp;
        for(int i = 0; i < word.length(); i++)
        {
            temp += word[i];
            std::cout << temp << std::endl;
            if(temp == searchWord)
            {
                return index;
            }
        }
        index++;
        std::cout << index << std::endl;
    }
    return -1;
}

int main()
{
	std::string sentence;
	std::string search_word;

	std::cout << "Enter the sentence: " << std::endl;
	getline(std::cin, sentence);

	std::cout << "Enter the search word: " << std::endl;
	std::cin >> search_word;

	Solution solution;
	int index = solution.isPrefixOfWord(sentence, search_word);

	std::cout << "Index: " << index << std::endl;

	return 0;
}