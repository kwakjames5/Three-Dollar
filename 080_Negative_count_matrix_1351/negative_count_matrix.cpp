#include "negative_count_matrix.h"
#include <iostream>

// link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// date: 6/19/2020

// description: given a grid (each vector is a row, there are multiple rows), iterate every element and return the total number of negatives

int Solution::countNegatives(std::vector<std::vector<int> >& grid) {
    int negative_count = 0;
    std::vector<std::vector<int> >::iterator it_1;
    std::vector<int>::iterator it_2;
    for(it_1 = grid.begin(); it_1 != grid.end(); it_1++)
    {
        for(it_2 = (*it_1).begin(); it_2 != (*it_1).end(); it_2++)
        {
            if(*it_2 < 0)
            {
                negative_count++;
            }
        }
    }
        
    return negative_count;
}

int main()
{
	std::vector<std::vector<int> > grid;

	std::cout << "How many vectors do you want?: " << std::endl;
	int grid_size = 0;
	std::cin >> grid_size;

	std::cout << "Size of vectors: " << std::endl;
	int vector_size = 0;
	std::cin >> vector_size;

	for(int i = 0; i < grid_size; i++)
	{
		std::cout << "Enter elements for vector " << i + 1 << ": " << std::endl;
		int element = 0;
		std::vector<int> temp_vector;
		for(int j = 0; j < vector_size; j++)
		{
			std::cin >> element;
			temp_vector.push_back(element);
		}
		grid.push_back(temp_vector);
	}

	Solution solution;
	int negative_count = solution.countNegatives(grid);

	std::cout << "Negative count: " << negative_count << std::endl;

	return 0;
}