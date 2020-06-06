#include "kids_greatest_candy.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// date: 6/6/2020

// description: there are kids, each with a different number of candies. there are also extra candies. 
// returns a vector of bools for whether or not each kid can have the highest number of candies in the group just using the extra candies

// ex) 2 3 5 1 3, extra candies = 3;
// true (2 + 3 = 5), true (3 + 3  > 5), true (5 + 3 > 5), false (1 + 3 < 5), true (3 + 3 > 5)

std::vector<bool> Solution::kidsWithCandies(std::vector<int>& candies, int extraCandies) {
    int max = 0;
        
    for(int i = 0; i < candies.size(); i++)
    {
        if(candies[i] > max)
        {
            max = candies[i];
        }
    }
        
    std::vector<bool> return_vector;
      
    for(int j = 0; j < candies.size(); j++)
    {
        if(candies[j] + extraCandies >= max)
        {
            return_vector.push_back(true);
        }
        else
        {
            return_vector.push_back(false);
        }
    }
       
    return return_vector;
}

int main()
{
	std::vector<int> candies;
	std::cout << "Enter number of candies per kid: (-1 to end)" << std::endl;	
	int flag = -1;
	int input;

	while(flag == -1)
	{
		std::cin >> input;
		if(input == -1)
		{
			flag = 0;
			break;
		}
		candies.push_back(input);
	}

	std::cout << "Enter number of extra candies:" << std::endl;

	int extra_candies;

	std::cin >> extra_candies;

	Solution solution;
	std::vector<bool> output = solution.kidsWithCandies(candies, extra_candies);

	std::vector<bool>::iterator it;

	for(it = output.begin(); it != output.end(); it++)
	{
		if(*it == 1)
		{
			std::cout << "True" << std::endl;
		}
		else
		{
			std::cout << "False" << std::endl;
		}
	}

	return 0;

}