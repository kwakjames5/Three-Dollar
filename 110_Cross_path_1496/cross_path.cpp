#include "cross_path.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// link: https://leetcode.com/problems/path-crossing/

// date: 7/6/2020

// description: given a string in which each char represents a single unit moved in that char's direction (each char is N, E, S, W for direction). Return whether or not you cross the path you are making.

bool Solution::isPathCrossing(std::string path) 
{
    int curr_x = 0;
    int curr_y = 0;
    std::vector<std::string> visited;
    visited.push_back("0,0");
        
    for(int i = 0; i < path.size(); i++)
    {
        if(path[i] == 'N')
        {
            curr_y += 1;
        }
        else if(path[i] == 'S')
        {
            curr_y -= 1;
        }
        else if(path[i] == 'E')
        {
            curr_x += 1;
        }
        else
        {
            curr_x -= 1;
        }
        std::string curr_coor = std::to_string(curr_x) + "," + std::to_string(curr_y);
        if(std::find(visited.begin(), visited.end(), curr_coor) != visited.end())
        {
            return true;
        }
        visited.push_back(curr_coor);
    }
        
    return false;
        
}

int main()
{
    std::string path;
    std::cout << "Enter path to travel (Enter N, S, E, W in sequence in one string; each letter accounts for 1 unit in that direction)" << std::endl;
    std::cin >> path;
    Solution solution;
    bool path_cross = solution.isPathCrossing(path);
    if(path_cross)
    {
        std::cout << "The path was crossed at one point" << std::endl;
    }
    else
    {
        std::cout << "The path was not crossed" << std::endl;
    }

    return 0;
}