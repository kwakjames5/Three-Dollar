#include "destination_city.h"
#include <vector>
#include <string>
#include <iostream>

// link: https://leetcode.com/problems/destination-city/

// date: 7/21/2020

// description: You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
// Return the destination city, that is, the city without any path outgoing to another city.
// It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

std::string Solution::destCity(std::vector<std::vector<std::string> >& paths) 
{
    bool at_end = false;
    std::string city_b = paths[0][1];
        
    while(!at_end)
    {
        for(int i = 0; i < paths.size(); i++)
        {
            if(paths[i][0] == city_b)
            {
                city_b = paths[i][1];
                break;
            }
                
            if(i == paths.size() - 1)
            {
                at_end = true;
            }
        }
    }
        
    return city_b;
}

int main()
{
    std::vector<std::vector<std::string> > paths;
    std::cout << "How many paths?" << std::endl;
    int path_count;
    std::cin >> path_count;
    std::cout << "Enter paths Format: (Current location, destination) (NO SPACES AND CASE SENSITIVE)" << std::endl;
    std::string temp;
    for(int i = 0; i < path_count; i++)
    {
        std::cout << "Path " << i + 1 << ": " << std::endl;
        std::vector<std::string> path;

        for(int j = 0; j < 2; j++)
        {
            std::cin >> temp;
            path.push_back(temp);
        }

        paths.push_back(path);
    }

    Solution solution;
    std::string dest_city = solution.destCity(paths);

    std::cout << "Destination city: " << dest_city << std::endl;

    return 0;
}