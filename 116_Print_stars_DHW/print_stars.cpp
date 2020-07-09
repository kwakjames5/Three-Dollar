#include "print_stars.h"
#include <iostream>

// date: 7/8/2020

// description: given a count, print lines of stars with quantity up to the count, incrementing up from 0

void Solution::printStars(int starCount)
{
	int curr_count = 0;
	for(int i = 0; i <= starCount; i++)
	{
		std::cout << i << " stars: ";
		for(int j = 0; j < curr_count; j++)
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
		curr_count++;
	}
}

int main()
{
	std::cout << "How many stars do you want to print up to?" << std::endl;
	int star_count = 0;
	std::cin >> star_count;

	Solution solution;

	std::cout << "Stars:" << std::endl;
	solution.printStars(star_count);

	return 0;
}