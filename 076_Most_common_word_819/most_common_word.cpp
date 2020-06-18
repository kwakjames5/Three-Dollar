#include "most_common_word.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// link: https://leetcode.com/problems/most-common-word/

// date: 6/18/2020

// description: given a string and a list of banned words, return the most common word from the string that is not banned

// ex) Bob hit a ball, the hit BALL flew far after it was hit.
// banned words: "hit"
// result: ball

string Solution::mostCommonWord(string paragraph, vector<string>& banned) 
{
    map<string, int> word_count;
    string temp = "";
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower); 
    for(int i = 0; i < paragraph.length(); i++)
    {
        if(paragraph[i] >= 'a' && paragraph[i] <= 'z' && paragraph[i] != ' ')
        {
            temp += paragraph[i];
        }
            
        if(paragraph[i] == ' ' || i == paragraph.length() - 1 || paragraph[i] == ',')
        {
            if(temp.size() != 0)
            {
                word_count[temp]++;
                temp.clear();
            }
        }
    }
        
    int highest = -1;
    int flag = 0;
    string most_common;
       
    for(map<string, int>::iterator it = word_count.begin(); it != word_count.end(); it++)
    {
        flag = 0;
        for(vector<string>::iterator it2 = banned.begin(); it2 != banned.end(); it2++)
        {
            if(it->first == *it2)
            {
                flag = -1;
            }
        }
            
        if(flag != -1 && it->second > highest)
        {
            most_common = it->first;
            highest = it->second;
        }
    }
     
    return most_common;
    /*for(int j = 0; j < banned.size(); j++)
    {
        cout << banned[j] << endl;
    }


    map<string, int> word_count;
    string temp = "";
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower); 
    for(int i = 0; i < paragraph.length(); i++)
    {
        if(paragraph[i] != ' ' && paragraph[i] >= 'a' && paragraph[i] <= 'z')
        {
            temp += paragraph[i];
            std::cout << temp << endl;
        }
          
        if(paragraph[i] == ' ' || i == paragraph.length() - 1 || paragraph[i] == ',')
        {
            if(find(banned.begin(), banned.end(), temp) == banned.end())
            {
                cout << "flag" << endl;
                word_count[temp]++;
            }
            temp = "";
        }
    }
        
    int highest = 0;
    string most_common;
        
    for(map<string, int>::iterator it = word_count.begin(); it != word_count.end(); it++)
    {
        cout << it->first << endl;
        cout << it->second << endl;
        if(it->second >= highest)
        {
            most_common = it->first;
            highest = it->second;
        }
        cout << most_common << highest << endl;
    }
        
    return most_common;
    */
}

int main()
{
    std::cout << "Enter the string to be checked: " << std::endl;
    string paragraph;
    getline(std::cin, paragraph);
    std::cout << std::endl;

    vector<string> banned;
    std::cout << "How many banned words?: " << std::endl;

    int count = 0;
    std::cin >> count;
    std::cout << std::endl;

    std::cout << "Enter banned words: " << std::endl;
    std::string temp;

    for(int i = 0; i < count; i++)
    {
        std::cin >> temp;
        banned.push_back(temp);
    }

    std::cout << std::endl;

    Solution solution;
    string most_common = solution.mostCommonWord(paragraph, banned);

    std::cout << "Most common word from the string: " << most_common << std::endl;

    return 0;
}