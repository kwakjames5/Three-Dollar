#include "top_k_freq_words.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>

// link: https://leetcode.com/problems/top-k-frequent-words/

// date: 7/13/2020

// description: Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

std::vector<std::string> Solution::topKFrequent(std::vector<std::string>& words, int k) {
    std::map<std::string, int> word_track;
    for(int i = 0; i < words.size(); i++)
    {
       word_track[words[i]]++;
    }
        
    std::map<int, std::set<std::string> > num_track;
    std::map<std::string, int>::iterator map_it;
    for(map_it = word_track.begin(); map_it != word_track.end(); map_it++)
    {
        num_track[map_it->second].insert(map_it->first);    
    }
        
    std::vector<std::string> result;
    // map<int, set<string> >::iterator map_it_1;
    std::set<std::string>::iterator set_it;
    for(auto map_it_1 = num_track.rbegin(); map_it_1 != num_track.rend(); map_it_1++)
    {
        for(set_it = map_it_1->second.begin(); set_it != map_it_1->second.end(); set_it++)
        {
            if(k <= 0)
            {
                return result;
            }
            result.push_back(*set_it);
            k--;
        }
    }
       
    return result;
     
}

int main()
{
	std::vector<std::string> words;
	int k;
	std::cout << "How many words?" << std::endl;
	int word_count = 0;
	std::cin >> word_count;
	std::string input;
	std::cout << "Enter words" << std::endl;
	for(int i = 0; i < word_count; i++)
	{
		std::cin >> input;
		words.push_back(input);
	}
	std::cout << "How many words do you want to check? " << std::endl;
	std::cin >> k;

	Solution solution;
	std::vector<std::string> result = solution.topKFrequent(words, k);

	std::cout << "Top " << k << " elements: " << std::endl;
	for(int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}