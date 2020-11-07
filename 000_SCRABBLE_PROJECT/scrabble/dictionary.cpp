#include "dictionary.h"
#include "exceptions.h"
#include <fstream>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;


string lower(string str) {
    transform(str.cbegin(), str.cend(), str.begin(), ::tolower);
    return str;
}

Dictionary Dictionary::read(const std::string& file_path) {
    ifstream file(file_path);
    if (!file) {
        throw FileException("cannot open dictionary file!");
    }

    std::string word;
    Dictionary dictionary;
    // HW 5
    dictionary.root = make_shared<TrieNode>();

    while(!file.eof())
    {
        file >> word;
        if(word.empty())
        {
            break;
        }

        word = lower(word);
        dictionary.add_word(word);
    }

    file.close();
    return dictionary;
    
    
}

bool Dictionary::is_word(const string& word) const {
    shared_ptr<TrieNode> cur = find_prefix(word);
    if (cur == nullptr)
        return false;

    cur = root;
    for(char letter : word)
    {
        // Each iteration, checks if letter is within cur's nexts map
        // if if is, check if the letter is the final letter in a word
        // if it is, return true.
        // if it is not, set cur to the TrieNode of the letter found
        if(cur->nexts.find(letter) != cur->nexts.end()) // if we have the letter
        {
            cur = cur->nexts.find(letter)->second; // set cur to the TrieNode of the letter found
        }
        else // no letter = not in dictionary
        {
            return false;
        }
    }

    if(cur->is_final)
    {
        return true;
    }

    return false;
}

shared_ptr<Dictionary::TrieNode> Dictionary::find_prefix(const string& prefix) const {
    shared_ptr<TrieNode> cur = root;
    // This is a for each loop in C++. It is equivalent to the following:
    // for (int i = 0; i < prefix.length(); i++) {
    //      char letter = prefix[i];
    for (char letter : prefix) {
        if(cur->nexts.find(letter) != cur->nexts.end()) // if cur has the letter
        {
            cur = cur->nexts.find(letter)->second;
        }
        else // if cur does not have the letter
        {
            return nullptr;
        }
    }
    return cur;
}

// Implemented for you to build the dictionary trie
void Dictionary::add_word(const string& word) {
    shared_ptr<TrieNode> cur = root;
    for (char letter : word) {
        if (cur->nexts.find(letter) == cur->nexts.end()) {
            cur->nexts.insert({letter, make_shared<TrieNode>()});
        }
        cur = cur->nexts.find(letter)->second;
    }
    cur->is_final = true;
}

vector<char> Dictionary::next_letters(const std::string& prefix) const {
    shared_ptr<TrieNode> cur = find_prefix(prefix);
    vector<char> nexts;
    if (cur == nullptr)
        return nexts;

    std::map<char, std::shared_ptr<TrieNode>>::iterator map_it; 
    for(map_it = cur->nexts.begin(); map_it != cur->nexts.end(); map_it++)
    {
        nexts.push_back(map_it->first);
    }
    return nexts;
}
