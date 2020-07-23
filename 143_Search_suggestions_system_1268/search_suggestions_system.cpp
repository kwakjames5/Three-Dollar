#include "search_suggestions_system.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// link: https://leetcode.com/problems/search-suggestions-system/

// date: 7/22/2020

// description: Given an array of strings products and a string searchWord. 
// We want to design a system that suggests at most three product names from products after each character of searchWord is typed. 
// Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

// Return list of lists of the suggested products after each character of searchWord is typed. 

std::vector<std::vector<std::string> > Solution::suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
    std::sort(products.begin(), products.end());
    std::vector<std::vector<std::string> > return_vector;
    std::vector<std::string> insert_vector;
    for(int i = 0; i < searchWord.size(); i++)
    {
        std::string search_temp = searchWord.substr(0, i + 1);
        int three_flag = 0;
        for(int j = 0; j < products.size(); j++)
        {
            std::string substr = products[j].substr(0, i + 1);
            if(substr == search_temp)
            {
                insert_vector.push_back(products[j]);
                three_flag++;
            }
                
            if(three_flag == 3)
            {
                break;
            }
        }
        return_vector.push_back(insert_vector);
        insert_vector.clear();
    }
        
    return return_vector;
}

int main()
{
    std::vector<std::string> products;
    std::string search_word;
    std::cout << "How many products? " << std::endl;
    int product_count = 0;
    std::cin >> product_count;
    std::cout << "Enter product names:" << std::endl;
    std::string temp;
    for(int i = 0; i < product_count; i++)
    {
        std::cin >> temp;
        products.push_back(temp);
    }
    std::cout << "Enter search word:" << std::endl;
    std::cin >> search_word;

    Solution solution;
    std::vector<std::vector<std::string> > suggested_products = solution.suggestedProducts(products, search_word);

    std::cout << "Search suggestions: " << std::endl;
    for(int i = 0; i < suggested_products.size(); i++)
    {
        std::vector<std::string> curr = suggested_products[i];
        for(int j = 0; j < curr.size(); j++)
        {
            std::cout << curr[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}