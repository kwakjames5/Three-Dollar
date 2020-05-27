#include "find_words_chars.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

// date: 5/27/2020

// description: a vector of words and a string are given. function will check each word and see if this word can be formed using characters available in the string.
//              when the a word can be fully formed using just the characters from the string, the length is added to a return sum
//              this return sum will ultimately have the total length of all of the words that can be formed by using the characters available in the string

// example input: words = ["cat","bt","hat","tree"] chars = "atach"
// example output: 6
// explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.


int Solution::countCharacters(std::vector<std::string>& words, std::string chars) 
{
    int good_word_length_sum = 0;
        
    // empty vector for keeping track of which characters are available from chars
    std::vector<int> char_count(26, 0);
            
    // iterate chars and update char_count for each character in chars
    for(int i = 0; i < chars.length(); i++)
    {
        char_count[chars[i] - 'a']++;
    }
        
    // iterate the words vector
    for(int i = 0; i < words.size(); i++)
    {  
        // temporary copy of char_count
        std::vector<int> temp_char_count;
        temp_char_count = char_count;
        
        // keep track of how many letters in the current word string can be found in chars
       int valid_char_count = 0;
    
        // iterate the word string's length
        for(int j = 0; j < words[i].length(); j++)
        {
            // increment valid count and decrement the temporary character count when the character 
            // that is currently being checked is available in temp_char_count
            if(temp_char_count[words[i][j] - 'a'] > 0)
            {
                valid_char_count++;
                temp_char_count[words[i][j] - 'a']--;
            }
        }
            
        // after iterating through the length of the word, if valid_char_count
        // is as long as the original word string, meaning that all of its characters
        // are available in chars, update the good_word_length_sum by the char_count
        if(valid_char_count == words[i].size())
        {
            good_word_length_sum += valid_char_count;
        }
    }
        
    return good_word_length_sum;
}

int main()
{
	std::cout << "Enter the words you want to check (Type 0 when done): " << std::endl;
	int flag = 0;
	std::string input;
	std::vector<std::string> words;

	while(flag == 0)
	{
		std::cin >> input;
		if(input == "0")
		{
			flag = 1;
			break;
		}

		words.push_back(input);
	}

	std::cout << "Enter the chars string (the available characters): " << std::endl;
	std::string chars;
	std::cin >> chars;

	Solution solution;
	int length_sum = solution.countCharacters(words, chars);

	std::cout << "Total sum of lengths of valid words: " << length_sum << std::endl;

	return 0;
}