#include "count_num_team.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/count-number-of-teams/

// date: 7/6/2020

// description:
// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

int Solution::numTeams(std::vector<int>& rating) 
{
    int total = 0;
    for(int i = 0; i < rating.size(); i++)
    {
        for(int j = i + 1; j < rating.size(); j++)
        {
            for(int k = j + 1; k < rating.size(); k++)
            {
                if((rating[i] < rating[j] && rating[j] < rating[k]) || 
                   (rating[k] < rating[j] && rating[j] < rating[i]))
                   {
                   		total++;
                   }
            }
        }
    }
        
    return total;
}

int main()
{
	std::vector<int> rating;
	std::cout << "How many soldiers?" << std::endl;
	int soldier_count;
	std::cin >> soldier_count;
	std::cout << "Enter soldier ranking(s)" << std::endl;
	int ranking_temp;
	for(int i = 0; i < soldier_count; i++)
	{
		std::cin >> ranking_temp;
		rating.push_back(ranking_temp);
	}

	Solution solution;
	int num_teams = solution.numTeams(rating);

	std::cout << "Total number of unique teams: " << num_teams << std::endl;

	return 0;
}