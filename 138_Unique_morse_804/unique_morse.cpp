#include "unique_morse.h"
#include <vector>
#include <string>
#include <set>
#include <iostream>

// link: https://leetcode.com/problems/unique-morse-code-words/

// date: 7/20/2020

// description:
// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
// For convenience, the full table for the 26 letters of the English alphabet is given below:
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. 
// For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation of a word.
// Return the number of different transformations among all words we have.

int Solution::uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::set<std::string> morse_count;
    std::string alpha[27] = {".-","-...","-.-.","-..",".","..-.","--.",
                      "....","..",".---","-.-",".-..","--","-.",
                      "---",".--.","--.-",".-.","...","-","..-",
                      "...-",".--","-..-","-.--","--.."};
    for(int i = 0; i < words.size(); i++)
    {
        std::string curr = words[i];
        std::string morse = "";
        for(int j = 0; j < curr.size(); j++)
        {
            std::string temp = alpha[curr[j] - 97];
            morse += temp;
        }
        morse_count.insert(morse);
    }
    return morse_count.size();
}

int main()
{
    std::cout << "Enter word count" << std::endl;
    int word_count;
    std::cin >> word_count;
    std::vector<std::string> words;
    std::string temp;
    std::cout << "Enter words" << std::endl;
    for(int i = 0; i < word_count; i++)
    {
        std::cin >> temp;
        words.push_back(temp);
    }

    Solution solution;
    int unique_count = solution.uniqueMorseRepresentations(words);

    std::cout << "Number of unique morse codes: " << unique_count << std::endl;

    return 0;
}