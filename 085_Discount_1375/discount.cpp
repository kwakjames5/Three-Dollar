#include "discount.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// date: 6/23/2020

// description: given a vector of pries of items at a shop, return the discounted prices. the discount is applied by subtracting the
// price of the closest item which is cheaper than itself
// item i is the current item; find the item j such that j > i and prices[j] <= prices[i]

std::vector<int> Solution::finalPrices(std::vector<int>& prices) 
{
    std::vector<int> final_prices;
        
    for(int i = 0; i < prices.size(); i++)
    {
        int curr_price = prices[i];
        int discount_price = 0;
        int discount_flag = 0;
            
        for(int j = i + 1; j < prices.size(); j++)
        {
            if(prices[j] <= curr_price && discount_flag == 0)
            {
                discount_price = prices[j];
                discount_flag = 1;
            }
        }
            
        final_prices.push_back(curr_price - discount_price);
    }
       
    return final_prices;
}

int main()
{
	std::cout << "Enter how many items you want to consider: " << std::endl;

	int item_count;
	std::cin >> item_count;

	std::vector<int> prices;
	int item_price;

	std::cout << "Enter price of the items: " << std::endl;

	for(int i = 0; i < item_count; i++)
	{
		std::cin >> item_price;
		prices.push_back(item_price);
	}

	Solution solution;

	std::vector<int> discount_prices = solution.finalPrices(prices);

	std::cout << "Discounted prices: " << std::endl;
	for(int j = 0; j < discount_prices.size(); j++)
	{
		std::cout << discount_prices[j] << " ";
	}
	std::cout << std::endl;

	return 0;

}